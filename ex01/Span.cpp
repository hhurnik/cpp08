#include "Span.hpp"
#include <algorithm>

Span::Span() : _numbers(), _maxSize(0)
{
}

Span::Span(unsigned int n) : _numbers(), _maxSize(n)
{
    _numbers.reserve(n);
}

Span::Span(const Span &other) : _numbers(other._numbers), _maxSize(other._maxSize)
{
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw SpanFullException();
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    //after sorting, the shortest span must be between neighboring values
    unsigned int shortest = distanceBetween(sorted[0], sorted[1]);
    for (std::vector<int>::size_type i = 2; i < sorted.size(); ++i)
    {
        unsigned int current = distanceBetween(sorted[i - 1], sorted[i]);
        if (current < shortest)
            shortest = current;
    }
    return shortest;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    //the longest span is the distance between the smallest and biggest values
    return distanceBetween(sorted.front(), sorted.back());
}

unsigned int Span::distanceBetween(int low, int high)
{
    long left = static_cast<long>(low);
    long right = static_cast<long>(high);

    return static_cast<unsigned int>(right - left);
}

const char *Span::SpanFullException::what() const throw()
{
    return "span is full";
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
    return "not enough numbers to calculate a span";
}