/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P60816.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 17:10:52 by agarcia2          #+#    #+#             */
/*   Updated: 2026/10/06 17:30:34 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	ft_ConvertBase(int *n)
{
	int		**pN;
	char	*pBase;
	char	base[17] = "0123456789ABCDEF";
	int		rem;

	pN = &n;
	if (*(*pN) == 0)
		std::cout << '0';
	while (*(*pN) != 0)
	{
		pBase = base;
		rem = *(*pN) % 16;
		if (rem < 0)
			rem = -rem;
		while (rem > 0)
		{
			pBase++;
			rem--;
		}
		std::cout << *pBase;
		*(*pN) /= 16;
	}
	std::cout << '\n';
}

int	main(void)
{
	int	nbr;

	std::cin >> nbr;
	ft_ConvertBase(&nbr);
	return (0);
}
