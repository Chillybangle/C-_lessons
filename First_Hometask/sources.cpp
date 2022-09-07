#include <iostream>

void cubeR (int& number);
void cubeV (int* number);
/*!
 * Принимает на вход строку str и подсчитывает число букв и цифр в этой строке.
 * Количество букв нужно записывает в переменную n_letters, количество цифр – в переменную n_digits,
 * а количество остальных символов – в переменную n_other.
 */
void count_letters(char str[], int& n_letters, int& n_digits, int& n_other);

int main ()
{
    int n = 3;
    cubeR (n);
    cubeV (&n);
    std::cout << n << std::endl;
    
    char str[] = "There are 3 numbers and 25 letters";
    int n_letters = 0;
    int n_digits = 0;
    int n_other = 0;
    count_letters (str, n_letters, n_digits, n_other);
    std::cout << "Буквы Цифры Другое" << '\n';
    std::cout << n_letters << "\t" << n_digits << "\t" << n_other << std::endl;
}

void cubeV (int* number)
{
    *number = (*number) * (*number) * (*number);
}

void cubeR (int& number)
{
    number = number * number * number;
}

void count_letters(char str[], int& n_letters, int& n_digits, int& n_other)
{
    for (; *str; str++)
    {
        if (isdigit (*str))
            n_digits++;
        else if (isalpha (*str))
            n_letters++;
        else
            n_other++;
    }
}
