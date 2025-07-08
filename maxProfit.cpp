#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
    if(prices.empty()) return 0;
    int profit = 0;

    for(int i = 1; i < prices.size(); ++i)
    {
        if(prices[i] > prices[i-1])
        {
            profit += prices[i] - prices[i-1];
        }
    }

    return profit;
}


int main()
{
    vector<int> nums{7,1,5,3,6,4};
    int k = maxProfit(nums);

    cout << "Max Profit: " << k << "\n";

    return 0;
}