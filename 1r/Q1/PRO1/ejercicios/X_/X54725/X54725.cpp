/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X54725.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:02:54 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/11 10:51:40 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	*ft_minimum(int *a, int *b)
{
	int	*min;

	min = a;
	if (*b < *min)
		min = b;
	return (min);
}

int	main(void)
{
	int	n;
	int	m;
	int	*result;

	if (std::cin >> n >> m)
	{
		result = ft_minimum(&n, &m);
		std::cout << *result << std::endl;
	}
	return (0);
}
