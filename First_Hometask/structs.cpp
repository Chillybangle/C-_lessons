#include <iostream>

struct Book
{
    char title[100];
    int pages;
    float price;
};

void addPrice (struct Book &book, float x);
bool isExpensive (const struct Book &book);

int main ()
{
    Book book = {"Harry Potter", 300, 1.25};
    addPrice (book, 1000);
    
    std::cout << "New price is " << book.price << std::endl;
    
    std::cout << isExpensive(book) << std::endl;
}

void addPrice (struct Book &book, float x)
{
    book.price += x;
}

bool isExpensive (const struct Book &book)
{
    if (book.price > 1000)
        return true;
    else
        return false;
}
