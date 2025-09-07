/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:35:05 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 16:12:09 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <unistd.h>

int	ft_vprintf(const char *fmt, va_list ap)
{
	int			fd;
	int			ret;
	t_ostream	os;
	char		buf[1024];

	fd = STDOUT_FILENO;
	os._write_fn = ft__write_fd;
	os._arg = &fd;
	os._flags = 0;
	os._lbf = OSTREAM_LINEBUF;
	os._buf = buf;
	os._pos = buf;
	os._end = buf + sizeof(buf);
	ret = ft_vfprintf(&os, fmt, ap);
	ft_ostream_flush(&os);
	return (ret);
}
