// 给定一个整数数组，判断是否存在重复元素。

// 1. 使用哈希表(map)来记录【通过】

class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map; //无序map更快
        for(int i = 0; i < nums.size(); i++)
            if (map.count(nums[i]) != NULL) return true;
            else map[nums[i]] += 1;
        return false;
    }
};


// 2. 使用快速排序，然后比较相邻两个值是否相等来判断是否有重复值，【不通过：超时】，应该是我的快速排序写得有问题

class Solution2 {
private:
    void exchange(vector<int>& nums, int m, int n) {
        int tmp = nums[m];
        nums[m] = nums[n];
        nums[n] = tmp;
    }
    int partition(vector<int>& nums, int lo, int hi) {
        int value = nums[lo];
        
        int l = lo;
        
        for (int i = l + 1; i < hi + 1; i++) {
            if (nums[i] < value) {
                exchange(nums, i, ++l);
            }
        }
        
        exchange(nums, lo, l);
        
        return l;
    }
    void sort(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) return;
        
        int mid = partition(nums, lo, hi);
        sort(nums, lo, mid);
        sort(nums, mid + 1, hi);
    }
    void sort(vector<int>& nums) {
        sort(nums, 0, (int)nums.size() - 1);
    }
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() < 1) return false;
        
        sort(nums);
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};
