/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P59875.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:04:58 by agarcia2          #+#    #+#             */
/*   Updated: 2026/10/03 12:30:27 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	ft_min(int *a, int *b)
{
	if (*b < *a)
		return (*b);
	return (*a);
}

int	ft_max(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

int	main(void)
{
	int	nbr[2];
	int	i;
	int	*pNbr;

	pNbr = nbr;
	if (std::cin >> *pNbr >> *(pNbr + 1))
	{
		i = ft_max(*pNbr, *(pNbr + 1));
		while (i >= ft_min(&nbr[0], &nbr[1]))
			std::cout << i-- << "\n";
	}
	return (0);
}
