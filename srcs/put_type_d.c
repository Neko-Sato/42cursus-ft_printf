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
#include "utils.h"
#include <stddef.h>

size_t	put_type_d(int n, int flag, int width, int precision)
{
	size_t	ret;
	UINT	un;
	int		issign;
	int		len;

	ret = 0;
	un = ft_abs(n);
	issign = (n < 0 || (flag & (FLAG_SPACE | FLAG_PLUS)));
	width -= (width != WIDTH_DEFAULT) && issign;
	len = ft_udigit(un);
	if (precision != PRECISION_DEFAULT && ((int)len < precision || !n))
	{
		len = precision;
	}
	ret += _put_width(flag, width, len, 0);
	ret += _put_sign(n, flag);
	ret += put_type_u(un, flag, width, precision);
	ret += _put_width(flag, width, len, 1);
	return (ret);
}
