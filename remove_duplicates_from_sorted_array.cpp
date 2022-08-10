//Array 6)
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   int removeDuplicates(vector<int>& nums) {
      //Write your code here
      int i=0,j=1;

     //when array is empty or have a single element.
      if(nums.size()<=1)
        return nums.size();
     
     //i always points to just replaced item.     
      while(j<nums.size()){
        if(nums[i]==nums[j])
            j++;
        else
            nums[++i]=nums[j++];
      }

      return (i+1);
   }
};
int main(){
   Solution ob;
   vector<int> v = {0,0,1,2,2,2,3,4};
   cout << ob.removeDuplicates(v);
}