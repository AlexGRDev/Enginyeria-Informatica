/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P37469.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:19:24 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/24 11:03:51 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

void	TimeDecompose(int *n, int *h, int *m, int *s)
{
    *h = *n / 3600;
    *m = (*n % 3600) / 60;
    *s = *n % 60;
}

int	main()
{
	int	n;
	int	h;
	int	m;
	int	s;

	if (std::cin >> n)
	{
		TimeDecompose(&n, &h, &m, &s);
		std::cout << h << " " << m << " " << s << std::endl;
	}
	return (0);
}
