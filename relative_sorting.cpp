//hashing 2)
#include <map>
#include <iostream>
using namespace std;
 
void customSort(int arr1[], int arr2[], int m, int n)
{
    map<int,int> mp;

    //count frequency of 1st array
    for(int i=0;i<m;i++){
        mp[arr1[i]]++;
    }

    //update acc to arr2 element
    int index=0;
    for(int i=0;i<n;i++){
        int count=mp[arr2[i]];

        while(count!=0){
            arr1[index++]=arr2[i];
            count--;
        }

        mp.erase(arr2[i]);
    }

    //update the rest elements which are not present in 2nd array
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        int count=itr->second;

        while(count!=0){
            arr1[index++]=itr->first;
            count--;
        }
    }
}
 
int main()
{
    int arr1[] = { 5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4 };
    int arr2[] = { 3, 5, 7, 2 };
 
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
 
    customSort(arr1, arr2, m, n);
 
    cout << "After sorting the array is : ";
    for (int i = 0; i < m; i++)
        cout << arr1[i] << " ";
    cout << endl;
 
    return 0;
}