/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 02:25:33 by ael-hana          #+#    #+#             */
/*   Updated: 2015/12/18 08:41:04 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_putnbr_ul_base16(unsigned long num)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = "0123456789abcdef";
	if (num / 16)
		i = ft_putnbr_ul_base16(num / 16);
	write(1, &str[num % 16], 1);
	return (i + 1);
}

int					ft_printf_p(t_list_p *list, void *params)
{
	int				i;

	i = 2;
	(void)list;
	ft_putstr("0x");
	i += ft_putnbr_ul_base16((unsigned long)va_arg(*(va_list *)params, void *));
	return (i);
}
