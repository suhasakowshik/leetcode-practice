#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int singleNumber(vector<int>& nums)
{
    sort(nums.begin(),nums.end());

    for(int i=0;i<n-1;i+=2)
    {
        if(nums[i]!=nums[i+1])
        {
            return nums[i];
        }
    }

    return nums[n-1];
}

int main()
{
    vector<int> nums{4,1,2,1,2};

    int k=singleNumber(nums);

    cout<<"Single Number : "<<k<<endl;

    return 0;
}