//Array 21)
#include <iostream> 
using namespace std; 
  
void findProfit(int array1[], int n) 
{ 
    
    int localMinima=0,localMaxima=0,profit=0;
    for(int i=0;i<n-1;i++){
        //next element is greater then i is a local minima
        if(localMinima==0 && array1[i+1]>=array1[i]){
            localMinima=array1[i];
            cout<<"LM="<<localMinima<<endl;
        }
        //next element is lesser then i is a localmaxima
        if(localMinima!=0 && array1[i+1]<array1[i]){
            profit+=(array1[i]-localMinima);
            localMinima=0;
            cout<<"LMAX="<<array1[i]<<endl;
        }
        
    }
    //ths is for a edge case like array is {5,4,2,3}
    //here localMinima=2 when i points to 2 but when i points to 3 it doesn't have
    //any next element but 3 is localMaxima so it added to profit
    if(localMinima!=0){
        profit+=(array1[n-1]-localMinima);
        cout<<"LMAX="<<array1[n-1]<<endl;
    }

    cout<<"Profit = "<<profit;
} 
  
int main() 
{ 
    int array1[] = { 7,1,5,3,6,4 }; 
    int n = sizeof(array1) / sizeof(array1[0]); 
  
    findProfit(array1, n); 
  
    return 0; 
} 
