/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:35:05 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/23 23:17:45 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static ssize_t	_write_fd(const char *buf, size_t len, int *fd)
{
	return (write(*fd, buf, len));
}

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_ostream	os;

	os.write_fn = (ssize_t(*)(const void *, size_t, void *))_write_fd;
	os.arg = &fd;
	return (ft_vfprintf(&os, fmt, ap));
}
