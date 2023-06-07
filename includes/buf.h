/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:36:58 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/07 17:19:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUF_H
# define BUF_H
# define BUF_SIZE 42

# include <stddef.h>

size_t	buf_flush_stdout(void);
size_t	buf_write_stdout(const char *str, size_t count);

#endif