#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    int n1=nums1.size();
    int n2=nums2.size();
    int i=0;
    int j=0;
    vector<int> nums;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    while(i<n1 && j<n2)
    {
        if(nums1[i]==nums2[j])
        {
            nums.push_back(nums1[i]);
            ++i;
            ++j;
        }
        else if(nums1[i]<nums2[j])
        {   
            ++i;
        }
        else
        {
            ++j;
        }
    }
    return nums;
}

int main()
{
    vector<int> nums1{4,9,5};
    vector<int> nums2{9,4,9,8,4};

    auto nums=intersect(nums1,nums2);

    for(auto val : nums)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}