/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 04:33:33 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/07 04:12:35 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list_p		*ft_init_list(t_list_p *list)
{
	list->modifi_atoi = 0;
	list->modifi_l = 0;
	list->modifi_L = 0;
	list->modifi_h = 0;
	list->modifi_j = 0;
	list->modifi_z = 0;
	list->chr = 0;
	list->dize = 0;
	list->p = 0;
	list->space = 0;
	return (list);
}

t_list_p		*ft_fill_list(char **str, t_list_p *list)
{
	t_list_p	*ptr;

	if (list)
		free(list);
	if (!(ptr = (t_list_p *)malloc(sizeof(t_list_p))))
		ft_error();
	ptr = ft_init_list(ptr);
	while (*(++*str) == ' ' || **str == '#' || **str == '+')
	{
		ptr->dize += **str == '#' ? 1 : 0;
		ptr->p += **str == '+' ? 1 : 0;
		ptr->space += **str == ' ' ? 1 : 0;
	}
	if (ft_isdigit(**str) || (**str == '-' && ft_isdigit(*(*str + 1))))
	{
		while (**str == '0')
		{
			ptr->chr++;
			(*str)++;
		}
		ptr->modifi_atoi = ft_atoi(*str);
		*str += ptr->modifi_atoi < 0 ?
			(ft_putnbr_ulong_len(ptr->modifi_atoi * -1) + 1) :
			ft_putnbr_ulong_len(ptr->modifi_atoi);
	}
	while (**str == 'l')
	{
		ptr->modifi_l++;
		(*str)++;
	}
	while (**str == 'h')
	{
		ptr->modifi_h++;
		(*str)++;
	}
	while (**str == 'L')
	{
		ptr->modifi_L++;
		(*str)++;
	}
	while (**str == 'j')
	{
		ptr->modifi_j++;
		(*str)++;
	}
	while (**str == 'z')
	{
		ptr->modifi_z++;
		(*str)++;
	}
	return (ptr);
}
