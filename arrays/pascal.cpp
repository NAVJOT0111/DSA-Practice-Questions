
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Generate a single row of Pascal's Triangle
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1); // first element is always 1
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back((int)ans);
        }
        return ansRow;
    }

    // Generate Pascal's Triangle
    vector<vector<int>> pascalTriangle(int n) {
        vector<vector<int>> ans;
        for (int row = 1; row <= n; row++) {
            ans.push_back(generateRow(row));
        }
        return ans;
    }
};
