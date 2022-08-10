//hashing 6)
#include<iostream>
#include<map>
using namespace std;

string singleDigit(int n){
    switch(n){
        case 0:
            return "";
        case 1:
            return "One ";
        case 2:
            return "Two ";
        case 3:
            return "Three ";
        case 4:
            return "Four ";
        case 5:
            return "Five ";
        case 6:
            return "Six ";
        case 7:
            return "Seven ";
        case 8:
            return "Eight ";
        case 9:
            return "Nine ";
    }
}

string doubleDigit(int n){
    if(n>=10 && n<=19){
        switch(n){
            case 10:
                return "Ten ";
            case 11:
                return "Eleven ";
            case 12:
                return "Twelve ";
            case 13:
                return "Thirteen ";
            case 14:
                return "Fourteen ";
            case 15:
                return "Fifteen ";
            case 16:
                return "Sixteen ";
            case 17:
                return "Seventeen ";
            case 18:
                return "Eighteen ";
            case 19:
                return "Nineteen ";
        }
    }
    else if(n>=20 && n<=29){
        return "Twenty "+singleDigit(n%10);
    }
    else if(n>=30 && n<=39){
        return "Thirty "+singleDigit(n%10);
    }
    else if(n>=40 && n<=49){
        return "Fourty "+singleDigit(n%10);
    }
    else if(n>=50 && n<=59){
        return "Fifty "+singleDigit(n%10);
    }
    else if(n>=60 && n<=69){
        return "Sixty "+singleDigit(n%10);
    }
    else if(n>=70 && n<=79){
        return "Seventy "+singleDigit(n%10);
    }
    else if(n>=80 && n<=89){
        return "Eighty "+singleDigit(n%10);
    }
    else if(n>=90 && n<=99){
        return "Ninety "+singleDigit(n%10);
    }
    else{
        return singleDigit(n%10);
    }
}

string numToWord(int num){
    string ans;
    map<int,int> mp;
    int pos=1;

    while(num!=0){
        if(pos==10 || pos==10000 || pos==1000000){
            mp[pos]=(num%10)*10+mp[pos/10];
            mp.erase(pos/10);
        }
        else{
            mp[pos]=num%10;
        }
        pos=pos*10;
        num=num/10;
    }
    //reverse traversing the map
    for(auto itr=mp.rbegin();itr!=mp.rend();itr++){
        cout<<itr->first<<"-"<<itr->second<<endl;
    }

    for(auto itr=mp.rbegin();itr!=mp.rend();itr++){
        if(itr->first==1000000){
            ans+=doubleDigit(itr->second);
            ans+="Lakh ";
        }
        else if(itr->first==100000){
            ans+=singleDigit(itr->second);
            ans+="Lakh ";
        }
        else if(itr->first==10000){
            ans+=doubleDigit(itr->second);
            ans+="Thousands ";
        }
        else if(itr->first==1000){
            ans+=singleDigit(itr->second);
            ans+="Thousands ";
        }
        else if(itr->first==100){
            ans+=singleDigit(itr->second);
            (itr->second!=0)?ans+="Hundred ":ans+="";
        }
        else if(itr->first==10){
            ans+=doubleDigit(itr->second);
        }
        else{
            ans+=singleDigit(itr->second);
        }
    }

    return ans;
    
}

int main(){
    int num=1121;

    cout<<numToWord(num);
}