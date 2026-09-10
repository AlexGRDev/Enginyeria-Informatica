/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 21:31:43 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/10 10:19:44 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

int	sumatori(int **start, int **end)
{
	int	term;

	if (**start > **end)
		return (0);
	term = (double)(pow(-1, *(*start) + 1)) * 2 * *(*start);
	if (term < 0)
		std::cout << "(" << term << ") ";
	else
		std::cout << "+ " << term << " ";
	*(*start) = *(*start) + 1;
	return (term + sumatori(start, end));
}

void	imprimir_notacion_sumatori(int *start, int *end, int (*f)(int **, int **))
{
	int	*pstar;

	pstar = start;
	std::cout << "   " << *end << std::endl;
	std::cout << "    \u2211  (-1)^(i+1)\u00b72i" << std::endl;
	std::cout << "   i=" << *start << std::endl << std::endl;
	f(&pstar, &end);
	std::cout << std::endl;
}

int	main(int ac, char **av)
{
	int	n;
	int	m;

	if (ac < 3)
	{
		std::cout << "Error: Faltan argumentos.\n" << std::endl;
		std::cout << "Uso: " << av[0] << " [n] [m]\n" << std::endl;
		return (1);
	}
	n = std::stoi(av[1]);
	m = std::stoi(av[2]);
	imprimir_notacion_sumatori(&n, &m, &sumatori);
	return (0);
}
