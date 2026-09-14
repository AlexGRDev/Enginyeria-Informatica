/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P51126.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 07:14:52 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/14 08:25:05 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	*ft_range(int **arry1, int **arry2)
{
	int	min;
	int	max;
	int	*result;

	min = ft_max(*(*arry1), *(*arry2));
	max = ft_min(*(*arry1 + 1), *(*arry2 + 1));
	result = (int *)malloc(sizeof(int) * 2);
	result[0] = min;
	result[1] = max;
	if (result[0] > result[1])
	{
		std::cout << "[]" << std::endl;
		free(result);
		return (NULL);
	}
	return (result);
}

int	main(void)
{
	int	*arry1;
	int	*arry2;
	int	*range;

	arry1 = (int *)malloc(sizeof(int) * 2);
	arry2 = (int *)malloc(sizeof(int) * 2);
	if (std::cin >> arry1[0] >> arry1[1] >> arry2[0] >> arry2[1])
	{
		range = ft_range(&arry1, &arry2);
		if (range != NULL)
		{
			std::cout << "[" << range[0] << "," << range[1] << "]" << std::endl;
			free(range);
			range = nullptr;
		}
	}
	free(arry1);
	free(arry2);
	arry1 = nullptr;
	arry2 = nullptr;
	return (0);
}
