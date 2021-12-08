/*
You are given a string that contains alphabetical characters (a-z, A-Z)
and some other characters ($, !, etc.)

Expected time complexity O(n)
Expected space complexity O(n)

For example:
input: "sea!$hells3"
output: "sll!$ehaes3"
*/

#include <string>
#include <iostream>
#include <stack>

/*
I wrote this method, but it exits already in C++: isalpha(c)

This method assesses if the character is a letter (a-z)(A-Z).
@return true if it's a letter, else false
*/
bool isLetter(char const &c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    else
        return false;
}

std::string reverseOnlyAlphabetical(std::string const &input)
{
    std::string res;

    // ASCII values: A-Z(65-90) a-z(97-122)
    // int isalpha ( int c ); Checks whether c is an alphabetic letter.

    // loop to find all the letters and store them in a stack
    std::stack<char> st;
    for (auto c : input)
    {
        if (isalpha(c))
            st.push(c);
    }

    // loop to replace the letters in the inverse order
    for (auto c : input)
    {
        if (isalpha(c))
        {
            char current = st.top();
            st.pop();
            res.push_back(current);
        }
        else
            res.push_back(c);
    }
    return res;
}

std::string reverseOnlyAlphabeticalPointer(std::string const &input)
{
    std::string res;
    // pointer that iterates the string backwards
    int j = input.size() - 1;
    for (auto c : input)
    {
        if (isalpha(c))
        {
            while (isalpha(input[j]) == false)
            {
                j--;
            }
            res.push_back(input[j]);
            // change to the next character as the current character has been processed
            j--;
        }
        else
        {
            res.push_back(c);
        }
    }
    return res;
}

int main()
{
    std::string input = "sea!$hells3";
    for (auto c : input)
        std::cout << c;
    std::cout << std::endl;

    // Approach1: using stack
    std::string output = reverseOnlyAlphabetical(input);
    for (auto c : output)
        std::cout << c;
    std::cout << std::endl;

    // Approach2: using backward pointer
    std::string output1 = reverseOnlyAlphabeticalPointer(input);
    for (auto c : output1)
        std::cout << c;
    std::cout << std::endl;

    return 0;
}