//Array 13)
#include <iostream>
#include <math.h>
using namespace std;


pair<int, int> find2Element(int arr[],int n)
{
	//Write your code here
    pair<int,int> p;

    int xorRes=arr[0];
    for(int i=1;i<n;i++)
        xorRes^=arr[i];

    //making mask bit like if a number is 1110 right most set bit mask is 0010
    //can be done by below process
    int rightMostSetBit=xorRes & ~(xorRes-1);
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if((arr[i]&rightMostSetBit)!=0){
            a^=arr[i];
        }
        else
            b^=arr[i];
    }

    p.first=a;
    p.second=b;

	return p;
}

// Find two duplicate elements in a limited range array
int main()
{
	int arr[] = { 1,1,2,2,3,3,4,5,5,6,7,7 };

	pair<int, int> p = find2Element(arr,(sizeof(arr)/sizeof(int)));
	cout << "Elements are " << p.first << " and " << p.second;

	return 0;
}

/* Try more Inputs

case1:
actual = find2Element([2,4,7,9,2,4])
expected = 7,9

case2:
actual = find2Element([4,5,4,5,3,2,9,3,9,8])
expected = 2,8

case3:
actual = find2Element([1,1,2,2,3,3,4,5,5,6,7,7])
expected = 6,4
        

*/