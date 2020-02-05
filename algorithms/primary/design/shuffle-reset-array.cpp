/**
Shuffle an Array
打乱一个没有重复元素的数组。
*/

// 暴力打乱
class Solution {
private:
    vector<int> original;
public:
    Solution(vector<int>& nums) {
        original = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result;
        vector<int> copy = original;
        int size = (int)copy.size();
        while (size > 0) {
            int j = rand() % size;
            result.push_back(copy[j]);
            copy.erase(copy.begin() + j); // 时间 O(n²) 的复杂度来自这里
            size--;
        }
        return result;
    }
};

// Fisher-Yates 洗牌算法 时间 O(n)
class Solution {
private:
    vector<int> original;
public:
    Solution(vector<int>& nums) {
        original = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> copy = original;
        int size = (int)copy.size();
        for (int i = 0; i < size; i++) {
            int j = rand() % size;
            int tmp = copy[i];
            copy[i] = copy[j];
            copy[j] = tmp;
        }
        return copy;
    }
};
