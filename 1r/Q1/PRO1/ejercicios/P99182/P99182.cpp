/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P99182.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 18:24:55 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/10 18:38:42 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

float	promedio(float *a, float *b)
{
	return ((*a + *b) / 2);
}

int	main(void)
{
	float	a;
	float	b;
	float	reesult;

	if (std::cin >> a >> b)
	{
		reesult = promedio(&a, &b);
		std::cout << reesult << std::endl;
	}
	return (0);
}
