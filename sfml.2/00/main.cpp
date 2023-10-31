#include <iostream>

int main()
{
    // цикл выводит числа от 1 до 100
    for (int num = 1; num <= 100; num += 1)
    {
        //   если остаток от деления на 3 равен 0
        if ((num % 3 == 0) && (num % 5 == 0))
        {
            // выводим Fizz
            std::cout << "FizzBuzz" << std::endl;
        }
        else if (num % 3 == 0)
        {
            // выводим Buzz
            std::cout << "Fizz" << std::endl;
        }
        else if (num % 5 == 0)
        {
            // выводим Buzz
            std::cout << "Buzz" << std::endl;
        }
        else
        {
            // выводим число num
            std::cout << num << std::endl;
        }
    }
}