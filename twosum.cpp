#include<iostream>
#include<vector>

// Two-Pointers leetcode data structures lesson
// O(n) run and O(1) space

bool checkTarget(std::vector<int>& t,int target)
{
    int left=0;
    int right=t.size()-1;

    while(left<right)
    {
        int sum=t[left]+t[right];

        if(sum==target)
        {
            return true;
        }
        else

        if(sum>target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return false;
}

int main()
{   
    std::vector<int> s{1,2,3,4,5,6,7,8,9,10};
    int target=9;

    if(checkTarget(s,target))
    {
        std::cout<<"it is a twosum"<<"\n";
    }
    else
    {
        std::cout<<"it is not a twosum"<<"\n";
    }
    return 0;

    return 0;
}
