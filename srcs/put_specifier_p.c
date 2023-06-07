/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_specifier_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:47:39 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/07 22:16:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include <stddef.h>

size_t	put_specifier_p(void *p)
{
	size_t	ret;

	ret = 0;
	ret += put_specifier_s("0x");
	ret += put_specifier_xl((unsigned long)p, 0);
	return (ret);
}
