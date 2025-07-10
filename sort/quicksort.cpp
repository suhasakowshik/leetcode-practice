#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr,int low,int high)
{
    int pind=low+rand()%(high-low+1);
    swap(arr[pind],arr[high]);
    
    // pick pinot as last element
    int pivot = arr[high];
    int i=low;

    for(int j=low;j<high;++j)
    {
        if(arr[j]<pivot)
        {   
            swap(arr[i],arr[j]);
            ++i;
        }
    }
    swap(arr[i],arr[high]);
    return i;
}

void quicksort(vector<int>& arr,int low,int high)
{   
    if(low<high)
    {
        int pivot=partition(arr,low,high);
        quicksort(arr,low,pivot-1); //left sort
        quicksort(arr,pivot+1,high); //right sort
    }
}

int main()
{
    vector<int> arr{5,3,4,1,2};
    quicksort(arr,0,arr.size()-1);

    cout<<"Sorted array :";
    for(auto val:arr)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}