
// C++ program to convert string
// to char array using c_str()
#include <cstring>
#include <string>
#include <iostream>

// driver code
int main()
{
    // assigning value to string s
    std::string s = "geeksforgeeks";

    char ca[s.length() + 1];

    strcpy(ca, s.c_str());

    for (int i = 0; i < s.length(); i++)
    {
        std::cout << ca[i];
    }
}