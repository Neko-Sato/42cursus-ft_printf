/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:40:44 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/20 17:54:52 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include "format.h"
#include "ft_printf.h"
#include "utils.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = ft_vprintf(format, ap);
	va_end(ap);
	return (ret);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int		ret;
	char	*temp;

	ret = 0;
	while (1)
	{
		temp = ft_strchr(format, '%');
		if (!temp)
			break ;
		ret += buf_write_stdout(format, temp - format);
		format = temp;
		ret += put_specifier(&format, ap);
	}
	ret += buf_write_stdout(format, ft_strlen(format));
	ret += buf_flush_stdout();
	return (ret);
}
