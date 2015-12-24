/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 05:22:35 by ael-hana          #+#    #+#             */
/*   Updated: 2015/12/24 07:27:22 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

tab_f			*oklm[] = {
					&ft_putstr_ret_len, //%s
					&ft_printf_op_s_unicode,//%S
					&ft_printf_p,//%p
					&ft_print_num_d,//%d
					&ft_print_num_d_height_long,//%D
					&ft_print_num_d,//%i
					&ft_print_op_o,//%o
					&ft_print_op_o_great,//%O
					&ft_print_num_d_height_u_int,//u
					&ft_print_num_d_height_u_long,//U
					&ft_print_op_x,//x
					&ft_print_op_x_great,//X
					&ft_print_chr,//c
					&ft_printf_op_c_unicode,//%C
					&ft_printf_poucent
							};

int			ft_printf_poucent(t_list_p *list, void *params)
{
	(void) list;
	(void) params;
	ft_putchar('%');
	return (1);
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
			while (*++format == ' ');
			list = ft_fill_list((char **)&format, list);
			if (-1 != (i = ft_chrstr_po(*format, params)))
				len += oklm[i](list, &ap);
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

	int str;

	str = 348;
	i = ft_printf("%d", str);
	ft_putstr("\n");
	ft_putnbr(i);
	ft_putstr("\n");
	ok = printf("%d", str);
	ft_putstr("\nle nombre :\n");
	ft_putnbr(ok);
	ft_putstr("\n");
	return (0);
}*/
