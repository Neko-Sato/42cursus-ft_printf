/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:49:38 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/07 17:16:49 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include <unistd.h>

static char		g_buf[BUF_SIZE];
static size_t	g_buf_count;

size_t	buf_flush_stdout(void)
{
	size_t	ret;

	write(1, g_buf, g_buf_count);
	ret = g_buf_count;
	g_buf_count = 0;
	return (ret);
}

size_t	buf_write_stdout(const char *str, size_t count)
{
	size_t	ret;

	ret = 0;
	while (count--)
	{
		g_buf[g_buf_count++] = str++;
		if (g_buf_count >= BUF_SIZE)
			ret += buf_flush();
	}
	return (ret);
}
