class Solution {
public:
    void reorderList(ListNode* head) {
        //Here we we use simple 2 pointer methd i at start anf j and end
        //so 1st all the list values addded to a vector to make use of pointers
        //now using i and j reorder the given list
        vector<int>v;
        ListNode *temp=head;
        while(temp!=NULL){
            int y=temp->val;
            v.push_back(y);
            temp=temp->next;
        }
         int n = v.size();
        int i=0, j=n-1;
        temp = head;
        while (i < j) {
            temp->val = v[i];
            temp=temp->next;
            i++;
            temp->val=v[j];
            temp=temp->next;
            j--;
        }
        if (i==j) {
            temp->val=v[i];
        }
    }
};
