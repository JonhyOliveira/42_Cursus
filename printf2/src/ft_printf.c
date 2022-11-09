/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaooliv <joaooliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:28:10 by joaooliv          #+#    #+#             */
/*   Updated: 2022/11/09 12:42:24 by joaooliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "internals.h"

void	print_options(t_f_options *opts);

static void	do_padding(t_list *str, t_f_options *opts)
{
	size_t	padd_len;
	t_list	*padd_str;

	padd_len = opts->field_width - ft_lstsize(str);
	padd_str = 0;
	if (padd_len > 0 && opts->field_width > 0)
	{
		padd_str = ft_lstnew(opts->padd_char);
		if (!padd_str)
			return ;
		while (padd_len-- > 0)
			ft_lstadd_back(padd_str, ft_lstnew(opts->padd_char));
	}
	if (opts->flags[minus])
		ft_lstadd_back(str, padd_str);
	else
		ft_lstadd_front(str, padd_str);
}

static t_list	*format(t_f_options *opts, va_list args, size_t index)
{
	va_list			copy;
	static t_list	*(*converters[CONVERSIONS_N])(t_f_options *, va_list);

	converters[null] = &to_perc;
	converters[character] = &to_character;
	converters[string] = &to_str;
	converters[pointer] = &to_pointer;
	converters[decimal] = &to_dec;
	converters[integer] = &to_dec;
	converters[udecimal] = &to_dec;
	converters[lhex] = &to_hex;
	converters[Hhex] = &to_hex;
	va_copy(copy, args);
	while (index-- > 1)
		va_arg(copy, void *);
	if (converters[opts->conv])
		do_padding(converters[opts->conv](opts, copy), opts);
	else
		return (0);
}

// because everyone hates norminette
static void	loopdy_loop(char **fmt_it, size_t *index, va_list args, t_list **str)
{
	t_f_options	*opts;
	t_list		*new;

	opts = parse_format(*fmt_it, fmt_it);
	if (opts)
	{
		if (opts->arg_i <= 0)
			new = format(opts, args, (*index)++);
		else
			new = format(opts, args, opts->arg_i);
		free(opts);
	}
	else
		new = ft_lstnew(ctos(*(*fmt_it)++));
	ft_lstadd_back(str, new);
}

static void	putstrlst(t_list *lst)
{
	while (lst && lst->content)
	{
		write(1, &(lst->content), 1);
		lst = lst->next;
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*fmt_it;
	t_list		*str;
	size_t		index;

	index = 1;
	fmt_it = (char *)fmt;
	str = (t_list *) 0;
	va_start(ap, fmt);
	while (*fmt_it)
		loopdy_loop(&fmt_it, &index, ap, &str);
	putstrlst(str);
	index = ft_lstsize(str);
	ft_lstclear(str, free);
	return (index);
}
