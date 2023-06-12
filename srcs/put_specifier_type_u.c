/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_specifier_type_u.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:21:52 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/13 03:32:05 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include "utils.h"
#include <stddef.h>

size_t	put_specifier_type_u(unsigned int n)
{
	char	buf[10];
	size_t	i;
	size_t	len;

	len = ft_udigit(n);
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
