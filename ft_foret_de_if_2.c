/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foret_de_if_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 20:06:35 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/12 20:44:22 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int		ft_foret_de_if_2_ft_print_num_d(t_list_p *list,
							void *params)
{
	unsigned long long int	num;

	if (list && list->modifi_l == 1)
		num = va_arg(*((va_list *)params), long int);
	else if (list && list->modifi_l == 2)
		num = va_arg(*((va_list *)params), long long int);
	else if (list && list->modifi_h == 1)
		num = (short)va_arg(*((va_list *)params), int);
	else if (list && list->modifi_h == 2)
		num = (char)va_arg(*((va_list *)params), int);
	else if (list && list->modifi_j == 1)
		num = va_arg(*((va_list *)params), long int);
	else if (list && list->modifi_z == 1)
		num = va_arg(*((va_list *)params), size_t);
	else
		num = va_arg(*((va_list *)params), int);
	return (num);
}

int							ft_foret_de_if_2_ft_print_num_d_nega(unsigned long
		long int num, t_list_p *list)
{
	int						i;
	int						tmp2;

	tmp2 = list->modifi_atoi;
	i = 0;
	num *= -1;
	ft_zebi_nega(num, list);
	i += list->chr ? write(1, "-", 1) : 0;
	if (list->modifi_atoi > 0)
		i += ft_write_space(list->modifi_atoi -
				(ft_putnbr_ulong_len(num) - list->p), list);
	i += list->chr ? ft_putnbr_ulong(num, list) : write(1, "-", 1) +
		ft_putnbr_ulong(num, list);
	return (i + ft_write_space((tmp2 + i) * -1, list));
}
