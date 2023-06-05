# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:49:22 by hshimizu          #+#    #+#              #
#    Updated: 2023/06/05 17:54:33 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a
DIR				= ./
INCLUDES_DIR	= $(DIR)includes/
SRCS_DIR		= $(DIR)srcs/

SRCS			= \
	ft_printf.c \
	ft_vprintf.c \

OBJECTS			= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

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