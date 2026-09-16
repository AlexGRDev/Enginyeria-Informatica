/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P48107.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:34:58 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/16 17:33:18 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

void	ft_div(int *a, int *b)
{
	int	*div;
	int	*mod;

	div = (int *)malloc(sizeof(int));
	mod = (int *)malloc(sizeof(int));

	*div = *a / *b;
	*mod = *a % *b;
	if (!mod)
		std::cout << *div << " " << *mod << std::endl;
	else
		std::cout << *div << " " << *mod << std::endl;
	free(div);
	free(mod);
	div = nullptr;
	mod = nullptr;

}

int	main(void)
{
	int	a;
	int	b;

	if (std::cin >> a >> b)
		ft_div(&a, &b);
	return (0);
}
