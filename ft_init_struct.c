/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:21:29 by gponti-s          #+#    #+#             */
/*   Updated: 2021/05/31 12:21:31 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->i = 0;
	flags->j = 0;
	flags->x = 0;
	flags->len = 0;
	flags->space = 0;
	flags->resp = 0;
	flags->str = 0;
	flags->conversion = '\0';
	flags->has_malloc = 0;
	flags->str_to_print = NULL;
}

void	ft_reinit_struct(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->len = 0;
	flags->space = 0;
	flags->str = 0;
	flags->j = 0;
	flags->x = 0;
	flags->conversion = '\0';
	flags->str_to_print = NULL;
}
