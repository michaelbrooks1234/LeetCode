class Solution {
public:
    bool isValid(string s) {
      stack<char> stackOfCharacters = {};       
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
          stackOfCharacters.push(s[i]);
          continue;
        }
        if (stackOfCharacters.size() == 0) {
          return false;
        }
        if (s[i] == '}') {
          if (stackOfCharacters.top() == '{') {
            stackOfCharacters.pop();
            continue;
          }
          return false;
        }
        if (s[i] == ']') {
          if (stackOfCharacters.top() == '[') {
            stackOfCharacters.pop();
            continue;
          }
          return false;
        }
        if (s[i] == ')') {
          if (stackOfCharacters.top() == '(') {
            stackOfCharacters.pop();
            continue;
          }
          return false;
        }
      }
      return stackOfCharacters.size() == 0;
    }
};