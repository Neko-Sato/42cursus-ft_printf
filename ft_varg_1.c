/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:36:52 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 16:01:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_varg.h>

#if !defined(__APPLE__)

unsigned long long	ft__va_arg_unsigned_long_long(t__va_list_ref ap)
{
	return (va_arg(ap, unsigned long long));
}

void	*ft__va_arg_pointer(t__va_list_ref ap)
{
	return (va_arg(ap, void *));
}

char	*ft__va_arg_string(t__va_list_ref ap)
{
	return (va_arg(ap, char *));
}

#endif
