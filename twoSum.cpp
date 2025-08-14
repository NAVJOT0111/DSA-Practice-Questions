// brute force
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
         for(int i =0; i<arr.size(); i++){
            for(int j = i+1; j<arr.size(); j++){
                if(arr[i] + arr[j] == target){
                    return true;
                }
            }
        } return false;
    }
};

// hashing
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_set <int> seen;

        for(int i=0; i<n; i++){
            int curr = arr[i];
            int req = target - curr;

            if(seen.find(req) != seen.end()){
                return true;
            }
            seen.insert(curr);
        }
        return false;
    }
};