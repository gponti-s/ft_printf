/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_conv_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:54:58 by gponti-s          #+#    #+#             */
/*   Updated: 2021/07/06 09:55:00 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexa_aux_p(unsigned long long num, char conv, t_flags **flags)
{
	char	res[20];
	char	*ptr1;

	while (num > 0)
	{
		(*flags)->z = num % 16;
		num = num / 16;
		if ((*flags)->z >= 10 && (*flags)->z <= 15)
		{
			ptr1 = ft_itoa((*flags)->z);
			res[(*flags)->j] = ptr1[0];
			free(ptr1);
			if (conv == 'x' || conv == 'p')
				res[(*flags)->j] = (*flags)->z + 87;
			else if (conv == 'X')
				res[(*flags)->j] = (*flags)->z + 55;
		}
		else
			ft_hexa_itoa(&res[(*flags)->j], (*flags)->z);
		res[(*flags)->j++ + 1] = '\0';
	}
	return (ft_strdup(res));
}

char	*ft_hexa_aux_c(unsigned int num, char conv, t_flags **flags)
{
	char	res[20];
	char	*ptr1;

	while (num > 0)
	{
		(*flags)->z = num % 16;
		num = num / 16;
		if ((*flags)->z >= 10 && (*flags)->z <= 15)
		{
			ptr1 = ft_itoa((*flags)->z);
			res[(*flags)->j] = ptr1[0];
			free(ptr1);
			if (conv == 'x' || conv == 'p')
				res[(*flags)->j] = (*flags)->z + 87;
			else if (conv == 'X')
				res[(*flags)->j] = (*flags)->z + 55;
		}
		else
			ft_hexa_itoa(&res[(*flags)->j], (*flags)->z);
		res[(*flags)->j++ + 1] = '\0';
	}
	return (ft_strdup(res));
}

void	ft_hexa_itoa(char *res, int z)
{
	char	*ptr1;

	ptr1 = ft_itoa(z);
	*res = ptr1[0];
	free(ptr1);
}
