/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_specifier_type_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:19:14 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/13 03:10:37 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include "utils.h"
#include <stddef.h>

size_t	put_specifier_type_s(char *s)
{
	if (!s)
		s = "(null)";
	return (buf_write_stdout(s, ft_strlen(s)));
}
