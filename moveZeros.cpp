#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void moveZeroes(vector<int>& nums) 
{
    int n=nums.size();
    vector<int> t1,t2,t3;

    if(n==1 && nums[0]==0)
    {
        nums;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                t2.push_back(nums[i]);
            }
            else
            {
                t1.push_back(nums[i]);
            }
        }

        nums.clear();
        nums.insert(nums.end(), t1.begin(), t1.end());
        nums.insert(nums.end(), t2.begin(), t2.end());
    }
}

int main()
{
    vector<int> nums{0};

    moveZeroes(nums);

    for(auto val : nums)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}