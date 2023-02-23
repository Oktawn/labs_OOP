#pragma once
#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono;

class CCall
{
private:
	bool priority;
	std::string
		abonent,
		numbers,
		thems;
	steady_clock::time_point end_number;
	steady_clock::time_point start_number;

	static int number_key_call;
	CCall &operator=(const CCall &) { return *this; }

public:
	CCall(bool priority,
		  std::string abonent = "anonim",
		  std::string numbers = "79XXXXXXXXXX",
		  std::string thems = "programming");
	CCall();

	bool correct_names(std::string);
	bool correct_number(std::string);
	bool correct_priority(const bool &);

	void show_thems() const;
	void show_number() const;
	void show_abonent() const;
	void show_priority() const;
	void show_call();

	void change_thems(std::string);
	void change_thems(std::string, bool);
	void change_number(std::string);
	void change_abonent(std::string);
	void change_priority(const bool &);

	float time_call();

	friend const bool operator>(CCall &, CCall &);
	friend const bool operator==(CCall &, CCall &);

	static int show_key()
	{
		return number_key_call;
	}
};
