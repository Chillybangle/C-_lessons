#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int* n = new int {123};
    string* str = new string("Cats and Dogs\n");
    int* array = new int[5] {10, 20, 30, 40, 50};
    string* str_array = new string[3] {{"Cat"}, {"Dog"}, {"Mouse"}};
    string_view* str_ptrs = new string_view[3] {{str_array[0]}, {str_array[1]}, {str_array[2]}};
    
    cout << *n << endl;
    cout << *str;
    cout << array[3] << endl;
    cout << str_array[1] << endl;
    cout << str_ptrs[1] << endl;
    
    delete n;
    delete str;
    delete[] array;
    delete[] str_array;
    delete[] str_ptrs;
}


