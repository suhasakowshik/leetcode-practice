#include<string>
#include<iostream>

using namespace std;

bool checkSubsq(string s,string t)
{
    int i=0,j=0;

    while(i<s.size() && j<t.size())
    {
        if(s[i]==t[j])
        {
            i++;
        }
        j++;
    }

    return i==s.size();

}

int main()
{
    string t="abcde";
    string s="ace";

    if(checkSubsq(s,t))
    {
        cout<<s<<" is a subsequence of "<<t<<"\n";
    }
    else
    {
        cout<<s<<" is not subsequence of "<<t<<"\n";
    }

    return 0;
}
