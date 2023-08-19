/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:47:21 by hshimizu          #+#    #+#             */
/*   Updated: 2023/08/19 23:20:39 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include <libft.h>
#include <limits.h>

static size_t	pars_flag(const char *specifier, int *flag);
static size_t	pars_width(const char *specifier, int *width);
static size_t	pars_precision(const char *specifier, int *precision);
static size_t	pars_type(const char *specifier, t_type *type);

//	%[flags][width][.precision]type
size_t	pars_specifier(t_specifier *specifier, const char *str)
{
	const char	*_str;

	_str = str++;
	str += pars_flag(str, &specifier->flag);
	str += pars_width(str, &specifier->width);
	str += pars_precision(str, &specifier->precision);
	str += pars_type(str, &specifier->type);
	if (specifier->type == type_none)
		return (1);
	return (str - _str);
}

static size_t	pars_flag(const char *specifier, int *flag)
{
	const char	*_specifier;

	_specifier = specifier;
	*flag = FLAG_NONE;
	while (1)
	{
		if (*specifier == '-')
			*flag |= FLAG_MINUS;
		else if (*specifier == '0')
			*flag |= FLAG_ZERO;
		else if (*specifier == '#')
			*flag |= FLAG_HASH;
		else if (*specifier == ' ')
			*flag |= FLAG_SPACE;
		else if (*specifier == '+')
			*flag |= FLAG_PLUS;
		else
			break ;
		specifier++;
	}
	return (specifier - _specifier);
}

static size_t	pars_width(const char *specifier, int *width)
{
	size_t	ret;

	ret = 0;
	if (!ft_isdigit(*specifier))
		*width = WIDTH_DEFAULT;
	else
	{
		*width = ft_atoi(specifier);
		while (ft_isdigit(*specifier++))
			ret++;
	}
	return (ret);
}

static size_t	pars_precision(const char *specifier, int *precision)
{
	size_t	ret;

	ret = 0;
	if (*specifier++ != '.')
		*precision = PRECISION_DEFAULT;
	else
	{
		ret++;
		*precision = ft_atoi(specifier);
		while (ft_isdigit(*specifier++))
			ret++;
	}
	return (ret);
}

static size_t	pars_type(const char *specifier, t_type *type)
{
	if (type_c == *specifier)
		*type = type_c;
	else if (type_s == *specifier)
		*type = type_s;
	else if (type_p == *specifier)
		*type = type_p;
	else if (type_d == *specifier)
		*type = type_d;
	else if (type_i == *specifier)
		*type = type_i;
	else if (type_u == *specifier)
		*type = type_u;
	else if (type_x == *specifier)
		*type = type_x;
	else if (type_X == *specifier)
		*type = type_X;
	else if (type_percent == *specifier)
		*type = type_percent;
	else
		*type = type_none;
	return (1);
}
