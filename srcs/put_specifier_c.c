/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_specifier_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:19:44 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/07 21:51:05 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"
#include <stddef.h>

size_t	put_specifier_c(char c)
{
	return (buf_write_stdout(&c, 1));
}
