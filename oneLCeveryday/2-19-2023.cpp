// 1792. Maximum Average Pass Ratio

// Standard Solution
class Solution {
public:
    struct Ratio {
        int pass, total;
        bool operator < (const Ratio& oth) const {
            return (long long) (oth.total + 1) * oth.total * (total - pass) < (long long) (total + 1) * total * (oth.total - oth.pass);
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Ratio> q;
        for (auto &c : classes) {
            q.push({c[0], c[1]});
        }

        for (int i = 0; i < extraStudents; i++) {
            auto [pass, total] = q.top();
            q.pop();
            q.push({pass + 1, total + 1});
        }

        double res = 0;
        for (int i = 0; i < classes.size(); i++) {
            auto [pass, total] = q.top();
            q.pop();
            res += 1.0 * pass / total;
        }
        return res / classes.size();
    }
};

// My solution
class Solution {
public:
    struct cmp{
        bool operator()(pair<int,long long> lhs, pair<int,long long> rhs){
            long long f1 = (lhs.second * (lhs.second + 1));
            long long f2 = (rhs.second * (rhs.second + 1));
            double l = 1.0 * (lhs.second-lhs.first) / f1;
            double r = 1.0 * (rhs.second-rhs.first) / f2;
            return l < r;
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int,long long>,vector<pair<int,long long>>, cmp> q;
        for(auto vec: classes){
            q.push({vec[0],vec[1]});
        }
        while(extraStudents--){
            auto t = q.top();
            q.pop();
            auto one = t.first;
            auto two = t.second;
            one++,two++;
            q.push({one,two});
        }
        double res{0.0};
        while(!q.empty()){
            auto t = q.top();
            q.pop();
            res += 1.0 * t.first / t.second;
        }
        return res / classes.size();
    }
};

// TODO
// Some points to improve:

