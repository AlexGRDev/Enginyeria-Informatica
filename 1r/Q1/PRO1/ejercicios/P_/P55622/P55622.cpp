/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P55622.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 17:33:51 by agarcia2          #+#    #+#             */
/*   Updated: 2026/10/06 17:43:14 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

size_t	ft_strlen(const char *str)
{
	const char	*pStr;

	pStr = str;
	while (*pStr)
		pStr++;
	return (pStr - str);
}


int	main(void)
{
	char	nbr[256];
	size_t	len;
	std::cin >> nbr;
	len = ft_strlen(nbr);
	std::cout << "The number of digits of " << nbr << " is " << len << "." << "\n";
	return (0);
}
