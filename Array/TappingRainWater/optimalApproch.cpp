#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int left = 0;
        int right = n-1;
        int leftMax = 0;
        int rightMax = 0;

        while(left<right){
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            if(leftMax < rightMax){
                ans+= leftMax - height[left];
                left++;
            }else{
                ans +=  rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};


int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    Solution sol;
    
    int result = sol.trap(height);
    
    cout << "Trapped Rainwater: " << result << endl;
    
    return 0;
}
