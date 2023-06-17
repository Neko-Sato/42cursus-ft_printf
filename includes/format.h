/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:26:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/17 16:08:02 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# include "utils.h"
# include <stdarg.h>
# include <stddef.h>

typedef enum e_type
{
	type_c = 'c',
	type_s = 's',
	type_p = 'p',
	type_d = 'd',
	type_i = 'i',
	type_u = 'u',
	type_x = 'x',
	type_X = 'X',
	type_percent = '%',
}			t_type;

# define FLAG_NONE (0)
# define FLAG_MINUS (1 << 0)
# define FLAG_ZERO (1 << 1)
# define FLAG_HASH (1 << 2)
# define FLAG_SPACE (1 << 3)
# define FLAG_PLUS (1 << 4)

# define WIDTH_DEFAULT (-1)
# define PRECISION_DEFAULT (-1)

typedef struct s_specifier
{
	int		flag;
	int		width;
	int		precision;
	t_type	type;
}			t_specifier;

size_t		pars_specifier(t_specifier *specifier, const char *str);
size_t		put_specifier(t_specifier *specifier, va_list ap);
size_t		_put_width(int flag, int width, int len, int after);
size_t		_put_uint(UINT n, size_t digit);
size_t		_put_sign(int n, int flag);

size_t		put_type_c(char c, int flag, int width);
size_t		put_type_s(char *s, int flag, int width, int precision);
size_t		put_type_p(void *p);
size_t		put_type_d(int n, int flag, int width, int precision);
size_t		put_type_u(UINT n, int flag, int width, int precision);
size_t		put_type_x(UINT n, int large, int flag, int width, int precision);
size_t		put_type_percent(void);
size_t		put_type_xl(unsigned long n, int large, int flag, int width,
				int precision);

#endif
