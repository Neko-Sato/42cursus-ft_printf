/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:21:11 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/13 05:17:14 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned int	ft_atou(const char *str)
{
	unsigned int	ret;

	ret = 0;
	while (ft_isdigit(*str))
		ret = ret * 10 + *str++ - '0';
	return (ret);
}
