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

	bool correct_names(std::string);
	bool correct_number(std::string);
	bool correct_priority(const char&);

	static int number_key_call;

public:
	CCall(bool priority, std::string abonent = "anonim",
		std::string numbers = "79XXXXXXXXX", std::string thems = "programming");
	CCall(const CCall& C);
	CCall();
	~CCall() {}



	void show_thems() const;
	void show_number() const;
	void show_abonent() const;
	void show_priority() const;
	void show_call();

	void change_thems(const std::string&);
	void change_thems(const std::string&, const int&);
	void change_number(const std::string&);
	void change_abonent(const std::string&);
	void change_priority(const char&);

	float time_call();

	friend const bool operator>(CCall&, CCall&);
	friend const bool operator==(CCall&, CCall&);
	CCall& operator=(const CCall&) { return *this; }

	static int show_key()
	{
		return number_key_call;
	}
};
