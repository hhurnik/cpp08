#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

static void testVector(void)
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    //std::find returns an iterator to the first matching value
    std::vector<int>::iterator it = easyfind(numbers, 20);
    std::cout << "vector found: " << *it << std::endl;

    *it = 200;
    std::cout << "vector changed value: " << numbers[1] << std::endl;
}

static void testList(void)
{
    std::list<int> numbers;

    numbers.push_back(7);
    numbers.push_back(8);
    numbers.push_back(9);

    //list has no operator[], so iterators are the correct STL way
    std::list<int>::iterator it = easyfind(numbers, 9);
    std::cout << "list found: " << *it << std::endl;
}

static void testConstDeque(void)
{
    std::deque<int> tmp;

    tmp.push_back(1);
    tmp.push_back(2);
    tmp.push_back(3);

    const std::deque<int> numbers(tmp);

    //const containers must return const_iterator
    std::deque<int>::const_iterator it = easyfind(numbers, 2);
    std::cout << "const deque found: " << *it << std::endl;
}

static void testMissingValue(void)
{
    std::vector<int> numbers;

    numbers.push_back(42);

    try
    {
        easyfind(numbers, -1);
        std::cout << "this line should not be printed" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "missing value: " << e.what() << std::endl;
    }
}

int main(void)
{
    testVector();
    testList();
    testConstDeque();
    testMissingValue();
    return 0;
}