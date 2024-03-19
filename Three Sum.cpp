#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// we took hash function over here cuz if we didn't mention it we couldn't able to insert vector into set and it causes error
    struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        size_t hash = 0;
        for (int i : v) {
            hash ^= std::hash<int>{}(i);
        }
        return hash;
    }
};

    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(begin(nums), end(nums));
       unordered_set<vector<int>, VectorHash> s;
       
       for(int i = 0; i < nums.size(); i++){
         int j = i + 1;
         int k = nums.size()-1;
         while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                s.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            }
            else if(sum < 0){
                j++;
            }
            else{
                k--;
            }
         }
       }
       // at last we're gonna assign assign each vector into 2d vector
       vector<vector<int>> ans(s.begin(), s.end());
       return ans;
    }
};
