#include "func.h"




int main()
{
	srand(unsigned int(time(0)));
	int array[SIZE_ARRAY]{ 0 };
	test testing[SIZE_ARRAY];

	create_randow(array, SIZE_ARRAY);
	create_randow(testing, SIZE_ARRAY);
	classic_output(array,SIZE_ARRAY);
	//classic_output(testing, SIZE_ARRAY);
	/*std::cout << std::endl;
	for (const auto& i : testing)
		std::cout << i.n_x << " ";*/
	//std::cout << std::endl;
	//sort_quick(array, SIZE_ARRAY);
	//sort_quick(testing, SIZE_ARRAY);
	//for (const auto& i : array)
	//	std::cout << i << " ";
	//std::cout << std::endl;
	//for (const auto& i : testing)
	//	std::cout << i.n_x << " ";
	std::cout << max_el_inx(array, SIZE_ARRAY);

	system("pause>nul");
	return 0;

}
