# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 12:49:50 by gponti-s          #+#    #+#              #
#    Updated: 2021/02/12 12:49:55 by gponti-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
NAME        = libftprintf.a
INCLUDE     = ft_printf.h

LIBFT 		= ./libft/libft.a

SRCS        = ft_hexa_conv.c \
			ft_init_struct.c \
			ft_minus_zero.c \
			ft_print_c_s.c \
			ft_print_d_aux.c \
			ft_printf.c \
			ft_strdup_print.c \
			ft_conversion.c \
			ft_hexa_conv_aux.c \
			ft_itoa_uint.c \
			ft_precision.c \
			ft_print_d.c \
			ft_printer.c \
			ft_width.c
				
OBJS        = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):    $(OBJS)
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			ar -rcs $(NAME) $(OBJS)

.c.o:
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)
			$(MAKE) clean -C ./libft

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) fclean -C ./libft

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus