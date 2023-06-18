/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_xl.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:22:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/13 03:10:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include "format.h"
#include "utils.h"
#include <stddef.h>

static size_t	ft_ultohlen(unsigned long n)
{
	size_t	len;

	if (!n)
		return (1);
	len = 0;
	while (n)
		n >>= 4 + 0 * len++;
	return (len);
}

static size_t	_put_hex(unsigned long n, int large, size_t digit)
{
	char	buf[16];
	size_t	i;
	UINT	m;

	i = digit;
	while (1)
	{
		m = n & 0xFUL;
		buf[--i] = '0' + m + (10 <= m) * (0x7 + !large * 0x20);
		n >>= 4;
		if (!n)
			break ;
	}
	return (buf_write_stdout(buf, digit));
}

static size_t	_put_type_xl(unsigned long n, int flag, int width,
		int precision)
{
	size_t	ret;
	size_t	len;

	ret = 0;
	len = ft_ultohlen(n);
	if (precision != PRECISION_DEFAULT)
	{
		if ((int)len < precision || !n)
			len = precision;
		else
			flag &= ~FLAG_ZERO;
	}
	ret += _put_width(flag, width, len, 0);
	if (precision && precision != PRECISION_DEFAULT)
		ret += _put_type_xl(n, (flag & ~FLAG_MINUS) | FLAG_ZERO, precision, PRECISION_DEFAULT);
	else if (len)
		ret += _put_hex(n, !!(flag & X_LARGE), len);
	ret += _put_width(flag, width, len, 1);
	return (ret);
}

size_t	put_type_xl(unsigned long n, int flag, int width, int precision)
{
	int		isprefix;
	int		_width;
	size_t	ret;
	size_t	len;

	ret = 0;
	isprefix = (!!(flag & (FLAG_HASH | X_IS_P)));
	if (width != WIDTH_DEFAULT)
		width -= 2 * isprefix;
	len = ft_ultohlen(n);
	_width = WIDTH_DEFAULT;
	if (!(flag & FLAG_ZERO))
		ret += _put_width(flag, width, len, 0);
	else
		_width = width;
	if (precision && (n || flag & X_IS_P) && isprefix)
		ret += buf_write_stdout(&"0x0X"[2 * !!(flag & X_LARGE)], 2);
	ret += _put_type_xl(n, flag, _width, precision);
	ret += _put_width(flag, width, len, 1);
	return (ret);
}
