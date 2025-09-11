/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:58:14 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/12 01:40:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

int	ft_vasprintf(char **strptr, const char *fmt, va_list ap)
{
	va_list	ap2;
	int		size;

	va_copy(ap2, ap);
	size = ft_vsnprintf(0, 0, fmt, ap2);
	va_end(ap2);
	if (size < 0)
		return (-1);
	*strptr = malloc(++size);
	if (!*strptr)
		return (-1);
	return (ft_vsnprintf(*strptr, size, fmt, ap));
}
