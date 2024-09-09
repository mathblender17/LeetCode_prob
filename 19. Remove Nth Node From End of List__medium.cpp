/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
/**
we solve this by using 2 pointers and the gap between these pointer is n(nth number from end to be removed)

**/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* res=new ListNode(0,head);
    ListNode* dummy=res;

    for(int i=0;i<n;i++){
        head=head->next;
    }
    while(head != 0){
        head=head->next;
        dummy=dummy->next;
    }
    dummy->next=dummy->next->next;

    return res->next;
    
    }
    
};
