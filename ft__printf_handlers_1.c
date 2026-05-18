/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__printf_handlers_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:13:54 by hshimizu          #+#    #+#             */
/*   Updated: 2026/05/18 14:50:31 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdint.h>

static long long	_value(const t__printf_specifier *spec, va_list *ap)
{
	long long	n;

	if (spec->length == _PRINTF_LEN_CHAR)
		n = (signed char)va_arg(*ap, int);
	else if (spec->length == _PRINTF_LEN_SHORT)
		n = (signed short)va_arg(*ap, int);
	else if (spec->length == _PRINTF_LEN_LONG)
		n = va_arg(*ap, long);
	else if (spec->length == _PRINTF_LEN_LLONG)
		n = va_arg(*ap, long long);
	else if (spec->length == _PRINTF_LEN_SIZE_T)
		n = va_arg(*ap, ssize_t);
	else if (spec->length == _PRINTF_LEN_INTMAX)
		n = va_arg(*ap, intmax_t);
	else if (spec->length == _PRINTF_LEN_PTRDIFF)
		n = va_arg(*ap, ptrdiff_t);
	else
		n = va_arg(*ap, int);
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
