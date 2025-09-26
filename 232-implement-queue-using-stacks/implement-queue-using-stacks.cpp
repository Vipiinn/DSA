class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int>st;
    stack<int>qt;
    void push(int x) {
        if(st.size() == 0) st.push(x);
        else{
            while(st.size() > 0){
                qt.push(st.top());
                st.pop();
            }
            qt.push(x);

            while(qt.size() > 0){
                st.push(qt.top());
                qt.pop();
            }
        }
    }
    
    int pop() {
        int x = st.top();
        st.pop();
        return x;
    }
    
    int peek() {
        return st.top();   
    }
    
    bool empty() {
        if(st.size() == 0) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */