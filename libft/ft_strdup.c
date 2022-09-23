/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:43:48 by joaooliv          #+#    #+#             */
/*   Updated: 2022/09/23 13:34:51 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*dupped;
	unsigned int	index;

	dupped = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dupped)
	{
		index = 0;
		while (s && s[index])
		{
			dupped[index] = s[index];
			index++;
		}
		dupped[index] = 0;
	}
	return (dupped);
}
