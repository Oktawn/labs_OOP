#ifndef NEWPAPER_HPP
#define NEWPAPER_HPP
#include "List.hpp"

template <typename N>
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
    void change_number(const int &num);
    void change_number(const int &num, const int &sold);
    void get_per_sold_number() const { std::cout << ((double)copies_sold / all_copies) * 100 << "%\n"; }
    void get_per_sold_years() const;
};

#endif