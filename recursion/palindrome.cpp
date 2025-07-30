#include<bits/stdc++.h>
using namespace std;

int palin(int l, int r, string &str){

     // Base Case 1: If left pointer crosses or meets right pointer,
    // it means all characters have been successfully compared.
    if(l>=r) return true;

    if(str[l] != str[r]) return false;

    return palin(l+1,r-1,str);
}