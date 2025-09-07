/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__printf_handlers_0.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:13:54 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 16:32:50 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	ft__printf_handler_char(t_ostream *os, const t__printf_specifier *spec,
		t__va_list_ref ap)
{
	return (ft__printf_char(os, spec, (char)ft__va_arg_signed_int(ap)));
}

size_t	ft__printf_handler_percent(t_ostream *os,
		const t__printf_specifier *spec, t__va_list_ref ap)
{
	(void)ap;
	return (ft__printf_char(os, spec, '%'));
}

size_t	ft__printf_handler_string(t_ostream *os,
		const t__printf_specifier *spec, t__va_list_ref ap)
{
	const char	*s;

	s = ft__va_arg_string(ap);
	if (!s)
	{
		if ((spec->precision == -1 || 5 < spec->precision))
			s = "(null)";
		else
			return (0);
	}
	return (ft__printf_str(os, spec, s));
}

size_t	ft__printf_handler_pointer(t_ostream *os,
		const t__printf_specifier *spec, t__va_list_ref ap)
{
	void				*p;
	t__iniprint_args	args;

	p = ft__va_arg_pointer(ap);
	if (!p)
		return (ft__printf_str(os, spec, "(nil)"));
	args.base = 16;
	args.flags = _INTPRINT_FLAG_ALT_FORM;
	args.flags |= _INTPRINT_FLAG_LEFT_ADJ
		& -!!(spec->flags & _PRINTF_FLAG_MINUS);
	args.flags |= _INTPRINT_FLAG_ZERO_PAD
		& -!!(spec->flags & _PRINTF_FLAG_ZERO);
	args.flags |= _INTPRINT_FLAG_ALT_FORM
		& -!!(spec->flags & _PRINTF_FLAG_HASH);
	args.flags |= _INTPRINT_FLAG_PAD_POS
		& -!!(spec->flags & _PRINTF_FLAG_SPACE);
	args.flags |= _INTPRINT_FLAG_MARK_POS
		& -!!(spec->flags & _PRINTF_FLAG_PLUS);
	args.prec = spec->precision;
	args.width = spec->width;
	return (ft__intprint(os, (unsigned long long)p, &args));
}
