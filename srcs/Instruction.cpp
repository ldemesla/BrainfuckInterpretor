#include "Instruction.hpp"

int is_loop(Instruction& p)
{
	EndLoop *a = 0;
	StartLoop *b = 0;

	a = dynamic_cast<EndLoop*>(&p);
	if (a != NULL)
		return (1);
	b = dynamic_cast<StartLoop*>(&p);
	if (b != NULL)
		return (2);
	return (0);
}

Instruction::Instruction(char *tb)
{
	int i;

	i = 0;
	pointer = 15000;
	instruction = tb;
	tab = new int[30000];
	while (i < 30000)
		tab[i++] = 0;
}

int Instruction::create_instruction(char c)
{
	if (c == instruction[0])
		list.push_back(new Increment());
	else if (c == instruction[1])
		list.push_back(new Decrement());
	else if (c == instruction[2])
		list.push_back(new Right());
	else if (c == instruction[3])
		list.push_back(new Left());
	else if (c == instruction[4])
		list.push_back(new PrintValue());
	else if (c == instruction[5])
		list.push_back(new StartLoop());
	else if (c == instruction[6])
		list.push_back(new EndLoop());
	else if (c == instruction[7])
		list.push_back(new GetValue());
	else if (c != '\n' && c != ' ')
		return (error("Error : invalid instruction"));
	return (1);
}

int Instruction::execute_instructions()
{
	std::vector<Instruction*>::iterator it;
	std::vector<Instruction*>::iterator ending;
	int res;
	int count;

	it = list.begin();
	ending = list.end();
	count = 0;
	while (it != ending)
	{
		res = (*it)->exec(&tab, pointer);
		if (res == 5)
			count++;
		else if (res == 1 && is_loop(**it) == 1)
		{
			while (res)
			{
				if (is_loop(**it) == 2)
				{
					count--;
					if (count <= 0)
					{
						count = 1;
						res = 2;
						break ;
					}
				}
				it--;
			}
		}
		it++;
	}
	return (1);
}

int Instruction::exec(int **tab, int &p)
{
	(void)tab;
	(void)p;
	return (1);
}

Increment::Increment() : Instruction()
{
}

Decrement::Decrement() : Instruction()
{
}

Left::Left() : Instruction()
{
}

Right::Right() : Instruction()
{
}

PrintValue::PrintValue() : Instruction()
{
}

GetValue::GetValue() : Instruction()
{
}

StartLoop::StartLoop() : Instruction()
{
}

EndLoop::EndLoop() : Instruction()
{
}

int error(std::string error)
{
	std::cout << error << std::endl;
	return (0);
}

int Increment::exec(int **tab, int &p)
{
	tab[0][p] += 1;
	return (1);
}

int Decrement::exec(int **tab, int &p)
{
	tab[0][p] -= 1;
	return (1);
}

int Right::exec(int **tab, int &p)
{
	(void)tab;
	p++;
	return (1);
}

int Left::exec(int **tab, int &p)
{
	(void)tab;
	p--;
	return (1);
}

int PrintValue::exec(int **tab, int &p)
{
	char c;
	c = tab[0][p];
	std::cout << c;
	return (1);
}

int GetValue::exec(int **tab, int &p)
{
	p = tab[0][p];
	return (1);
}

int EndLoop::exec(int **tab, int &p)
{
	if (tab[0][p] == 0)
		return (0);
	else
		return (1);
}

int StartLoop::exec(int **tab, int &p)
{
	(void)tab;
	(void)p;
	return (5);
}
