/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   U43326.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 07:44:47 by agarcia2          #+#    #+#             */
/*   Updated: 2026/10/27 07:44:47 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
   * PRE:  Dos enters $x \geq 0$ i $y \geq 0$.
   * POST: La diferència entre $x$ i $y$.
*/

int	diferencia(int x, int y)
{
	if (x < 10 && y < 10)
	{
		if (x > y)
			return (x - y);
		return (y - x);
	}
	return (diferencia(x % 10, y % 10) + diferencia(x / 10, y / 10));
}

int	main(void)
{
	int	a,b;

	while (std::cin >> a >> b)
		std::cout << diferencia(a, b) << '\n';
	return (0);
}