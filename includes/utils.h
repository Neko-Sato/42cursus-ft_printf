/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:20:39 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/17 14:46:16 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# define UINT unsigned int

UINT	ft_abs(int j);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
size_t	ft_udigit(UINT n);
UINT	ft_atou(const char *str);

#endif
