/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:20:39 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/13 03:30:43 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

unsigned int	ft_abs(int j);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);
size_t			ft_udigit(unsigned int n);
unsigned int	ft_atou(const char *str);

#endif
