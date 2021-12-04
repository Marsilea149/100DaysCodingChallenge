#include <iostream>
#include <string>
#include <stack>
#include <string.h>

/** Brute force O(n) **/
std::string reverseAString(std::string const &input)
{
    //declare a stack to use FILO property
    std::stack<char> s;
    //declare the string to store the result
    std::string res;
    for (auto c : input)
    {
        s.push(c);
    }
    while (s.size())
    {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

/** Two pointers O(n) **/
char *reverseWithTwoPointers(char *pString)
{
    if (!pString)
        return nullptr;

    char *pStart = pString;
    char *pEnd = pStart + strlen(pString) - 1;

    while (pEnd > pStart)
    {
        char tmp = *pStart;
        *pStart = *pEnd;
        *pEnd = tmp;

        //update the pointers
        pStart++;
        pEnd--;
    }
    return pString;
}

int main()
{
    std::string sIn = "abcd";
    std::cout << "Input string is: " << sIn << std::endl;
    std::string sOut = reverseAString(sIn);
    std::cout << "Output string is: " << sOut << std::endl;

    char sIn1[100] = "efgh";
    std::cout << "Input string is: " << sIn1 << std::endl;
    std::cout << "Output string (with 2 pointers) is: " << reverseWithTwoPointers(sIn1) << std::endl;
    return 0;
}