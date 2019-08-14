
#include "Header.h"

int main()
{
	SLL quang;
	std::ifstream in;
	in.open("input.txt");
	if (!in.is_open())
	{
		std::cout << "Couldnt open file"; 
		return 0;
	}
	in.close();
	quang.Display();
	return 0;
}