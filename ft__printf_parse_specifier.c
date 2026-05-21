/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__printf_parse_specifier.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:47:50 by hshimizu          #+#    #+#             */
/*   Updated: 2026/05/21 12:11:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype/ft_ctype.h>
#include <ft_printf.h>
#include <ft_stdlib/ft_stdlib.h>
#include <ft_string/ft_string.h>
#include <limits.h>

static inline const char	*_parse_flags(const char *str, unsigned int *flags)
{
	static char const			marks[] = "-0# +";
	static unsigned int const	values[] = {
		_PRINTF_FLAG_MINUS,
		_PRINTF_FLAG_ZERO,
		_PRINTF_FLAG_HASH,
		_PRINTF_FLAG_SPACE,
		_PRINTF_FLAG_PLUS
	};
	const char					*tmp;

	*flags = 0;
	while (1)
	{
		tmp = ft_memchr(marks, *str, sizeof(marks) - 1);
		if (!tmp)
			break ;
		*flags |= values[tmp - marks];
		str++;
	}
	return (str);
}

static inline const char	*_parse_width(const char *str, int *width)
{
	long	tmp;

	if (!ft_isdigit(*str))
		tmp = -1;
	else
	{
		tmp = ft_strtol(str, (char **)&str, 10);
		if (INT_MAX < tmp)
			tmp = INT_MAX;
	}
	*width = tmp;
	return (str);
}

static inline const char	*_parse_precision(const char *str, int *precision)
{
	long	tmp;

	if (*str != '.')
		tmp = -1;
	else
	{
		str++;
		if (!ft_isdigit(*str))
			tmp = 0;
		else
			tmp = ft_strtol(str, (char **)&str, 10);
		if (INT_MAX < tmp)
			tmp = INT_MAX;
	}
	*precision = tmp;
	return (str);
}

static inline const char	*_parse_length(const char *str,
	t__printf_length *length)
{
	*length = _PRINTF_LEN_DEFAULT;
	if (*str == 'h')
	{
		*length = (str++, _PRINTF_LEN_SHORT);
		if (*str == 'h')
			*length = (str++, _PRINTF_LEN_CHAR);
	}
	else if (*str == 'l')
	{
		*length = (str++, _PRINTF_LEN_LONG);
		if (*str == 'l')
			*length = (str++, _PRINTF_LEN_LLONG);
	}
	else if (*str == 'j')
		*length = (str++, _PRINTF_LEN_INTMAX);
	else if (*str == 'z')
		*length = (str++, _PRINTF_LEN_SIZE_T);
	else if (*str == 't')
		*length = (str++, _PRINTF_LEN_PTRDIFF);
	return (str);
}

//	%[flags][width][.precision][length]type
const char	*ft__printf_parse_specifier(const char *str,
		t__printf_specifier *spec)
{
	str = _parse_flags(str, &spec->flags);
	str = _parse_width(str, &spec->width);
	str = _parse_precision(str, &spec->precision);
	str = _parse_length(str, &spec->length);
	return (str);
}
