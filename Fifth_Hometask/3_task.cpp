#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

bool string_isup (std::string& string);

int main ()
{
    std::string string = "ABc123#!&";
    bool result = string_isup (string);
    
    std::cout << "Test:" << std::endl;
    std::cout << result << std::endl;
}

bool string_isup (std::string& string)
{
    bool result = true;
    
    for (std::string::iterator it = string.begin(); it != string.end(); it++)
    {
        if (islower(*it))
            return false;
    }
    
    return result;
}
