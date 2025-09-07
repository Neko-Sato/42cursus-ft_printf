/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:36:52 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 16:01:52 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VARG_H
# define FT_VARG_H

# include <stdarg.h>

# if defined(__APPLE__)

typedef va_list		*t__va_list_ref;
# else

typedef va_list		t__va_list_ref;
# endif

signed int			ft__va_arg_signed_int(t__va_list_ref ap);
signed long			ft__va_arg_signed_long(t__va_list_ref ap);
signed long long	ft__va_arg_signed_long_long(t__va_list_ref ap);

unsigned int		ft__va_arg_unsigned_int(t__va_list_ref ap);
unsigned long		ft__va_arg_unsigned_long(t__va_list_ref ap);
unsigned long long	ft__va_arg_unsigned_long_long(t__va_list_ref ap);

void				*ft__va_arg_pointer(t__va_list_ref ap);
char				*ft__va_arg_string(t__va_list_ref ap);

#endif
