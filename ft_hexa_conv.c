/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <gponti-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:04:17 by gponti-s          #+#    #+#             */
/*   Updated: 2022/03/07 16:50:13 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_reverse(char *ptr)
{
	char	resp[20];
	int		i;
	int		x;

	x = ft_strlen(ptr);
	i = 0;
	while (ptr[i])
	{
		resp[i] = ptr[(x - 1) - i];
		i++;
	}
	resp[x] = '\0';
	return (ft_strdup(resp));
}

char	*ft_hexc(unsigned int num, char conv, t_flags **flags)
{
	char	*ptr1;
	char	*res;

	if (num == 0)
	{
		ft_malloc_zero(flags);
		return ((*flags)->str_to_print);
	}
	res = ft_hexa_aux_c(num, conv, flags);
	ptr1 = ft_reverse((char *)res);
	free (res);
	return (ptr1);
}

char	*ft_hexp(unsigned long long num, char conv, t_flags **flags)
{
	char	*ptr1;
	char	*res;

	if (num == 0)
	{
		ft_malloc_zero(flags);
		return ((*flags)->str_to_print);
	}
	res = ft_hexa_aux_p(num, conv, flags);
	ptr1 = ft_reverse((char *)res);
	free (res);
	return (ptr1);
}

void	ft_malloc_zero(t_flags **flags)
{
	(*flags)->str_to_print = malloc(2);
	(*flags)->str_to_print[0] = '0';
	(*flags)->str_to_print[1] = '\0';
}
