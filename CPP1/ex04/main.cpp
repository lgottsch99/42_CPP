/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:25:42 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/30 15:40:06 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

// https://www.geeksforgeeks.org/file-handling-c-classes/
//std::string.replace FORBIDDEN

/*
fstream can read + write to a file
*/


bool check_success(std::fstream& stream, std::string name)
{
	if (!stream.is_open())
	{
		std::cout << "Error: cannot open file " << name << std::endl;
		return false;
	}
	std::cout << "opening " << name << " succesfull!\n";
	return true;
}

// ./a.out filename s1 s2
int main(int argc, char *argv[])
{
	std::fstream fs;
	std::fstream newfile;
	std::string new_file_name;
	
	//check input valid
	if (argc != 4)
	{
		std::cout << "Usage: <filename> <str1> <str2>\n";
		return 1;
	}

	//open input file
	fs.open(argv[1]);
	//check if successful opening
	if (!check_success(fs, "fs"))
		return 1;

	//open output file 
	new_file_name = argv[1];
	new_file_name.append(".replace");
	
	newfile.open(new_file_name.c_str());
	if (!check_success(newfile, "newfile"))
		return 1;

	//copy its content into new file
	//replacing every occurence of s1 with s2 
std::string var;
	fs >> var;
	newfile << var;



	
	return 0;
}