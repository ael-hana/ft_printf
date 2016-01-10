/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_op_s_unicode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 01:23:45 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/10 07:13:59 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf_op_s_unicode(t_list_p *list, void *params)
{
	unsigned int	*str;
	int				i;
	int				tmp;
	(void)list;

	str = (unsigned int *)va_arg(*(va_list *)params, unsigned int *);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	if (list->modifi_atoi > 0)
		i = ft_write_space(list->modifi_atoi - ft_strlen_unicode(str), list);
	tmp = 0;
	while (*str && ((list->prec > tmp) || (!list->prec)))
	{
		tmp += size_bin(*str);
		if (tmp < list->prec || !list->prec)
			i += ft_put_op_c_unicode(*(str++));
	}
	i += ft_write_space((list->modifi_atoi * -1) - i, list);
	return (i);
}
