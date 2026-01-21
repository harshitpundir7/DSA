#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int maxi = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
            } else {
                cnt = 0;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    int result = obj.findMaxConsecutiveOnes(nums);
    cout << "Maximum consecutive ones: " << result << endl;

    return 0;
}
