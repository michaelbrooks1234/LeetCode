class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> t = {}; 
      for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "/" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "+") {
          int y = t.top();
          t.pop();
          int x = t.top();
          t.pop();
          if (tokens[i] == "/") {
            t.push(x/y);
          }
          if (tokens[i] == "+") {
            t.push(x+y);
          }
          if (tokens[i] == "-") {
            t.push(x-y);
          }
          if (tokens[i] == "*") {
            t.push(x*y);
          }
          continue;
        } 
        t.push(stoi(tokens[i])); 
      }
      return t.top();
    }
};