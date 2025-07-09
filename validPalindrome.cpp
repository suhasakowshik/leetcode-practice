#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <cctype> 
using namespace std;

bool isPalindrome(string s)      
{   
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    s.erase(remove_if(s.begin(), s.end(), [](char c){ return !isalnum(c); }), s.end());

    int left=0;
    int right=s.size()-1;

    while(left<right)
    {
        if(s[left]!=s[right])
        {
            return false;
        }

        left++;
        right--;
    }
    return true;
}

int main()
{
    string s="0P";

    if(isPalindrome(s))
    {
        std::cout<<s<<" is a valid palindrome"<<"\n";
    }
    else
    {
        std::cout<<s<<" is not a valid palindrome"<<"\n";
    }
    return 0;
}