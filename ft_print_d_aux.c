/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <gponti-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:06:46 by gponti-s          #+#    #+#             */
/*   Updated: 2022/03/07 16:40:37 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aux_print_d(t_flags **print, t_flags **flags)
{
	if ((*flags)->conversion == 'p')
	{
		if (*(*flags)->str_to_print != '0')
			(*flags)->width = (*flags)->width - 2;
		else
			(*flags)->width = (*flags)->width - 2;
	}
	if ((*flags)->precision > (*print)->len)
		(*flags)->width = (*flags)->width - (*flags)->precision;
	else
		(*flags)->width = (*flags)->width - (*print)->len;
}

void	ft_aux2_print_d(t_flags **print, t_flags **flags)
{
	if ((*flags)->precision > (*print)->len)
	{
		(*print)->zero = (*flags)->precision - (*print)->len;
		(*print)->str = (*print)->len;
	}
	else
		(*print)->str = (*print)->len;
	if ((*flags)->precision > 0 || ((*flags)->width > (*flags)->precision
			&& (*flags)->precision == -1))
	{
		(*flags)->zero = 0;
	}
	else if ((*flags)->precision < 0
		&& ((*flags)->str_to_print[0] == '0' && (*print)->len == 1))
	{
		(*print)->str = 0;
		(*flags)->zero = 0;
		(*flags)->width++;
	}
}
