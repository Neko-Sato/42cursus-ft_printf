/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__printf_imple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 12:36:06 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 16:38:45 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <ft_string/ft_string.h>

size_t	ft__printf_char(t_ostream *os, const t__printf_specifier *spec, char c)
{
	size_t	i;
	size_t	ret;

	ret = 0;
	i = 0;
	if (spec->width != -1)
		i = spec->width - 1;
	if (!(spec->flags & _PRINTF_FLAG_MINUS))
		while (i)
			ret += (i--, ft_ostream_write(os, " ", 1));
	ret += ft_ostream_write(os, &c, 1);
	if (spec->flags & _PRINTF_FLAG_MINUS)
		while (i)
			ret += (i--, ft_ostream_write(os, " ", 1));
	return (ret);
}

size_t	ft__printf_str(t_ostream *os, const t__printf_specifier *spec,
		const char *s)
{
	size_t	ret;
	size_t	len;
	size_t	i;

	ret = 0;
	len = ft_strnlen(s, spec->precision);
	i = 0;
	if (spec->width != -1 && len < (size_t)spec->width)
		i = spec->width - len;
	if (!(spec->flags & _PRINTF_FLAG_MINUS))
		while (i)
			ret += (i--, ft_ostream_write(os, " ", 1));
	ret += ft_ostream_write(os, s, len);
	if (spec->flags & _PRINTF_FLAG_MINUS)
		while (i)
			ret += (i--, ft_ostream_write(os, " ", 1));
	return (ret);
}
