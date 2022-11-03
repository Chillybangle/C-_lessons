#include <iostream>
#include <string>
#include <string_view>
using namespace std;

string repeat1(string_view s)
{
    return string {s} + string {s};
}

void repeat2(string& s)
{
    s += s;
}

void repeat3(string* s)
{
    *s += *s;
}

string* repeat4(string_view s)
{
    string* result = new string;
    *result = string {s} + string {s};
    
    return result;
}

int main()
{
    string test;
    cin >> test;

    cout << "repeat1:" << endl << repeat1(test) << endl;

    repeat2(test);
    cout << "repeat2:" << endl << test << endl;

    repeat3(&test);
    cout << "repeat3:" << endl << test << endl;

    cout << "repeat4:" << endl << *repeat4(test) << endl;
}
 
