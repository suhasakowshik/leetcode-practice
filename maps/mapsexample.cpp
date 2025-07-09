#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main()
{
    map<int,double> nodeValues;
    nodeValues[1]=2.5;
    nodeValues[3]=4.7;
    nodeValues[2]=1.1;

    cout<<"Ordered Map :\n";
    for(const auto& p:nodeValues)
    {
        cout<<p.first<<" : "<<p.second<<"\n";
    }

    unordered_map<int,double> fastLookup;
    fastLookup[10]=5.5;
    fastLookup[20]=6.6;
    fastLookup[15]=7.7;

    cout<<"\nUnordered Map : \n";
    for(const auto& p:fastLookup)
    {
        cout<<p.first<<" : "<<p.second<<"\n";
    }
    return 0;

}