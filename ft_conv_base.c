/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 20:07:16 by ael-hana          #+#    #+#             */
/*   Updated: 2015/12/24 02:50:26 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_base(unsigned long long int num, int base, unsigned int i, char opt)
{
	char str[] = "0123456789ABCDEFGHIJKLMNOP";
	char str2[] = "0123456789abcdefghijklmnop";

	if (num / base)
		i = ft_printf_base(num / base, base, i, opt);
	if (opt)
		ft_putchar(str2[num % base]);
	else
		ft_putchar(str[num % base]);
	return (i + 1);
}

int		ft_print_op_o(t_list_p *list, void *params)
{
	if (list && list->modifi_l == 1)
		return (ft_printf_base((unsigned long)va_arg(*((va_list *)params), unsigned long int), 8, 0, 0));
	else if (list && list->modifi_l == 2)
		return (ft_printf_base((unsigned long)va_arg(*((va_list *)params), unsigned long long int), 8, 0, 0));
	else if (list && list->modifi_h == 2)
		return (ft_printf_base((unsigned char)va_arg(*((va_list *)params), int), 8, 0, 0));
	else if (list && list->modifi_j == 1)
		return (ft_printf_base(va_arg(*((va_list *)params), long), 8, 0, 0));
	else if (list && list->modifi_z == 1)
		return (ft_printf_base(va_arg(*((va_list *)params), size_t), 8, 0, 0));
	else
		return (ft_printf_base((unsigned long)va_arg(*((va_list *)params), unsigned int), 8, 0, 0));
}


int		ft_print_op_o_great(t_list_p *list, void *params)
{
	(void) list;
	return (ft_printf_base(va_arg(*((va_list *)params), unsigned long), 8, 0, 0));
}

int		ft_print_op_x(t_list_p *list, void *params)
{
	if (list && list->modifi_l == 1)
		return (ft_printf_base(va_arg(*((va_list *)params), unsigned long int), 16, 0, 1));
	else if (list && list->modifi_l == 2)
		return (ft_printf_base(va_arg(*((va_list *)params), unsigned long long int), 16, 0, 1));
	else if (list && list->modifi_h == 2)
		return (ft_printf_base((unsigned char)va_arg(*((va_list *)params), int), 16, 0, 1));
	else if (list && list->modifi_j == 1)
		return (ft_printf_base(va_arg(*((va_list *)params), long), 16, 0, 1));
	else if (list && list->modifi_z == 1)
		return (ft_printf_base(va_arg(*((va_list *)params), size_t), 16, 0, 1));
	else
		return (ft_printf_base(va_arg(*((va_list *)params), unsigned int), 16, 0, 1));
}

int		ft_print_op_x_great(t_list_p *list, void *params)
{
	if (list && list->modifi_l == 1)
		return (ft_printf_base(va_arg(*((va_list *)params), unsigned long int), 16, 0, 0));
	else if (list && list->modifi_l == 2)
		return (ft_printf_base(va_arg(*((va_list *)params), unsigned long long int), 16, 0, 0));
	else if (list && list->modifi_h == 2)
		return (ft_printf_base((unsigned char)va_arg(*((va_list *)params), int), 16, 0, 0));
	else if (list && list->modifi_j == 1)
		return (ft_printf_base(va_arg(*((va_list *)params), long), 16, 0, 0));
	else if (list && list->modifi_z == 1)
		return (ft_printf_base(va_arg(*((va_list *)params), size_t), 16, 0, 0));
	else
		return (ft_printf_base(va_arg(*((va_list *)params), unsigned int), 16, 0, 0));
}
