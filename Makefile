# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 19:05:06 by hshimizu          #+#    #+#              #
#    Updated: 2025/09/08 03:37:05 by hshimizu         ###   ########.fr        #
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
	ft__printf_varg_0.c \
	ft__printf_varg_1.c \
	ft__printf_varg_0_ref.c \
	ft__printf_varg_1_ref.c \
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

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -std=c99 -pedantic
CFLAGS			+= -fno-builtin -fno-common
CFLAGS			+= -fPIC -MMD -MP
AR				:= ar
ARFLAGS			:= rcs
IDFLAGS			:= -I.
LDFLAGS			:= 
LIBS			:=
LIBS_DEV		:=

ifneq ($(LIBFT_PATH),)
IDFLAGS			+= -I$(LIBFT_PATH)
LDFLAGS			+= -L$(LIBFT_PATH)
LIBS			+= -Wl,-rpath,$(LIBFT_PATH)
LIBS_DEV		+= -Wl,-rpath,$(LIBFT_PATH)
endif

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
$(NAME_A): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(NAME_SO): CFLAGS += $(CFLAGS_OPT)
$(NAME_SO): $(OBJS)
ifeq ($(UNAME_S),Linux)
	$(CC) $(CFLAGS) $(LDFLAGS) -shared -o $@ $^ $(LIBS)
else ifeq ($(UNAME_S),Darwin)
	$(CC) $(CFLAGS) $(LDFLAGS) -dynamiclib -o $@ $^ $(LIBS) -install_name @rpath/$@
endif

$(OUTDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IDFLAGS) -c $< -o $@

$(NAME_DEV_A): CFLAGS += $(CFLAGS_DEV)
$(NAME_DEV_A): $(OBJS_DEV)
	$(AR) $(ARFLAGS) $@ $^

$(NAME_DEV_SO): CFLAGS += $(CFLAGS_DEV)
$(NAME_DEV_SO): $(OBJS_DEV)
ifeq ($(UNAME_S),Linux)
	$(CC) $(CFLAGS) $(LDFLAGS) -shared -o $@ $^ $(LIBS_DEV)
else ifeq ($(UNAME_S),Darwin)
	$(CC) $(CFLAGS) $(LDFLAGS) -dynamiclib -o $@ $^ $(LIBS_DEV) -install_name @rpath/$@
endif

$(OUTDIR)/%_dev.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IDFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OUTDIR)

fclean: clean
	$(RM) $(NAME_A) $(NAME_SO) $(NAME_DEV_A) $(NAME_DEV_SO)

re:
	@$(MAKE) fclean
	@$(MAKE)

test: test.c $(NAME_DEV_A)
	$(CC) $(CFLAGS_DEV) -o $@ $^ $(IDFLAGS)

-include $(DEPS) $(DEPS_DEV)
