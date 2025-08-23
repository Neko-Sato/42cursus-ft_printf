/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 23:01:33 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/24 02:12:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

static inline ssize_t	_internal(t_ostream *os, const char **fmt, va_list ap)
{
	t__printf_specifier	spec;

	(void)os;
	(void)ap;
	(void)fmt;
	(void)spec;
	return (0);
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
