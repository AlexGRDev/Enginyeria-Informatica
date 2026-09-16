/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P97156.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:12:33 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/15 17:56:01 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	ft_interval(int *a, int *b)
{
	int	min;
	int	max;

	min = *a;
	max = *b;
	while (min <= max)
	{
		if (min > max)
			break ;
		if (min != *a)
			std::cout << ",";
		std::cout << min;
		min++;
	}
}

int	main(void)
{
	int	a;
	int	b;

	if (std::cin >> a >> b)
		ft_interval(&a, &b);
	std::cout << "\n";
	return (0);
}
