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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);// head of the result list
        ListNode* temp = dummy;//used to add the sum in the result list
        int carry=0;//initially carry  =0  
        while(l1!=0 || l2!=0 || carry){ // terminating conditions
            int sum=0; // for every step/node sum is intialised and calucated

            if(l1!=0){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=0){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry; // at every step the carry of the previous calc will be added 
            carry=sum/10;

            ListNode* newnode = new ListNode(sum%10);//the sum will added in the list
            temp->next=newnode;
            temp=temp->next;

        }
        return dummy->next;
        
    }
};
