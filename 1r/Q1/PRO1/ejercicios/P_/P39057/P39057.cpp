/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P39057.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-08 05:49:57 by agarcia2          #+#    #+#             */
/*   Updated: 2026-10-08 05:49:57 by agarcia2         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cmath>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
        unsigned char           *pDst;
        const unsigned char     *pSrc;

        pDst = (unsigned char *)dst;
        pSrc = (const unsigned char *)src;
        while (n--)
                *pDst++ = *pSrc++;
        return (dst);
}

void    rectangle(double **higth, double **withd)
{
        std::cin >> **higth >> **withd;
        std::cout << **higth * **withd << std::endl;
}

void    circle(double **higth)
{
        std::cin >> **higth;
        std::cout << M_PI * **higth * **higth << std::endl;
}

void    ft_controller(char **str, double *higth, double *withd)
{
        char    **pStr;

        pStr = str;
        while (*(*pStr))
        {
                if (*pStr == (std::string)"rectangle")
                        return (rectangle(&higth, &withd));
                else if (*pStr == (std::string)"circle")
                        return (circle(&higth));
                pStr++;
        }
}

int     main(void)
{
        int     nbr;
        char    buff[34];
        char    cpy[34];
        char    *str;
        double  higth;
        double  withd;

        str = cpy;
        std::cout << std::fixed << std::setprecision(6);
        std::cin >> nbr;
        while (nbr--)
        {
                std::cin >> buff;
                ft_memcpy(str, &buff, 34);
                ft_controller(&str, &higth, &withd);
        }
        return (0);
}