#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>

/*
    Класс Number -- класс положительных больших чисел

    Большое число будет храниться в динамическом массиве data
    Каждый элемент этого массива содержит разряд числа в 100-ричной системе счисления
    (так как base = 100)
    По сути, каждый элемент data хранит две цифры числа в десятичной записи

    Значение 100 для системы счисления выбрано как компромисс между
    эффективностью и удобством написания программы.
    Если выбрать значения базы 10 - то программа будет не так эффективна по памяти
    Если выбрать значения базы 256 (максимально эффективное использование памяти для типа char),
    то алгоритм печати на экран сильно усложнится
    В качестве альтернативы, можно было выбрать базу 1e9, 
    изменив при этом тип элементов c char на int

    capacity - размер массива data
    size - сколько ячеек занимет число в массиве data
    size <= capacity

    Для удобства разряды числа хранятся в обратном порядке
    Например, число 12345678 соответствует массиву
    data = {78, 56, 34, 12}
    (это упрощает многие алгоритмы с такими числами)
*/


class Number 
{
private:
    static const int base = 100;
    std::size_t size;
    std::size_t capacity;
    char* data;

public:

    Number(int a) 
    {
        // Находим размер необходимой памяти под это число
        int temp = a;
        capacity = 0;
        while (temp != 0) 
        {
            temp /= base;
            capacity += 1;
        }

        // Отдельно обрабатываем случай, когда число равно 0
        if (capacity == 0) 
            capacity = 1;

        // Выделяем память и записывем число a в массив data
        // Например, число 12345678 представится в виде массива [78, 56, 34, 12]
        
        data = new char[capacity];

        for (int i = 0; i < capacity; ++i) 
        {
            data[i] = a % base;
            a /= base;
        }

        // В данном случае размер будет равен вместимости
        size = capacity;
    }
    
    Number () : Number (0) {};
    
    Number(const Number& n)
    {
        size = n.size;
        capacity = n.capacity;
        data = new char[capacity];
        for (int i = 0; i < capacity; ++i)
        {
            data[i] = n.data[i];
        }
    }

    Number(const char* str)
    {
        capacity = 0;
        size = 1;
        
        size_t slength = 1;
        if (str[0] == '0')
            capacity = 1;
        else
        {
            slength = strlen(str);
            capacity = slength / 2 + 1;
        }
        data = new char[capacity];
        char num = 0;
        int cap_counter = 0;
        for (int i = slength - 1; i >= 0; i -= 2)
        {
            if (i == 0)
                num = (str[i] - '0');
            else
                num = (str [i - 1] - '0') * 10 + (str[i] - '0');
            data[cap_counter] = num;
            cap_counter++;
        }
        size = cap_counter;
    }

    Number& operator=(const Number& right)
    {
        //std::cout << "Welcome to ASSignment\n";
        size = right.size;
        capacity = right.capacity;
        data = new char[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = right.data[i];
        }
        //std::cout << right.data << std::endl;
        //std::cout << data << std::endl;
        return *this;
    }
    
    Number operator+ (const Number& right)
    {
        //std::cout << "[INFO] welc to PLUS\n";
        std::size_t max_size = (right.size > size) ? right.size : size;
        std::size_t min_size = (right.size < size) ? right.size : size;
        std::size_t difference = max_size - min_size;
        
        Number result;
        result.size = max_size;
        result.capacity = max_size + 1;
        delete [] result.data;
        result.data = new char[result.size];
        int temporary = 0;
        bool add = 0;
        
        for (std::size_t i = 0; i < min_size; i++)
        {
            temporary = right.data[i] + data[i] + add;
            if (temporary >= 100)
            {
                temporary -= 100;
                add = 1;
            }
            else
                add = 0;
            result.data[i] = temporary;
            //std::cout << result.data << " на шаге " << i << std::endl;
        }
        
        //std::cout << "difference is " << add << std::endl;
        if (difference > 0)
        {
            if (right.size > size)
                for (;difference > 0; difference--)
                {
                    result.data[right.size - difference] = right.data[right.size - difference] + add;
                    add = 0;
                }
            else
                for (;difference > 0; difference--)
                {
                    result.data[size - difference] = data[size - difference] + add;
                    add = 0;
                }
        }
        
        if (add == 1)
        {
            result.size = max_size + 1;
            result.data[max_size] = 1;
            //std::cout << "meow " << result <<  std::endl;
        }
        else
        {
            //std::cout << "meow111 " << result <<  std::endl;
        }
        
        //std::cout << result.data <<  std::endl;
        return result;
    }
    
    Number operator+= (Number& right)
    {
        *this = *this + right;
        return *this;
    }
    
    void show_data ()
    {
        std::cout << "show data: " << data << std::endl;
    }
    
    Number F (int x)
    {
        Number var1 = Number {0};
        Number var2 = Number {1};
        Number var3;
        for (int i = 0; i < x - 1; i++)
        {
            var3 = var1 + var2;
            var1 = var2;
            var2 = var3;
        }
        return var3;
    }
    
    bool isEven () const
    {
        int temp = data[0] % 2;
        
        return (temp == 0) ? true : false;
    }

    ~Number() 
    {
        delete [] data;
    }


    friend std::ostream& operator<<(std::ostream& stream, const Number& right);
};



std::ostream& operator<<(std::ostream& stream, const Number& right)
{
    // Печатаем самый большой разряд
    stream << (int)right.data[right.size - 1];

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw это то же самое, что и в языке C спецификатор %02d
    for (std::size_t i = 0; i < right.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << (int)right.data[right.size - 2 - i];

    return stream;
}

int main() 
{
    Number x = 2;
    Number y;
    y = Number{"60"};
    std::cout << y.isEven() << " " << y << std::endl;
    
    Number z;
    z = Number{"0"};
    //z.show_data ();
    x = y + z;
    //std::cout << x.F(1000) << std::endl;
}
