#include<vector>
#include<iostream>

using namespace std;

// Two-Pointers leetcode data structures lesson
// O(n) run and O(1) space
vector<int> combine(vector<int>& arr1,vector<int>& arr2)
{
    vector<int> ans;

    int i=0,j=0;

    while(i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]<arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while(i<arr1.size())
    {
        ans.push_back(arr1[i]);
        i++;
    }

    while(j<arr2.size())
    {
        ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

int main()
{
    vector<int> a{1,4,7,20};
    vector<int> b{3,5,6};

    vector<int> c=combine(a,b);

    for(auto val:c)
    {
        cout<<val<<" ";
    }
    cout<<"\n";

    return 0;
}