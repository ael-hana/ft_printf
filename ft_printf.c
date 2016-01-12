/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 05:22:35 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/12 20:47:01 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int			ft_printf_poucent(t_list_p *list, void *params)
{
	int		i;
	int		tmp;

	(void) params;
	tmp = list->modifi_atoi;
	if ((!list->prec_i && !list->prec) || list->modifi_atoi)
	{
		i = ft_write_space(list->modifi_atoi - 1, list);
		i += write(1, "%", 1);
	}
	else
	{
		i = ft_write_space(list->modifi_atoi - 1, list);
		i += write(1, "%", 1);
	}
	i += ft_write_space(((tmp * -1) - i), list);
	return (i);
}

int			ft_chrstr_po(char chr, char *search)
{
	int	i;

	i = 0;
	while (search[i])
	{
		if (search[i] == chr)
			return (i);
		i++;
	}
	return (-1);
}

void		ft_error()
{
	exit (EXIT_FAILURE);
}

int				ft_printf(const char *format, ...)
{
	int				i;
	t_list_p		*list = NULL;
	int				len;
	char			params[] = "sSpdDioOuUxXcC%";
	va_list			ap;
	va_start(ap, format);
	len = 0;

	while (*format)
	{
		while ((*format == '%'))
		{
			list = ft_fill_list((char **)&format, list);
			if (-1 != (i = ft_chrstr_po(*format, params)))
				len += oklm[i](list, &ap) + (list->modifi_atoi = 0);
			else if (list->modifi_atoi > 0)
				len += ft_write_space(*format ? list->modifi_atoi - 1 : list->modifi_atoi, list);
			if (*format && i != -1)
				format++;
		}
		if (*format)
		{
			ft_putchar(*format++);
			if (list)
				len += ft_write_space(((list->modifi_atoi * -1) - 1), list);
			len++;
		}
	}
	va_end(ap);
	return ((int)len);
}
