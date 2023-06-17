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
	return (put_type_xl((unsigned long)p, 0, FLAG_HASH, WIDTH_DEFAULT,
			PRECISION_DEFAULT));
}
