/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:34:56 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/07 20:29:14 by hshimizu         ###   ########.fr       */
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
		ret = put_specifier_p(va_arg(ap, void *));
	else if (specifier->specifier == 'd')
		ret = put_specifier_d(va_arg(ap, int));
	else if (specifier->specifier == 'i')
		ret = put_specifier_d(va_arg(ap, int));
	else if (specifier->specifier == 'u')
		ret = put_specifier_u(va_arg(ap, unsigned int));
	else if (specifier->specifier == 'x')
		ret = put_specifier_x(va_arg(ap, unsigned int), 0);
	else if (specifier->specifier == 'X')
		ret = put_specifier_x(va_arg(ap, unsigned int), 1);
	else if (specifier->specifier == '%')
		ret = put_specifier_percent();
	else
		ret = 0;
	return (ret);
}