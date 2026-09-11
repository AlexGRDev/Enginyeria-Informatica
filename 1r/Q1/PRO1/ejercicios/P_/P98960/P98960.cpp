/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P98960.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 11:50:01 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/11 11:59:39 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

int ft_convert(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	*a;

	a = (char *)malloc(sizeof(char));
	if (std::cin >> *a)
	{
		*a = ft_convert(*a);
		std::cout << *a << std::endl;
		free(a);
		a = nullptr;
	}
	return (0);
}
