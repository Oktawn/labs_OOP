#include "CCall.h"

int CCall::number_key_call = 0;

CCall::CCall()
	: start_number(steady_clock::now()), priority(false),
	abonent("anonim"), numbers("79XXXXXXXXX"), thems("programming") {}

CCall::CCall(bool priority, std::string abonent, std::string numbers, std::string thems)
{
	start_number = steady_clock::now();
	this->priority = (correct_priority(priority)) ? priority : this->priority;
	this->abonent = (correct_names(abonent)) ? abonent : this->abonent;
	this->numbers = (correct_number(numbers)) ? numbers : "79XXXXXXXXX";
	this->thems = (correct_names(thems)) ? thems : this->thems;
	if (priority)
		number_key_call++;
}

CCall::CCall(const CCall& C)
	:start_number(C.start_number), priority(C.priority),
	abonent(C.abonent), numbers(C.numbers), thems(C.thems) {}


void CCall::show_number() const
{
	std::cout << "numbers: " << numbers << std::endl;
}

void CCall::show_abonent() const
{
	std::cout << "abonent: " << abonent << std::endl;
}

bool CCall::correct_names(std::string ch)
{
	for (int i = 0; i < ch.size(); i++)
	{
		if (isalpha(ch[i]) || isspace(ch[i]))
			continue;
		else
		{
			std::cout << "\ninvalid syntax, change canceled\n";
			return false;
		}
	}
	return true;
}

bool CCall::correct_number(std::string ch)
{
	for (size_t i = 0; i < ch.size(); i++)
	{
		if (isdigit(ch[i]) && ch.size() == numbers.size())
			continue;
		else
		{
			std::cout << "invalid number changes canceled\n";
			return false;
		}
	}
	return true;
}

bool CCall::correct_priority(const char& ch)
{
	if (isdigit(ch + '0'))
		return true;
	else
	{
		std::cout << "invalid priority\n";
		return false;
	}
}

void CCall::show_thems() const
{
	std::cout << "thems: " << thems << std::endl;
}

void CCall::show_priority() const
{
	std::cout << "priority: " << std::boolalpha << priority << std::endl;
}

void CCall::show_call()
{
	show_priority(),
		show_abonent(),
		show_number(),
		show_thems();
	std::cout << "time: " << time_call() << "s\n";
}

void CCall::change_thems(const std::string& ch)
{
	thems = (correct_names(ch)) ? ch : thems;
}
void CCall::change_thems(const std::string& ch, const int& prior)
{
	if (correct_names(ch))
		thems = ch;
	priority = (correct_priority(prior)) ? number_key_call++, prior : priority;
}

void CCall::change_number(const std::string& ch)
{
	numbers = (correct_number(ch)) ? ch : numbers;
}

void CCall::change_abonent(const std::string& ch)
{
	abonent = (correct_names(ch)) ? ch : abonent;
}

void CCall::change_priority(const char& ch)
{
	bool temp = priority;
	priority = (correct_priority(ch)) ? ch : priority;
	if (priority == 1 && temp == 0)
	{
		number_key_call++;
		return;
	}
	if (priority == temp)
		return;
	else
		number_key_call--;
}

float CCall::time_call()
{
	end_number = steady_clock::now();
	duration<double> elapsed = end_number - start_number;
	return elapsed.count();
}

const bool operator>(CCall& left, CCall& right)
{
	return left.time_call() > right.time_call();
}

const bool operator==(CCall& left, CCall& right)
{
	return left.time_call() == right.time_call();
}
