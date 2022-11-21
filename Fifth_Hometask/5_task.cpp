#include <algorithm>
#include <string>
#include <iostream> 

int spaceINend (std::string& string);

int main ()
{
    std::string s = "cats and dogs";
    spaceINend (s);
    std::cout << "\'" << s << "\'" << std::endl;
}

int spaceINend (std::string& string)
{
    int nspaces = 0;
	std::string str_result = "";
    
	for (int i = 0; i < string.length(); i++) {
		if (string[i] != ' ') {
			str_result += string[i];
		}
		else {
			nspaces += 1;
		}
	}
	
	while ((nspaces--) != 0) {
		str_result += ' ';
	}
	
	string = str_result;
    
    return 0;
}
