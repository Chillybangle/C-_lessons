#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> str_vect_reverse (std::vector<std::string> vector_of_str);

int main ()
{
    std::vector<std::string> vector_of_str = {"abc", "def"};
    
    vector_of_str = str_vect_reverse (vector_of_str);
    
    std::cout << "Test:" << endl;
    for (auto it = vector_of_str.begin(); it != vector_of_str.end(); it++)
        std::cout << *it;
    std::cout <<  endl;
}

std::vector<std::string> str_vect_reverse (std::vector<std::string> vector_of_str)
{
    size_t size = vector_of_str.size();
    
    for (size_t counter = 0; counter < size; counter++)
    {
        std::reverse (vector_of_str[counter].begin(), vector_of_str[counter].end());
    }
    
    std::reverse (vector_of_str.begin(), vector_of_str.end());
    
    return vector_of_str;
}
