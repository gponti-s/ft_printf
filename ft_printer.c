/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <gponti-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:02:08 by gponti-s          #+#    #+#             */
/*   Updated: 2022/03/07 16:42:55 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printer_str(t_flags **print, t_flags **flags, int i)
{
	while ((*print)->str > 0)
	{
		ft_putchar_fd((*flags)->str_to_print[i], 1);
		(*flags)->resp++;
		i++;
		(*print)->str--;
	}
}

void	ft_printer_zero(t_flags **print, t_flags **flags)
{
	while ((*print)->zero > 0)
	{
		ft_putchar_fd('0', 1);
		(*flags)->resp++;
		(*print)->zero--;
	}
}

void	ft_printer_width(t_flags **flags)
{
	while ((*flags)->width > 0)
	{
		if ((*flags)->zero > 0)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		(*flags)->resp++;
		(*flags)->width--;
	}
}

int	ft_printer_signal(t_flags **print, t_flags **flags, int i)
{
	ft_putchar_fd((*flags)->str_to_print[i], 1);
	(*flags)->resp++;
	(*print)->str--;
	i++;
	return (i);
}

void	ft_printer_space(t_flags **print, t_flags **flags)
{
	while ((*print)->space > 0)
	{
		ft_putchar_fd(' ', 1);
		(*flags)->resp++;
		(*print)->space--;
	}
}
