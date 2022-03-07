/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:21:59 by gponti-s          #+#    #+#             */
/*   Updated: 2021/06/09 13:22:02 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus(t_flags *flags)
{
	flags->minus = 1;
	flags->i++;
}

void	ft_zero(t_flags *flags)
{
	flags->zero = 1;
	flags->i++;
}
