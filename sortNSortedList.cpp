/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pQueue;
        for(int i = 0; i < lists.size(); i++){
            ListNode* list = lists[i];
            while(list != NULL){
                pQueue.push(list->val);
                list = list->next;
            }
        }
        ListNode* start = NULL;
        ListNode* p = NULL;
        while(!pQueue.empty()){
            int val = pQueue.top();
            pQueue.pop();
            ListNode* temp = new ListNode(val);
            if(start == NULL){
                start = temp;
                p = start;
            } else {
                p->next = temp;
                p = p->next;
            }
        }
        
        return start;
    }
};
