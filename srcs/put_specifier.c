/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:34:56 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/13 04:57:00 by hshimizu         ###   ########.fr       */
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

	if (specifier->type == type_c)
		ret = put_specifier_type_c((char)va_arg(ap, int));
	else if (specifier->type == type_s)
		ret = put_specifier_type_s(va_arg(ap, char *));
	else if (specifier->type == type_p)
		ret = put_specifier_type_p(va_arg(ap, void *));
	else if (specifier->type == type_d)
		ret = put_specifier_type_d(va_arg(ap, int));
	else if (specifier->type == type_i)
		ret = put_specifier_type_d(va_arg(ap, int));
	else if (specifier->type == type_u)
		ret = put_specifier_type_u(va_arg(ap, unsigned int));
	else if (specifier->type == type_x)
		ret = put_specifier_type_x(va_arg(ap, unsigned int), 0);
	else if (specifier->type == type_X)
		ret = put_specifier_type_x(va_arg(ap, unsigned int), 1);
	else if (specifier->type == type_percent)
		ret = put_specifier_type_percent();
	else
		ret = 0;
	return (ret);
}
