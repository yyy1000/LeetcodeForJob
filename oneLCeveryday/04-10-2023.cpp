1019. Next Greater Node In Linked List
Standard solution: monotonic stack
vector<int> nextLargerNodes(ListNode* head) {
        vector<int> a, stk;
        int i = 0;
        while (head != nullptr) {
            a.push_back(head->val);
            while (!stk.empty() && a[stk.back()] < head->val) {
                a[stk.back()] = head->val;
                stk.pop_back();
            }
            stk.push_back(i++);
            head = head->next;
        }
        for (int &j: stk) a[j] = 0;
        return move(a);
}

My solution: binary search(not good for time efficiency, but general. eg: the elements that are at least 5 larger)
vector<int> nextLargerNodes(ListNode* head) {
        set<pair<int,int>> st;
        int i = 0;
        vector<int> res;
        while(head != nullptr){
            res.push_back(0);
            auto val = head->val;
            auto iter = st.upper_bound({val, i});
            auto it = st.begin();
            while(it != iter){
                auto k = it->first, v = it->second;
                v *= (-1);
                res[v] = val;
                auto delete_it = it;
                it++;
                st.erase(delete_it);
            }
            st.insert({val, i});
            --i;
            head = head->next;
        }
        return res;
    }