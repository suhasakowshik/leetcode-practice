#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cctype>
using namespace std;

void reverseString(vector<char>& s)
{
    int i=0;
    int j=s.size()-1;
    char t1,t2;

    while(i<j)
    {
        t1=s[i];
        t2=s[j];
        s[i]=t2;
        s[j]=t1;
        ++i;
        --j;
    }
}

int reverseInteger(int x)
{
    int out=0;

    while(x!=0)
    {
        int d=x%10;
        x/=10;

        out=out*10+d;
    }
    return out;
}

int firstUniqChar(string s) 
{
    unordered_map<char,int> freqMap;
    for(char c:s)
    {
        freqMap[c]++;
    }

    for(int i=0;i<s.size();i++)
    {
        if(freqMap[s[i]]==1)
        {
            return i;
        }
    }

    return -1;
}

bool isAnagram(string s,string t)
{
    if(s.size()!=t.size()) return false;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    return s==t;
}

bool isPalindrome(string s)
{
    
    string clean;

    for(char c:s)
    {
        if(isalnum(c))
        {
            clean+=tolower(c);
        }
    }

    int n=clean.size();
    int i=0;
    int j=n-1;
    while(i<j)
    {
        if(clean[i]!=clean[j]) return false;

        ++i;
        --j;

    }
    return true;
}

int strStr(string haystack, string needle) 
{
    int h=haystack.size();
    int n=needle.size();

    if(n==0) return 0;
    if(h==1 && n==1) return 0;

    for(int i=0;i<=h-n;i++)
    {
        int j=0;
        for(;j<n;j++)
        {
            if(needle[j]!=haystack[i+j])
            {
                break;
            }
        }

        if(j==n) return i;
    }

    return -1;
    
}

int main()
{
    // vector<char>  s = {'h','e','l','l','o','s'};
    // reverseString(s);
    // cout<<"Reverse string is : \n";
    // for(char v:s)
    // {
    //     cout<<v<<" ";
    // }

    // int x=123;
    // auto rx=reverseInteger(x);
    // cout<<"reversed integer : "<<rx<<"\n";

    // string s="aabb";
    // int c=firstUniqChar(s);
    // cout<<"First unique char index: "<<c<<"\n";

    // string s="cat";
    // string t="rat";

    // if(isAnagram(s,t))
    // {
    //     cout<<s<<" and "<<t<<" are anagram"<<"\n";
    // }
    // else
    // {
    //     cout<<s<<" and "<<t<<" are not anagram"<<"\n";
    // }

    // string s="a man, a plan, a canal: panama";

    // if(isPalindrome(s))
    // {
    //     cout<<s<<" is a palindrome"<<"\n";
    // }
    // else
    // {
    //      cout<<s<<" is not a palindrome"<<"\n";
    // }

    string s="abc";
    string t="c";
    auto i=strStr(s,t);
    cout<<t<<" is in "<<s<<" at "<<i<<endl;

    return 0;
}