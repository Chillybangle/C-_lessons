#include <iostream>
#include <string>
using namespace std;

string operator*(const string str, int n) {
    string result;
    for (int i = 0; i < n; ++i)
        result += str; 
    
    return result;
}

string operator*(int n, const string str) {
    string result;
    for (int i = 0; i < n; ++i)
        result += str; 
    
    return result;
}

int main() {
    string test;
    cin >> test;
    cout << 6 * test << endl;
}
 
