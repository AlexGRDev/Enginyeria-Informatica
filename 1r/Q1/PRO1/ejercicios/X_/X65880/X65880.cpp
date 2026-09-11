/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X65880.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 11:35:30 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/11 11:48:02 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

int	main(void)
{
	char	*a;

	a = (char *)malloc(sizeof(char));
	if (std::cin >> *a)
	{
		if (*a >= 'A' && *a <= 'Z')
			std::cout << "Uppercase letter" << std::endl;
		else if (*a >= 'a' && *a <= 'z')
			std::cout << "Lowercase letter" << std::endl;
		else if (*a >= '0' && *a <= '9')
			std::cout << "Number" << std::endl;
		free(a);
		a = nullptr;
	}
	return (0);
}
