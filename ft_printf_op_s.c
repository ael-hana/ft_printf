/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_op_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:40:28 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/10 17:15:30 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_putstr_len(char *str, int len)
{
	int				i;

	i = 0;
	while (str[i] && (len > i || !len))
		write(1, str + i++, 1);
	return (i);
}

int					ft_putstr_ret_len(t_list_p *list, void *params)
{
	int				i;
	int				tmp;
	void			*ptr;

	if (list && list->modifi_l == 1)
		return (ft_printf_op_s_unicode(list, params));
	if (!(ptr = va_arg(*(va_list *)params, char *)))
	{
		ft_putstr("(null)");
		return (6);
	}
	if (list->prec_i && ft_strlen(ptr) > (size_t)list->prec)
	{
		i = ft_write_space(list->modifi_atoi - (list->prec), list);
	}
	else
	{
		tmp = list->prec;
		list->prec = 0;
		i = ft_write_space(list->modifi_atoi - (ft_strlen(ptr)), list);
		list->prec = tmp;
	}
	if (list->prec_i && (!list->prec))
		return (i);
	return (i + ft_putstr_len(ptr, list->prec));
}

int					ft_print_chr(t_list_p *list, void *params)
{
	int				n;

	if (list && list->modifi_l == 1)
		return (ft_put_op_c_unicode(va_arg(*((va_list *)params), unsigned int)));
	n = ft_write_space(list->modifi_atoi - 1, list);
	ft_putchar((char)va_arg(*((va_list *)params), int));
	return (1 + n);
}
