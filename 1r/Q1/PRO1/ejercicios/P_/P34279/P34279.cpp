/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P34279.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:54:44 by agarcia2          #+#    #+#             */
/*   Updated: 2026/09/21 12:59:25 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

int	main(void)
{
	int	*a;
	int	*ptr;
	int	*end;

	a = (int *)malloc(sizeof(int) * 3);
	if (std::cin >> a[0] >> a[1] >> a[2])
	{
		a[2]++;
		if (a[2] == 60)
		{
			a[2] = 0;
			a[1]++;
			if (a[1] == 60)
			{
				a[1] = 0;
				a[0]++;
				if (a[0] == 24)
				{
					a[0] = 0;
				}
			}
		}
		ptr = a;
		end = a + 3;
		while (ptr < end)
		{
			if (*ptr < 10)
				std::cout << "0";
			std::cout << *ptr;
			if (ptr < end - 1)
				std::cout << ":";
			else
				std::cout << std::endl;

			ptr++;
		}
	}
	free(a);
	a = nullptr;
	return (0);
}
