/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 05:22:46 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/12 23:59:58 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
typedef struct				t_list_params
{
	char					prec_i;
	char					prec;
	char					space;
	char					d;
	char					p;
	char					modifi_atoi;
	char					modifi_l;
	char					modifi_L;
	char					modifi_h;
	char					modifi_j;
	char					modifi_z;
	char					chr;
	char					dize;
}							t_list_p;

typedef int					(tab_f)(t_list_p *, void *);
int							ft_printf(const char *format, ...)
							__attribute__ ((format (printf, 1, 2)));
int							ft_printf_poucent(t_list_p *list, void *params);
/*ft_printf_op_s.c*/
int							ft_putstr_ret_len(t_list_p *list, void *params);
int							ft_print_chr(t_list_p *list, void *params);
/*end ft_printf_op_s.c*/

/*ft_conv_base*/
int							ft_print_op_o(t_list_p *list, void *params);
int							ft_print_op_o_great(t_list_p *list, void *params);
int							ft_print_op_x(t_list_p *list, void *params);
int							ft_print_op_x_great(t_list_p *list, void *params);
/*end ft_conv_base*/
int							ft_printf_op_s_unicode(t_list_p *list,
							void *params);
int							ft_printf_op_c_unicode(t_list_p *list,
							void *params);
int							ft_printf_p(t_list_p *list, void *params);
int							ft_print_num_d(t_list_p *list, void *params);
int							ft_print_num_d_height_long(t_list_p *list,
							void *params);
int							ft_print_num_d_height_u_long(t_list_p *list,
							void *params);
int							ft_print_num_d_height_u_int(t_list_p *list,
							void *params);
t_list_p					*ft_fill_list(char **str, t_list_p *list);

/*ft_printf_op_c_unicode*/
int							ft_printf_base(unsigned long long int num, int base,
							unsigned int i, char opt);
int							ft_put_op_c_unicode(unsigned int c);
int							ft_printf_op_c_unicode(t_list_p *list, void *params);
int							ft_strlen_unicode(unsigned int *c);
/*end ft_printf_op_c_unicode*/
/*ft_bit_wise*/
int							size_bin(unsigned int chr);
int							four_oct(unsigned int a);
int							three_oct(unsigned int a);
int							two_oct(unsigned int a);
/*end ft_bit_wise*/
void						ft_error();
/*ft_len_func*/
int							ft_putnbr_ulong_len(unsigned long long int num);
int							ft_write_space(long long int num, t_list_p *list);
int							ft_len_base(unsigned long long int num, int base);
/*end ft_len_func*/

void						ft_zebi(long long int num, t_list_p *list);
void						ft_zebi_nega(long long int num, t_list_p *list);
int							ft_check_for_ft_print_op_x(unsigned long long int num,
							int tmp, t_list_p *list);
int							ft_print_op_o_nega(unsigned long long int num,
							t_list_p *list);
unsigned long long int		ft_foret_de_if_2_ft_print_num_d(t_list_p *list,
							void *params);
int							ft_foret_de_if_2_ft_print_num_d_nega(unsigned long
							long int num, t_list_p *list);
int							ft_putnbr_ulong(unsigned long long int num,
							t_list_p *list);
#endif
