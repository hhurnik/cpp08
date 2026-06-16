#include "Span.hpp"
#include <iostream>
#include <vector>

static void testSubjectExample()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "subject shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "subject longest: " << sp.longestSpan() << std::endl;
}

static void testTooFewNumbers()
{
    Span sp(1);

    sp.addNumber(42);
    try
    {
        sp.shortestSpan();
    }
    catch (const std::exception &e)
    {
        std::cout << "too few numbers: " << e.what() << std::endl;
    }
}

static void testFullSpan()
{
    Span sp(2);

    sp.addNumber(1);
    sp.addNumber(2);
    try
    {
        sp.addNumber(3);
    }
    catch (const std::exception &e)
    {
        std::cout << "full span: " << e.what() << std::endl;
    }
}

static void testRangeInsert()
{
    std::vector<int> values;

    for (int i = 0; i < 10000; ++i)
        values.push_back(i * 2);

    Span sp(values.size());

    //addRange fills the Span with one iterator range instead of many calls
    sp.addRange(values.begin(), values.end());

    std::cout << "range shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "range longest: " << sp.longestSpan() << std::endl;
}

static void testDuplicates()
{
    Span sp(4);

    sp.addNumber(5);
    sp.addNumber(100);
    sp.addNumber(5);
    sp.addNumber(-10);

    std::cout << "duplicates shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "duplicates longest: " << sp.longestSpan() << std::endl;
}

int main()
{
    testSubjectExample();
    testTooFewNumbers();
    testFullSpan();
    testRangeInsert();
    testDuplicates();
    return 0;
}