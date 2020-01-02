class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map; //无序map更快
        for(int i = 0; i < nums.size(); i++)
            if (map.count(nums[i]) != NULL) return true;
            else map[nums[i]] += 1;
        return false;
    }
};
