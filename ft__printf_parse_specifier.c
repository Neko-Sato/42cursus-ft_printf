/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__printf_parse_specifier.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:47:50 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/26 02:27:21 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

static inline const char	*_parse_flag(const char *str, int *flag)
{
	static char const	flags[] = "-0# +";
	static int const	flag_values[] = {
		_PRINTF_FLAG_MINUS,
		_PRINTF_FLAG_ZERO,
		_PRINTF_FLAG_HASH,
		_PRINTF_FLAG_SPACE,
		_PRINTF_FLAG_PLUS
	};
	const char			*tmp;

	*flag = 0;
	while (1)
	{
		tmp = ft_memchr(flags, *str, sizeof(flags) - 1);
		if (!tmp)
			break ;
		*flag |= flag_values[tmp - flags];
		str++;
	}
	return (str);
}

static inline const char	*_parse_width_precision(const char *str,
		int *width_precision)
{
	if (!ft_isdigit(*str))
		*width_precision = -1;
	else
		*width_precision = ft_strtol(str, (char **)&str, 10);
	return (str);
}

static inline const char	*_parse_rank(const char *str, int *rank)
{
	size_t				i;

	*rank = 0;
	while (*str)
	{
		if (*str == 'h')
			(*rank)--;
		else if (*str == 'l')
			(*rank)++;
		else
			break ;
	}
	return (str);
}

static inline const char	*_parse_type(const char *str, int *type)
{
	if (*str)
		*type = *str++;
	else
		*type = -1;
	return (str);
}

//	%[flags][width][.precision]type
const char	*ft__printf_parse_specifier(const char *str,
		t__printf_specifier *spec)
{
	str = _parse_flag(str, &spec->flag);
	str = _parse_width_precision(str, &spec->width);
	str = _parse_width_precision(str, &spec->precision);
	return (str);
}
