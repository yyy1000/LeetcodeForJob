// 1653. Minimum Deletions to Make String Balanced
// My solution
// Consider when we encounter 'b', we can delete all the 'a' after it or we could delete it and see next
class Solution {
public:
    vector<int> a_pos;
    int minimumDeletions(string s) {
        // that is to say, 'a' must appears early that 'b'.
        for(int i=0;i<s.size();++i){
            if(s[i]=='a') a_pos.push_back(i);
        }
        int res = 0;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i] == 'a') continue;
            int erase_b = 1 + res;
            // this is problemetic, actually we don't need to search how many 'a' after it, but just count.
            int not_erase_b = a_pos.size() - (upper_bound(a_pos.begin(), a_pos.end(), i) - a_pos.begin());
            res = min(erase_b, not_erase_b);
        }
        return res;
    }
};

// official solution
class Solution {
public:
    int minimumDeletions(string s) {
        int leftb = 0, righta = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                righta++;
            }
        }
        int res = righta;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'a') {
                righta--;
            } else {
                leftb++;
            }
            res = min(res, leftb + righta);
        }
        return res;
    }
};

// My updated solution
class Solution {
public:
    vector<int> a_pos;
    int minimumDeletions(string s) {
        // that is to say, 'a' must appears early that 'b'.
        int cntA = 0;
        int res = 0;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i] == 'a') {
                cntA++;
                continue;
            }
            int erase_b = 1 + res;
            int not_erase_b = cntA;
            res = min(erase_b, not_erase_b);
        }
        return res;
    }
};