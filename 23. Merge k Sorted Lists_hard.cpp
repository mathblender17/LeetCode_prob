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
/**
CORE IDEA : to use Divide and conquer along with helper function MergeTwoLists() 

**/
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if (n==0) return NULL;//edge cases
        //if(n==1) return lists[0];  - no need for this as if there is only one list elelment we just directly use it

        while(n>1){// to decide a stopping point for the divide (of divide and conquer)
             for(int i=0;i<n/2;i++){
                lists[i]=mergeTwoLists(lists[i],lists[n-i-1]);//using the helper function to mege 2 list at a time
                //also to savew the mergered array back in the same list
             }
             n=(n+1)/2;//halving the count as the number of elements are now divided and conqured
        }
        return lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        if(l1==NULL && l2==NULL) return NULL;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        ListNode* head=NULL;
        //here the head which was poiting to NULL is given aa strting node to point to
        if(l1->val <= l2->val){
            head=l1;
            l1=l1->next;
        }
        else{
            head=l2;
            l2=l2->next;
        }
        ListNode* curr=head;
        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(l1!=NULL){
            curr->next=l1;
        }
        if(l2!=NULL){
            curr->next=l2;
        }
        return head;//head->next not used as here we do not make a new node but instead use a pointer head
    }
};
