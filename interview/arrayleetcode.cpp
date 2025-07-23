#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
#include<unordered_map>
using namespace std;

int removeDuplicates(vector<int>& nums) 
{
    sort(nums.begin(),nums.end());

    int i=0;

    for(int j=1;j<nums.size();j++)
    {
        if(nums[j]!=nums[i])
        {
            ++i;
            nums[i]=nums[j];
        }
    }

    nums.resize(i+1);
    return i+1;
}


void rotate(vector<int>& nums, int k) 
{
    vector<int> test;
    int n=nums.size();
    k=k%n;
    for(int i=n-k;i<n;i++)
    {
        test.push_back(nums[i]);
    }
    for(int i=0;i<n-k;i++)
    {
        test.push_back(nums[i]);
    }

    nums=test;

}

bool containsDuplicate(vector<int>& nums) 
{
    unordered_map<int,int> freq;
    for(auto s:nums)
    {
        freq[s]++;
    }

    for(int i=0;i<nums.size();i++)
    {
        if(freq[nums[i]]>1)
        {
            return true;
        }
    }
    return false;
}

vector<int> twoSum(vector<int>& nums, int target) 
{

    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]+nums[j]==target)
            {
                return {i,j};
            }
        }
    }

    return {-1};
}


int main()
{   
    // vector<int> nums{1,2,2,3,3,3,7,7,4,4,4};
    // auto i=removeDuplicates(nums);
    // cout<<"Final size after remove duplicates: "<<i<<"\n";
    // for(auto s:nums)
    // {
    //     cout<<s<<" ";
    // }
    // cout<<endl;

    // vector<int> nums{1,2,2,3,3,3,7,7,4,4,4};
    // rotate(nums,3);
    // for(auto s:nums)
    // {
    //     cout<<s<<" ";
    // }
    // cout<<endl;

    // vector<int> nums{1,2,3};
    // if(containsDuplicate(nums))
    // {
    //     cout<<"Contains atleast one duplicate"<<endl;
    // }
    // else{
    //     cout<<"No duplicate"<<endl;
    // }

    vector<int> nums{3,2,4};
    int target=6;

    auto s= twoSum(nums,target);
    for(int c:s)
    {
        cout<<c<<" ";
    }
    cout<<endl;

    return 0;
}