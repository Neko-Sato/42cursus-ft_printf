/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_specifier_type_xl.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:22:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/13 03:10:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include <stddef.h>

static size_t	ft_ultohlen(unsigned long n)
{
	size_t	len;

	if (!n)
		return (1);
	len = 0;
	while (n)
		n >>= 4 + 0 * len++;
	return (len);
}

size_t	put_specifier_type_xl(unsigned long n, int large)
{
	char			buf[16];
	size_t			i;
	unsigned int	m;
	size_t			len;

	len = ft_ultohlen(n);
	i = len;
	while (1)
	{
		m = n & 0xFUL;
		buf[--i] = '0' + m + (10 <= m) * (0x7 + (large == 0) * 0x20);
		n >>= 4;
		if (!n)
			break ;
	}
	return (buf_write_stdout(buf, len));
}
