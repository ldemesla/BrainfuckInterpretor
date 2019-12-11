#include <iostream>
#include <fstream>
#include "Instruction.hpp"

int	exist_in(char *tab, int i, char c)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (tab[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int main(int ac, char **av)
{
	int i;
	char c;
	char instruction[8];
	std::string file_name;

	if (ac == 9)
	{
		i = 0;
		while (i < 8)
		{
			if (strlen(av[i + 1]) > 1)
				return (error("Error : instruction must be 1 char long"));
			if (exist_in(instruction, i, av[i+1][0]))
				return (error("Error : each instruction must have a different symbol"));
			instruction[i] = av[i + 1][0];
			i++;
		}
		while (1)
		{
			Instruction interpretor(instruction);
			std::cout << "Please provide a BrainFuck type file : ";
			std::cin >> file_name;
			std::ifstream file(file_name);
			if (file)
			{
				while (file.get(c))
					if (!(interpretor.create_instruction(c)))
						return (0);
				interpretor.execute_instructions();
				break ;
			}
			else
				return(error("Error : incorrect file"));
		}
	}
	else
		return (error("Error : you need to provide 8 arguments"));
	return (0);
}
