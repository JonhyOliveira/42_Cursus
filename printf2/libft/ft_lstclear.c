/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:39:25 by joaooliv          #+#    #+#             */
/*   Updated: 2022/10/26 16:00:05 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (lst && *lst && del)
	{
		aux = *lst;
		while (aux)
		{	
			aux = aux->next;
			ft_lstdelone(*lst, del);
			*lst = aux;
		}
		*lst = 0;
	}
}
