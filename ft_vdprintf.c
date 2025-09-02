/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:35:05 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/02 09:54:10 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	int			ret;
	t_ostream	os;
	char		buf[1024];

	os._write_fn = (ssize_t(*)(const void *, size_t, void *))ft__write_fd;
	os._arg = &fd;
	os._flags = 0;
	os._lbf = OSTREAM_FULLBUF;
	os._buf = buf;
	os._pos = buf;
	os._end = buf + sizeof(buf);
	ret = ft_vfprintf(&os, fmt, ap);
	ft_ostream_flush(&os);
	return (ret);
}
