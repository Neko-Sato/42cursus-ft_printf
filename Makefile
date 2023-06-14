# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:49:22 by hshimizu          #+#    #+#              #
#    Updated: 2023/06/14 22:10:14 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS			= -Wall -Wextra -Werror -g

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
	put_type_c.c \
	put_type_p.c \
	put_type_s.c \
	put_type_x.c \
	put_type_d.c \
	put_type_u.c \
	put_type_percent.c \
	put_type_xl.c \

UTILS			= \
	ft_abs.c \
	ft_strchr.c \
	ft_strlen.c \
	ft_atou.c \
	ft_isdigit.c \
	ft_udigit.c \

OBJECTS			= \
	$(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o)) \
	$(addprefix $(UTILS_DIR)/, $(UTILS:.c=.o)) \

.PHONY: all clean fclean re test

$(NAME): $(OBJECTS)
	$(AR) rc $@ $^

bonus: $(NAME)

test: test.c $(NAME)
	$(CC) -g -I $(INCLUDES_DIR) $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) -I $(INCLUDES_DIR) $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all