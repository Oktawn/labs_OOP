#include "CCall.h"

int main()
{
	CCall test;
	CCall temp[4];
	test.show_call();
	test.change_abonent("k pop");
	std::cout << std::endl;
	test.show_abonent();
	temp[2].change_priority(4);
	std::cout << "temp[2] prior: ";
	temp[2].show_priority();
	test.change_priority(false);
	test.show_priority();

	test.change_thems("nock", true);
	test.show_thems();
	test.show_priority();

	test.change_number("79199566302");
	test.show_number();

	std::cout << test.time_call() << std::endl;

	std::cout << CCall::show_key();


	system("pause>nul");
	return 0;
}


