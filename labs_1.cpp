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
	sort_bubble(array, SIZE_ARRAY, less_more);
	//remove_shift(testing,4, SIZE_ARRAY);
	std::cout << std::endl;
	classic_output(array, SIZE_ARRAY);
	//classic_output(testing, SIZE_ARRAY);

	//std::cout << max_el_inx(array, SIZE_ARRAY);

	system("pause>nul");
	return 0;

}
