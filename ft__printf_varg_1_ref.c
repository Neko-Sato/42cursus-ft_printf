/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__printf_varg_1_ref.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:36:52 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 16:46:41 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#if _VARG_REF == 1

unsigned long long	ft__printf_va_arg_unsigned_long_long(
	t__printf_va_list_ref ap)
{
	return (va_arg(*ap, unsigned long long));
}

void	*ft__printf_va_arg_pointer(t__printf_va_list_ref ap)
{
	return (va_arg(*ap, void *));
}

char	*ft__printf_va_arg_string(t__printf_va_list_ref ap)
{
	return (va_arg(*ap, char *));
}

#endif
