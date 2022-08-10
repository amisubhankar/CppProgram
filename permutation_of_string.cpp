#include <iostream>
using namespace std;

// Function to find all Permutations of a given string str[i..n-1]
// containing all distinct characters
void permutations(string str, string op)
{
    if(str.length()==0){
        cout<<op<<endl;
        return;
    }
    for(int i=0;i<str.length();i++){
        permutations(str.substr(0,i)+str.substr(i+1),op+str[i]);
    }
}


int main()
{
    string str = "ABC";
    
    permutations(str, "");

    return 0;
}
