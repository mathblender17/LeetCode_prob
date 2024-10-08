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
only thing different here is we splice the list and nopt create a new one
proper use of dummy - only to keep the track of the head- dlete it after use
use of dummy also removes the edge case of 0 
**/

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* dummy = new ListNode(0);//dummy is there only for keep thte track of the head of the list
        ListNode* curr = dummy;


        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val ){
                curr->next=list1;
                list1=list1->next;
            }
            else{
                curr->next=list2;
                list2=list2->next;
            }
            curr=curr->next;
        }
        if(list1 == nullptr){
            curr->next=list2;
        }
        if(list2 == nullptr){
            curr->next=list1;
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};
