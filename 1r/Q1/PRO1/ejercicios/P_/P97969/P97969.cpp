/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P97969.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:34:13 by agarcia2          #+#    #+#             */
/*   Updated: 2026/10/03 13:36:07 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>

char	*ft_strchr(const char *s, int c)
{
	const char	*pStr;

	pStr = s;
	while (*pStr)
	{
		if (*pStr == (char)c)
			return ((char *)pStr);
		pStr++;
	}
	if ((char)c == '\0')
		return ((char *)pStr);
	return (NULL);
}

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

int	main(void)
{
	int		i;
	char	buff[32];
	char	cpy[32];
	char	*str;
	char	*pBuff;

	pBuff = buff;
	str = cpy;
	i = 0;
	if(std::cin >> *pBuff)
	{
		while (*pBuff)
		{
			ft_memcpy(str, pBuff, 1);
			if (*str == '.')
				break ;
			if (ft_strchr("a", *str))
				i++;
			if (!(std::cin >> *pBuff))
				break ;
		}
		std::cout << i << std::endl;
	}
	return (0);
}
