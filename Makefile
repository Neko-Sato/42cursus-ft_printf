# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:49:22 by hshimizu          #+#    #+#              #
#    Updated: 2023/09/07 19:48:36 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

DIR				= .
FT				= $(DIR)/libft
INCS_DIR		= $(DIR)/includes
SRCS_DIR		= $(DIR)/srcs
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
	$(addprefix $(FT)/, \
		ft_strchr.c \
		ft_strlen.c \
		ft_atoi.c \
		ft_isdigit.c \
		ft_abs.c \
		ft_digit.c \
		ft_bzero.c \
	)

OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CFLAGS			= -Wall -Wextra -Werror
IDFLAGS			+= -I$(FT)
IDFLAGS			+= -I$(INCS_DIR)

.PHONY: all clean fclean re test norm

all: $(FT) $(NAME)

$(NAME): $(OBJS)
	$(AR) rc $@ $^

bonus: $(NAME)

objs/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(LDFLAGS) $(IDFLAGS) $< -o $@ $(LIBS)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: test.c $(name)
	@make
	$(CC) -g $(CFLAGS) -L./ -I./  $< -o $@ -lftprintf

norm: $(SRCS_DIR) $(INCS_DIR)
	@norminette $^

.PHONY: $(FT)
$(FT):
	@git submodule init $@
	@git submodule update $@
