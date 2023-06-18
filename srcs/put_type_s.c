/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:19:14 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/13 03:10:37 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include "format.h"
#include "utils.h"
#include <stddef.h>

size_t	put_type_s(char *s, int flag, int width, int precision)
{
	size_t	ret;
	size_t	len;

	if (!s)
		return (put_type_s("(null)", flag, width, precision));
	ret = 0;
	len = ft_strlen(s);
	if (precision != PRECISION_DEFAULT && (int)len > precision)
		len = precision;
	ret += _put_width(flag, width, len, 0);
	ret += buf_write_stdout(s, len);
	ret += _put_width(flag, width, len, 1);
	return (ret);
}
