/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:25:42 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/31 12:49:52 by lgottsch         ###   ########.fr       */
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
	std::fstream	fs; //inout file
	std::fstream	newfile;
	std::string		new_file_name;
	
	if (argc != 4)
	{
		std::cout << "Usage: <filename> <str1> <str2>\n";
		return 1;
	}

	//open input file
	fs.open(argv[1], std::ios::in); //explicitly adding mode makes thing more robust!!
	if (!check_success(fs, "fs"))
		return 1;

	//open output file 
	new_file_name = argv[1];
	new_file_name.append(".replace");

	newfile.open(new_file_name.c_str(), std::ios::out | std::ios::trunc);
	if (!check_success(newfile, "newfile"))
		return 1;


	read_and_replace(fs, newfile, argv);


	// //copy its content into new file
	// //replacing every occurence of s1 with s2 

	// std::string fulltext;
	// //read whole text inputfile
	// read_whole_file(fs, fulltext);
	// std::cout << fulltext; //OK


	// std::string s1 = argv[2];
	// std::string s2 = argv[3];
	// size_t		index = 0;
	// bool		match = true;

	// while (match)
	// {
	// 	index = -1;
	// 	//look for s1 in fulltext
	// 	// size_t	index;
	// 	size_t	start = 0;
	// 	match = false;

	// 	index = fulltext.find(argv[2]);
	// 	if (index >= fulltext.length())
	// 	{
	// 		std::cout << "No (more) match found in fulltext\n";
	// 		match = false;
	// 		// index = -1;
	// 		newfile << fulltext;
	// 	}
	// 	else
	// 	{
	// 		std::cout << "found s1 at " << index << "\n";
	// 		match = true;

	// 		newfile << fulltext.substr(start, index);
	// 		newfile << argv[3];

	// 		std::string tmp;
	// 		std::string sub;
	// 		size_t 	sub_start = index + s1.length();

	// 		std:: cout << "sub start: " << sub_start;

	// 		sub = fulltext.substr(sub_start , fulltext.length() - index);

	// 		fulltext.clear();
	// 		fulltext = sub;
	// 		// if (fulltext.length() == 0)
	// 		// {
	// 		// 	std::cout << "Reached end of file\n";
	// 		// 	newfile << sub;
	// 		// 	fs.close();
	// 		// 	newfile.close();
	// 		// 	return 0;
	// 		// }

	// 	}


	// }

	std::cout << "Reached end of file\n";
	fs.close();
	newfile.close();
	return 0;
}