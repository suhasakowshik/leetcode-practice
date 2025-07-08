#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if(nums.empty()) return 0;

    int i=0;
    for(int j=1;j<nums.size();++j)
    {
        if(nums[j]!=nums[i])
        {
            ++i;
            nums[i]=nums[j];
        }
    }

    return (i+1);
}

int main()
{
    vector<int> nums{1,1,2};
    int k = removeDuplicates(nums);

    cout << "Number of Unique Elements: " << k << "\n";
    cout << "Updated array: ";
    for(int i = 0; i < k; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}