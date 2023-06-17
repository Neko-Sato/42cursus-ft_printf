/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:58:49 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/17 14:16:16 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include "format.h"
#include <stddef.h>

size_t	put_type_c(char c, int flag, int width)
{
	size_t	ret;

	ret = 0;
	ret += _put_width(flag, width, 1, 0);
	ret += buf_write_stdout(&c, 1);
	ret += _put_width(flag, width, 1, 1);
	return (ret);
}
