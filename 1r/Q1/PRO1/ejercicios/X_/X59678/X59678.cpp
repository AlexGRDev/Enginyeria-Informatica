/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X59678.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:22:51 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/11 11:09:07 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	*ft_minimum2(int *a, int *b, int *c)
{
	int	*min;

	min = a;
	if (*b < *min)
		min = b;
	if (*c < *min)
		min = c;
	return (min);
}

int	main(void)
{
	int	n;
	int	m;
	int	o;
	int	*result;

	if (std::cin >> n >> m >> o)
	{
		result = ft_minimum2(&n, &m, &o);
		std::cout << *result << std::endl;
	}
	return (0);
}
