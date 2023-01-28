#include<iostream>
using namespace std;

bool palindromeCheck(int i, string &str){
    if(i > str.size()/2){
        return true;
    }
    if(str[i] != str[str.size()-i-1]){
        return false;
    }
    return palindromeCheck(i+1,str);
}

int main(){
    string s = "sanchit";
    cout<<palindromeCheck(0,s);
}