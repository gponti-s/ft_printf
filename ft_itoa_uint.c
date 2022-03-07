/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:47:32 by gponti-s          #+#    #+#             */
/*   Updated: 2021/06/03 13:47:34 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(unsigned int nb)
{
	int		len;

	if (nb == 0)
	{
		len = 1;
		return (len = 1);
	}
	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_uint(int nb)
{
	char			*str;
	size_t			i;

	i = len((unsigned int)nb);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	if ((unsigned int)nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	if ((unsigned int)nb < 0)
	{
		str[0] = '-';
		nb = (unsigned int)nb * -1;
	}
	while ((unsigned int)nb > 0)
	{
		str[i--] = 48 + ((unsigned int)nb % 10);
		nb = (unsigned int)nb / 10;
	}
	return (str);
}
