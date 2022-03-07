/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <gponti-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:45:41 by gponti-s          #+#    #+#             */
/*   Updated: 2022/03/07 16:55:43 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_flags
{
	int		zero;
	int		minus;
	int		width;
	int		precision;
	int		i;
	int		z;
	int		j;
	int		x;
	int		len;
	int		space;
	int		resp;
	int		str;
	char	conversion;
	char	*str_to_print;
	int		has_malloc;
}t_flags;

char		*ft_strdup_print(const char *s1);
void		ft_malloc_zero(t_flags **flags);
char		*ft_hexa_aux_p(unsigned long long num, char conv, t_flags **flags);
char		*ft_hexa_aux_c(unsigned int num, char conv, t_flags **flags);
void		ft_hexa_itoa(char *res, int z);
void		ft_pre_printer_c_s(t_flags *print, t_flags **flags);
void		ft_aux_print_d(t_flags **print, t_flags **flags);
void		ft_aux2_print_d(t_flags **print, t_flags **flags);
void		ft_pre_printer_d(t_flags *print, t_flags **flags);
void		ft_printer_str(t_flags **print, t_flags **flags, int i);
void		ft_printer_zero(t_flags **print, t_flags **flags);
void		ft_printer_width(t_flags **flags);
int			ft_printer_signal(t_flags **print, t_flags **flags, int i);
void		ft_printer_space(t_flags **print, t_flags **flags);
void		ft_minus(t_flags *flags);
void		ft_zero(t_flags *flags);
void		ft_precision(va_list ap, char *str, int i, t_flags *flags);
void		ft_width(va_list ap, char *str, int i, t_flags *flags);
char		*ft_itoa_uint(int nb);
char		*ft_hexc(unsigned int number, char conv, t_flags **flags);
char		*ft_hexp(unsigned long long num, char conv, t_flags **flags);
void		ft_conversion(va_list ap, char *str, int i, t_flags *flags);
void		ft_init_struct(t_flags *flags);
void		ft_reinit_struct(t_flags *flags);
int			ft_printf(const char *format, ...);

#endif