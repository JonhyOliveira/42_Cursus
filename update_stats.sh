# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update_stats.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 13:14:18 by joaooliv          #+#    #+#              #
#    Updated: 2022/09/24 22:35:16 by joaooliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# this script counts lines in C files for all my projects

count_lines()
{
	if [[ $PROJECTS ]]
	then 
		touch /tmp/a
		printf "|%-25.15s|%-15.15s|\n" "Project" "Lines of Code"
		printf "|%-25.15s|%-15.15s|\n" " :-- " " :---: "
		p_count=
		for project in $PROJECTS
		do
			CFILES=$(git ls-files $project | grep -e "\.c$")
			HFILES=$(git ls-files $project | grep -e "\.h$")
			p_count=$(cat $CFILES /tmp/a | sed '/#include/d' | cat - $HFILES /tmp/a | sed '/\/\*/d' | sed '/^\//d' | sed '/^[[:space:]]*$/d' | wc -l)
			printf "|%-25.15s|%-15.15s|\n" $project $p_count
		done
		rm /tmp/a
		exit 1
	else
		exit 0
	fi
}
PROJECTS=$(find -P $1 -maxdepth 1 -type d -not -name ".*" | cut -d '/' -f 2)
echo $PROJECTS

if [ -e README.part1 ] && [ -d .git ] && [[ $PROJECTS ]];
then
	count_lines | cat README.part1 - > README.md
else
	echo "No projects :("
fi
