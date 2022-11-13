/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:37:39 by joaooliv          #+#    #+#             */
/*   Updated: 2022/11/13 17:43:37 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	*ft_newstr(size_t size)
{
	t_str	*new;

	new = (t_str *) malloc(sizeof(t_str));
	if (!new)
		return (0);
	new->size = size;
	new->content = (char *) malloc(sizeof(char) * (size + 1));
	if (!new->content)
	{
		free(new);
		return (0);
	}
	return (new);
}

t_str	*ft_newstr_backedby(char *str)
{
	t_str	*new;

	new = (t_str *) malloc(sizeof(t_str));
	if (!new)
		return (0);
	new->content = str;
	new->size = ft_strlen(str);
	return (new);
}