#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

using std::string;

const int SIZE_ARRAY = 10;

struct test
{
	int n_x;
	string s_x;
};

template<typename T>
bool pos_el(const T&);
template<>
bool pos_el(const test&);

template<typename T>
bool neg_el(const T&);
template<>
bool neg_el(const test&);

template<typename T>
bool zero_el(const T&);
template<>
bool zero_el(const test&);

template<typename T>
bool mult_el(const T&, int);
template<>
bool mult_el(const test&, int);

template<typename T>
void create_randow(T*, int);
template<>
void create_randow(test*, int);

template<typename T>
void insert_shift(T*, int, int);
template<>
void insert_shift(test*, int, int);

template<typename T>
void remove_shift(T*, int, int);
template<>
void remove_shift(test*, int, int);

template<typename T>
void sort_bubble(T*, int);
template<>
void sort_bubble(test*, int);

template<typename T>
void sort_select(T*, int);
template< >
void sort_select(test*, int);

template<typename T>
void sort_quick(T*, int);
template<>
void sort_quick(test*, int);

template<typename T>
int max_el_inx(const T*, int);
template<>
int max_el_inx(const test*, int);

template<typename T>
int min_el_inx(const T*, int);
template<>
int min_el_inx(const test*, int);

template<typename T>
bool search_lin_el_iter(const T*, int, int);
template<>
bool search_lin_el_iter(const test*, int, int);

template<typename T>
bool search_bin_el_rec(const T*, int, int, int);
template<>
bool search_bin_el_rec(const test*, int, int, int);

template<typename T>
int count_el(const T*, int);
template<typename node>
int count_el(const test*, int);
template<typename T>
int count_el(const T*, bool(*pred)(const T&), int);
template<typename node>
int count_el(const test*, bool(*pred)(const node&), int);

template<typename T>
int sum_el(const T*, bool(*pred)(const T&), int);
template<typename T>
int sum_el(const test*, bool(*pred)(const T&), int);

template<typename T>
auto mul_el(const T*, int) -> double;
template<typename T>
auto mul_el(const test*, int) -> double;

template<typename T>
auto mul_el(const T*, bool(*pred)(const T&), int) -> T;
template<typename T>
auto mul_el(const test*, bool(*pred)(const T&), int) -> T;

template <typename T>
void classic_input(T*, int);
template <>
void classic_input(test*, int);

template <typename T>
void classic_output(const T*, int);
template <>
void classic_output(const test*, int);

template <typename T>
void file_input(T*, int);
template <>
void file_input(test*, int);

template <typename T>
void file_output(T*, int);

template<typename T>
void compress(T*, int, int);
template<>
void compress(test*, int, int);

template<typename T>
bool pos_el(const T& num) { return num > 0; }

template<>
bool pos_el(const test& st_obj) { return st_obj.n_x > 0; }

template<typename T>
bool neg_el(const T& num) { return num < 0; }

template<>
bool neg_el(const test& st) { return st.n_x < 0; }

template<typename T>
bool zero_el(const T& num) { return num == 0; }

template<>
bool zero_el(const test& st) { return st.n_x == 0; }

template<typename T>
bool mult_el(const T& num, int k) { return num % k == 0; }

template<>
bool mult_el(const test& st, int k) { return st.n_x % k == 0; }

template<typename T>
void create_randow(T* arr, int size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] = (double)(rand()) / RAND_MAX * (150 + (-50)) - 40;
}

template<>
void create_randow(test* arr_st, int size)
{
	for (size_t i = 0; i < size; i++)
		arr_st[i] = { rand() % +101,
		string(1,char(65 + rand() % +26)) };
}

template<typename T>
void insert_shift(T* arr, int inx, int size)
{
	for (size_t i = size_t(size - 1); i > inx; i--)
		std::swap(arr[i], arr[i - 1]);

	arr[inx] = rand() % +101;
}

template<>
void insert_shift(test* st_arr, int inx, int size)
{
	for (size_t i = size_t(size - 1); i > inx; i--)
		std::swap(st_arr[i], st_arr[i - 1]);

	st_arr[inx] = { rand() % +101,
			string(1,char(65 + rand() % +26)) };
}

template<typename T>
void remove_shift(T* arr, int inx, int size)
{
	for (size_t i = inx; i < size_t(size - 1); i++)
		std::swap(arr[i], arr[i + 1]);
	arr[size - 1] = 0;
}

template<>
void remove_shift(test* st_arr, int inx, int size)
{
	for (int i = inx; i < size - 1; i++)
		std::swap(st_arr[i], st_arr[i + 1]);
	st_arr[size - 1] = { 0,"0" };
}

template<typename T>
void sort_bubble(T* arr, int size)
{
	bool flag = true;
	int i = 0;
	while (flag == true)
	{
		flag = false;
		for (int j = 0; i < size - j - 1; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]),
				flag = true;
		i++;
	}

}

template<>
void sort_bubble(test* st_arr, int size)
{
	bool flag = true;
	int i = 0;
	while (flag == true)
	{
		flag = false;
		for (int j = 0; i < size - j - 1; j++)
			if (st_arr[j].n_x > st_arr[j + 1].n_x)
				std::swap(st_arr[j], st_arr[j + 1]),
				flag = true;
		i++;
	}

}

template<typename T>
void sort_select(T* arr, int size)
{
	int min;
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
			min = (arr[j] < arr[min]) ? j : min;
		std::swap(arr[i], arr[min]);
	}
}

template<>
void sort_select(test* st_arr, int size)
{
	int min;
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
			min = (st_arr[j].n_x < st_arr[min].n_x) ? j : min;
		std::swap(st_arr[i], st_arr[min]);
	}
}

template<typename T>
void sort_quick(T* arr, int size)
{
	int left = 0; int right = size - 1; int mid = arr[size / 2];
	int temp;
	do
	{
		while (arr[left] < mid) left++;
		while (arr[right] > mid) right--;
		if (left <= right)
		{
			std::swap(arr[left], arr[right]);
			left++;
			right--;
		}
	} while (left <= right);
	if (right > 0) sort_quick(arr, right + 1);
	if (left < size) sort_quick(&arr[left], size - left);
}

template<>
void sort_quick(test* st_arr, int size)
{
	int left = 0,
		right = size - 1,
		mid = st_arr[size / 2].n_x;
	do
	{
		while (st_arr[left].n_x < mid)left++;
		while (st_arr[right].n_x > mid)right--;
		if (left <= right)
		{
			std::swap(st_arr[left], st_arr[right]);
			left++;
			right--;
		}
	} while (left <= right);
	if (right > 0) sort_quick(st_arr, right + 1);
	if (left < size) sort_quick(&st_arr[left], size - left);
}

template<typename T>
int max_el_inx(const T* arr, int size)
{
	T max = INT_MIN;
	int inx = 0;

	for (int i = 0; i < size; i++)
		if (max < arr[i])
			max = arr[i], inx = i;
	return inx;
}

template<>
int max_el_inx(const test* st_arr, int size)
{

	decltype(st_arr->n_x) max = INT_MIN;
	int inx = 0;
	for (int i = 0; i < size; i++)
		if (max < st_arr[i].n_x)
			max = st_arr[i].n_x, inx = i;
	return inx;
}

template<typename T>
int min_el_inx(const T* arr, int size)
{
	T min = INT_MAX;
	int inx = 0;
	for (int i = 0; i < size; i++)
		if (min > arr[i])
			min = arr[i], inx = i;

	return inx;
}

template<>
int min_el_inx(const test* st_arr, int size)
{
	decltype(st_arr->n_x) min = INT_MAX;
	int inx = 0;
	for (int i = 0; i < size; i++)
		if (min > st_arr[i].n_x)
			min = st_arr[i].n_x,
			inx = i;

	return inx;
}

template<typename T>
bool search_lin_el_iter(const T* arr, int num, int size)
{
	for (int i = 0; i < size; i++)
		if (arr[i] == num) return true;
	return false;
}

template<>
bool search_lin_el_iter(const test* st_arr, int num, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (num == st_arr[i].n_x) return true;
	}
	return false;
}

template<typename T>
bool search_bin_el_rec(const T* arr, int left, int right, int num)
{
	if (right >= left)
	{
		int mid{ left + (right - 1) / 2 };
		if (arr[mid] == num)
			return true;
		if (arr[mid] > num)
			return search_bin_el_rec(arr, left, mid - 1, num);
		return search_bin_el_rec(arr, mid + 1, right, num);
	}

	return false;
}

template<>
bool search_bin_el_rec(const test* st, int left, int right, int num)
{
	if (right >= left)
	{
		decltype(st->n_x) mid{ left + (right - 1) / 2 };
		if (st[mid].n_x == num)
			return true;
		if (st[mid].n_x > num)
			return search_bin_el_rec(st, left, mid - 1, num);
		return search_bin_el_rec(st, mid + 1, right, num);
	}
	return false;
}

template<typename T>
int count_el(const T* arr, int size)
{
	int sum(0);
	for (int i = 0; i < size; i++)
		if (neg_el(arr[i]))
			if (zero_el(arr[i]))
				sum++;
	return sum;
}

template<typename node>
int count_el(const test* st_arr, int size)
{
	int sum(0);
	for (int i = 0; i < size; i++)
		if (neg_el(st_arr[i].n_x))
			if (zero_el(st_arr[i].n_x))
				sum++;
	return sum;
}

template<typename T>
int count_el(const T* arr, bool(*pred)(const T&), int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		if (pred(arr[i]))
			sum++;
	return sum;
}

template<typename node>
int count_el(const test* st_arr, bool(*pred)(const node&), int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		if (pred(st_arr[i].n_x))
			sum++;
	return sum;
}

template<typename T>
auto sum_el(const T* arr, bool(*pred)(const T&), int size) -> T
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		if (pred(arr[i]))
			sum += arr[i];
	return sum;
}

template<typename T>
auto sum_el(const test* st_arr, bool(*pred)(const T&), int size) -> decltype(st_arr->n_x)
{
	decltype(st_arr->n_x) sum = 0;
	for (int i = 0; i < size; i++)
		if (pred(st_arr[i].n_x))
			sum += st_arr[i].n_x;
	return sum;
}

template<typename T>
auto mul_el(const T* arr, int size) -> double
{
	auto mul = 1.0; int inx = size;

	for (int i = size - 1; i > 0; i--)
		if (neg_el(arr[i]))
		{
			inx = i;
			break;
		}
	for (int i = 0; i < inx; i++)
		mul *= arr[i];

	return double(mul);
}

template<typename T>
auto mul_el(const test* st_arr, int size) -> double
{
	auto mul = 1.0; int inx = size;

	for (int i = size - 1; i > 0; i--)
		if (neg_el(st_arr[i].n_x))
		{
			inx = i;
			break;
		}
	for (int i = 0; i < inx; i++)
		mul *= st_arr[i].n_x;

	return mul;
}

template<typename T>
auto mul_el(const T* arr, bool(*pred)(const T&), int size) -> T
{
	T mul = 1;
	for (int i = 0; i < size; i++)
		if (pred(arr[i]))
			mul *= arr[i];
	return mul;
}

template<typename T>
auto mul_el(const test* st_arr, bool(*pred)(const T&), int size) -> decltype(st_arr->n_x)
{
	decltype(st_arr->n_x) mul = 1;
	for (int i = 0; i < size; i++)
		if (pred(st_arr[i].n_x))
			mul += st_arr[i].n_x;
	return mul;
}

template<typename T>
void classic_input(T* arr, int size)
{
	for (int i = 0; i < size; i++)
		std::cin >> i;
}

template<>
void classic_input(test* st_arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "number: ";
		std::cin >> st_arr[i].n_x;
		std::cout << "\rtext: ";
		std::getline(std::cin, st_arr[i].s_x);
	}
}

template<typename T>
void classic_output(const T* arr, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

template<>
void classic_output(const test* st_arr, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << st_arr[i].n_x << " "
		<< st_arr[i].s_x << std::endl;
}

template<typename T>
void file_input(T* arr, int size)
{
	char file_name[] = "array.txt";
	int i = 0;
	std::ofstream File_array(file_name);
	while (!File_array.eof() && i < size)
	{
		File_array << arr[i] << " ";
		i++;
	}
	File_array.close();
}

template<>
void file_input(test* st_arr, int size)
{
	char file_name[] = "struct.txt";
	int i = 0;
	std::ofstream File_struct(file_name);
	while (!File_struct.eof() && i < size)
	{
		File_struct << std::to_string(st_arr[i].n_x) << " "
			<< st_arr[i].s_x << std::endl;
	}

}

template<typename T>
void file_output(T* arr, int size)
{
	/*char file_name[] = "array.txt";
	int i = 0;
	std::ofstream File_array(file_name);
	while (!File_array.eof() && i < size)
	{
		File_array >> arr[i];
		i++;
	}
	File_array.close();*/

	char* text = new char[1500];
	std::ifstream file("array.txt");
	if (file.is_open()) {
		file.getline(text, 1500);
		std::cout << text << std::endl;
	}
	file.close();

}

template<typename T>
void compress(T* arr, int k, int size)
{
	for (int i = 0; i < size; i++)
		if (mult_el(arr[i], k))
			remove_shift(arr, i, size);
}

template<>
void compress(test* st_arr, int k, int size)
{
	for (int i = 0; i < size; i++)
		if (mult_el(st_arr[i].n_x, k))
			remove_shift(st_arr, i, size);
}

