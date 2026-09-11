/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P42042.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 13:45:24 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/11 13:59:33 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	*ft_strchr(const char *s, int c)
{
	const char	**ptrs;

	ptrs = &s;
	while (*(*ptrs))
	{
		if (*(*ptrs)== (char )c)
			return ((char *)s);
		ptrs++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	ft_chrclasifion(char *c)
{
	const char	*alphaLower;
	const char	*alphaUper;
	const char	*vowel;

	alphaLower = "abcdefghijklmnopqrstuvwxyz";
	alphaUper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vowel = "aeiou";
	if (ft_strchr(alphaLower, *c))
		std::cout << "lowercase" << std::endl;
	else if (ft_strchr(alphaUper, *c))
		std::cout << "uppercase" << std::endl;
	if (ft_strchr(vowel, *c))
		std::cout << "vowel" << std::endl;
	else
		std::cout << "consonant" << std::endl;
}

int	main(void)
{
	char	c;

	if (std::cin >> c)
		ft_chrclasifion(&c);
	return (0);
}
