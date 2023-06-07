/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:47:21 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/07 22:26:08 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

// static void	pars_flag(const char **specifier, int *flag);
// static void	pars_field_width(const char **specifier, int *field_width);
// static void	pars_accuracy(const char **specifier, int *accuracy);

size_t	pars_specifier(t_specifier *specifier, const char *str)
{
	const char	*_str;

	_str = str++;
	specifier->flag = 0;
	specifier->field_width = 0;
	specifier->accuracy = 0;
	specifier->specifier = *str++;
	return (str - _str);
}
