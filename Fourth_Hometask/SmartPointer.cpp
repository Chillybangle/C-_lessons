#include <iostream>
#include <string>
using namespace std;
template <typename Type>
class SmartPointer
{
private:
    Type* pointer;
    
public:
    SmartPointer (Type* p)
    {
        if (p != NULL)
            pointer = p;
        else
            cout << "Warning! This pointer is a NULL-pointer" << endl;
    }
    
    Type& operator* ()
    {
        return *pointer;
    }
    
    ~SmartPointer ()
    {
        delete pointer;
    }
};
int main()
{
    SmartPointer<int> pi = new int(123);
    SmartPointer<string> ps = new string("Hello");
    *pi = 543;
    *ps = "World";
    cout << *pi << " " << *ps << endl;
    // Освобождать не нужно, так как всё освободится в деструкторе
    // Таким образом, память всегда освободится
} 
