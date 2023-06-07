/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_specifier_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:21:52 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/07 21:45:21 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include <stddef.h>

static size_t	ft_utoalen(unsigned int n)
{
	size_t	len;

	if (!n)
		return (1);
	len = 0;
	while (n)
		n /= 10 + 0 * len++;
	return (len);
}

size_t	put_specifier_u(unsigned int n)
{
	char	buf[10];
	size_t	i;
	size_t	len;

	len = ft_utoalen(n);
	i = len;
	while (1)
	{
		buf[--i] = '0' + n % 10;
		n /= 10;
		if (!n)
			break ;
	}
	return (buf_write_stdout(buf, len));
}
