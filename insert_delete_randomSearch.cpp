#include <iostream>
#include<map>
#include<vector> 
  
using namespace std; 
  
class findRandom { 
private: 
    vector<int> arrays; 
    map<int, int> map; 
  
public: 
    bool insert(int val) 
    {
        //element is already there so no insertion
        if(map.find(val)!=map.end())
            return false;
        arrays.push_back(val);
        map[val]=arrays.size()-1;
        return true;
    } 

    bool remove(int val) 
    { 
        //element is not there
        if(map.find(val)==map.end())
            return false;
        //getting value
        auto itr =map.find(val);
        //getting index and swap with last of vector
        int index=arrays.size()-1;
        swap(arrays[itr->second],arrays[index]);
        map[arrays[itr->second]]=itr->second;
        map.erase(val);
        arrays.pop_back();
        return true;
    } 

    int getRandom() 
    { 
        int randomIndex = rand() % arrays.size(); 
        return arrays[randomIndex];  
    } 
}; 
  
int main() 
{ 
    findRandom random; 
    cout << random.insert(10) << endl; 
    cout << random.insert(20) << endl; 
    cout << random.insert(10) << endl;
    cout << random.insert(30) << endl; 
    cout << random.remove(30) << endl; 
    cout << random.remove(30) << endl; 
    cout << random.getRandom() << endl; 
    return 0; 
} 


/* Try more Inputs

Case 1:
findRandom random;
random.insert(1) 
random.insert(2)
random.insert(3)
result = random.remove(3)
expected = [True]
Case 2: 
findRandom random;
random.insert(1) 
random.insert(2)
random.remove(1)
result = random.remove(2)
expected = [True]

*/
