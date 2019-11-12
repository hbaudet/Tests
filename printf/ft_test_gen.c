/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_gen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:39:50 by hbaudet           #+#    #+#             */
/*   Updated: 2019/11/12 16:27:13 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
    int j;
    int k;

//
// NARMOL
//

  j = -16;
    while (j < 16)
    {
        if (j)
            printf("\t\tc[i] = ptr(\"%%d\\t%%%%%ds\\t\\t\\t: |%%%ds|\\n\", i, \"Hello World!\"); i++;\n", j, j);
        j++;
    }
    j = -16;
    while (j < 16)
    {
        k = 0;
        while (k < 16)
        {
            if (j)
                printf("\t\tc[i] = ptr(\"%%d\\t%%%%%d.%ds\\t\\t\\t: |%%%d.%ds|\\n\", i, \"Hello World!\"); i++;\n", j, k, j, k);
            k++;
        }
        j++;
    }
    j = -16;
    while (j < 16)
    {
        k = 0;
        while (k < 16)
        {
            if (j)
                printf("\t\tc[i] = ptr(\"%%d\\t%%%%*.*s\\t\\t\\t: |%%*.*s|\\n\", i, %d, %d, \"Hello World!\"); i++;\n", j, k);
            k++;
        }
        j++;
    }

//
//  NULL
//

    j = -16;
    while (j < 16)
    {
        if (j)
            printf("\t\tc[i] = ptr(\"%%d\\t%%%%%ds\\t\\t\\t: |%%%ds|\\n\", i, NULL); i++;\n", j, j);
        j++;
    }
    j = -16;
    while (j < 16)
    {
        k = 0;
        while (k < 16)
        {
            if (j)
                printf("\t\tc[i] = ptr(\"%%d\\t%%%%%d.%ds\\t\\t\\t: |%%%d.%ds|\\n\", i, NULL); i++;\n", j, k, j, k);
            k++;
        }
        j++;
    }
    j = -16;
    while (j < 16)
    {
        k = 0;
        while (k < 16)
        {
            if (j)
                printf("\t\tc[i] = ptr(\"%%d\\t%%%%*.*s\\t\\t\\t: |%%*.*s|\\n\", i, %d, %d, NULL); i++;\n", j, k);
            k++;
        }
        j++;
    }
    
//
// MINUS
//    

    j = -16;
    while (j < 16)
    {
        k = 0;
        while (k < 16)
        {
            if (j)
                printf("\t\tc[i] = ptr(\"%%d\\t%%%%-*.*s\\t\\t\\t: |%%-*.*s|\\n\", i, %d, %d, \"Hello World!\"); i++;\n", j, k);
            k++;
        }
        j++;
    }

//
// MINUS - NULL
//    

  
    j = -16;
    while (j < 16)
    {
        k = 0;
        while (k < 16)
        {
            if (j)
                printf("\t\tc[i] = ptr(\"%%d\\t%%%%-*.*s\\t\\t\\t: |%%-*.*s|\\n\", i, %d, %d, NULL); i++;\n", j, k);
            k++;
        }
        j++;
    }
    /*printf("%-25s\n", "salut");
    printf("%*s\n", -25, "salut");
    printf("%-25.2s\n", "salut");
    printf("%25.2s\n", "salut");
    printf("%-*.*s\n", -25, -2, "salut");*/
}