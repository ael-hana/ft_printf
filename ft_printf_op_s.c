/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_op_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:40:28 by ael-hana          #+#    #+#             */
/*   Updated: 2015/12/18 10:16:40 by ael-hana         ###   ########.fr       */
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

unsigned int	ft_putstr_ret_len(t_list_p *list, void *params)
{
	void		*ptr;

	ft_putstr(ptr = va_arg(*(va_list *)params, char *));
	return (ft_strlen(ptr));
}
