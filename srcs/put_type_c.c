/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:19:44 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/14 21:56:51 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include "format.h"
#include <stddef.h>

size_t	put_type_c(char c, int flag, int *width)
{
	size_t	ret;
	int		i;
	
	i = 0;
	ret = 0;
	if (flag && FLAG_MINUS)
		ret += buf_write_stdout(&c, 1);
	if (width)
		while (*width - 1 > i)
			ret += buf_write_stdout(" ", 1) + 0 * i++;
	if (!(flag && FLAG_MINUS))
		ret += buf_write_stdout(&c, 1);
	return (ret);
}
