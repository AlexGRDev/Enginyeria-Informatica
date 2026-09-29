/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P34279.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:54:44 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/23 16:14:10 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

int	ft_addOnSecond(int **satrt, int **pos)
{
	if (**pos == 60)
	{
		**pos = 0;
		return (1);
	}
	else if (*pos == *satrt && **pos == 24)
		**pos = 0;
	return (0);
}

void	ft_printTime(int *arry, int *pArry)
{
	arry = pArry;
	while (pArry < arry + 3)
	{
		if (*pArry < 10)
			std::cout << "0";
		std::cout << *pArry;
		if (pArry < arry + 2)
			std::cout << ":";
		else
			std::cout << std::endl;
		pArry++;
	}
}

int	main(void)
{
	int	*arry;
	int	*pArry;

	arry = (int *)malloc(sizeof(*arry) * 3);
	if (!arry)
		return (1);
	if (std::cin >> arry[0] >> arry[1] >> arry[2])
	{
		pArry = arry;
		pArry[2]++;
		arry = pArry + 3;
		while (arry > pArry)
		{
			arry--;
			if (ft_addOnSecond(&pArry, &arry) && arry > pArry)
				(*(arry - 1))++;
			else
				break ;
		}
		arry = pArry;
		ft_printTime(arry, pArry);
	}
	free(arry);
	arry = nullptr;
	return (0);
}
