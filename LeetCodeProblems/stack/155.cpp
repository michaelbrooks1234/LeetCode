class MinStack {
public:
    stack<int> stacky = {};
    stack<int> minStacky = {};
    int minny = 0;
    MinStack() {
      stacky = {};
      minStacky = {};
    }
    
    void push(int val) {
      stacky.push(val); 
      if (stacky.size() == 1) {
        minny = val;
      } else {
        minny = min(minny, val);
      }
      minStacky.push(minny);
    }
    
    void pop() {
      stacky.pop();
      minStacky.pop();
      if (minStacky.empty()) {
          return;
      }
      minny = max(minStacky.top(), minny);
    }
    
    int top() {
      return stacky.top();   
    }
    
    int getMin() {
      return minny;
    } 
};