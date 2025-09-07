/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__printf_handlers_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:13:54 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/08 06:11:37 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static long long	_value(const t__printf_specifier *spec, va_list *ap)
{
	long long	n;

	if (spec->rank <= -2)
		n = (signed char)va_arg(*ap, int);
	else if (spec->rank == -1)
		n = (signed short)va_arg(*ap, int);
	else if (spec->rank == 0)
		n = va_arg(*ap, int);
	else if (spec->rank == 1)
		n = va_arg(*ap, long);
	else
		n = va_arg(*ap, long long);
	return (n);
}

size_t	ft__printf_handler_signed(t_ostream *os,
		const t__printf_specifier *spec, va_list *ap)
{
	t__iniprint_args	args;

	args.base = 10;
	args.flags = _INTPRINT_FLAG_SIGNED;
	if (spec->flags & _PRINTF_FLAG_MINUS)
		args.flags |= _INTPRINT_FLAG_LEFT_ADJ;
	if (spec->flags & _PRINTF_FLAG_ZERO)
		args.flags |= _INTPRINT_FLAG_ZERO_PAD;
	if (spec->flags & _PRINTF_FLAG_HASH)
		args.flags |= _INTPRINT_FLAG_ALT_FORM;
	if (spec->flags & _PRINTF_FLAG_SPACE)
		args.flags |= _INTPRINT_FLAG_PAD_POS;
	if (spec->flags & _PRINTF_FLAG_PLUS)
		args.flags |= _INTPRINT_FLAG_MARK_POS;
	args.prec = spec->precision;
	args.width = spec->width;
	return (ft__intprint(os, _value(spec, ap), &args));
}
