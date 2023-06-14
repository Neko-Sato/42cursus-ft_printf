/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_percent.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:18:24 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/14 21:46:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include <stddef.h>

size_t	put_type_percent(void)
{
	return (put_type_c('%', 0, NULL));
}
