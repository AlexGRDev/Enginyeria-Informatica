/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P74398.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 09:13:27 by agarcia2          #+#    #+#             */
/*   Updated: 2026/10/07 09:13:29 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int     main(int ac, char **av)
{
	char	buff[256];
	char	*t;
	int		k;
	int		base;
	int		n;
	int		digits;

	*buff = '\0';
	if (ac > 1)
		t = *(av + 1);
	else
	{
		std::cin >> buff;
		t = buff;
	}
	k = 0;
	while (*t)
	{
		k = k * 10 + (*t - '0');
		t++;
	}
	base = 2;
	while (base <= 16)
	{
		n = k;
		digits = 0;
		while (n > 0)
		{
			n /= base;
			digits++;
		}
		std::cout << "Base " << base << ": " << digits << " cifras.\n";
		base++;
	}
}