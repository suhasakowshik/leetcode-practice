#include <vector>
#include <iostream>
using namespace std;

void bubbleSort(vector<int>& arr)
{
    int n=arr.size();
    bool swapped;

    for(int pass=0;pass<n-1;++pass)
    {
        swapped=false;
        for(int i=0;i<n-1-pass;i++)
        {   
            if(arr[i]>arr[i+1])
            {
            swap(arr[i],arr[i+1]);
            swapped=true;
            }
        }
        if(!swapped) break;
    }
}

void merge(vector<int>& arr, int left, int mid, int right)
{
    vector<int> temp;

    int i=left;
    int j=mid+1;
    while(i<=mid && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    // Copy remaining elements
    while(i<=mid) temp.push_back(arr[i++]);
    while(j<=right) temp.push_back(arr[j++]);

    // Copy sorted temp back to original
    for(int k=0;k<temp.size();k++)
    {
        arr[left+k]=temp[k];
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if(left>=right) return;

    int mid=left+(right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);

    merge(arr,left,mid,right);
}


int main() {
    std::vector<int> nums = {5, 3, 4, 1,-9,90};
    //bubbleSort(nums);
    mergeSort(nums,0,nums.size()-1);

    for (int x : nums) std::cout << x << " ";
    cout<<endl;
}