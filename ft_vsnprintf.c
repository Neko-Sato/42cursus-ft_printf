/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:39:19 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/23 23:25:41 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>

static ssize_t	_write_buffer(const char *buf, size_t len,
		t__printf_write_buffer *buffer)
{
	size_t	size;

	if (!buffer->buffer && !buffer->size)
		return (len);
	if (buffer->pos >= buffer->size)
		return (len);
	size = buffer->size - buffer->pos;
	if (len < size)
		size = len;
	ft_memcpy(buffer->buffer + buffer->pos, buf, size);
	buffer->pos += size;
	if (buffer->pos < buffer->size)
		buffer->buffer[buffer->pos] = '\0';
	return (len);
}

int	ft_vsnprintf(char *str, size_t size, const char *fmt, va_list ap)
{
	t_ostream				os;
	t__printf_write_buffer	buffer;

	buffer.buffer = str;
	buffer.size = size;
	buffer.pos = 0;
	os.write_fn = (ssize_t(*)(const void *, size_t, void *))_write_buffer;
	os.arg = &buffer;
	return (ft_vfprintf(&os, fmt, ap));
}
