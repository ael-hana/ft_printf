/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 05:22:46 by ael-hana          #+#    #+#             */
/*   Updated: 2015/12/18 11:52:09 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
typedef struct			t_list_params
{
	char				*flags;
	char				*champ;
	char				*prec;
	char				*modifi;
}						t_list_p;
typedef unsigned int	(tab_f)(t_list_p *, void *);
int						ft_printf(const char *format, ...)
						__attribute__ ((format (printf, 1, 2)));
unsigned int			ft_putstr_ret_len(t_list_p *list, void *params);
void					ft_printf_op_c_unicode(void *dest);
unsigned int			ft_printf_p(t_list_p *list, void *params);
unsigned int			ft_print_num_d(t_list_p *list, void *params);
void					*ft_putstr_stop(char *str, char chr);
#endif
