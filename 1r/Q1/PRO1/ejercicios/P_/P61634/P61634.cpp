/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P61634.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:15:51 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/23 17:11:25 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

int	ft_IsLeap(int **y)
{
	while (*(*y))
	{
		if (*(*y) % 100 == 0)
			*(*y) /= 100;
		if (*(*y) % 4 == 0)
			return (1);
		else
			return (0);
		*(*y++);
	}
	return (0);
}

int	main(void)
{
	int	*year;

	year = (int *)malloc(sizeof(*year));
	if (!year)
		return (1);
	if (std::cin >> *year)
	{
		if (ft_IsLeap(&year) == 1)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
	free(year);
	year = nullptr;
	return (0);
}
