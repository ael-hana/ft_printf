/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_op_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:40:28 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/06 03:46:44 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putstr_ret_len(t_list_p *list, void *params)
{
	int		i;
	void	*ptr;

	if (list && list->modifi_l == 1)
		return (ft_printf_op_s_unicode(list, params));
	if (!(ptr = va_arg(*(va_list *)params, char *)))
	{
		ft_putstr("(null)");
		return (6);
	}
	i = ft_write_space(list->modifi_atoi - ft_strlen(ptr), list);
	ft_putstr(ptr);
	return ((int)ft_strlen(ptr) + i);
}

int			ft_print_chr(t_list_p *list, void *params)
{
	int		n;

	if (list && list->modifi_l == 1)
		return (ft_put_op_c_unicode(va_arg(*((va_list *)params), unsigned int)));
	n = ft_write_space(list->modifi_atoi - 1, list);
	ft_putchar((char)va_arg(*((va_list *)params), int));
	return (1 + n);
}
