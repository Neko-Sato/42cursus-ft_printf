/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udigit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:16:42 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/17 14:06:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stddef.h>

size_t	ft_udigit(UINT n)
{
	size_t	count;

	if (!n)
		return (1);
	count = 0;
	while (n)
		n /= 10 + 0 * count++;
	return (count);
}
