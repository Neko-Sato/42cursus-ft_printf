/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__printf_varg_0_ref.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:36:52 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 16:44:38 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#if _VARG_REF == 1

signed int	ft__printf_va_arg_signed_int(t__printf_va_list_ref ap)
{
	return (va_arg(*ap, signed int));
}

signed long	ft__printf_va_arg_signed_long(t__printf_va_list_ref ap)
{
	return (va_arg(*ap, signed long));
}

signed long long	ft__printf_va_arg_signed_long_long(t__printf_va_list_ref ap)
{
	return (va_arg(*ap, signed long long));
}

unsigned int	ft__printf_va_arg_unsigned_int(t__printf_va_list_ref ap)
{
	return (va_arg(*ap, unsigned int));
}

unsigned long	ft__printf_va_arg_unsigned_long(t__printf_va_list_ref ap)
{
	return (va_arg(*ap, unsigned long));
}

#endif
