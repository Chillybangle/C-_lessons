#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

bool isIdentifier(std::string_view s);

int main ()
{
    std::string s = "hello world";
    
    bool result = isIdentifier (s);
    
    std::cout << result << std::endl;
}

bool isIdentifier(std::string_view s)
{
    if (!isalpha(s[0]))
        if (s[0] != '_')
            return false;
    
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (!isalnum(*it))
            if (*it != '_')
                return false;
    }
    
    return true;
}
