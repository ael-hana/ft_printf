/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 05:22:35 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/13 00:01:08 by ael-hana         ###   ########.fr       */
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

tab_f		**ft_init_tab_func(void)
{

	tab_f	**oklm;
	int		i;

	i = 0;
	if (!(oklm = malloc(sizeof(tab_f**) * 15)))
		ft_error();
	oklm[0] = &ft_putstr_ret_len;//%s
	oklm[1] = &ft_printf_op_s_unicode;
	oklm[2] = &ft_printf_p;//%p
	oklm[3] = &ft_print_num_d;//%d
	oklm[4] = &ft_print_num_d_height_long;//%D
	oklm[5] = &ft_print_num_d;//%i
	oklm[6] = &ft_print_op_o;//%o
	oklm[7] = &ft_print_op_o_great;//%O
	oklm[8] = &ft_print_num_d_height_u_int;//u
	oklm[9] = &ft_print_num_d_height_u_long;//U
	oklm[10] = &ft_print_op_x;//x
	oklm[11] = &ft_print_op_x_great; //X
	oklm[12] = &ft_print_chr;//X
	oklm[13] = &ft_printf_op_c_unicode;//C
	oklm[14] = &ft_printf_poucent;//C
	return (oklm);
}

int				ft_printf(const char *format, ...)
{
	int			i;
	t_list_p	*list = NULL;
	int			len;
	va_list		ap;
	tab_f		**oklm;
/*	tab_f			*oklm[15] = {
					&ft_putstr_ret_len,//%s
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
					};*/
	len = 0;
	oklm = ft_init_tab_func();
	va_start(ap, format);
	while (*format)
	{
		while ((*format == '%'))
		{
			list = ft_fill_list((char **)&format, list);
			if (-1 != (i = ft_chrstr_po(*format, "sSpdDioOuUxXcC%")))
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
