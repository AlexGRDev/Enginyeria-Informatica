/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P50327.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 09:26:29 by agarcia2          #+#    #+#             */
/*   Updated: 2026/10/07 09:26:42 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int     main(int ac, char **av)
{
	char	buff[256];
	char	*t;
	char	*s;

	*buff = '\0';
	if (ac > 1)
		t = *(av + 1);
	else
	{
		std::cin >> buff;
		t = buff;
	}
	s = t;
	while (*t)
		t++;
	while (t != s)
	{
		t--;
		std::cout << *t;
	}
	std::cout << "\n";
}
