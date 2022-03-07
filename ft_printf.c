/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <gponti-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:38:38 by gponti-s          #+#    #+#             */
/*   Updated: 2022/03/07 16:44:11 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Syntax %[parameter][flags][width][.precision][length]type

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags	flags;

	va_start(ap, format);
	ft_init_struct(&flags);
	while (format[flags.i])
	{
		if (format[flags.i] == '%' && format[flags.i + 1] != '\0')
			ft_printf_aux(ap, format, &flags);
		if (format[flags.i] != '%' && format[flags.i])
		{
			ft_putchar_fd(format[flags.i], 1);
			flags.resp++;
			flags.i++;
		}
	}
	va_end(ap);
	return (flags.resp);
}

static void	ft_pre_printer(t_flags *flags)
{
	t_flags	print;

	ft_init_struct(&print);
	if (flags->str_to_print != NULL)
		print.len = ft_strlen(flags->str_to_print);
	if (flags->conversion == 'c' || flags->conversion == '%')
		ft_pre_printer_c_s(&print, &flags);
	if (flags->conversion == 's')
		ft_pre_printer_c_s(&print, &flags);
	if (flags->conversion == 'd' || flags->conversion == 'u'
		|| flags->conversion == 'i')
		ft_pre_printer_d(&print, &flags);
	if (flags->conversion == 'x' || flags->conversion == 'X'
		|| flags->conversion == 'p')
		ft_pre_printer_d(&print, &flags);
}

static void	ft_printf_aux(va_list ap, const char *format, t_flags *flags)
{
	flags->i++;
	ft_reinit_struct(flags);
	if (format[flags->i] == '-')
		ft_minus(flags);
	if (format[flags->i] == '0')
		ft_zero(flags);
	if (format[flags->i] == '*' || ((format[flags->i] >= '1'
				&& format[flags->i] <= '9') || format[flags->i] == '-'))
		ft_width(ap, (char *)format, flags->i, flags);
	if (format[flags->i] == '.')
		ft_precision(ap, (char *)format, flags->i, flags);
	if (ft_strrchr("cspdiuxX%", format[flags->i]))
		ft_conversion(ap, (char *)format, flags->i, flags);
	ft_pre_printer(flags);
}
