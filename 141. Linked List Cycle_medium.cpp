class Solution {
public:
    bool hasCycle(ListNode *head) {
        //thius is the turtle and hare problm
        //if(head==NULL)return false;
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast!=NULL && fast->next!=NULL ){
            fast=fast->next->next;
            slow=slow->next;

            if(fast==slow)return true;
        }return false;
    }
};
