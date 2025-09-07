# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 19:05:06 by hshimizu          #+#    #+#              #
#    Updated: 2025/09/08 06:16:24 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S			:= $(shell uname -s)

NAME 			:= libftprintf
NAME_DEV 		:= $(NAME)_dev

NAME_A			:= $(NAME).a
NAME_DEV_A		:= $(NAME_DEV).a
ifeq ($(UNAME_S),Linux)
NAME_SO			:= $(NAME).so
NAME_DEV_SO		:= $(NAME_DEV).so
else ifeq ($(UNAME_S),Darwin)
NAME_SO			:= $(NAME).dylib
NAME_DEV_SO		:= $(NAME_DEV).dylib
else
$(error Unsupported OS: $(UNAME_S))
endif

SRCS			:= \
	ft__printf_imple.c \
	ft__printf_handlers_0.c \
	ft__printf_handlers_1.c \
	ft__printf_handlers_2.c \
	ft__printf_parse_specifier.c \
	ft_asprintf.c \
	ft_dprintf.c \
	ft_fprintf.c \
	ft_printf.c \
	ft_snprintf.c \
	ft_sprintf.c \
	ft_vasprintf.c \
	ft_vdprintf.c \
	ft_vfprintf.c \
	ft_vprintf.c \
	ft_vsnprintf.c \
	ft_vsprintf.c

OUTDIR			:= .out
OBJS			:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.o))
OBJS_DEV		:= $(addprefix $(OUTDIR)/, $(SRCS:.c=_dev.o))
DEPS			:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.d))
DEPS_DEV		:= $(addprefix $(OUTDIR)/, $(SRCS:.c=_dev.d))

LIBFT_A			:= libft/libft.a
LIBFT_DEV_A		:= libft/libft_dev.a

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -std=c99 -pedantic
CFLAGS			+= -fno-builtin -fno-common
CFLAGS			+= -fPIC -MMD -MP
AR				:= ar
ARFLAGS			:= rcs
IDFLAGS			:= -I. -I./libft
LDFLAGS			:= -L./libft
LIBS			:=
LIBS_DEV		:=

CFLAGS_OPT		:= -O3 -DNDEBUG
CFLAGS_DEV		:= -g -fsanitize=address
ifneq ($(shell $(CC) --version | grep -i clang),)
CFLAGS_DEV		+= -fstandalone-debug
endif

.PHONY: all clean fclean re bonus

all:
ifeq ($(UNAME_S),Linux)
	@$(MAKE) $(NAME_A) -j $(shell nproc)
else ifeq ($(UNAME_S),Darwin)
	@$(MAKE) $(NAME_A) -j $(shell sysctl -n hw.ncpu)
endif

bonus: all

$(NAME_A): CFLAGS += $(CFLAGS_OPT)
$(NAME_A): $(OBJS) | $(LIBFT_A)
	cp -f $(LIBFT_A) $@
	$(AR) $(ARFLAGS) $@ $^

$(NAME_SO): CFLAGS += $(CFLAGS_OPT)
$(NAME_SO): $(OBJS) $(LIBFT_A)
ifeq ($(UNAME_S),Linux)
	$(CC) $(CFLAGS) $(LDFLAGS) -shared -o $@ $^ $(LIBS)
else ifeq ($(UNAME_S),Darwin)
	$(CC) $(CFLAGS) $(LDFLAGS) -dynamiclib -o $@ $^ $(LIBS) -install_name @rpath/$@
endif

$(OUTDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IDFLAGS) -c $< -o $@

$(NAME_DEV_A): CFLAGS += $(CFLAGS_DEV)
$(NAME_DEV_A): $(OBJS_DEV) | $(LIBFT_DEV_A)
	cp -f $(LIBFT_DEV_A) $@
	$(AR) $(ARFLAGS) $@ $^

$(NAME_DEV_SO): CFLAGS += $(CFLAGS_DEV)
$(NAME_DEV_SO): $(OBJS_DEV) $(LIBFT_DEV_A)
ifeq ($(UNAME_S),Linux)
	$(CC) $(CFLAGS) $(LDFLAGS) -shared -o $@ $^ $(LIBS_DEV)
else ifeq ($(UNAME_S),Darwin)
	$(CC) $(CFLAGS) $(LDFLAGS) -dynamiclib -o $@ $^ $(LIBS_DEV) -install_name @rpath/$@
endif

$(OUTDIR)/%_dev.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IDFLAGS) -c $< -o $@

$(LIBFT_A):
	@$(MAKE) -C libft libft.a

$(LIBFT_DEV_A):
	@$(MAKE) -C libft libft_dev.a

clean:
	@$(MAKE) -C libft fclean
	$(RM) -r $(OUTDIR)

fclean: clean
	$(RM) $(NAME_A) $(NAME_SO) $(NAME_DEV_A) $(NAME_DEV_SO)

re:
	@$(MAKE) fclean
	@$(MAKE)

test: test.c $(NAME_DEV_A)
	$(CC) $(CFLAGS_DEV) -o $@ $^ $(IDFLAGS)

-include $(DEPS) $(DEPS_DEV)
