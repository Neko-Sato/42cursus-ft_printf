/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:21:02 by hshimizu          #+#    #+#             */
/*   Updated: 2026/05/18 13:44:02 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <ft_ostream/ft_ostream.h>
# include <stdarg.h>

int						ft_printf(const char *fmt, ...);
int						ft_fprintf(t_ostream *os, const char *fmt, ...);
int						ft_sprintf(char *str, const char *fmt, ...);
int						ft_snprintf(char *str, size_t size, const char *fmt,
							...);
int						ft_asprintf(char **strptr, const char *fmt, ...);
int						ft_dprintf(int fd, const char *fmt, ...);

int						ft_vprintf(const char *fmt, va_list ap);
int						ft_vfprintf(t_ostream *os, const char *fmt, va_list ap);
int						ft_vsprintf(char *str, const char *fmt, va_list ap);
int						ft_vsnprintf(char *str, size_t size, const char *fmt,
							va_list ap);
int						ft_vasprintf(char **strptr, const char *fmt,
							va_list ap);
int						ft_vdprintf(int fd, const char *fmt, va_list ap);

typedef enum e__printf_flag
{
	_PRINTF_FLAG_MINUS = 0x1,
	_PRINTF_FLAG_ZERO = 0x2,
	_PRINTF_FLAG_HASH = 0x4,
	_PRINTF_FLAG_SPACE = 0x8,
	_PRINTF_FLAG_PLUS = 0x10,
	_PRINTF_FLAG_SIGNED = 0x20,
	_PRINTF_FLAG_UPPER = 0x40,
}						t__printf_flag;

typedef enum e__printf_length
{
	_PRINTF_LEN_DEFAULT = 0,
	_PRINTF_LEN_CHAR,
	_PRINTF_LEN_SHORT,
	_PRINTF_LEN_LONG,
	_PRINTF_LEN_LLONG,
	_PRINTF_LEN_SIZE_T,
	_PRINTF_LEN_INTMAX,
	_PRINTF_LEN_PTRDIFF,
}						t__printf_length;

typedef struct s__printf_specifier
{
	unsigned int		flags;
	int					width;
	int					precision;
	t__printf_length	length;
}						t__printf_specifier;

const char				*ft__printf_parse_specifier(const char *str,
							t__printf_specifier *spec);
size_t					ft__printf_char(t_ostream *os,
							const t__printf_specifier *spec, char c);
size_t					ft__printf_str(t_ostream *os,
							const t__printf_specifier *spec, const char *s);

typedef size_t			(*t__printf_handler)(t_ostream *os,
				const t__printf_specifier *spec, va_list *ap);

size_t					ft__printf_handler_char(t_ostream *os,
							const t__printf_specifier *spec, va_list *ap);
size_t					ft__printf_handler_string(t_ostream *os,
							const t__printf_specifier *spec, va_list *ap);
size_t					ft__printf_handler_pointer(t_ostream *os,
							const t__printf_specifier *spec, va_list *ap);
size_t					ft__printf_handler_signed(t_ostream *os,
							const t__printf_specifier *spec, va_list *ap);
size_t					ft__printf_handler_unsigned(t_ostream *os,
							const t__printf_specifier *spec, va_list *ap);
size_t					ft__printf_handler_hexadecimal_lower(t_ostream *os,
							const t__printf_specifier *spec, va_list *ap);
size_t					ft__printf_handler_hexadecimal_upper(t_ostream *os,
							const t__printf_specifier *spec, va_list *ap);
size_t					ft__printf_handler_octal(t_ostream *os,
							const t__printf_specifier *spec, va_list *ap);
size_t					ft__printf_handler_percent(t_ostream *os,
							const t__printf_specifier *spec, va_list *ap);

#endif
