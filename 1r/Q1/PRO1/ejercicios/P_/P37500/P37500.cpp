/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P37500.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 07:34:43 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/30 07:59:07 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	ft_firstnbr(int **len)
{
	int	i;

	i = 0;
	while (i <= **len)
		std::cout << i++ << "\n";
}

int	main(void)
{
	int	nbr;
	int	*pNbr;

	pNbr = &nbr;
	if (std::cin >> *pNbr)
		ft_firstnbr(&pNbr);
	return (0);
}
