/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 23:01:33 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/25 16:08:36 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>

static const t__printf_handler_entry	g__handler_entry[] = {
{'c', ft__printf_handle_char},
{'s', ft__printf_handle_string},
{'p', ft__printf_handle_pointer},
{'d', ft__printf_handle_signed_decimal},
{'i', ft__printf_handle_signed_decimal},
{'u', ft__printf_handle_unsigned_decimal},
{'x', ft__printf_handle_hexadecimal},
{'X', ft__printf_handle_hexadecimal},
{'%', ft__printf_handle_percent}
};

static const size_t						g__handler_entry_size
	= sizeof(g__handler_entry) / sizeof(g__handler_entry[0]);

static inline ssize_t	_internal(t_ostream *os, const char **fmt, va_list ap)
{
	t__printf_specifier	spec;
	const char			*str;
	size_t				i;

	str = *fmt;
	str = ft__printf_parse_specifier(str, &spec);
	i = 0;
	while (i < g__handler_entry_size)
	{
		if (g__handler_entry[i].type == spec.type)
		{
			*fmt = str;
			return (g__handler_entry[i].handler(os, &spec, ap));
		}
		i++;
	}
	return (os->write_fn("%", 1, os->arg));
}

int	ft_vfprintf(t_ostream *os, const char *fmt, va_list ap)
{
	ssize_t	tmp;
	int		ret;
	char	*find;

	ret = 0;
	while (1)
	{
		find = ft_strchr(fmt, '%');
		if (!find)
			break ;
		tmp = os->write_fn(fmt, find - fmt, os->arg);
		if (tmp < 0)
			return (-1);
		ret += tmp;
		fmt = ++find;
		tmp = _internal(os, &fmt, ap);
		if (tmp < 0)
			return (-1);
	}
	tmp = os->write_fn(fmt, ft_strlen(fmt), os->arg);
	if (tmp < 0)
		return (-1);
	ret += tmp;
	return (ret);
}
