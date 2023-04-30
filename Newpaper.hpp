#ifndef NEWPAPER_HPP
#define NEWPAPER_HPP
#include <vector>
#include <iostream>

class Newpaper
{
private:
	int number;
	int years;
	int copies_sold;
	int all_copies;
	std::vector<std::string> list_author;
	std::vector<std::string> list_articles;

public:
	Newpaper();
	Newpaper(int, int, int, int, std::vector<std::string>, std::vector<std::string>);
	Newpaper(Newpaper& C)
		: number(C.number), years(C.years), copies_sold(C.copies_sold), all_copies(C.all_copies),
		list_articles(C.list_articles), list_author(C.list_author) {}

	void Get_info();

	void Show_number();
	void Show_years();
	void Show_articles();
	void Show_author();
	void Show_sold();
	void Show_all();

	int get_number() { return number; }
	int get_years() { return years; }
	int get_copies_sold() { return copies_sold; }
	int get_all_copies() { return all_copies; }

	void Add_author(const std::string& aut);
	void Add_articler(const std::string& art);

	void Change_author(const std::string& aut_old, const std::string& aut_new);
	void Change_articler(const std::string& art_old, const std::string& art_new);

	void Change_sold(const int& sold) { this->copies_sold = sold; }
	void Change_all_copies(const int& cop) { this->all_copies = cop; }

	void Change_number(const int& num) { this->number = num; }
	void Change_number(const int& num, const int& sold)
	{
		Change_number(num);
		Change_sold(sold);
	}

	void Get_per_sold_number();

	friend std::ostream& operator<<(std::ostream& os, Newpaper& nw);
	friend std::ostream& operator<<(std::ostream& os, const Newpaper& nw);
};

Newpaper::Newpaper()
	: number(0), years(1970), copies_sold(0), all_copies(0)
{
	list_articles.push_back("bub");
	list_author.push_back("gg");
}

Newpaper::Newpaper(int number, int years, int copies_sold, int all_copies,
	std::vector<std::string> list_articles, std::vector<std::string> list_author)
{
	this->number = number;
	this->years = years;
	this->all_copies = all_copies;
	this->copies_sold = copies_sold;
	this->list_articles = list_articles;
	this->list_author = list_author;
}

void Newpaper::Get_info()
{
	std::cout << "number: " << number << std::endl
		<< "years: " << years << std::endl;
	Show_articles(), Show_author();
	std::cout
		<< "sold copies: " << copies_sold << std::endl
		<< "all copies: " << all_copies << std::endl;
}

void Newpaper::Show_number()
{
	std::cout << "number newpaper: " << number << std::endl;
}

void Newpaper::Show_years()
{
	std::cout << "years newpaper: " << years << std::endl;
}

void Newpaper::Show_articles()
{
	std::cout << "articles newpaper: ";
	for (auto& i : list_articles)
		std::cout << i << " ";
	std::cout << std::endl;
}

void Newpaper::Show_author()
{
	std::cout << "author newpaper: ";
	for (auto& i : list_author)
		std::cout << i << " ";
	std::cout << std::endl;
}

void Newpaper::Show_sold()
{
	std::cout << "sold copies newpaper: " << copies_sold << std::endl;
}

void Newpaper::Show_all()
{
	std::cout << "all copies newpaper: " << all_copies << std::endl;
}

void Newpaper::Add_author(const std::string& aut)
{
	list_author.push_back(aut);
}

void Newpaper::Add_articler(const std::string& art)
{
	list_articles.push_back(art);
}

void Newpaper::Change_author(const std::string& aut_old, const std::string& aut_new)
{
	for (auto& i : list_author)
	{
		if (i == aut_old)
		{
			i = aut_new;
			return;
		}
	}
	std::cout << "no found author\n";
}

void Newpaper::Change_articler(const std::string& art_old, const std::string& art_new)
{
	for (auto& i : list_articles)
	{
		if (i == art_old)
		{
			i = art_new;
			return;
		}
	}
	std::cout << "no found articler\n";
}
void Newpaper::Get_per_sold_number()
{
	std::cout << ((double)copies_sold / all_copies) * 100 << "%\n";
}

std::ostream& operator<<(std::ostream& os, Newpaper& nw)
{
	os << nw.number << "\n"
		<< nw.years << "\n";

	nw.Show_author();
	nw.Show_articles();
	os << nw.copies_sold << "\n"
		<< nw.all_copies << "\n";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Newpaper& nw)
{
	os << nw.number << "\n"
		<< nw.years << "\n"
		<< nw.copies_sold << "\n"
		<< nw.all_copies << "\n";
	return os;
}


#endif