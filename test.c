/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:07:59 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/17 16:13:02 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int print(const char *f, ...)
{
	va_list	ap;
	va_list	ap2;

	va_start(ap, f);
	va_copy(ap2, ap);
	printf("1-----------------\n");
	vprintf(f, ap);
	fflush(stdout);
	printf("$\n2-----------------\n");
	ft_vprintf(f, ap2);
	printf("$\n-----------------\n\n");
	va_end(ap);
	va_end(ap2);
}

void TEST(int a, int s){}

int	main(void)
{
TEST(1, print(" %#x ", 0));
	TEST(2, print(" %#x ", -1));
	TEST(3, print(" %#x ", 1));
	TEST(4, print(" %#x ", 9));
	TEST(5, print(" %#x ", 10));
	TEST(6, print(" %#x ", 11));
	TEST(7, print(" %#x ", 15));
	TEST(8, print(" %#x ", 16));
	TEST(9, print(" %#x ", 17));
	TEST(10, print(" %#x ", 99));
	TEST(11, print(" %#x ", 100));
	TEST(12, print(" %#x ", 101));
	TEST(13, print(" %#x ", -9));
	TEST(14, print(" %#x ", -10));
	TEST(15, print(" %#x ", -11));
	TEST(16, print(" %#x ", -14));
	TEST(17, print(" %#x ", -15));
	TEST(18, print(" %#x ", -16));
	TEST(19, print(" %#x ", -99));
	TEST(20, print(" %#x ", -100));
	TEST(21, print(" %#x ", -101));
	TEST(22, print(" %#x ", INT_MAX));
	TEST(23, print(" %#x ", INT_MIN));
	TEST(24, print(" %#x ", LONG_MAX));
	TEST(25, print(" %#x ", LONG_MIN));
	TEST(26, print(" %#x ", UINT_MAX));
	TEST(27, print(" %#x ", ULONG_MAX));
	TEST(28, print(" %#x ", 9223372036854775807LL));
	TEST(29, print(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	TEST(30, print(" %#x%#x ", INT_MAX, INT_MIN));

	TEST(31, print(" %#X ", 0));
	TEST(32, print(" %#X ", -1));
	TEST(33, print(" %#X ", 1));
	TEST(34, print(" %#X ", 9));
	TEST(35, print(" %#X ", 10));
	TEST(36, print(" %#X ", 11));
	TEST(37, print(" %#X ", 15));
	TEST(38, print(" %#X ", 16));
	TEST(39, print(" %#X ", 17));
	TEST(40, print(" %#X ", 99));
	TEST(41, print(" %#X ", 100));
	TEST(42, print(" %#X ", 101));
	TEST(43, print(" %#X ", -9));
	TEST(44, print(" %#X ", -10));
	TEST(45, print(" %#X ", -11));
	TEST(46, print(" %#X ", -14));
	TEST(47, print(" %#X ", -15));
	TEST(48, print(" %#X ", -16));
	TEST(49, print(" %#X ", -99));
	TEST(50, print(" %#X ", -100));
	TEST(51, print(" %#X ", -101));
	TEST(52, print(" %#X ", INT_MAX));
	TEST(53, print(" %#X ", INT_MIN));
	TEST(54, print(" %#X ", LONG_MAX));
	TEST(55, print(" %#X ", LONG_MIN));
	TEST(56, print(" %#X ", UINT_MAX));
	TEST(57, print(" %#X ", ULONG_MAX));
	TEST(58, print(" %#X ", 9223372036854775807LL));
	TEST(59, print(" %#X %#X %#X %#X %#X %#X %#X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

}
