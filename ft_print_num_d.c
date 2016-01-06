/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 04:51:48 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/06 03:32:46 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_putnbr_ulong(unsigned long long int num)
{
	unsigned int	i;

	i = 0;
	if (num / 10)
		i = ft_putnbr_ulong(num / 10);
	ft_putchar((num % 10) + '0');
	return (i + 1);
}

int					ft_print_num_d(t_list_p *list, void *params)
{
	long long int	num;
	int				i;

	if (list && list->modifi_l == 1)
		num = va_arg(*((va_list *)params), long int);
	else if (list && list->modifi_l == 2)
		num = va_arg(*((va_list *)params), long long int);
	else if (list && list->modifi_h == 2)
		num = (char)va_arg(*((va_list *)params), int);
	else if (list && list->modifi_j == 1)
		num = va_arg(*((va_list *)params),long int);
	else if (list && list->modifi_z == 1)
		num = va_arg(*((va_list *)params), size_t);
	else
		num = va_arg(*((va_list *)params), int);
	if (num < 0)
	{
		list->chr ? ft_putchar('-') : 0;
		i = ft_write_space(list->modifi_atoi - (ft_putnbr_ulong_len(num * -1) + 1), list);
		list->chr ? 0 : ft_putchar('-');
		return (ft_putnbr_ulong(num * -1) + 1 + i);
	}
	i = ft_write_space(list->modifi_atoi - ft_putnbr_ulong_len(num), list);
	return (((int)ft_putnbr_ulong(num) + i) +
			ft_write_space((list->modifi_atoi * -1) - ft_putnbr_ulong_len(num), list));
}

int					ft_print_num_d_height_u_int(t_list_p *list, void *params)
{
	long			num;

	if (list && list->modifi_l == 1)
		num = va_arg(*((va_list *)params), unsigned long int);
	else if (list && list->modifi_l == 2)
		num = va_arg(*((va_list *)params), unsigned long long int);
	else if (list && list->modifi_h == 2)
		num = (unsigned char)va_arg(*((va_list *)params), int);
	else if (list && list->modifi_j == 1)
		num = (unsigned long)va_arg(*((va_list *)params), long);
	else if (list && list->modifi_z == 1)
		num = va_arg(*((va_list *)params), size_t);
	else
		num = va_arg(*((va_list *)params), unsigned int);
	return (ft_putnbr_ulong(num));
}

int					ft_print_num_d_height_u_long(t_list_p *list, void *params)
{
	unsigned long		num;

	(void)list;
	num = va_arg(*((va_list *)params), unsigned long);
	return (ft_putnbr_ulong(num));
}

int					ft_print_num_d_height_long(t_list_p *list, void *params)
{
	long int		num;

	(void)list;
	num = va_arg(*((va_list *)params), long int);
	if (num < 0)
	{
		ft_putchar('-');
		return (ft_putnbr_ulong(num * -1) + 1);
	}
	return (ft_putnbr_ulong(num));
}
