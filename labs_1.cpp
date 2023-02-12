#include "func.h"



int main()
{
	srand(unsigned int(time(0)));
	int array[SIZE_ARRAY]{ 0 };
	test testing[SIZE_ARRAY];
	create_randow(array, SIZE_ARRAY);
	//create_randow(testing, SIZE_ARRAY);
	classic_output(array, SIZE_ARRAY);
	//classic_output(testing, SIZE_ARRAY);
	std::cout << std::endl;
	std::cout << count_el(array, SIZE_ARRAY, pos_el);
	//classic_output(array, SIZE_ARRAY);
	//classic_output(testing, SIZE_ARRAY);

	//std::cout << max_el_inx(array, SIZE_ARRAY);

	system("pause>nul");
	return 0;

}
