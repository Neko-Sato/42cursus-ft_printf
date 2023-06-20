/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:34:56 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/20 18:03:43 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include "format.h"
#include "utils.h"
#include <stdarg.h>
#include <stddef.h>

static int	_put_specifier(size_t *ret, t_specifier *s, va_list ap);

size_t	put_specifier(const char **str, va_list ap)
{
	size_t		ret;
	t_specifier	specifier;
	size_t		specifier_len;

	ret = 0;
	specifier_len = pars_specifier(&specifier, *str);
	if (_put_specifier(&ret, &specifier, ap))
	{
		ret += put_type_percent();
		specifier_len = 1;
	}
	*str += specifier_len;
	return (ret);
}

static int	_put_specifier(size_t *ret, t_specifier *s, va_list ap)
{
	if (s->type == type_c)
		*ret = put_type_c((char)va_arg(ap, int), s->flag, s->width);
	else if (s->type == type_s)
		*ret = put_type_s(va_arg(ap, char *), s->flag, s->width, s->precision);
	else if (s->type == type_p)
		*ret = put_type_p(va_arg(ap, void *), s->flag, s->width, s->precision);
	else if (s->type == type_d)
		*ret = put_type_d(va_arg(ap, int), s->flag, s->width, s->precision);
	else if (s->type == type_i)
		*ret = put_type_d(va_arg(ap, int), s->flag, s->width, s->precision);
	else if (s->type == type_u)
		*ret = put_type_u(va_arg(ap, UINT), s->flag, s->width, s->precision);
	else if (s->type == type_x)
		*ret = put_type_x(va_arg(ap, UINT), s->flag, s->width, s->precision);
	else if (s->type == type_X)
		*ret = put_type_x(va_arg(ap, UINT), s->flag | X_LARGE, s->width,
				s->precision);
	else if (s->type == type_percent)
		*ret = put_type_percent();
	else
		return (1);
	return (0);
}

size_t	_put_width(int flag, int width, int len, int after)
{
	int		i;
	size_t	ret;

	i = 0;
	ret = 0;
	if (width != WIDTH_DEFAULT && !((flag & FLAG_MINUS) ^ after))
		while (width - len > i)
			ret += buf_write_stdout(&" 0"[!!(flag & FLAG_ZERO)], 1) + 0 * i++;
	return (ret);
}

size_t	_put_uint(UINT n, size_t digit)
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
