/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 04:33:33 by ael-hana          #+#    #+#             */
/*   Updated: 2015/12/24 07:27:21 by ael-hana         ###   ########.fr       */
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
	return (list);
}

t_list_p		*ft_fill_list(char **str, t_list_p *list)
{
	t_list_p	*ptr;

	if (list)
		free(list);
/*	if (!ft_strchr("sSpdDioOuUxXcC%", **str))
		return (NULL);*/
	if (!(ptr = (t_list_p *)malloc(sizeof(t_list_p))))
		ft_error();
	ptr = ft_init_list(ptr);
	if (ft_isdigit(**str))
	{
		ptr->modifi_atoi = ft_atoi(*str);
		*str += ft_putnbr_ulong_len(ptr->modifi_atoi);
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
