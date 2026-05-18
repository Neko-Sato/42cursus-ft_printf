*This project has been created as part of the 42 curriculum by hshimizu.*

# 42cursus-ft_printf

## Description

This project is a simplified reimplementation of the standard `printf` family of functions.

It provides formatted output functionality based on a limited but compatible subset of the original `printf` specification.

The goal of the project is to reproduce formatted output behavior while implementing format parsing and variadic argument handling.

The library provides the following functions:

- `ft_printf`
- `ft_fprintf`
- `ft_sprintf`
- `ft_snprintf`
- `ft_asprintf`
- `ft_dprintf`
- `ft_vprintf`
- `ft_vfprintf`
- `ft_vsprintf`
- `ft_vsnprintf`
- `ft_vasprintf`
- `ft_vdprintf`

---

## Format Specification

```text
%[flags][width][.precision][length]type
```

### Conversion specifiers

- `c` : character output
- `s` : string output
- `p` : pointer address (implementation-defined format)
- `d`, `i` : signed decimal integer
- `u` : unsigned decimal integer
- `x` : unsigned hexadecimal (lowercase)
- `X` : unsigned hexadecimal (uppercase)
- `o` : unsigned octal
- `%` : literal `%` character output

---

### Flags

- `-` : left alignment
- `0` : zero padding
- `#` : alternate form
- ` ` : space prefix
- `+` : force sign output

---

### Length modifiers

- `hh` : char
- `h`  : short
- `l`  : long
- `ll` : long long
- `z`  : size_t
- `j`  : intmax_t
- `t`  : ptrdiff_t (only valid with `u` conversion)

---

## Instructions

### Installation

Build the library:

```sh
$ git clone <repository url>
$ cd 42cursus-ft_printf
$ make
```

### Usage

Compile your program with `libftprintf`:

```sh
$ cc your_program.c -I<libftprintf_path> -L<libftprintf_path> -lftprintf
```

---

## Algorithm and Data Structure

The implementation uses a parser that scans the format string sequentially.

When a `%` character is encountered, the parser extracts:

1. flags
2. width
3. precision
4. length modifier
5. conversion specifier

The parsed state is stored in an internal formatting structure used during conversion and output generation.

Integer formatting is implemented using base conversion routines for decimal, hexadecimal, and octal output.

---

## Resources

- [42cursus-ft_printf Repository](https://github.com/Neko-Sato/42cursus-ft_printf)
- [FreeBSD Repository](https://github.com/freebsd/freebsd-src)
- [musl libc Repository](https://github.com/kraj/musl)
- [klibc Repository](https://git.kernel.org/pub/scm/libs/klibc/klibc.git)