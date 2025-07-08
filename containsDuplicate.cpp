#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool containsDuplicate(vector<int>& nums) 
{
    int n=nums.size();
    sort(nums.begin(),nums.end());

    for(int i=1;i<n;++i)
    {
        if(nums[i]==nums[i-1])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> nums{1,2,3};

    if(containsDuplicate(nums))
    {
        cout<<" Contains duplicate"<<"\n";
    }
    else
    {
        cout<<" NO duplicate"<<"\n";
    }

    return 0;
}