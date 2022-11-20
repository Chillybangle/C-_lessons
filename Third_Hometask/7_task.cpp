#include <cstdlib>
#include <iostream>
#include "miptstring.hpp"

using namespace std;

int main()
{
    //1
    mipt::String Cat{"Cat"};
    //cout << Cat << endl;
    
    //2
    mipt::String* str_ptr = new mipt::String ("Not a cat");
    cout << *str_ptr << endl;
    delete str_ptr;
    
    //3
    char x[sizeof(mipt::String)] = {0};
    mipt::String* str_cringe = new (x) mipt::String ("Elephant");
    cout << *str_cringe << endl;
    str_cringe -> ~String();
}
