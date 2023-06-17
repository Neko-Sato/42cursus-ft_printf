/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:22:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/13 03:10:48 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "utils.h"
#include <stddef.h>

size_t	put_type_x(UINT n, int flag, int width, int precision)
{
	return (put_type_xl(n, flag, width, precision));
}
