// Design a max stack data structure that supports the stack operations and supports finding the stack maximum element.

// Implement the MaxStack class:

// MaxStack() Initializes the stack object.
// void push(int x) Pushes element x onto the stack.
// int pop() Removes the element on top of the stack and returns it.
// int top() Gets the element on the top of the stack without removing it.
// int peekMax() Retrieves the maximum element in the stack without removing it.
// int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, only remove the top-most one.
// You must come up with a solution that supports O(1) for each top call and O(logn) for each other call.

class MaxStack {
public:
    stack<pair<int, int>> stk; 
    priority_queue<pair<int, int>> heap;
    unordered_set<int> removed;
    int cnt=0;
    MaxStack() {
        
    }
    
    void push(int x) {
        stk.push({x,cnt});
        heap.push({x,cnt});
        cnt++;

    }
    
    int pop() {
        while(removed.count(stk.top().second)){
            stk.pop();
        }
        const pair<int, int> p = stk.top();
        stk.pop();
        removed.insert(p.second);
        return p.first;
    }
    
    int top() {
        while(removed.count(stk.top().second)){
            stk.pop();
        }
        return stk.top().first;
    }
    
    int peekMax() {
        while(removed.count(heap.top().second)){
            heap.pop();
        }
        return heap.top().first;
    }
    
    int popMax() {
        while(removed.count(heap.top().second)){
            heap.pop();
        }
        const pair<int, int> p = heap.top();
        heap.pop();
        removed.insert(p.second);
        return p.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */