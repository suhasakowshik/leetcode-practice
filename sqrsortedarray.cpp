#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> sortedSqures(vector<int>& nums)
{   
    int n=nums.size();
    vector<int> result(n);

    int left=0;
    int right=n-1;
    int pos=n-1;

    while (left<=right)
    {
        int leftSq=nums[left]*nums[left];
        int rightSq=nums[right]*nums[right];

        if(leftSq>=rightSq)
        {
            result[pos]=leftSq;
            ++left;
        }
        else
        {
            result[pos]=rightSq;
            --right;
        }
        --pos;
    }
    return result;
}

int main()
{   
    vector<int> nums{-4,-1,0,3,10};
    vector<int> sqrSortArr;

    sqrSortArr=sortedSqures(nums);

    for(auto val:sqrSortArr)
    {
        cout<<val<<" ";
    }
    cout<<"\n";

    
    return 0;
}