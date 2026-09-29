/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P51352.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 11:40:05 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/24 12:38:07 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstdlib>
#include <iostream>

int	ft_Elements(char **str)
{
	if (**str == *(*str + 1))
		return (-1);
	if ((**str == 'A' && *(*str + 1) == 'P')
		|| (**str == 'P' && *(*str + 1) == 'V')
		|| (**str == 'V' && *(*str + 1) == 'A'))
		return (1);
	return (0);
}

int	main(void)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) + 1);
	if (!str)
		return (1);
	if (std::cin >> str[0] >> str[1])
	{
		if (ft_Elements(&str) == 1)
			std::cout << "1" << "\n";
		else if (ft_Elements(&str) == 0)
			std::cout << "2" << "\n";
		else
			std::cout << "-" << "\n";
	}
	free(str);
	return (0);
}
