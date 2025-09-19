/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* mergeKSortedLists(vector<ListNode*> &head) {
        ListNode* head1 = new ListNode(-1);
        ListNode* tail = head1;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>q;
        for(auto i: head){
            if(i!=NULL){
                q.push({i->val,i});
            }
        }
        while(!q.empty()){
            auto fNode = q.top();

            ListNode* a = new ListNode(fNode.first);
            tail->next = a;
            tail = a;
            q.pop();
            if(fNode.second->next){
                q.push({fNode.second->next->val,fNode.second->next});
            }
        }
        return head1->next;









    }   
};