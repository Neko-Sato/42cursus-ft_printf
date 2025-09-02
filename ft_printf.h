/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:21:02 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/02 09:59:15 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <ft_ostream/ft_ostream.h>
# include <stdarg.h>

int			ft_printf(const char *fmt, ...);
int			ft_fprintf(t_ostream *os, const char *fmt, ...);
int			ft_sprintf(char *str, const char *fmt, ...);
int			ft_snprintf(char *str, size_t size, const char *fmt, ...);
int			ft_asprintf(char **strptr, const char *fmt, ...);
int			ft_dprintf(int fd, const char *fmt, ...);

int			ft_vprintf(const char *fmt, va_list ap);
int			ft_vfprintf(t_ostream *os, const char *fmt, va_list ap);
int			ft_vsprintf(char *str, const char *fmt, va_list ap);
int			ft_vsnprintf(char *str, size_t size, const char *fmt, va_list ap);
int			ft_vasprintf(char **strptr, const char *fmt, va_list ap);
int			ft_vdprintf(int fd, const char *fmt, va_list ap);

# define _PRINTF_FLAG_MINUS 0x1
# define _PRINTF_FLAG_ZERO 0x2
# define _PRINTF_FLAG_HASH 0x4
# define _PRINTF_FLAG_SPACE 0x8
# define _PRINTF_FLAG_PLUS 0x10
# define _PRINTF_FLAG_SIGNED 0x20
# define _PRINTF_FLAG_UPPER 0x40

typedef struct s__printf_specifier
{
	int		flag;
	int		width;
	int		precision;
	int		rank;
	int		type;
}			t__printf_specifier;

const char	*ft__printf_parse_specifier(const char *str,
				t__printf_specifier *spec);

typedef struct s__printf_handler_entry
{
	int		type;
	ssize_t	(*handler)(t_ostream *, t__printf_specifier *, va_list);
}			t__printf_handler_entry;

ssize_t		ft__printf_handle_char(t_ostream *os,
				const t__printf_specifier *spec, va_list ap);
ssize_t		ft__printf_handle_string(t_ostream *os,
				const t__printf_specifier *spec, va_list ap);
ssize_t		ft__printf_handle_pointer(t_ostream *os,
				const t__printf_specifier *spec, va_list ap);
ssize_t		ft__printf_handle_signed_decimal(t_ostream *os,
				const t__printf_specifier *spec, va_list ap);
ssize_t		ft__printf_handle_unsigned_decimal(t_ostream *os,
				const t__printf_specifier *spec, va_list ap);
ssize_t		ft__printf_handle_hexadecimal(t_ostream *os,
				const t__printf_specifier *spec, va_list ap);
ssize_t		ft__printf_handle_percent(t_ostream *os,
				const t__printf_specifier *spec, va_list ap);

ssize_t		ft__printf_string(t_ostream *os, t__printf_specifier *spec,
				const char *s);
ssize_t		ft__printf_integer(t_ostream *os, t__printf_specifier *spec,
				long num, int base);
ssize_t		ft__printf_unsigned(t_ostream *os, t__printf_specifier *spec,
				unsigned long long num, int base);

#endif
