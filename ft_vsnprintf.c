/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:39:19 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 16:12:13 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_vsnprintf(char *str, size_t size, const char *fmt, va_list ap)
{
	t_ostream		os;
	t__write_buffer	buffer;

	buffer.buf = str;
	buffer.size = size;
	buffer.pos = 0;
	os._write_fn = ft__write_buffer;
	os._arg = &buffer;
	os._flags = 0;
	os._lbf = OSTREAM_UNBUF;
	os._buf = NULL;
	os._pos = NULL;
	os._end = NULL;
	return (ft_vfprintf(&os, fmt, ap));
}
