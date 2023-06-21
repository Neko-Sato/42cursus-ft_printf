# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:49:22 by hshimizu          #+#    #+#              #
#    Updated: 2023/06/21 17:56:11 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a
DIR				= .
INCS_DIR		= $(DIR)/includes
SRCS_DIR		= $(DIR)/srcs
UTILS_DIR		= $(DIR)/utils
OBJS_DIR		= $(DIR)/objs

SRCS			= \
	$(addprefix $(SRCS_DIR)/, \
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
	) \
	$(addprefix $(UTILS_DIR)/, \
		ft_abs.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_atou.c \
		ft_isdigit.c \
		ft_udigit.c \
	) \

OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

.PHONY: all clean fclean re test

$(NAME): $(OBJS)
	$(AR) rc $@ $^

bonus: $(NAME)

test: test.c $(NAME)
	$(CC) -g -I $(INCS_DIR) $^ -o $@

objs/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) -I $(INCS_DIR) $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all