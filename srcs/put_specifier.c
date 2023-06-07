/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:34:56 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/07 19:51:00 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include "format.h"
#include "utils.h"
#include <stdarg.h>
#include <stddef.h>

size_t	put_specifier(t_specifier *specifier, va_list ap)
{
	size_t	ret;

	if (specifier->specifier == 'c')
		ret = put_specifier_c((char)va_arg(ap, int));
	else if (specifier->specifier == 's')
		ret = put_specifier_s(va_arg(ap, char *));
	else if (specifier->specifier == 'p')
		ret = 0; // put_specifier_p(va_arg(ap, void *));
	else if (specifier->specifier == 'd')
		ret = 0; // put_specifier_d(va_arg(ap, int));
	else if (specifier->specifier == 'i')
		ret = 0; // put_specifier_d(va_arg(ap, int));
	else if (specifier->specifier == 'u')
		ret = 0; // put_specifier_u(va_arg(ap, unsigned int));
	else if (specifier->specifier == 'x')
		ret = 0; // put_specifier_x(va_arg(ap, unsigned int), 0);
	else if (specifier->specifier == 'X')
		ret = 0; // put_specifier_x(va_arg(ap, unsigned int), 1);
	else if (specifier->specifier == '%')
		ret = put_specifier_percent();
	else
		ret = 0;
	return (ret);
}

size_t	put_specifier_c(char c)
{
	return (buf_write_stdout(&c, 1));
}

size_t	put_specifier_s(char *s)
{
	return (buf_write_stdout(s, ft_strlen(s)));
}

size_t	put_specifier_percent(void)
{
	return (buf_write_stdout("%", 1));
}
