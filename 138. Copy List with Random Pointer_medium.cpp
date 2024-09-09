/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
/**
3 parts to it 
1. to create a set of new nodes ( hash map or irectly...better to use directly mpre optimised)
2.to assign the random connections 
3.to assign the nextxonnextions and detach the new copied nodes from the old ones
**/

    void NewCopyNodes(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);
            copy->next=nextElement;
            temp->next=copy; 
            temp=nextElement;

        }
    }

    void randomConn(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copy = temp->next;
            if(temp->random){
                copy->random=temp->random->next;
            }
            else{
                copy->random = nullptr;
            }
            temp=temp->next->next;
            
        }
    }
    Node* setnextConn(Node* head){
        Node* res=new Node(-1);
        Node* dummy=res;
        Node* temp=head;
        while(temp!=NULL){
            dummy->next=temp->next;
            dummy=dummy->next;

            temp->next=temp->next->next;
            temp=temp->next;
        }
        return res->next;
    }
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        NewCopyNodes(head);
        randomConn(head);
        return setnextConn(head);
    }
};
