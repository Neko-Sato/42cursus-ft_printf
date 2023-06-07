/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:26:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/07 17:31:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H
# include <stddef.h>

// typedef enum e_specifier
// {
// 	specifier_c = 'c',
// 	specifier_s = 's',
// 	specifier_p = 'p',
// 	specifier_d = 'd',
// 	specifier_i = 'i',
// 	specifier_u = 'u',
// 	specifier_x = 'x',
// 	specifier_X = 'X',
// 	specifier_percent = '%',
// }			t_specifier;

# define FLAG_HASH 0b001
# define FLAG_SPACE 0b010
# define FLAG_PLUS 0b100

typedef struct e_specifier
{
	int		flag;
	int		field_width;
	int		accuracy;
	char	specifier;
	size_t	len;
}			t_specifier;

size_t		pars_specifier(t_specifier *specifier, const char *str);

#endif
