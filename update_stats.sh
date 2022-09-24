# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update_stats.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 13:14:18 by joaooliv          #+#    #+#              #
#    Updated: 2022/09/24 20:34:02 by joaooliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# this script counts lines in C files for all my projects



count_lines()
{
	if [[ $PROJECTS ]]
	then 
		touch /tmp/a
		rm /tmp/line_count
		touch /tmp/line_count
		printf "|%-25.15s|%-15.15s|\n" "project" "lines of code"
		printf "|%-25.15s|%-15.15s|\n" " :-- " " :---: "
		p_count=
		for project in $PROJECTS
		do
			cd $project
			CFILES=$(git ls-files | grep -e "\.c$")
			HFILES=$(git ls-files | grep -e "\.h$")
			p_count=$(cat $CFILES /tmp/a | sed '/#include/d' | cat - $HFILES /tmp/a | sed '/\/\*/d' | sed '/^\//d' | sed '/^[[:space:]]*$/d' | wc -l)
			printf "|%-25.15s|%-15.15s|\n" $project $p_count
			cd ..
		done
		rm /tmp/a
	else
		echo "No projects here :("
	fi
	cat /tmp/line_count
}
PROJECTS=$(find -P -maxdepth 1 -type d -not -name ".*" | cut -d '/' -f 2)
# echo $PROJECTS

count_lines | cat README.part1 - > README.md
