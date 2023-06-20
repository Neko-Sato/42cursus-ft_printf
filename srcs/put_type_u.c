/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_u.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:21:52 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/13 03:32:05 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include "format.h"
#include "utils.h"
#include <stddef.h>

size_t	put_type_u(UINT n, int flag, int width, int precision)
{
	size_t	ret;
	size_t	len;

	ret = 0;
	len = ft_udigit(n);
	if (precision != PRECISION_DEFAULT)
	{
		flag &= ~FLAG_ZERO;
		if ((int)len < precision || !n)
			len = precision;
	}
	ret += _put_width(flag, width, len, 0);
	if (precision && precision != PRECISION_DEFAULT)
		ret += put_type_u(n, (flag & ~FLAG_MINUS) | FLAG_ZERO, precision,
				PRECISION_DEFAULT);
	else if (len)
		ret += _put_uint(n, len);
	ret += _put_width(flag, width, len, 1);
	return (ret);
}
