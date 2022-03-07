/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <gponti-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 09:59:56 by gponti-s          #+#    #+#             */
/*   Updated: 2022/03/07 16:41:42 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pre_printer_d(t_flags *print, t_flags **flags)
{
	if ((*flags)->str_to_print[0] == '-' && (*flags)->precision > 0)
		(*flags)->precision++;
	if ((*flags)->width > (*flags)->precision)
		ft_aux_print_d(&print, &flags);
	else
		(*flags)->width = 0;
	ft_aux2_print_d(&print, &flags);
	if ((*flags)->precision == -1 && ((*flags)->width > (*flags)->precision)
		&& ((*flags)->str_to_print[0] == '0' && print->len == 1))
	{
		print->str = 0;
		(*flags)->zero = 0;
		if ((*flags)->width != 0)
			(*flags)->width++;
	}
	if ((*flags)->minus == 1)
		ft_print_number_minus(&print, &flags);
	else
		ft_print_number(&print, &flags);
}

static void	ft_print_number_minus(t_flags **print, t_flags **flags)
{
	int	i;

	i = 0;
	if ((*flags)->str_to_print[i] == '-' && (*print)->zero > 0)
		i = ft_printer_signal(&print, &flags, i);
	ft_printer_zero(&print, &flags);
	if ((*flags)->conversion == 'p')
		ft_printer_p(&flags);
	ft_printer_str(&print, &flags, i);
	ft_printer_width(&flags);
	free((*flags)->str_to_print);
}

static void	ft_print_number(t_flags **print, t_flags **flags)
{
	int	i;

	i = 0;
	if ((*flags)->str_to_print[i] == '-' && (*flags)->zero > 0)
		i = ft_printer_signal(&print, &flags, i);
	ft_printer_width(&flags);
	if ((*flags)->str_to_print[i] == '-' && (*print)->zero > 0)
		i = ft_printer_signal(&print, &flags, i);
	ft_printer_zero(&print, &flags);
	if ((*flags)->conversion == 'p')
		ft_printer_p(&flags);
	ft_printer_str(&print, &flags, i);
	free((*flags)->str_to_print);
}

static void	ft_printer_p(t_flags **flags)
{
	ft_putstr_fd("0x", 1);
	(*flags)->resp = (*flags)->resp + 2;
}
