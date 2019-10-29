/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:38:39 by hbaudet           #+#    #+#             */
/*   Updated: 2019/10/29 09:36:51 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#ifndef STRING
# define STRING "this is a string"
#endif

int	main(int ac, char *av[])
{
	int				i;
	int				c[2][350];
	unsigned int	u = 4147483647;
	char			str[] = STRING;
	int				val;
	unsigned char	ch;
	int				(*ptr)(const char *, ...);

	i = 1;
	(void)ac;
	ch = 0;
	if ((val = ft_atoi(av[1])) == 1)
		ptr = &printf;
	else if (val == 2)
		ptr = &ft_printf;
	if (av[2][0] == '1')
	{
		while (ch < 255)
		{
			if (ch != 10 && ch != 13)
			{
				c[val - 1][i] = ptr("%d\t%%c\t\t\t: |%c|\n", i, ch);
				i++;
			}
			ch++;
		}
	}
	else
	{
		ptr("CHARARCTERS : \n");
		c[val - 1][i] = ptr("%d\t%%-8c\t\t: |%-8c|\n", i, 'g'); i++;
		c[val - 1][i] = ptr("%d\t%%*c\t\t\t: |%*c|\n", i, -4, 'g'); i++;
		c[val - 1][i] = ptr("%d\t%%05c\t\t: |%05c|\n", i, 42); i++;
		ptr("\n\nPOINTERS : \n");
		c[val - 1][i] = ptr("%d\t%%-27p\t\t: |%-27p|\n", i, &u); i++;
		c[val - 1][i] = ptr("%d\t%%-*p\t\t: |%-*p|\n", i, 18, &u); i++;
		c[val - 1][i] = ptr("%d\t%%14p\t\t: |%14p|\n", i, &u); i++;
		c[val - 1][i] = ptr("%d\t%%2p\t\t\t: |%2p|\n", i, &u); i++;
		c[val - 1][i] = ptr("%d\t%%*p\t\t\t: |%*p|\n", i, 18, &u); i++;
		c[val - 1][i] = ptr("%d\t%%p\t\t\t: |%p|\n", i, &u); i++;
		c[val - 1][i] = ptr("%d\t%%023p\t\t: |%023p|\n", i, &u); i++;
		c[val - 1][i] = ptr("%d\t%%24p\t\t: |%24p|\n", i, &u); i++;
		c[val - 1][i] = ptr("%d\t%%-24p\t\t: |%-24p|\n", i, &u); i++;
		c[val - 1][i] = ptr("%d\t%%-023p\t\t: |%-023p|\n", i, &u); i++;
		c[val - 1][i] = ptr("%d\t%%-27p\t\t: |%-27p|\n", i, NULL); i++;
		c[val - 1][i] = ptr("%d\t%%-*p\t\t: |%-*p|\n", i, 18, NULL); i++;
		c[val - 1][i] = ptr("%d\t%%14p\t\t: |%14p|\n", i, NULL); i++;
		c[val - 1][i] = ptr("%d\t%%2p\t\t\t: |%2p|\n", i, NULL); i++;
		c[val - 1][i] = ptr("%d\t%%*p\t\t\t: |%*p|\n", i, 18, NULL); i++;
		c[val - 1][i] = ptr("%d\t%%p\t\t\t: |%p|\n", i, NULL); i++;
		c[val - 1][i] = ptr("%d\t%%023p\t\t: |%023p|\n", i, NULL); i++;
		c[val - 1][i] = ptr("%d\t%%24p\t\t: |%24p|\n", i, NULL); i++;
		c[val - 1][i] = ptr("%d\t%%-24p\t\t: |%-24p|\n", i, NULL); i++;
		c[val - 1][i] = ptr("%d\t%%-023p\t\t: |%-023p|\n", i, NULL); i++;
		ptr("\n\nINTEGERS : \n");
		c[val - 1][i] = ptr("%d\t%%08.3d\t\t: |%08.3d|\n", i, 45); i++;
		c[val - 1][i] = ptr("%d\t%%.*d\t\t: |%.*d|\n", i, 4, 23); i++;
		c[val - 1][i] = ptr("%d\t%%.1d\t\t: |%.1d|\n", i, 17); i++;
		c[val - 1][i] = ptr("%d\t%%8.3d\t\t: |%8.3d|\n", i, 45); i++;
		c[val - 1][i] = ptr("%d\t%%.*d\t\t: |%.*d|\n", i, 4, 789); i++;
		c[val - 1][i] = ptr("%d\t%%05d\t\t: |%05d|\n", i, 2); i++;
		c[val - 1][i] = ptr("%d\t%%00d\t\t: |%00d|\n", i, 78); i++;
		c[val - 1][i] = ptr("%d\t%%0.0d\t\t: |%0.0d|\n", i, 123); i++;
		c[val - 1][i] = ptr("%d\t%%00.0d\t\t: |%00.0d|\n", i, 123); i++;
		c[val - 1][i] = ptr("%d\t%%06.0d\t\t: |%06.0d|\n", i, 42); i++;
		c[val - 1][i] = ptr("%d\t%%6d\t\t\t: |%6d|\n", i, 42); i++;
		c[val - 1][i] = ptr("%d\t%%06d\t\t: |%06d|\n", i, 42); i++;
		c[val - 1][i] = ptr("%d\t%%0d\t\t\t: |%0d|\n", i, 78); i++;
		c[val - 1][i] = ptr("%d\t%%-8d\t\t: |%-8d|\n", i, 123); i++;
		c[val - 1][i] = ptr("%d\t%%06.4d\t\t: |%06.4d|\n", i, 42); i++;
		c[val - 1][i] = ptr("%d\t%%6.4d\t\t: |%6.4d|\n", i, -78); i++;
		c[val - 1][i] = ptr("%d\t%%-8d\t\t: |%-8d|\n", i, -123); i++;
		c[val - 1][i] = ptr("%d\t%%06.4d\t\t: |%06.4d|\n", i, -42); i++;
		c[val - 1][i] = ptr("%d\t%%08.3d\t\t: |%08.3d|\n", i, -45); i++;
		c[val - 1][i] = ptr("%d\t%%.*d\t\t: |%.*d|\n", i, 0, -23); i++;
		c[val - 1][i] = ptr("%d\t%%.1d\t\t: |%.1d|\n", i, -17); i++;
		c[val - 1][i] = ptr("%d\t%%8.3d\t\t: |%8.3d|\n", i, -45); i++;
		c[val - 1][i] = ptr("%d\t%%.*d\t\t: |%.*d|\n", i, -4, -789); i++;
		c[val - 1][i] = ptr("%d\t%%05d\t\t: |%05d|\n", i, -2); i++;
		c[val - 1][i] = ptr("%d\t%%00d\t\t: |%00d|\n", i, -78); i++;
		c[val - 1][i] = ptr("%d\t%%0.0d\t\t: |%0.0d|\n", i, -123); i++;
		c[val - 1][i] = ptr("%d\t%%06.0d\t\t: |%06.0d|\n", i, -42); i++;
		c[val - 1][i] = ptr("%d\t%%0d\t\t\t: |%0d|\n", i, -78); i++;
		c[val - 1][i] = ptr("%d\t%%-8d\t\t: |%-8d|\n", i, -123); i++;
		c[val - 1][i] = ptr("%d\t%%06.4d\t\t: |%06.4d|\n", i, -42); i++;
		c[val - 1][i] = ptr("%d\t%%6.4d\t\t: |%6.4d|\n", i, -78); i++;
		c[val - 1][i] = ptr("%d\t%%-8d\t\t: |%-8d|\n", i, -123); i++;
		c[val - 1][i] = ptr("%d\t%%06.4\t\t: |%06.4d|\n", i, -42); i++;
		c[val - 1][i] = ptr("%d\t%%*.4d\t\t: |%*.4d|\n", i, 6, 2); i++;
		c[val - 1][i] = ptr("%d\t%%08d\t\t: |%08d|\n", i, 4); i++;
		c[val - 1][i] = ptr("%d\t%%d\t\t\t: |%d|\n", i, 2); i++;
		c[val - 1][i] = ptr("%d\t%%010.10d\t: |%010.10d|\n", i, 42); i++;
		c[val - 1][i] = ptr("%d\t%%*.4d\t\t: |%*.4d|\n", i, -6, -2); i++;
		c[val - 1][i] = ptr("%d\t%%08d\t\t: |%08d|\n", i, -4); i++;
		c[val - 1][i] = ptr("%d\t%%d\t\t\t: |%d|\n", i, -2); i++;
		c[val - 1][i] = ptr("%d\t%%010.10d\t\t: |%010.10d|\n", i, -42); i++;
		c[val - 1][i] = ptr("%d\t%%d\t\t\t: |%d|\n", i, 2147483647); i++;
		c[val - 1][i] = ptr("%d\t%%d\t\t\t: |%d|\n", i, -2147483648); i++;
		c[val - 1][i] = ptr("%d\t%%.0d\t\t: |%.0d|\n", i, 0); i++;
		c[val - 1][i] = ptr("%d\t%%.0d\t\t: |%.0d|\n", i, 1); i++;
		c[val - 1][i] = ptr("%d\t%%.1d\t\t: |%.0d|\n", i, 0); i++;
		c[val - 1][i] = ptr("%d\t%%.0\t\t\t: |%.0d|\n", i, 0); i++;
		c[val - 1][i] = ptr("%d\t%%0d\t\t\t: |%0d|\n", i, 0);i++;
		ptr("\n\nUNSIGNED INTS : \n");
		c[val - 1][i] = ptr("%d\t%%.2u\t\t: |%.2u|\n", i, u); i++;
		c[val - 1][i] = ptr("%d\t%%010.10u\t: |%010.10u|\n", i, u); i++;
		c[val - 1][i] = ptr("%d\t%%-10.10u\t: |%-10.10u|\n", i, u); i++;
		c[val - 1][i] = ptr("%d\t%%*.6u\t\t: |%*.6u|\n", i, 4, u); i++;
		c[val - 1][i] = ptr("%d\t%%0*.2u\t\t: |%0*.2u|\n", i, 2, u); i++;
		c[val - 1][i] = ptr("%d\t%%u\t\t\t: |%u|\n", i, 4294967295); i++;
		c[val - 1][i] = ptr("%d\t%%.0u\t\t: |%.0u|\n", i, 0); i++;
		c[val - 1][i] = ptr("%d\t%%2.0u\t\t: |%2.0u|\n", i, 0); i++;
		c[val - 1][i] = ptr("%d\t%%03.0u\t\t: |%03.0u|\n", i, 0); i++;
		c[val - 1][i] = ptr("%d\t%%.0u\t\t: |%.0u|\n", i, 15); i++;
		ptr("\n\nHEXA : \n");
		c[val - 1][i] = ptr("%d	%x\n", i, 2147483647); i++;
		c[val - 1][i] = ptr("%d	%x\n", i, -2147483648); i++;
		c[val - 1][i] = ptr("%d	%X\n", i, 2147483647); i++;
		c[val - 1][i] = ptr("%d	%X\n", i, -2147483648); i++;
		c[val - 1][i] = ptr("%d	%x\n", i, 0); i++;
		c[val - 1][i] = ptr("%d	%010x\n", i, 0); i++;
		c[val - 1][i] = ptr("%d	%010x\n", i, 20); i++;
		c[val - 1][i] = ptr("%d	%010x\n", i, -20); i++;
		c[val - 1][i] = ptr("%d\t%%10x\t\t: |%10x|\n", i, 20); i++;
		c[val - 1][i] = ptr("%d\t%%10.2x\t\t: |%10.2x|\n", i, -20); i++;
		c[val - 1][i] = ptr("%d\t%%10.25x\t\t: |%10.25x|\n", i, -20); i++;
		c[val - 1][i] = ptr("%d\t%%27.25x\t\t: |%27.25x|\n", i, -20); i++;
		c[val - 1][i] = ptr("%d	%-10x\n", i, 50); i++;
		c[val - 1][i] = ptr("%d	%-15x\n", i, 0); i++;
		c[val - 1][i] = ptr("%d	%.1x\n", i, 500); i++;
		c[val - 1][i] = ptr("%d	%*.*x\n", i, 50, 10, 2); i++;
		c[val - 1][i] = ptr("%d	%x\n", i, -1); i++;
		c[val - 1][i] = ptr("%d\t%%8.4x\t\t: |%8.4x|\n", i, 2); i++;
		c[val - 1][i] = ptr("%d\t%%8.4x\t\t: |%8.4x|\n", i, 0); i++;
		c[val - 1][i] = ptr("%d\thexa \t\t: |%.0x|\n", i, 0); i++;
		c[val - 1][i] = ptr("%d\t%%.2x\t\t: |%.0x|\n", i, 0); i++;
		c[val - 1][i] = ptr("%d\thexa \t\t: |%.0x|\n", i, 0); i++;
		c[val - 1][i] = ptr("%d\thexa \t\t: |%.15x|\t\t\t%% |%10X|\n", i, u, u); i++;
		c[val - 1][i] = ptr("%d\thexa \t\t: |%-10x|\t\t\t\t%% |%20.15X|\n", i, u, u); i++;
		c[val - 1][i] = ptr("%d\thexa \t\t: |%-20.15x|\t%% |%020.15X|\n", i, u, u); i++;
		c[val - 1][i] = ptr("%d\t%%.0x\t\t: |%.0x|\n", i, 100); i++;
		c[val - 1][i] = ptr("%d\t%%2.0x\t\t: |%2.0x|\n", i, 100); i++;
		c[val - 1][i] = ptr("%d\t%%03.0x\t\t: |%03.0x|\n", i, 100); i++;
		c[val - 1][i] = ptr("%d\t%%.0x\t\t: |%.0x|\n", i, 0); i++;
		c[val - 1][i] = ptr("%d\t%%2.0x\t\t: |%2.0x|\n", i, 0); i++;
		c[val - 1][i] = ptr("%d\t%%03.0x\t\t: |%03.0x|\n", i, 0); i++;
		ptr("\n\nSTRINGS : \n");
		c[val - 1][i] = ptr("%d\t%%.4s\t\t: |%.4s|\n", i, NULL); i++;
		c[val - 1][i] = ptr("%d\t%%.*s\t\t: |%.*s|\n", i, 8, str); i++;
		c[val - 1][i] = ptr("%d\t%%25s\t\t: |%25s|\n", i, str); i++;
		c[val - 1][i] = ptr("%d\t%%-24.4s\t\t: |%-25.4s|\n", i, str); i++;
		c[val - 1][i] = ptr("%d\t%%-24s\t\t: |%-25s|\n", i, str); i++;
		c[val - 1][i] = ptr("%d\t%%25.0s\t\t: |%25.0s|\n", i, str); i++;
		c[val - 1][i] = ptr("%d\t%%.0s\t\t: |%.0s|\n", i, str); i++;
		c[val - 1][i] = ptr("%d\t%%*s\t\t\t: |%*s|\n", i, 0, str); i++;
		c[val - 1][i] = ptr("%d\t%%-*s\t\t: |%-*s|\n", i, 0, str); i++;
		c[val - 1][i] = ptr("%d\t%%010s\t\t: |%010s| is a string\n", i, "this"); i++;
		c[val - 1][i] = ptr("%d\t%%-010s\t\t: |%-010s| is a string\n", i, "this"); i++;
		c[val - 1][i] = ptr("%d\t%%-010s\t\t: |%-010s| is a &u string\n", i, NULL); i++;
		c[val - 1][i] = ptr("%d\t%%s\t\t\t: Hello 42 school! |%s|\n", i, NULL); i++;
		ptr("\n\n%% : \n");
		c[val - 1][i] = ptr("%d\t%%5%%\t\t\t: |%5%|\n", i); i++;
		c[val - 1][i] = ptr("%d\t%%-5%%\t\t: |%-5%|\n", i); i++;
		c[val - 1][i] = ptr("%d\t%%05%%\t\t: |%05%|\n", i); i++;
		c[val - 1][i] = ptr("%d\t%%-05%%\t\t: |%-05%|\n", i); i++;
		c[val - 1][i] = ptr("%d\t%%%%%%\t\t\t: |%%%|\n", i, "test"); i++;
		c[val - 1][i] = ptr("%d\t%%010%%\t\t: |%010%|\n", i); i++;
		c[val - 1][i] = ptr("%d\t%%\t\t\t: |%|\n", i); i++;
		c[val - 1][i] = ptr("%d\t%%012%%\t\t: |%012%\n", i); i++;
		c[val - 1][i] = ptr("%d\t%%12%%\t\t\t: |%12%|\n", i); i++;
		c[val - 1][i] = ptr("%d\t%%-12%%\t\t: |%-12%| \n", i); i++;
		c[val - 1][i] = ptr("%d\t%%0%%\t\t\t: |%0%|\n", i); i++;
	}
#ifdef BONUS
	ptr("\n\n\033[1;34mBONUS\n");
	c[val - 1][i] = ptr("%d\t%%\t\t\t: |%   %|\n", i); i++;
	c[val - 1][i] = ptr("%d\t%%\t\t\t: |%%   %|\n", i, "test"); i++;
	c[val - 1][i] = ptr("%d\t%%\t\t\t: |%0 d|\n", i, 42); i++;
	c[val - 1][i] = ptr("%d\t%%\t\t\t: |%000   %|\n", i, "test"); i++;
	c[val - 1][i] = ptr("%d\n", c[val - 1][i] = ptr("02 This is a float : %.3f\n\n", 45.236)); i++;
	c[val - 1][i] = ptr("%d\n",   c[val - 1][i] = ptr("01 This is a float : %3f\n\n", 45.236)); i++;
	c[val - 1][i] = ptr("%d\n", c[val - 1][i] = ptr("000 This is a float : %f\n\n", -45.236)); i++;
	c[val - 1][i] = ptr("%d\n", c[val - 1][i] = ptr("0 This is a float : %.3f\n\n", -45.236)); i++;
	c[val - 1][i] = ptr("%d\n", c[val - 1][i] = ptr("00 This is a float : %3f\n\n", -45.236)); i++;
	c[val - 1][i] = ptr("1 This is a float : %f\n\n", 0.00025); i++;
	c[val - 1][i] = ptr("2 This is a float : %.3f\n\n", 0.00025); i++;
	c[val - 1][i] = ptr("3 This is a float : %3f\n\n", 0.00025); i++;
	c[val - 1][i] = ptr("4 This is a float : %f\n\n", -0.00025); i++;
	c[val - 1][i] = ptr("5 This is a float : %f\n\n", -0.00025); i++;
	c[val - 1][i] = ptr("6 This is a float : %.3f\n\n", -0.00025); i++;
	c[val - 1][i] = ptr("7 This is a float : %3f\n\n", -0.00025); i++;
	c[val - 1][i] = ptr("8 This is a float : %3f\n\n", 1.0 / 0.0); i++;
	c[val - 1][i] = ptr("9 This is a float : %3f\n\n", -1.0 / 0.0); i++;
	c[val - 1][i] = ptr("10 This is a float : %3f\n\n", 0.0 / 0.0); i++;
	c[val - 1][i] = ptr("11 This is a float : %3f\n\n", -0.0 / 0.0); i++;
	c[val - 1][i] = ptr("12 This is a float : %.0f\n\n", 2.5); i++;
	c[val - 1][i] = ptr("13 This is a float : %.0f\n\n", 3.5); i++;
	c[val - 1][i] = ptr("14 This is a float : %.0f\n\n", -2.5); i++;
	c[val - 1][i] = ptr("15 This is a float : %.0f\n\n", -3.5); i++;
	c[val - 1][i] = ptr("16 This is a float : %.0f\n\n", 2.51); i++;
	c[val - 1][i] = ptr("17 This is a float : %.0f\n\n", 3.51); i++;
	c[val - 1][i] = ptr("18 This is a float : %10.0f\n\n", -2.51); i++;
	c[val - 1][i] = ptr("19 This is a float : %10.0f\n\n", -3.51); i++;
	c[val - 1][i] = ptr("20 This is a float : %10.5f\n\n", -2.51); i++;
	c[val - 1][i] = ptr("21 This is a float : %10.5f\n\n", -3.51); i++;
	c[val - 1][i] = ptr("22 This is a float : %10.5f\n\n", 2.51); i++;
	c[val - 1][i] = ptr("23 This is a float : %10.5f\n\n", 3.51); i++;
	c[val - 1][i] = ptr("24 This is a float : %10.0f\n\n", 2.51); i++;
	c[val - 1][i] = ptr("25 This is a float : %10.0f\n\n", 3.51); i++;
	c[val - 1][i] = ptr("26 This is a float : %010f\n\n", 2.51); i++;
	c[val - 1][i] = ptr("27 This is a float : %-10f\n\n", 3.51); i++;
	c[val - 1][i] = ptr("28 This is a float : %015f\n\n", 2.51); i++;
	c[val - 1][i] = ptr("29 This is a float : %15f\n\n", 3.51); i++;
	c[val - 1][i] = ptr("30 This is a float : %.0f\n\n", 0.0); i++;
	ptr("\033[0m");
#endif

	ptr("\n\nRETURN VALUES :\n");
	for (int p = 1; p < i ; p++)
		ptr("%d\t: %d\n", p, c[val - 1][p]);
	return (0);
}
