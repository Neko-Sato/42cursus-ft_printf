/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:57:12 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/18 20:23:09 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{
//    printf("=%020.10d=", -42000);
//    printf("=%0014.2d==%020d==%0002.d==%000.5d=", (int)-2147483648, 3, 30, -1);
//    printf("=%020.10i=", -42000);
//    printf("=%0014.2i==%020i==%0002.i==%000.5i=", (int)-2147483648, 3, 30, -1);
//    printf("%020d", -42000);
   printf("%030d\n", (int)-2147483648);
   printf("%012d\n", (int)-2147483648);
   printf("%012d, %20d, %2d, %42d\n", (int)-2147483648, 3, 30, -1);
   printf("%012d, %d, %2d, %42d\n", (int)-2147483648, 3, 30, -1);
   printf("%014d%020d%02d%0d\n", (int)-2147483648, 3, 30, -1);
   printf("%014dc%020ds%02dx%0du\n", (int)-2147483648, 3, 30, -1);
   printf("%01.d\n", 0);
   printf("%01.0d\n", 0);
   printf("%02.0d\n", 0);
   printf("%03.0d\n", 0);
//    printf("%042.2d", 42000);
//    printf("%042.20d", 42000);
//    printf("%020.19d is how many tests are going to be made", 8000);
//    printf("%030d", (int)-2147483648);
//    printf("%012d", (int)-2147483648);
//    printf("%012d, %20d, %2d, %000042d", (int)-2147483648, 3, 30, -1);
//    printf("%012d, %d, %002d, %42d", (int)-2147483648, 3, 30, -1);
//    printf("%014dc%020ds%02dx%0du", (int)-2147483648, 3, 30, -1);
//    printf("%020i", -42000);
//    printf("%030i", (int)-2147483648);
//    printf("%012i", (int)-2147483648);
//    printf("%012i, %20i, %2i, %42i", (int)-2147483648, 3, 30, -1);
//    printf("%012i, %i, %2i, %42i", (int)-2147483648, 3, 30, -1);
//    printf("%014i%020i%02i%0i", (int)-2147483648, 3, 30, -1);
//    printf("%014ic%020is%02ix%0iu", (int)-2147483648, 3, 30, -1);
//    printf("%01.i", 0);
//    printf("%01.0i", 0);
//    printf("%02.0i", 0);
//    printf("%03.0i", 0);
//    printf("%042.2i", 42000);
//    printf("%042.20i", 42000);
//    printf("%020.19i is how many tests are going to be made", 8000);
//    printf("%030i", (int)-2147483648);
//    printf("%012i", (int)-2147483648);
//    printf("%012i, %20i, %2i, %000042i", (int)-2147483648, 3, 30, -1);
//    printf("%012i, %i, %002i, %42i", (int)-2147483648, 3, 30, -1);
//    printf("%014ic%020is%02ix%0iu", (int)-2147483648, 3, 30, -1);
	printf("\n");
	fflush(stdout);

//    ft_printf("=%020.10d=", -42000);
//    ft_printf("=%0014.2d==%020d==%0002.d==%000.5d=", (int)-2147483648, 3, 30, -1);
//    ft_printf("=%020.10i=", -42000);
//    ft_printf("=%0014.2i==%020i==%0002.i==%000.5i=", (int)-2147483648, 3, 30, -1);
//    ft_printf("%020d", -42000);
   ft_printf("%030d\n", (int)-2147483648);
   ft_printf("%012d\n", (int)-2147483648);
   ft_printf("%012d, %20d, %2d, %42d\n", (int)-2147483648, 3, 30, -1);
   ft_printf("%012d, %d, %2d, %42d\n", (int)-2147483648, 3, 30, -1);
   ft_printf("%014d%020d%02d%0d\n", (int)-2147483648, 3, 30, -1);
   ft_printf("%014dc%020ds%02dx%0du\n", (int)-2147483648, 3, 30, -1);
   ft_printf("%01.d\n", 0);
   ft_printf("%01.0d\n", 0);
   ft_printf("%02.0d\n", 0);
   ft_printf("%03.0d\n", 0);
//    ft_printf("%042.2d", 42000);
//    ft_printf("%042.20d", 42000);
//    ft_printf("%020.19d is how many tests are going to be made", 8000);
//    ft_printf("%030d", (int)-2147483648);
//    ft_printf("%012d", (int)-2147483648);
//    ft_printf("%012d, %20d, %2d, %000042d", (int)-2147483648, 3, 30, -1);
//    ft_printf("%012d, %d, %002d, %42d", (int)-2147483648, 3, 30, -1);
//    ft_printf("%014dc%020ds%02dx%0du", (int)-2147483648, 3, 30, -1);
//    ft_printf("%020i", -42000);
//    ft_printf("%030i", (int)-2147483648);
//    ft_printf("%012i", (int)-2147483648);
//    ft_printf("%012i, %20i, %2i, %42i", (int)-2147483648, 3, 30, -1);
//    ft_printf("%012i, %i, %2i, %42i", (int)-2147483648, 3, 30, -1);
//    ft_printf("%014i%020i%02i%0i", (int)-2147483648, 3, 30, -1);
//    ft_printf("%014ic%020is%02ix%0iu", (int)-2147483648, 3, 30, -1);
//    ft_printf("%01.i", 0);
//    ft_printf("%01.0i", 0);
//    ft_printf("%02.0i", 0);
//    ft_printf("%03.0i", 0);
//    ft_printf("%042.2i", 42000);
//    ft_printf("%042.20i", 42000);
//    ft_printf("%020.19i is how many tests are going to be made", 8000);
//    ft_printf("%030i", (int)-2147483648);
//    ft_printf("%012i", (int)-2147483648);
//    ft_printf("%012i, %20i, %2i, %000042i", (int)-2147483648, 3, 30, -1);
//    ft_printf("%012i, %i, %002i, %42i", (int)-2147483648, 3, 30, -1);
//    ft_printf("%014ic%020is%02ix%0iu", (int)-2147483648, 3, 30, -1);
}