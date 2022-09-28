#include <iostream>
#include <string>
using namespace std;

template <typename Type_1, typename Type_2>
struct Pair
{
    Type_1 first;
    Type_2 second;
    
    Pair (Type_1 f, Type_2 s) : first{f}, second {s} {}
    
};

int main()
{
Pair<int, string> a = {777, "Axolotl"};
Pair<string, float> b = {"Hippo", 6.45};
cout << a.first << " " << a.second << endl;
b.first += "potamus";
b.second = 3.14;
cout << b.first << " " << b.second << endl;
} 
