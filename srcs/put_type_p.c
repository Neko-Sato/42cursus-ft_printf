/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_p.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:47:39 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/13 03:11:23 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include <stddef.h>

size_t	put_type_p(void *p)
{
	size_t	ret;

	ret = 0;
	ret += put_type_s("0x", 0, NULL, NULL);
	ret += put_type_xl((unsigned long)p, 0);
	return (ret);
}
