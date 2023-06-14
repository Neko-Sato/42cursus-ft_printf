/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:26:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/14 22:05:52 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

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

# define FLAG_MINUS 0b00001
# define FLAG_ZERO 0b00010
# define FLAG_HASH 0b00100
# define FLAG_SPACE 0b01000
# define FLAG_PLUS 0b10000

typedef struct s_specifier
{
	int		flag;
	int		*width;
	int		__width;
	int		*precision;
	int		__precision;
	t_type	type;
}			t_specifier;

size_t		pars_specifier(t_specifier *specifier, const char *str);
size_t		put_specifier(t_specifier *specifier, va_list ap);

size_t		put_type_c(char c, int flag, int *width);
size_t		put_type_s(char *s, int flag, int *width, int *precision);
size_t		put_type_p(void *p);
size_t		put_type_d(int n);
size_t		put_type_u(unsigned int n);
size_t		put_type_x(unsigned int n, int large);
size_t		put_type_percent(void);
size_t		put_type_xl(unsigned long n, int large);

#endif
