/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:17:20 by gponti-s          #+#    #+#             */
/*   Updated: 2021/05/31 12:17:24 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion(va_list ap, char *str, int i, t_flags *flags)
{
	flags->conversion = str[i];
	if (str[i] == '%')
	{
		flags->str_to_print = malloc(2);
		flags->str_to_print[0] = '%';
		flags->str_to_print[1] = '\0';
	}
	else if (str[i] == 'c')
	{
		flags->str_to_print = malloc(2);
		flags->str_to_print[0] = va_arg(ap, int);
		flags->str_to_print[1] = '\0';
	}
	else if (str[i] == 's')
		flags->str_to_print = ft_strdup_print(va_arg(ap, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		flags->str_to_print = ft_itoa(va_arg(ap, int));
	else if (str[i] == 'x' || str[i] == 'X')
		flags->str_to_print = ft_hexc(va_arg(ap, unsigned int), str[i], &flags);
	else if (str[i] == 'p')
		flags->str_to_print = ft_hexp(va_arg(ap, unsigned long long),
				str[i], &flags);
	else if (str[i] == 'u')
		flags->str_to_print = ft_itoa_uint(va_arg(ap, unsigned int));
	flags->i++;
}
