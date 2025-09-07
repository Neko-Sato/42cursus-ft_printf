/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__printf_handlers_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:13:54 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 15:43:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static unsigned long long	_value(const t__printf_specifier *spec,
		t__va_list_ref ap)
{
	unsigned long long	n;

	if (spec->rank <= -2)
		n = (unsigned char)ft__va_arg_unsigned_int(ap);
	else if (spec->rank == -1)
		n = (unsigned short)ft__va_arg_unsigned_int(ap);
	else if (spec->rank == 0)
		n = ft__va_arg_unsigned_int(ap);
	else if (spec->rank == 1)
		n = ft__va_arg_unsigned_long(ap);
	else
		n = ft__va_arg_unsigned_long_long(ap);
	return (n);
}

size_t	ft__printf_handler_unsigned(t_ostream *os,
		const t__printf_specifier *spec, t__va_list_ref ap)
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
		const t__printf_specifier *spec, t__va_list_ref ap)
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
		const t__printf_specifier *spec, t__va_list_ref ap)
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
		t__va_list_ref ap)
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
