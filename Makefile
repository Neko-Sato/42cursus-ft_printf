# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:49:22 by hshimizu          #+#    #+#              #
#    Updated: 2023/06/07 22:12:10 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a
DIR				= .
INCLUDES_DIR	= $(DIR)/includes
SRCS_DIR		= $(DIR)/srcs
UTILS_DIR		= $(DIR)/utils

SRCS			= \
	ft_printf.c \
	buf.c \
	put_specifier.c \
	pars_specifier.c \
	put_specifier_c.c \
	put_specifier_p.c \
	put_specifier_s.c \
	put_specifier_x.c \
	put_specifier_d.c \
	put_specifier_u.c \
	put_specifier_percent.c \
	put_specifier_xl.c \

UTILS			= \
	ft_abs.c \
	ft_strchr.c \
	ft_strlen.c \

OBJECTS			= \
	$(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o)) \
	$(addprefix $(UTILS_DIR)/, $(UTILS:.c=.o)) \

.PHONY: all clean fclean re

$(NAME): $(OBJECTS)
	$(AR) rc $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) -I $(INCLUDES_DIR) $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all