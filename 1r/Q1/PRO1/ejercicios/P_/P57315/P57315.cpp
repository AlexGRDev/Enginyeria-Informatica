/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P57315.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 10:26:12 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/30 07:09:10 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

void	ft_ABC(int **n, char **order)
{
	int		*pN;
	char	*pO;
	int		tmp;

	pN = *n;
	pO = *order;
	while (*pO)
	{
		if (*pN > *(pN + 1))
		{
			tmp = *pN;
			*pN = *(pN + 1);
			*(pN + 1) = tmp;
		}
		if (*(pN + 1) > *(pN + 2))
		{
			tmp = *(pN + 1);
			*(pN + 1) = *(pN + 2);
			*(pN + 2) = tmp;
		}
		if (*pN > *(pN + 1))
		{
			tmp = *pN;
			*pN = *(pN + 1);
			*(pN + 1) = tmp;
		}
		if (*pO == 'A')
			std::cout << *pN;
		else if (*pO == 'B')
			std::cout << *(pN + 1);
		else if (*pO == 'C')
			std::cout << *(pN + 2);
		if (*(pO + 1))
			std::cout << " ";
		pO++;
	}
	std::cout << "\n";
}

int	main(void)
{
	int	arry[3];
	char	ord[4];
	int		*nbr;
	char	*str;

	nbr = arry;
	str = ord;
	if (std::cin >> *nbr >> *(nbr + 1) >> *(nbr + 2) >> *str >> *(str + 1) >> *(str + 2))
	{
		*(str + 3) = '\0';
		ft_ABC(&nbr, &str);
	}
	return (0);
}
