/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 05:22:35 by ael-hana          #+#    #+#             */
/*   Updated: 2015/12/21 20:25:49 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_printf_poucent(t_list_p *list, void *params)
{
	(void) list;
	(void) params;
	ft_putchar('%');
	return (1);
}

int		ft_chrstr_po(char chr, char *search)
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

void	ft_error()
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
	tab_f			*oklm[] = {&ft_putstr_ret_len, //%s
					&ft_printf_op_s_unicode,//%S
					&ft_printf_p,//%p
					&ft_print_num_d,//%d
					NULL,//%D
					NULL,//%i
					NULL,//%o
					NULL,//%O
					NULL,//u
					NULL,//U
					NULL,//x
					NULL,//X
					NULL,//c
					&ft_printf_op_c_unicode,//%C
					&ft_printf_poucent};
	va_start(ap, format);
	len = 0;
	while (*format)
	{
		while ((*format == '%'))
		{
			while (*++format == ' ');
			if (-1 != (i = ft_chrstr_po(*format, params)))
				len += oklm[i](list, /*va_arg(ap, void *)*/ &ap);
			if (*format && i != -1)
				format++;
		}
		if (*format)
		{
			ft_putchar(*format++);
			len++;
		}
	}
	va_end(ap);
	return ((int)len);
}
/*
int			main()
{
	int	i;
	int ok;

	char *str = NULL;
	i = ft_printf("{%S}", str);
	ft_putnbr(i);
	ft_putstr("\n");
	ok = printf("{%S}", str);
	ft_putstr("\n");
	ft_putnbr(ok);
	ft_putstr("\n");
	return (0);
}*/
