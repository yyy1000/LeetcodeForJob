
// My solution
// Sort and Double Pointers
class Solution
{
public:
    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        //[ 3, 4, 5, 7]
        int sz = nums.size();
        int mi = sz / 2;
        int res = 0;
        for (int i = 0, j = mi; i < mi && j < sz;)
        {
            int l = nums[i], r = nums[j];
            if (l * 2 <= r)
            {
                res++;
                i++, j++;
            }
            else
            {
                j++;
            }
        }
        return res * 2;
    }
};

// More Clear Solution
// From https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/solutions/2134078/er-fen-da-an-pythonjavacgo-by-endlessche-t9f5/
class Solution
{
public:
    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size();
        for (int j = (n + 1) / 2; j < n; ++j)
            if (nums[i] * 2 <= nums[j])
                ++i;
        return i * 2;
    }
};

// Summary
// 1. We can find: res equals i, so we don't need to declare res
// 2. If we get upper case of j, the i < mi is not needed.
// 3. We will add j forever, so extract it.
