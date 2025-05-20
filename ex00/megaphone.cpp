/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:38:19 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/20 14:46:54 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

int	main(int argc, char *argv[])
{
	int		i;
	int 	y;
	char	*tmp;

	//No argument given
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	
	//loop through arguments
	i = 1;
	while (i < argc)
	{
		y = 0;
		tmp = argv[i];
		while (tmp[y] != '\0')
		{
			std::cout << ft_toupper(tmp[y]);
			y++;
		}
		i++;
	}
	std::cout << std::endl;
	return 0;			
}