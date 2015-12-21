/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_op_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:40:28 by ael-hana          #+#    #+#             */
/*   Updated: 2015/12/21 15:56:59 by ael-hana         ###   ########.fr       */
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

int	ft_putstr_ret_len(t_list_p *list, void *params)
{
	void		*ptr;

	(void)list;
	if (!(ptr = va_arg(*(va_list *)params, char *)))
	{
		ft_putstr("(null)");
		return (6);
	}ft_putstr(ptr);
	return ((int)ft_strlen(ptr));
}
