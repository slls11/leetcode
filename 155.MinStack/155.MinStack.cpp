class MinStack {
public:    
    void push(int val) {
        s.push(val);
        if (min_s.empty() || val <= min_s.top()) min_s.push(val);
    }
    
    void pop() {
        if (s.top() == min_s.top()){
            s.pop();
            min_s.pop();
        }
        else s.pop();
    }
    
    int top() {return s.top();}
    int getMin() {return min_s.top();}

private:
    stack<int> s;
    stack<int> min_s;
};
