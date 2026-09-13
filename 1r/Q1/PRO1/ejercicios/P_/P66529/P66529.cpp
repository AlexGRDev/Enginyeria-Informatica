/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P66529.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 10:47:06 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/13 11:58:11 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

void	TAECalculator(float **interest, int *(*f)(char **), char **frequency)
{
	int	*periods;
	float	*result;
	float	tae;

	result = (float *)malloc(sizeof(float));
	periods = f(frequency);
	*result = (**interest / 100) / *periods;
	tae = (std::pow(1.0 + *result, *periods) - 1.0) * 100.0;
	std::cout.setf(std::ios::fixed);
	std::cout.precision(4);
	std::cout << tae << std::endl;
	free(result);
	free(periods);
	result = nullptr;
	periods = nullptr;
}

int	*ConverToYears(char **frequency)
{
	int	*periods;

	periods = (int *)malloc(sizeof(int));
	if (std::string(*frequency) == "setmanal")
		*periods = 52;
	else if (std::string(*frequency) == "mensual")
		*periods = 12;
	else if (std::string(*frequency) == "trimestral")
		*periods = 4;
	else if (std::string(*frequency) == "semestral")
		*periods = 2;
	else
		*periods = 0;
	return (periods);
}

int	main(void)
{
	float	*interest;
	char	*frequency;

	interest = (float *)malloc(sizeof(float));
	frequency = (char *)malloc(sizeof(std::string) + 1);
	if (std::cin >> *interest >> frequency)
	{
		TAECalculator(&interest, ConverToYears, &frequency);
		free(interest);
		free(frequency);
		interest = nullptr;
		frequency = nullptr;
	}
	return (0);
}
