#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> plusOne(vector<int>& digits) 
{
    int n = digits.size();

    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] < 9)
        {
            digits[i] += 1;
            while (digits.size() > 1 && digits[0] == 0)
            {
                digits.erase(digits.begin());
            }
            return digits; 
        }
        digits[i] = 0;
    }

    digits.insert(digits.begin(), 1);
    return digits;
}


int main()
{
    vector<int> nums{0,1,2,3};

    auto out=plusOne(nums);

    for(auto val : out)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}

