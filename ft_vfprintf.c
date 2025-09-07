/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 23:01:33 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 15:57:40 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

static const t__printf_handler	g_handler[] = {
['c'] = ft__printf_handler_char,
['s'] = ft__printf_handler_string,
['p'] = ft__printf_handler_pointer,
['d'] = ft__printf_handler_signed,
['i'] = ft__printf_handler_signed,
['u'] = ft__printf_handler_unsigned,
['x'] = ft__printf_handler_hexadecimal_lower,
['X'] = ft__printf_handler_hexadecimal_upper,
['o'] = ft__printf_handler_octal,
['%'] = ft__printf_handler_percent
};

static const size_t				g_handler_size
	= sizeof(g_handler) / sizeof(g_handler[0]);

static inline size_t	_internal(t_ostream *os, const char **fmt,
		t__va_list_ref ap)
{
	size_t				ret;
	const char			*tmp;
	t__printf_specifier	spec;
	t__printf_handler	handler;

	tmp = *fmt + 1;
	tmp = ft__printf_parse_specifier(tmp, &spec);
	if (0 <= *tmp && (size_t)(*tmp) <= g_handler_size)
		handler = g_handler[(unsigned char)*tmp];
	else
		handler = NULL;
	if (handler)
		ret = handler(os, &spec, ap);
	else
		ret = ft_ostream_write(os, *fmt, tmp - *fmt);
	*fmt = ++tmp;
	return (ret);
}

static inline int	_core(t_ostream *os, const char *fmt, t__va_list_ref ap)
{
	size_t	ret;
	char	*find;

	if (ft_ostream_error(os))
		return (-1);
	ret = 0;
	while (1)
	{
		find = ft_strchr(fmt, '%');
		if (!find)
			break ;
		ret += ft_ostream_write(os, fmt, find - fmt);
		if (ft_ostream_error(os))
			return (-1);
		fmt = find;
		ret += _internal(os, &fmt, ap);
		if (ft_ostream_error(os))
			return (-1);
	}
	ret += ft_ostream_write(os, fmt, ft_strlen(fmt));
	if (ft_ostream_error(os))
		return (-1);
	return (ret);
}

#if defined(__APPLE__)

int	ft_vfprintf(t_ostream *os, const char *fmt, va_list ap)
{
	return (_core(os, fmt, &ap));
}
#else

int	ft_vfprintf(t_ostream *os, const char *fmt, va_list ap)
{
	return (_core(os, fmt, ap));
}
#endif
