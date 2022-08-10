#include<iostream> 
#include<string>
using namespace std; 
  
const int no_of_chars = 256; 
  
// Function to find smallest window containing 
// all characters of 'ptr' 
int findMinWindow(string str, string ptr) 
{
    int ascii_str[no_of_chars]={0};
    //making ascii array or ptr
    int ascii_ptr[no_of_chars]={0};
    for(int i=0;i<ptr.length();i++){
        ascii_ptr[ptr[i]]++;
    }

    int count=0;
    int window=INT8_MAX;
    int strt=0;
    for(int j=0;j<str.length();j++){
        ascii_str[str[j]]++;

        //1st condition-> str[j] present in substring or not
        //2nd condition->if present,check frequency of str[j] is less r equal to ptr's frequency
        if(ascii_ptr[str[j]]!=0 && ascii_str[str[j]]<=ascii_ptr[str[j]])
            count++;
        if(count==ptr.length()){
            //try to reduce size by 2 condtn.
            //1st->if str[strt] isn't present in ptr
            //2nd->if present, then if frequency of str[j] is > frequency of that char in ptr
            while(ascii_ptr[str[strt]]==0 || ascii_str[str[strt]]>ascii_ptr[str[strt]]){
                ascii_str[str[strt]]--;
                strt++;
            }
            
            window=min(window,j-strt+1);
        }
    }
    
    return window;

} 
  

int main() 
{ 
    string str = "ADOBECODEBANC"; 
    string ptr = "ABC"; 
  
    cout << "Smallest window is : \n"<< findMinWindow(str, ptr); 
    return 0; 
} 

/* Try more Inputs
case 1: 
actual = findMinWindow("a","a")
expected = Smallest window is : a

case2: 
 actual = findMinWindow("zaaskzaa", "zsk")
 expected = Smallest window is : skz
 
case3: 
actual = findMinWindow("tutorial","oti")
expected = Smallest window is : tori


*/