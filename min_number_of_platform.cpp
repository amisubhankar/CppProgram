//Array 9)
#include<iostream>
#include<algorithm>
using namespace std;

int minPlatform(int arrival[], int departure[], int n) {
   
   sort(departure,departure+n);
   
   int i=0,j=0,platform_need=0;
   int max_platform=0;
   
   while(i<n && j<n){
       if(arrival[i]<=departure[j]){
           platform_need++;
           i++;
           if(platform_need>max_platform){
               max_platform=platform_need;
           }
       }
       else{
           platform_need--;
           j++;
       }
   }
   
   return max_platform;
   
}

int main() {
   int arrival[] = {900, 1100, 1235};
   int departure[] = {1000, 1200, 1240};
   int n = sizeof(arrival)/sizeof(int);
   cout << "Minimum Number of Platforms Required: " << minPlatform(arrival, departure, n);
}

/* Try more Inputs
case 1: 
actual = minimumNumberOfPlatform([900,940,950,1100,1500,1800],[910, 1200, 1120, 1130, 1900, 2000],6)
expected = 3

case2: 
actual = minimumNumberOfPlatform([200, 210, 300, 320, 350, 500],[230, 340, 320, 430, 400, 520],6)
expected = 3
 
case3: 
actual = minimumNumberOfPlatform([900, 1100, 1235],[1000, 1200, 1240],3)
expected = 1
*/