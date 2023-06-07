/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_specifier_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:32:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/07 21:51:04 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "utils.h"
#include <stddef.h>

size_t	put_specifier_d(int n)
{
	size_t	ret;

	ret = 0;
	if (n < 0)
		ret += put_specifier_c('-');
	ret += put_specifier_u(ft_abs(n));
	return (ret);
}
