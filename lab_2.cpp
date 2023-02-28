#include "CCall.h"

int main()
{
	CCall test;
	CCall temp[4];
	test.show_call();	
	std::cout << std::endl;
	test.change_abonent("k pop");
	test.show_abonent();
	//test.change_priority(false);
	test.show_priority();

	test.change_thems("nock", true);
	test.show_thems();
	test.show_priority();

	test.change_number("7919956632");
	test.show_number();
	std::cout << test.time_call() << std::endl;

	temp[3] = temp[1];
	temp[2].show_call();

	CCall bb(test);

	std::cout << std::endl;
	bb.show_call();

	std::cout << CCall::show_key();


	system("pause>nul");
	return 0;
}


