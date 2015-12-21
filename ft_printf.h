/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 05:22:46 by ael-hana          #+#    #+#             */
/*   Updated: 2015/12/21 19:56:06 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
typedef struct			t_list_params
{
	char				*flags;
	char				*champ;
	char				*prec;
	char				*modifi;
}						t_list_p;

typedef int				(tab_f)(t_list_p *, void *);
int						ft_printf(const char *format, ...)
						__attribute__ ((format (printf, 1, 2)));
int						ft_printf_poucent(t_list_p *list, void *params);
/*ft_printf_op_s.c*/
int						ft_putstr_ret_len(t_list_p *list, void *params);
/*end ft_printf_op_s.c*/

int						ft_printf_op_s_unicode(t_list_p *list, void *params);
int						ft_printf_op_c_unicode(t_list_p *list, void *params);
int						ft_printf_p(t_list_p *list, void *params);
int						ft_print_num_d(t_list_p *list, void *params);

/*ft_printf_op_c_unicode*/
void					*ft_putstr_stop(char *str, char chr);
int						ft_put_op_c_unicode(unsigned int c);
int						ft_printf_op_c_unicode(t_list_p *list, void *params);
/*end ft_printf_op_c_unicode*/
/*ft_bit_wise*/
int						size_bin(unsigned int chr);
int						four_oct(unsigned int a);
int						three_oct(unsigned int a);
int						two_oct(unsigned int a);
/*end ft_bit_wise*/
#endif
