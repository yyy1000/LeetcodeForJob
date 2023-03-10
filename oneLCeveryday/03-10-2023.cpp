//1590. Make Sum Divisible by P
//My solution: prefix sum and hashtable
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for(int i=0;i<nums.size();++i){
            sum += nums[i];
            sum %= p;
        }
        if(sum == 0) return 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        auto tem = 0;
        int res = nums.size();
        for(int i=0;i<nums.size();++i){
            tem += nums[i];
            tem %= p;
            auto need = (tem - sum + p)%p;
            if(mp.find(need)!=mp.end()){
                res = min(res, i - mp[need]);
            }
            mp[tem] = i;
        }
        if(res == nums.size()) return -1;
        return res;
    }
};

// Standard Solution
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int x = 0;
        for (auto num : nums) {
            x = (x + num) % p;
        }
        if (x == 0) {
            return 0;
        }
        unordered_map<int, int> index;
        int y = 0, res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            index[y] = i; // f[i] mod p = y，因此哈希表记录 y 对应的下标为 i
            y = (y + nums[i]) % p;
            if (index.count((y - x + p) % p) > 0) {
                res = min(res, i - index[(y - x + p) % p] + 1);
            }
        }
        return res == nums.size() ? -1 : res;
    }
};
