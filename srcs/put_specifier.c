/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:34:56 by hshimizu          #+#    #+#             */
/*   Updated: 2023/08/19 23:25:55 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include "format.h"
#include <stdarg.h>
#include <stddef.h>

static t_value	get_value(t_type type, va_list ap);

size_t	put_specifier(t_specifier *s, va_list ap)
{
	size_t	ret;
	t_value	value;

	ret = 0;
	value = get_value(s->type, ap);
	if (s->type == type_c)
		ret += put_type_c(value.t_char, s->flag, s->width);
	else if (s->type == type_s)
		ret += put_type_s(value.t_str, s->flag, s->width, s->precision);
	else if (s->type == type_p)
		ret += put_type_p(value.t_ptr, s->flag, s->width, s->precision);
	else if (s->type == type_d)
		ret += put_type_d(value.t_int, s->flag, s->width, s->precision);
	else if (s->type == type_i)
		ret += put_type_d(value.t_int, s->flag, s->width, s->precision);
	else if (s->type == type_u)
		ret += put_type_u(value.t_uint, s->flag, s->width, s->precision);
	else if (s->type == type_x)
		ret += put_type_x(value.t_uint, s->flag, s->width, s->precision);
	else if (s->type == type_X)
		ret += put_type_x(value.t_uint, s->flag | X_LARGE, s->width,
				s->precision);
	else if (s->type == type_percent || s->type == type_none)
		ret += put_type_percent();
	return (ret);
}

static t_value	get_value(t_type type, va_list ap)
{
	t_value	value;

	if (type == type_c)
		value.t_char = (char)va_arg(ap, int);
	else if (type == type_s)
		value.t_str = va_arg(ap, char *);
	else if (type == type_p)
		value.t_ptr = va_arg(ap, void *);
	else if (type == type_d)
		value.t_int = va_arg(ap, int);
	else if (type == type_i)
		value.t_int = va_arg(ap, int);
	else if (type == type_u)
		value.t_uint = va_arg(ap, unsigned int);
	else if (type == type_x)
		value.t_uint = va_arg(ap, unsigned int);
	else if (type == type_X)
		value.t_uint = va_arg(ap, unsigned int);
	return (value);
}

size_t	_put_width(int flag, int width, int len, int after)
{
	int		i;
	size_t	ret;

	i = 0;
	ret = 0;
	if (width != WIDTH_DEFAULT && !((flag & FLAG_MINUS) ^ after))
		while (width - len > i)
			ret += buf_write_stdout(&" 0"[!!(flag & FLAG_ZERO) && !after], 1)
				+ 0 * i++;
	return (ret);
}

size_t	_put_uint(unsigned int n, size_t digit)
{
	char	buf[10];
	size_t	i;

	i = digit;
	while (1)
	{
		buf[--i] = '0' + n % 10;
		n /= 10;
		if (!n)
			break ;
	}
	return (buf_write_stdout(buf, digit));
}

size_t	_put_sign(int n, int flag)
{
	size_t	ret;
	int		sgin;

	ret = 0;
	if (n < 0)
		sgin = 0;
	else if (flag & FLAG_SPACE)
		sgin = 1;
	else if (flag & FLAG_PLUS)
		sgin = 2;
	else
		sgin = -1;
	if (0 <= sgin)
		ret += buf_write_stdout(&"- +"[sgin], 1);
	return (ret);
}
