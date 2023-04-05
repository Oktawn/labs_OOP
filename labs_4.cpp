#include "Interface.hpp"

int main()
{
	// system("chcp 1251>nul");
	Calculator cal;

	cal.result("2 3 4 + *");

	std::cout << "\nDone!\n";
	system("pause>nul");
	return 0;
}
