/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P57315.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 10:26:12 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/29 07:10:43 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	int	valores[3];
	char	orden[3];
	int	*v;
	char	*o;

	v = valores;
	while (v != valores + 3)
	{
		std::cin >> *v;
		v++;
	}
	o = orden;
	while (o != orden + 3)
	{
		std::cin >> *o;
		o++;
	}
	o = orden;
	while (o != orden + 3)
	{
		std::cout << *(valores + (*o - 'A'));
		o++;
		if (o != orden + 3)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
