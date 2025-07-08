#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int>> v;

    // Store value and original index
    for(int i=0; i<nums.size(); i++)
    {
        v.push_back({nums[i], i});
    }

    // Sort by value
    sort(v.begin(), v.end());

    int left = 0, right = nums.size() - 1;

    while(left < right)
    {
        int sum = v[left].first + v[right].first;

        if(sum == target)
        {
            return {v[left].second, v[right].second};
        }
        else if(sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return {}; // No solution
}

int main()
{
    vector<int> nums = {3, 2, 4};
    int target = 6;

    auto result = twoSum(nums, target);

    for(auto i : result)
        cout << i << " ";
    cout << endl;

    return 0;
}
