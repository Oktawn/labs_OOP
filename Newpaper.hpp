#ifndef NEWPAPER_HPP
#define NEWPAPER_HPP
#include "List.hpp"

class Newpaper
{
private:
    int number;
    int years;
    int copies_sold;
    int all_copies;
    List<std::string> list_author;
    List<std::string> list_articles;

public:
    Newpaper();
    ~Newpaper();

    void Get_info() const;

    void Add_author(const std::string &aut);
    void Add_articler(const std::string &art);

    void Change_author(const std::string &aut_old, const std::string &aut_new);
    void Change_articler(const std::string &art_old, const std::string &art_new);
    void Change_sold(const int &sold);
    void Change_all_copies(const int &cop);
    void Change_number(const int &num);
    void Change_number(const int &num, const int &sold);

    void Get_per_sold_number() const;
};

Newpaper::Newpaper()
    : number(000), years(1970), copies_sold(0), all_copies(0),
    list_articles("bib"),list_author("bruh") {}

void Newpaper::Get_info() const
{
    std::cout << "number: " << number << std::endl
              << "years: " << years << std::endl;
    list_articles.Show_on_Head(), list_author.Show_on_Head();
    std::cout
        << "sold copies: " << copies_sold << std::endl
        << "all copies: " << all_copies << std::endl;
}

void Newpaper::Get_per_sold_number() const
{
    std::cout << ((double)copies_sold / all_copies) * 100 << "%\n";
}

#endif