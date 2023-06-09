/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:52:58 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/17 14:45:55 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

UINT	ft_abs(int j)
{
	if (j < 0)
		return (-(j + 1) + 1u);
	else
		return (j);
}
