#include<iostream>
#include<string>

// O(n) run and O(1) space

bool checkIfPalindrom(std::string s)
{
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
    std::string s="suhas";

    if(checkIfPalindrom(s))
    {
        std::cout<<s<<" is a palindrome"<<"\n";
    }
    else
    {
        std::cout<<s<<" is not a palindrome"<<"\n";
    }
    return 0;
}