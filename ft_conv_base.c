/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 20:07:16 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/11 01:11:58 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							ft_printf_base(unsigned long long int num, int base,
		unsigned int i, char opt)
{
	char					str[] = "0123456789ABCDEFGHIJKLMNOP";
	char					str2[] = "0123456789abcdefghijklmnop";

	if (num / base)
		i = ft_printf_base(num / base, base, i, opt);
	if (opt)
		ft_putchar(str2[num % base]);
	else
		ft_putchar(str[num % base]);
	return (i + 1);
}

int							ft_print_op_o(t_list_p *list, void *params)
{
	unsigned long long int	num;
	int						i;
	int						tmp;

	if (list && list->modifi_l == 1)
		num = va_arg(*((va_list *)params), unsigned long int);
	else if (list && list->modifi_l == 2)
		num = va_arg(*((va_list *)params), unsigned long long int);
	else if (list && list->modifi_h == 2)
		num = (unsigned char)va_arg(*((va_list *)params), int);
	else if (list && list->modifi_j == 1)
		num = va_arg(*((va_list *)params), long);
	else if (list && list->modifi_z == 1)
		num = va_arg(*((va_list *)params), size_t);
	else
		num = (unsigned long)va_arg(*((va_list *)params), unsigned int);
	if (list->dize && num)
		return (write(1, "0", 1) + ft_printf_base(num, 8, 0, 0));
	i = ft_write_space(list->modifi_atoi - ((list->prec > ft_len_base(num, 8)) ?
				list->prec : ft_len_base(num, 8)), list);
	list->chr = 1;
	tmp = list->prec;
	list->prec = 0;
	if (!(num || list->modifi_atoi || list->modifi_h ||
				list->modifi_L || list->modifi_j || list->modifi_z
				|| tmp || list->dize || list->p) && list->prec_i)
		return (0);
	return (i + ft_write_space(tmp - ft_len_base(num, 8), list) + ft_printf_base(num, 8, 0, 0));
}

int							ft_print_op_o_great(t_list_p *list, void *params)
{
	list->modifi_l = 1;
	return (ft_print_op_o(list, params));
}

int							ft_print_op_x(t_list_p *list, void *params)
{
	int						i;
	unsigned long long int	num;
	int						tmp;

	i = 0;
	if (list->modifi_l == 1)
		num = va_arg(*((va_list *)params), unsigned long int);
	else if (list->modifi_l == 2)
		num = va_arg(*((va_list *)params), unsigned long long int);
	else if (list->modifi_h == 2)
		num = (unsigned char)va_arg(*((va_list *)params), int);
	else if (list->modifi_j == 1)
		num  = va_arg(*((va_list *)params), long);
	else if (list->modifi_z == 1)
		num = va_arg(*((va_list *)params), size_t);
	else
		num = va_arg(*((va_list *)params), unsigned int);
	if (list->dize && num)
		return (write(1, "0x", 2) + i + ft_printf_base(num, 16, 0, 1));
	i = ft_write_space(list->modifi_atoi - ((list->prec > ft_len_base(num, 16)) ?
				list->prec : ft_len_base(num, 16)), list);
	list->chr = 1;
	tmp = list->prec;
	list->prec = 0;
	if (!(num || list->modifi_atoi || tmp || list->p) && list->prec_i)
		return (i);
	return (ft_write_space(tmp - ft_len_base(num , 16), list) + i + ft_printf_base(num, 16, 0, 1));
}

int		ft_print_op_x_great(t_list_p *list, void *params)
{
	int						i;
	unsigned long long int	num;
	int						tmp;

	i = 0;
	if (list->modifi_l == 1)
		num = va_arg(*((va_list *)params), unsigned long int);
	else if (list->modifi_l == 2)
		num = va_arg(*((va_list *)params), unsigned long long int);
	else if (list->modifi_h == 2)
		num = (unsigned char)va_arg(*((va_list *)params), int);
	else if (list->modifi_j == 1)
		num  = va_arg(*((va_list *)params), long);
	else if (list->modifi_z == 1)
		num = va_arg(*((va_list *)params), size_t);
	else
		num = va_arg(*((va_list *)params), unsigned int);
	if (list->dize && num)
		return (write(1, "0X", 2) + i + ft_printf_base(num, 16, 0, 0));
	i = ft_write_space(list->modifi_atoi - ((list->prec > ft_len_base(num, 16)) ?
				list->prec : ft_len_base(num, 16)), list);
	list->chr = 1;
	tmp = list->prec;
	list->prec = 0;
	if (!(num || list->modifi_atoi || tmp || list->p) && list->prec_i)
		return (i);
	return (ft_write_space(tmp - ft_len_base(num , 16), list) + i + ft_printf_base(num, 16, 0, 0));
}
