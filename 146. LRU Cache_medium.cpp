/**
CORE IDEA : we use 2 data structures hash table and doubly lnked list to solve this questiom
hash table as we want the grt and put operaTIONS to be done in O(1) possible when using a hash table
doubly linked list to keep the recency lru and mru - MRU added in the last - LRU removed from th e first
all the elememntys in the list are kept between to nodes leftand right as all the opetions are to be done either on the left or the right side
if HIT case adde dinthe end ( right - mru)
if number is to be added adeed on the mru adn 1 number deleted from lru
TC : O(1)
SC : O(capacity) - O(n)
**/

class Node { 
    public://imp as we use Node(constructor) function declared here in Node classs for further creation of new nodes
    //it is important to use public acess speficier as in cpp contructors genreally(if not specifed) private and such privaate functions cannot be used outside of their classes
    int k;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int value) {//Node for doubly linked List
        k = key;
        val = value;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
public:
    LRUCache(int capacity) {//contructor for LRUCache for intititalisastion 
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }

    int get(int key) {//check of the element exists if yest return the value form the key if no return -1
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            insert(cache[key]);
            // order is update as a get fuction is performed on cache[key] or
            // key pair
            return cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {//to put values if already presernt updaet position on the DLL else add aat mru and if nedd be remove rfom lru
        if (cache.find(key) !=cache.end()) { // a HIT case has been found so againthe position is to be updated
            remove(cache[key]);
            delete cache[key];
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);

        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->k);
            delete lru;
        }
    }

private:
// the hash table declaration and initalisaation 
// here we use both left,right as well as Nodes prev and next(created just for helping in operations) 
// all operation done at O(1) Tc
    int cap;
    unordered_map<int, Node*> cache; /// {key->Node}
    Node* left;
    Node* right;

    void insert(Node* node) {//insertion happens at the MRU 
        Node* prev = right->prev;
        Node* next = right;

        prev->next = node;
        next->prev = node;

        node->prev = prev;
        node->next = next;
    }
    void remove(Node* node) {// deeltion at the lru
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
