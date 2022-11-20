#include <iostream>
#include <string>

using namespace std;


void truncateToDot(string& s) {
	size_t n = s.find('.');
	s =  s.substr(0, n);
}

int main() {
	string s;
	while (cin >> s) {
		truncateToDot(s);
		cout << s << " " <<  s.capacity() << endl;
	}
} 
