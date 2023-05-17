#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] *= A[i];
        }
        sort(A.begin(), A.end());
        return A;
    }
};

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10}; // Added missing '>' in vector declaration and added semicolon
    Solution solution;
    vector<int> result = solution.sortedSquares(nums); // Corrected function call
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
