/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:34:56 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/14 22:05:45 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include "format.h"
#include "utils.h"
#include <stdarg.h>
#include <stddef.h>

size_t	put_specifier(t_specifier *s, va_list ap)
{
	size_t	ret;

	if (s->type == type_c)
		ret = put_type_c((char)va_arg(ap, int), s->flag, s->width);
	else if (s->type == type_s)
		ret = put_type_s(va_arg(ap, char *), s->flag, s->width, s->precision);
	else if (s->type == type_p)
		ret = put_type_p(va_arg(ap, void *));
	else if (s->type == type_d)
		ret = put_type_d(va_arg(ap, int));
	else if (s->type == type_i)
		ret = put_type_d(va_arg(ap, int));
	else if (s->type == type_u)
		ret = put_type_u(va_arg(ap, unsigned int));
	else if (s->type == type_x)
		ret = put_type_x(va_arg(ap, unsigned int), 0);
	else if (s->type == type_X)
		ret = put_type_x(va_arg(ap, unsigned int), 1);
	else if (s->type == type_percent)
		ret = put_type_percent();
	else
		ret = 0;
	return (ret);
}
