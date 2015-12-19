/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 05:22:35 by ael-hana          #+#    #+#             */
/*   Updated: 2015/12/18 11:44:51 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int				ft_printf(const char *format, ...)
{
	int				i;
	t_list_p		*list = NULL;
	unsigned int	len;
	char			params[] = "sSpdDioOuUxXcC";
	va_list			ap;
	tab_f			*oklm[] = {&ft_putstr_ret_len,
					NULL,//%S
					&ft_printf_p,//%p
					&ft_print_num_d,//%d
					NULL};

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		i = -2;
		while ((*format == '%') && (0 <= (i = ft_chrstr_po(*++format, params))))
		{
			len += oklm[i](list, /*va_arg(ap, void *)*/ &ap);
			format++;
		}
		ft_putchar(*format++);
		len++;
	}
	va_end(ap);
	return ((int)len);
}

int			main()
{
	int	i;

	void	*ptr = "oklm";

	i = ft_printf("Bonjour to%%ut monde %p %s%d\n", ptr, ptr, 42);
	ft_putnbr(i);
	ft_putstr("\n");
	i =    printf("Bonjour to%%ut monde %p %s%d\n", ptr, ptr, 42);
	ft_putnbr(i);
	return (0);
}
