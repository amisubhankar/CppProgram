//Array 22)
#include <iostream>
#include <string>
using namespace std;
 
// Function to remove duplicates
void removeDuplicates(string str)
{
    //write your code here
    int arr[26]={0};
    string finalStr="";
    for(int i=0;i<str.length();i++){
        if(arr[str[i]-97]==0){
            finalStr+=str[i];
            arr[str[i]-97]=1;
        }
    }
    cout<<finalStr;
}
 

int main()
{
    string str = "cbacdcbc";
    removeDuplicates(str);
    return 0;
}