/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:25:42 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/31 13:08:12 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

// https://www.geeksforgeeks.org/file-handling-c-classes/
//std::string.replace FORBIDDEN

/*
Tests:

	- input file does not exist
	- s1 does not occur in input file
	- s1 empty
	- s2 empty
	- s1 = s2


*/


bool check_success(std::fstream& stream, std::string name)
{
	if (!stream.is_open())
	{
		std::cout << "Error: cannot open file " << name << std::endl;
		return false;
	}
	return true;
}

std::string& read_whole_file(std::fstream& fs, std::string& fulltext)
{
	std::string line;

	while(getline(fs, line))
	{
		fulltext.append(line);
		fulltext.append("\n");
		line.clear();
	}
	return (fulltext);
}

void	update_fulltext(std::string& fulltext, std::string& s1, size_t index)
{
	std::string sub;
	size_t 		sub_start;
	
	sub_start = index + s1.length();
	sub = fulltext.substr(sub_start , fulltext.length() - index);
	fulltext.clear();
	fulltext = sub;
}

//copy its content into new file
//replacing every occurence of s1 with s2 
void		read_and_replace(std::fstream& fs, std::fstream& newfile, char *argv[])
{
	std::string fulltext;
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	bool		match = true;
	size_t		start = 0;
	size_t		index = 0;


	read_whole_file(fs, fulltext);

	if (s1.empty())
	{
		newfile << fulltext;
		return;
	}

	while (match)
	{
		start = 0;
		index = -1;
		match = false;

		index = fulltext.find(s1);
		if (index >= fulltext.length())
		{
			// std::cout << "No (more) match found in fulltext\n";
			match = false;
			newfile << fulltext;
		}
		else
		{
			// std::cout << "found s1 at " << index << "\n";
			match = true;
			newfile << fulltext.substr(start, index);
			newfile << s2;
			update_fulltext(fulltext, s1, index);
		}
	}
	return;
}


int main(int argc, char *argv[])
{
	std::fstream	fs; //input file
	std::fstream	newfile;
	std::string		new_file_name;
	
	if (argc != 4)
	{
		std::cout << "Usage: <filename> <str1> <str2>\n";
		return 1;
	}

	fs.open(argv[1], std::ios::in); //explicitly adding mode makes thing more robust!!
	if (!check_success(fs, "fs"))
		return 1;

	new_file_name = argv[1];
	new_file_name.append(".replace");

	newfile.open(new_file_name.c_str(), std::ios::out | std::ios::trunc);
	if (!check_success(newfile, "newfile"))
		return 1;

	read_and_replace(fs, newfile, argv);

	fs.close();
	newfile.close();
	return 0;
}