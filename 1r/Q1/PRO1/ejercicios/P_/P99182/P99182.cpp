/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P99182.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 18:24:55 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/11 11:34:02 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

float	*ft_average(int *a, int *b)
{
	float	*res;

	res = (float *)malloc(sizeof(float));
	*res = (float)(*a + *b) / 2.0f;
	return (res);
}

int	main(void)
{
	int	n;
	int	m;
	float	*reesult;

	if (std::cin >> n >> m)
	{
		reesult = ft_average(&n, &m);
		std::cout << *reesult << std::endl;
		free(reesult);
		reesult = nullptr;
	}
	return (0);
}
