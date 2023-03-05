// 1599. Maximum Profit of Operating a Centennial Wheel
// My solution
// Simulation
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int profit = 0;
        int now = 0;
        int res = -1;
        int cnt = 0;
        int res_people = 0;
        int i=0;
        while(i<customers.size() || res_people > 0){
            if(i<customers.size()) {
                res_people += customers[i];
                i++;
            }
            int number = 0;
            if(res_people >= 4) {
                res_people -= 4;
                number = 4;
            }
            else{
                number = res_people;
                res_people = 0;
            }
            now = now - runningCost + boardingCost * number;
            cnt++;
            if(now > profit){
                profit = now;
                res = cnt;
            }
        }
        return res;
    }
};


// More Clear Solution from Leetcode website
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans = -1;
        int maxProfit = 0;
        int totalProfit = 0;
        int operations = 0;
        int customersCount = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++) {
            operations++;
            customersCount += customers[i];
            int curCustomers = min(customersCount, 4);
            customersCount -= curCustomers;
            totalProfit += boardingCost * curCustomers - runningCost;
            if (totalProfit > maxProfit) {
                maxProfit = totalProfit;
                ans = operations;
            }
        }
        // return early, though not necessary
        if (customersCount == 0) {
            return ans;
        }
        // return early to avoid calculation
        int profitEachTime = boardingCost * 4 - runningCost;
        if (profitEachTime <= 0) {
            return ans;
        }
        // the below paragraph could change the calculation from O(n) to O(1)
        if (customersCount > 0) {
            int fullTimes = customersCount / 4;
            totalProfit += profitEachTime * fullTimes;
            operations += fullTimes;
            if (totalProfit > maxProfit) {
                maxProfit = totalProfit;
                ans = operations;
            }
            int remainingCustomers = customersCount % 4;
            int remainingProfit = boardingCost * remainingCustomers - runningCost;
            totalProfit += remainingProfit;
            if (totalProfit > maxProfit) {
                maxProfit = totalProfit;
                operations++;
                ans++;
            }
        }
        return ans;
    }
};