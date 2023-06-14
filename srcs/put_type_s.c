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

size_t	put_type_s(char *s, int flag, int *width, int *precision)
{
	size_t	ret;
	size_t	len;
	int		i;

	if (!s)
		return (put_type_s("(null)", 0, NULL, NULL));
	ret = 0;
	i = 0;
	len = ft_strlen(s);
	if (precision && *precision && (int)len > *precision)
		len = *precision;
	if (flag && FLAG_MINUS)
		ret += buf_write_stdout(s, len);
	if (width)
		while (*width - (int)len > i)
			ret += buf_write_stdout(" ", 1) + 0 * i++;
	if (!(flag && FLAG_MINUS))
		ret += buf_write_stdout(s, len);
	return (ret);
}
