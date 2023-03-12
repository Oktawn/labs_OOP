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
    ~Newpaper()
    {
    }

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
      list_articles("bib"), list_author("bruh") {}

void Newpaper::Get_info() const
{
    std::cout << "number: " << number << std::endl
              << "years: " << years << std::endl;
    list_articles.Show_on_Head(), list_author.Show_on_Head();
    std::cout
        << "sold copies: " << copies_sold << std::endl
        << "all copies: " << all_copies << std::endl;
}

void Newpaper::Add_author(const std::string &aut)
{
    list_author.Add_Tail(aut);
}

void Newpaper::Add_articler(const std::string &art)
{
    list_articles.Add_Tail(art);
}

void Newpaper::Change_author(const std::string &aut_old, const std::string &aut_new)
{
    if (list_author.Find_Node(aut_old) != nullptr)
        list_author.Find_Node(aut_old)->key = aut_new;
    else
        std::cout << "no found author\n";
}

void Newpaper::Change_articler(const std::string &art_old, const std::string &art_new)
{
    if (list_articles.Find_Node(art_old) != nullptr)
        list_articles.Find_Node(art_old)->key = art_new;
    else
        std::cout << "no found articles\n";
}

void Newpaper::Change_sold(const int &sold)
{
    if (sold > copies_sold)
        copies_sold = sold;
    else
        std::cout << "there should be more copies sold\n";
}

void Newpaper::Change_all_copies(const int &cop)
{
    if (cop > all_copies)
        all_copies = cop;
    else
        std::cout << "there should be more copies\n";
}

void Newpaper::Change_number(const int &num)
{
    number = num;
}

void Newpaper::Change_number(const int &num, const int &sold)
{
    Change_number(num), Change_sold(sold);
}

void Newpaper::Get_per_sold_number() const
{
    std::cout << ((double)copies_sold / all_copies) * 100 << "%\n";
}

#endif