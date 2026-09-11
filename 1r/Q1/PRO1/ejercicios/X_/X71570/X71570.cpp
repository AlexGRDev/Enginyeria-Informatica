/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X71570.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 09:52:33 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/11 11:02:04 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	*ft_diff(int *a, int *b)
{
	*a = *a - *b;
	return (a);
}

int	main(void)
{
	int	n;
	int	m;
	int	*result;

	if (std::cin >> n >> m)
	{
		result = ft_diff(&n, &m);
		std::cout << *result << std::endl;
	}
	return (0);
}
