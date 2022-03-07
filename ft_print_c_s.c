/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <gponti-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 10:14:44 by gponti-s          #+#    #+#             */
/*   Updated: 2022/03/07 16:56:27 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pre_printer_c_s(t_flags *print, t_flags **flags)
{
	int	i;

	i = 0;
	if ((*flags)->str_to_print[0] == '\0' && (*flags)->conversion == 'c')
	{
		print->str++;
		print->len = 1;
	}
	if (print->len <= 0)
		(*flags)->precision = 0;
	if ((*flags)->precision <= 0)
		ft_analyse_width_c_s(print, flags);
	else if ((*flags)->precision > print->len
		&& (*flags)->width < (*flags)->precision)
		(*flags)->precision = print->len;
	ft_aux_space(print, flags);
	if ((*flags)-> precision != -1)
		(*flags)->width = 0;
	if (print->str == 0)
		print->str = print->len;
	if ((*flags)->precision == -3)
		(*flags)->str_to_print = 0;
	ft_print_c_s(print, &flags);
}

void	ft_analyse_width_c_s(t_flags *print, t_flags **flags)
{
	if ((*flags)->precision < 0)
	{
		(print)->len = 0;
		(print)->str = -1;
	}
	while ((*flags)->width > (print)->len)
	{
		if ((*flags)->zero == 1)
		{
			if ((*flags)->minus == 1 && (*flags)->conversion == '%')
				(print)->space++;
			else
				(print)->zero++;
		}
		else
			(print)->space++;
		(*flags)->width--;
	}
}

void	ft_print_c_s(t_flags **print, t_flags **flags)
{
	int	i;

	i = 0;
	if ((*flags)->minus == 1)
	{
		ft_printer_str(print, flags, i);
		ft_printer_space(print, flags);
	}
	else
	{
		ft_printer_space(print, flags);
		ft_printer_zero(print, flags);
		ft_printer_str(print, flags, i);
	}
	free((*flags)->str_to_print);
}

static void	ft_aux_space(t_flags **print, t_flags **flags)
{
	int	i;

	i = 0;
	while ((*flags)->width > (*flags)->precision && (*flags)->precision > 0)
	{
		(*print)->space++;
		(*flags)->width--;
	}
	while ((*flags)->precision > (*print)->len)
	{
		(*print)->space++;
		(*flags)->precision--;
	}
	while ((*flags)->precision > 0 && (*flags)->str_to_print[i] != '\0')
	{
		(*print)->str++;
		(*flags)->precision--;
		i++;
	}
}
