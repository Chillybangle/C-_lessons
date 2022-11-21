#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    int arr_size = 0;
    cin >> arr_size;
    
    vector<int> array;
    
    int temp = 0;
    for (int i = 0; i < arr_size; i++)
    {
        cin >> temp;
        array.push_back(temp);
    }
    
    vector<int>::iterator max_elem_it = std::max_element (array.begin(), array.end());
    
    std::sort (array.begin(), max_elem_it);
    std::sort (array.rbegin(), vector<int>::reverse_iterator (max_elem_it));
    
    for (int i = 0; i < arr_size; i++)
        cout << array[i] << " ";
}
