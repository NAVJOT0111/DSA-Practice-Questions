#include <bits/stdc++.h> 
using namespace std;

int removeDubplicates(int arr[], int n){
    int i = 0;
    for(int j=1; j<n; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    } return i+1 ;
}    

// another two pointer
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;   // Edge case: empty array
        
        int i = 0;                    // i -> index of last unique element
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) { // Found new unique element
                i++;
                nums[i] = nums[j];    // Move unique element forward
            }
        }
        return i + 1;                 // Length of unique elements
    }
};

// hashing : to check duplicates
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set <int> seen;
        for(int i=0; i<n; i++){
            int num = nums[i];
            if(seen.count(num)) //alredy in set
                return true;
            seen.insert(num);
        }
    return false;
    }
};