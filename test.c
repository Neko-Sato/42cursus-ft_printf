/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:57:12 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/22 03:54:15 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

void print(const char *f, ...)
{
	va_list	ap;
	va_list	ap2;

	va_start(ap, f);
	va_copy(ap2, ap);
	vprintf(f, ap);
	fflush(stdout);
	ft_printf("$\n");
	ft_vprintf(f, ap2);
	ft_printf("$\n");
	va_end(ap);
	va_end(ap2);
}

int main()
{
	print("a%% ta%@aa%k0", 4);
	return 0;
   print("%#x", 0);
   print("--.%#xp", 0);
   print("--.%#xs", 0);
   print("%#X", 0);
   print("--.%#Xp", 0);
   print("--.%#Xs", 0);
}