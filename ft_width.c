/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:29:23 by gponti-s          #+#    #+#             */
/*   Updated: 2021/06/03 16:29:31 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_width_aux(char *str, int i, t_flags *flags);

void	ft_width(va_list ap, char *str, int i, t_flags *flags)
{
	if (str[i] == '-')
	{
		flags->minus = 1;
		flags->zero = 0;
		i++;
		flags->i++;
	}
	if (str[i] == '*')
	{
		flags->width = va_arg(ap, int);
		flags->i++;
		if (flags->width < 0)
		{			
			flags->width = flags->width * -1;
			flags->minus = 1;
			flags->zero = 0;
		}
	}
	else if (str[i] >= '1' && str[i] <= '9')
		ft_width_aux(str, i, flags);
}

static void	ft_width_aux(char *str, int i, t_flags *flags)
{
	char	temp[20];
	int		x;
	int		resp;

	x = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp[x] = str[i];
		i++;
		x++;
		flags->i++;
	}
	resp = ft_atoi(temp);
	flags->width = resp;
}
