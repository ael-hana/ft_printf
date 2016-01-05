/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 03:47:05 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/06 00:54:05 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_write_space(long long int num, t_list_p *list)
{
	int				i;

	i = 0;
	while (num > 0)
	{
		if (list->chr)
			write(1, "0",1);
		else
			write(1, " ",1);
		num--;
		i++;
	}
	return (i);
}

int					ft_putnbr_ulong_len(unsigned long long int num)
{
	unsigned int	i;

	i = 0;
	if (num / 10)
		i = ft_putnbr_ulong_len(num / 10);
	return (i + 1);
}
