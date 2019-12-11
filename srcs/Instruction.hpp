#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP
# include <iostream>
# include <vector>
# include <typeinfo>
class Instruction
{
	public:
		Instruction(){};
		Instruction(char *tab);
		int create_instruction(char a);
		virtual int exec(int **tab, int &p);
		int		execute_instructions();
	private:
		char	*instruction;
		int		*tab;
		int		pointer;
		std::vector<Instruction*> list;
};

class Increment : public Instruction
{
	public:
		Increment();
		int exec(int **tab, int &p);
};

class Decrement : public Instruction
{
	public:
		Decrement();
		int exec(int **tab, int &p);
};

class Right : public Instruction
{
	public:
		Right();
		int exec(int **tab, int &p);
};

class Left : public Instruction
{
	public:
		Left();
		int exec(int **tab, int &p);
};

class PrintValue : public Instruction
{
	public:
		PrintValue();
		int exec(int **tab, int &p);
};

class StartLoop : public Instruction
{
	public:
		StartLoop();
		int exec(int **tab, int &p);
};

class EndLoop : public Instruction
{
	public:
		EndLoop();
		int exec(int **tab, int &p);
};

class GetValue : public Instruction
{
	public:
		GetValue();
		int  exec(int **tab, int &p);
};

int error(std::string error);
#endif
