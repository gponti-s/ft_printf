/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:23:58 by gponti-s          #+#    #+#             */
/*   Updated: 2021/06/04 17:24:00 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_aux(char **str, int i, t_flags **flags);
static void	ft_aux2(t_flags **flags);

void	ft_precision(va_list ap, char *str, int i, t_flags *flags)
{
	i++;
	flags->i++;
	if (str[i] == '0')
	{
		while (str[i] == '0')
		{
			flags->precision = -1;
			flags->i++;
			i++;
		}
		if (str[i] >= '1' && str[i] <= '9')
			ft_aux(&str, i, &flags);
	}
	else if (str[i] == '*')
	{
		flags->precision = va_arg(ap, int);
		flags->i++;
		ft_aux2(&flags);
	}
	else if (str[i] >= '1' && str[i] <= '9')
		ft_aux(&str, i, &flags);
	else
		flags->precision = -2;
}

static void	ft_aux(char **str, int i, t_flags **flags)
{
	char	temp[20];
	int		resp;

	while ((*str)[i] >= '0' && (*str)[i] <= '9')
	{
		temp[(*flags)->x] = (*str)[i];
		i++;
		(*flags)->x++;
		(*flags)->i++;
	}
	temp[(*flags)->x] = '\0';
	resp = ft_atoi(temp);
	(*flags)->precision = resp;
}

static void	ft_aux2(t_flags **flags)
{
	if ((*flags)->precision < 0)
		(*flags)->precision = 0;
	else if ((*flags)->precision == 0)
		(*flags)->precision = -3;
}
