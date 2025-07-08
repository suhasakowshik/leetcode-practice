#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void rotate(vector<int>& nums, int k)
{
     int n = nums.size();
    k = k % n;

    // Reverse the whole array
    reverse(nums.begin(), nums.end());
    // Reverse first k elements
    reverse(nums.begin(), nums.begin() + k);
    // Reverse remaining n-k elements
    reverse(nums.begin() + k, nums.end());
    
}


int main()
{
    vector<int> nums{-1,-100,3,99};
    int k = 2;

    rotate(nums,k);

     for(int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}