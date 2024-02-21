class Solution {
public:
   void solve(vector<string>& answer, string p, int n, int open, int closed) {
      if (closed == open && open == n) {
        answer.push_back(p);
        return;
      }
      if (open < n) {
        string temp = p;
        temp += '(';
        solve(answer, temp, n, open + 1, closed);
      }
      if (closed < open) {
        string temp = p;
        temp += ')';
        solve(answer, temp, n, open, closed + 1);
      }
    }

    vector<string> generateParenthesis(int n) {
      int open = 0;       
      int closed = 0;
      string p = {};
      vector<string> answer = {};
      solve(answer, p, n, open, closed); 
      return answer;
    } 
};