/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__printf_handlers_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:13:54 by hshimizu          #+#    #+#             */
/*   Updated: 2026/05/18 14:50:50 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdint.h>

static unsigned long long	_value(const t__printf_specifier *spec, va_list *ap)
{
	unsigned long long	n;

	if (spec->length == _PRINTF_LEN_CHAR)
		n = (unsigned char)va_arg(*ap, unsigned int);
	else if (spec->length == _PRINTF_LEN_SHORT)
		n = (unsigned short)va_arg(*ap, unsigned int);
	else if (spec->length == _PRINTF_LEN_LONG)
		n = va_arg(*ap, unsigned long);
	else if (spec->length == _PRINTF_LEN_LLONG)
		n = va_arg(*ap, unsigned long long);
	else if (spec->length == _PRINTF_LEN_SIZE_T)
		n = va_arg(*ap, size_t);
	else if (spec->length == _PRINTF_LEN_INTMAX)
		n = va_arg(*ap, uintmax_t);
	else
		n = va_arg(*ap, unsigned int);
	return (n);
}

size_t	ft__printf_handler_unsigned(t_ostream *os,
		const t__printf_specifier *spec, va_list *ap)
{
	t__iniprint_args	args;

	args.base = 10;
	args.flags = 0;
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

size_t	ft__printf_handler_hexadecimal_lower(t_ostream *os,
		const t__printf_specifier *spec, va_list *ap)
{
	t__iniprint_args	args;

	args.base = 16;
	args.flags = 0;
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

size_t	ft__printf_handler_hexadecimal_upper(t_ostream *os,
		const t__printf_specifier *spec, va_list *ap)
{
	t__iniprint_args	args;

	args.base = 16;
	args.flags = _INTPRINT_FLAG_UPPER;
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

size_t	ft__printf_handler_octal(t_ostream *os, const t__printf_specifier *spec,
		va_list *ap)
{
	t__iniprint_args	args;

	args.base = 8;
	args.flags = 0;
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
