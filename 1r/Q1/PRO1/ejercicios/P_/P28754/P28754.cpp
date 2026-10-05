/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P28754.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 14:24:14 by agarcia2          #+#    #+#             */
/*   Updated: 2026/10/03 15:04:55 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

unsigned int	reverse_bits(unsigned int octet, int len)
{
	unsigned int	*pOctet;
	unsigned int	bit;
	int				i;

	pOctet = &octet;
	bit = 0;
	i = len;
	while (i--)
	{
		bit = (bit << 1) | (*pOctet & 1);
		*pOctet >>= 1;
	}
	return (bit);
}

void	print_bits(unsigned int octet, int len)
{
	unsigned int	*poctet;
	unsigned int	mask;
	char			c;

	poctet = &octet;
	mask = 1u << (len - 1);
	while (mask > 0)
	{
		if (*poctet & mask)
			c = '1';
		else
			c = '0';
		std::cout << c;
		mask >>= 1;
	}
	return ;
}

int	main(void)
{
	unsigned int	bit;
	unsigned int	rev;
	unsigned int	tmp;
	int				len;

	if (std::cin >> bit)
	{
		tmp = bit;
		len = 0;
		while (tmp > 0)
		{
			len++;
			tmp >>= 1;
		}
		if (len == 0)
			len = 1;
		rev = reverse_bits(bit, len);
		print_bits(rev, len);
		std::cout << "\n";
	}
	return (0);
}
