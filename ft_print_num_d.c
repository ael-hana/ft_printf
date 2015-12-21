/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 04:51:48 by ael-hana          #+#    #+#             */
/*   Updated: 2015/12/21 20:47:14 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_putnbr_ulong(unsigned long int num)
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
	long int		num;

	(void)list;
	num = (long)va_arg(*((va_list *)params), int);
	if (num < 0)
	{
		ft_putchar('-');
		return (ft_putnbr_ulong(num * -1) + 1);
	}
	return ((int)ft_putnbr_ulong(num));
}

int					ft_print_num_d_height(t_list_p *list, void *params)
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
