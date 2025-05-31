#include<string>
#include<iostream>

using namespace std;

string reverseString(string s)
{
    int left=0;
    int right=s.size()-1;

    while(left<right)
    {
        const char temp=s[left];
        s[left++]=s[right];
        s[right--]=temp;
    }

    return s;
}

int main()
{   
    string s="Suhas A Kowshik";

    string rs=reverseString(s);

    cout<<rs<<" is reversed string of "<<s<<"\n";

    return 0;
}