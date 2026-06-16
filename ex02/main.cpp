#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

static void testSubjectExample()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    //MutantStack iterators walk through the underlying container
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    //public inheritance allows a MutantStack to be copied into std::stack
    std::stack<int> s(mstack);
    std::cout << "copied stack top: " << s.top() << std::endl;
}

static void testConstIteration()
{
    MutantStack<int> mstack;

    mstack.push(10);
    mstack.push(20);
    mstack.push(30);

    const MutantStack<int> constStack(mstack);
    MutantStack<int>::const_iterator it = constStack.begin();
    MutantStack<int>::const_iterator ite = constStack.end();

    while (it != ite)
    {
        std::cout << "const item: " << *it << std::endl;
        ++it;
    }
}

static void testListComparison()
{
    std::list<int> list;

    list.push_back(5);
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();

    while (it != ite)
    {
        std::cout << "list item: " << *it << std::endl;
        ++it;
    }
}

int main()
{
    testSubjectExample();
    testConstIteration();
    testListComparison();
    return 0;
}