/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X89070.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 11:11:27 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/11 11:30:33 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

int	*ft_sum(int **a, int **b)
{
	int	*result;

	result = (int *)malloc(sizeof(int));
	*result = *(*a) + *(*b);
	return (result);
}

int	*ft_minimum(int *a, int *b, int *c)
{
	int	*min;
	int	*max;

	min = a;
	max = a;
	if (*b < *min)
		min = b;
	if (*c < *min)
		min = c;
	if (*b > *max)
		max = b;
	if (*c > *max)
		max = c;
	return (ft_sum(&min, &max));
}

int	main(void)
{
	int	n;
	int	m;
	int	o;
	int	*result;

	if (std::cin >> n >> m >> o)
	{
		result = ft_minimum(&n, &m, &o);
		std::cout << *result << std::endl;
		free(result);
		result = nullptr;
	}
	return (0);
}
