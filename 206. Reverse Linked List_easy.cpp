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
    ListNode* reverseList(ListNode* head) {
        /**
        //iterative method - to maintain a curr ,  summy and a prev pointer
        //it reverses the nodes at there positons only
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr!=NULL){
            ListNode* dummy = curr->next;
            curr->next = prev;
            prev=curr;
            curr=dummy;
        }
        return  prev;
        **/
        if(head== NULL || head->next == NULL){ // Base case 
            return head;
        }
        ListNode* newHead =reverseList(head->next); // diviong the problem in to smaller parts
        head->next->next = head; //reversing ther direction
        head->next=NULL ;
        return newHead;

        
    }
};
