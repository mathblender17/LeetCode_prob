class MinStack {
/**
MinStack is a stack that keeps the track of minimum numbers if elements  from the whole set of numbers . The top of the minstack gives the minimum number present.
Also be careful with encapsulation for classes and exceptions when a stack is empty 
**/
private:
    stack<int> dataStack;
    stack<int> minStack;
public:
    MinStack() {}

    void push(int val) {
        dataStack.push(val);
        if (minStack.empty() || minStack.top() >= val) {
            minStack.push(val);
        }
    }

    void pop() {
        if (!dataStack.empty()) {
            if (dataStack.top() == minStack.top()) {
               
                minStack.pop();
            }
            dataStack.pop();
        }
    }

    int top() { 
        if (!dataStack.empty()) {return dataStack.top(); }
        throw runtime_error("Stack is empty");
    }
    int getMin() { 
        if(!dataStack.empty()){
            return minStack.top(); 
        }
        throw runtime_error("Stack is empty");
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
