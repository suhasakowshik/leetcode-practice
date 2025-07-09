#include<string>
#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

bool isAnagram(string s, string t)
{
   sort(s.begin(),s.end());
   sort(t.begin(),t.end());

   if(s==t)
   {
    return true;
   }
   else
   {
    return false;
   }
}

int main()
{
    string s="anagram";
    string t="nagaramaa";

    if(isAnagram(s,t))
    {
        cout<<"it is a anagram"<<"\n";
    }
    else
    {
        cout<<" it is not an anagram"<<"\n";
    }

    return 0;
}