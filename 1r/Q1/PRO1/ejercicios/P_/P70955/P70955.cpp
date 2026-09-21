/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P70955.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 17:39:47 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/21 11:52:38 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

int	*ft_getSeconds(int **arry)
{
	int	*parry;
	int	*multipliers;
	int	*end;
	int	*total;

	total = (int *)malloc(sizeof(int));
	multipliers = (int *)malloc(sizeof(int) * 5);
	if (!total || !multipliers)
		return (nullptr);
	multipliers[0] = 365 * 24 * 3600;
	multipliers[1] = 24 * 3600;
	multipliers[2] = 3600;
	multipliers[3] = 60;
	multipliers[4] = 1;
	*total = 0;
	parry = *arry;
	end = multipliers + 5;
	while (multipliers < end)
	{
		*total += *parry * *multipliers;
		parry++;
		multipliers++;
	}
	return (total);
}

int	main(void)
{
	int	*a;
	int	*result;

	a = (int *)malloc(sizeof(int) * 5);
	if (!a)
		return (1);
	if (std::cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4])
	{
		result = ft_getSeconds(&a);
		if (result != nullptr)
		{
			std::cout << *result << std::endl;
			free(result);
			result = nullptr;
		}
	}
	free(a);
	a = nullptr;
	return (0);
}
