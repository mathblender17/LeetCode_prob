

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
/** CORE IDEA :  traversing through the lists + creating new nodes to add and hold the sum + to deal with the carry(while traversing as well as after completing the traversal)

1> here we use && for when both compulsory have elements, and separate while loops for the left remaining list - this is most probably redundant (O(3n))
I keep forgetting the part that in the  new nodes are to be made/created here for the res linked list

2> if we use OR(||) i think it would decrease the number of while loops to 1 ~prolly O(n)
**/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode* res =new ListNode(-1);
        ListNode* d =res;

        while(l1 != nullptr || l2 != nullptr){
            int a = (l1 ?l1->val : 0);
            int b = (l2 ?l2->val : 0);
            int sum = a+b + c;

            c=sum/10;
            sum=sum%10;

            d->next =new ListNode(sum);
            d=d->next;

            if(l1) l1=l1->next;
            if(l2) l2=l2->next;            
        }
       
        if (c > 0) {
            d->next = new ListNode(c);
        }
        
        return res->next;
    }
};


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
/**
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
**/
