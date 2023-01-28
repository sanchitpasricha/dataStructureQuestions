#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int second(string str){
    unordered_map<char, int> mp;

    int size = str.length();
    for(int i=0;i<size;i++){
        mp[str[i]]++;
    }

    for(int i=0;i<size;i++){
        if(mp[str[i]] == 1){
            return i;
        }
    }
    return -1;
}

int main(){
    string str = "sasar";
    cout<<second(str);
    return 0;
}