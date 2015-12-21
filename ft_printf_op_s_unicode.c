/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_op_s_unicode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 01:23:45 by ael-hana          #+#    #+#             */
/*   Updated: 2015/12/21 20:25:25 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf_op_s_unicode(t_list_p *list, void *params)
{
	unsigned int	*str;
	int				i;
	(void)list;

	str = (unsigned int *)va_arg(*(va_list *)params, unsigned int *);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (*str)
	{
		i += ft_put_op_c_unicode(*str);
		str++;
	}
	return (i);
}
