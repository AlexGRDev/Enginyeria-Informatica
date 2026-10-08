/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X50286.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 16:32:51 by agarcia2          #+#    #+#             */
/*   Updated: 2026/10/07 18:18:08 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pDst;
	const unsigned char	*pSrc;

	pDst = (unsigned char *)dst;
	pSrc = (const unsigned char *)src;
	while (n--)
		*pDst++ = *pSrc++;
	return (dst);
}

int	ft_search(char *str, char  *to_search)
{
	char	*pStr;
	char	*pTo_search;
	char	*pAux;
	int	flag;

	pStr =  str;
	flag = 0;
	while (*pStr)
	{
		pTo_search = to_search;
		pAux = pStr;
		while (*pTo_search && *pAux == *pTo_search)
		{
			pTo_search++;
			pAux++;
		}
		if (!*pTo_search && (*pAux == ' ' || !*pAux)
			&& (pStr == str || *(pStr - 1) == ' '))
			flag++;
		pStr++;
	}
	return (flag);
}

int	main(void)
{
	char	buff[34] = "";
	char	cpy[34];
	char	*str;
	int	total;

	total = 0;
	str = cpy;
	std::cin >> buff;
	ft_memcpy(str, &buff, 34);
	total = ft_search(str, (char *)"hello");
	std::cout << total << "\n";
	return (0);
}
