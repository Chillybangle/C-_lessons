#include <iostream>

namespace myspace
{
    void print_n_times(char str[], int n = 10)
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << str << std::endl;
        }
    }
}

int main ()
{
    char str[] = "meow";
    myspace::print_n_times (str);
}
