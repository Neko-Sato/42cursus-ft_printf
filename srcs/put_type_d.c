/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:32:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/14 21:46:04 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "libft.h"
#include <stddef.h>

size_t	put_type_d(int n, int flag, int width, int precision)
{
	size_t			ret;
	unsigned int	un;
	int				exist_precision;
	int				len;

	ret = 0;
	un = ft_abs(n);
	exist_precision = (precision != PRECISION_DEFAULT);
	width -= (n < 0 || (flag & (FLAG_SPACE | FLAG_PLUS)));
	len = ft_digit(un);
	if (exist_precision && ((int)len < precision || !n))
		len = precision;
	if (flag & FLAG_ZERO && !(exist_precision ^ (width < len)))
	{
		ret += _put_sign(n, flag);
		ret += put_type_u(un, flag, width, precision);
	}
	else
	{
		ret += _put_width(flag & ~(exist_precision * FLAG_ZERO), width, len, 0);
		ret += _put_sign(n, flag);
		ret += put_type_u(un, flag, WIDTH_DEFAULT, precision);
		ret += _put_width(flag, width, len, 1);
	}
	return (ret);
}
