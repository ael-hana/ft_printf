/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_op_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:40:28 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/05 11:15:08 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*ft_putstr_stop(char *str, char chr)
{
	while (*str && *str != chr)
		write(1, str++, 1);
	if (*str)
		return (str);
	return (NULL);
}

int			ft_putstr_ret_len(t_list_p *list, void *params)
{
	void	*ptr;

	if (list && list->modifi_l == 1)
		return (ft_printf_op_s_unicode(list, params));
	if (!(ptr = va_arg(*(va_list *)params, char *)))
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(ptr);
	return ((int)ft_strlen(ptr));
}

int			ft_print_chr(t_list_p *list, void *params)
{
	int		n;

	if (list && list->modifi_l == 1)
		return (ft_put_op_c_unicode(va_arg(*((va_list *)params), unsigned int)));
	n = 0;
	while (list->modifi_atoi > 1)
	{
		n++;
		write(1, " ", 1);
		list->modifi_atoi--;
	}
	ft_putchar((char)va_arg(*((va_list *)params), int));
	return (1 + n);
}
