class Solution {
public:
    bool hasCycle(ListNode *head) {
        //this is the turtle and hare problem
        //if(head==NULL)return false;
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast!=NULL && fast->next!=NULL ){
            fast=fast->next->next;
            slow=slow->next;

            if(fast==slow)return true;//checking in each iteration only as we only need find the occurrence 
        }return false;
    }
};
