#include <iostream>
using namespace std;
// recursive solution to calculate pow(x, n)
// using Divide & Conquer
float power(int x, int p)
{
    //for negative power
    if(p<0){
        return 1/power(x,p*-1);
    }
    //base condtion
    if(p==0)    return 1;
    else if(p%2==0){
        int n=power(x,p/2);
        return n*n;
    }
    else{
        int n=power(x,p/2);
        return x*n*n;
    }
}

int main(void)
{
	int x = 2;
	int n = -3;

	cout<<"pow("<<x<<","<<n<<") = "<<power(x, n);

	return 0;
}