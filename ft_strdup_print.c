/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 09:29:32 by gponti-s          #+#    #+#             */
/*   Updated: 2021/06/22 09:29:35 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup_print(const char *s1)
{
	char	*ptr;
	char	null[7];
	int		i;

	ft_strlcpy(null, "(null)", 7);
	i = 0;
	if (s1 == NULL || s1 == 0)
	{
		ptr = malloc((7));
		while (i < 7)
		{
			ptr[i] = null[i];
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	else
	{
		ptr = malloc((ft_strlen(s1) * sizeof(char) + 1));
		if (ptr == NULL)
			return (NULL);
		return (ft_memcpy(ptr, s1, ft_strlen(s1) + 1));
	}
}
