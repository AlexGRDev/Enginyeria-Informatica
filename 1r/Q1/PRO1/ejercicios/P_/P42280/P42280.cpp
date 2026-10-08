/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P42280.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 18:12:01 by agarcia2          #+#    #+#             */
/*   Updated: 2026/10/07 08:49:20 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
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

int    main(void)
{
	int	r;
	int	c;
	char	ch;
	char	buff[256];
	int    result;
	int    i;

	std::cin >> r >> c;
	result = 0;
	while (r > 0)
	{
		i = 0;
		while (i < c)
		{
			std::cin >> ch;
			ft_memcpy(buff, &ch, 1);
			result += buff[0] - '0';
			i++;
		}
		r--;
	}
	std::cout << result << "\n";
}
