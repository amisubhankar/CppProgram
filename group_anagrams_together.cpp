//Hashing 9)
//create a map whose key = a map contains frequency of character
//value  = string which have same key(frequency map)
#include<iostream>
#include<vector>
#include<map>
using namespace std;

void group_anagrams(string str_arr[],int n){
    map<map<char,int>,vector<string>> bigmp;

    for(int i=0;i<n;i++){
        //creating frequency map
        map<char,int> mp;
        string str=str_arr[i];
        for(int i=0;i<str.length();i++){
            mp[str[i]]++;
        }
        //push strings into big map acc to frequency map
        bigmp[mp].push_back(str);
    }

    //printing anagrams 
    for(auto itr=bigmp.begin();itr!=bigmp.end();itr++){
        for(string str: itr->second)
            cout<<str<<" ";
        cout<<endl;

        // for(auto itr1=itr->first.begin();itr1!=itr->first.end();itr1++)
        //     cout<<itr1->first<<itr1->second;
        // cout<<endl;
    }
}

int main(){
    string str_arr[]={"eat", "tea", "tan", "ate", "nat", "bat"};
    int n=sizeof(str_arr)/sizeof(string);

    group_anagrams(str_arr,n);
}