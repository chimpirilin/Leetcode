// https://leetcode.com/problems/remove-nodes-from-linked-list/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        auto curNode = head;
        while(curNode!=nullptr){
            v.push_back(curNode->val);
            curNode = curNode->next;
        }
        ListNode* newHead = new ListNode(v.back());
        v.pop_back();
        reverse(v.begin(), v.end());
        int curMax = newHead->val;
        for(auto x: v){
            if(curMax <= x){
                auto newNode = new ListNode(x, newHead);
                newHead = newNode;
                curMax = max(curMax, x);
            }
        }
        return newHead;
    }
};