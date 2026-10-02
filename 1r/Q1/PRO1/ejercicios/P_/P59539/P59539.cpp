/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P59539.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 12:01:58 by agarcia2          #+#    #+#             */
/*   Updated: 2026/10/01 09:00:09 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

double	ft_harmonic(int *nbr)
{
	int		i;
	double	h;

	i = 1;
	h = 0;
	while (i <= *nbr)
		h += 1.0 / i++;
	return (h);
}

int	main(void)
{
	int		n;
	int		r;
	int		d;
	double	res;
	int		*pN;

	pN = &n;
	if (std::cin >> *pN)
	{
		res = ft_harmonic(&n);
		r = (int)(res * 10000 + 0.5);
		std::cout << r / 10000 << ".";
		d = 1000;
		while (d)
		{
			std::cout << r / d % 10;
			d /= 10;
		}
		std::cout << "\n";
	}
	return (0);
}
