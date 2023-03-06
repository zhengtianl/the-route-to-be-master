#include "queue"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // 最大堆
        auto cmp = [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.first + lhs.second < rhs.first + rhs.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            for (int j = 0; j < nums2.size() && j < k; ++j) {
                if (heap.size() < k) {
                    heap.push({nums1[i], nums2[j]});
                }
                else if (nums1[i] + nums2[j] < heap.top().first + heap.top().second)  {
                    heap.pop();
                    heap.push({nums1[i], nums2[j]});
                }
            }
        }
        int size = heap.size();
        vector<vector<int>> ret(size, vector<int>(2, 0));
        for (int i = 0; i < size; ++i) {
            ret[size - 1 - i][0] = heap.top().first;
            ret[size - 1 - i][1] = heap.top().second;
            heap.pop();
        }
        return ret;
    }
};

