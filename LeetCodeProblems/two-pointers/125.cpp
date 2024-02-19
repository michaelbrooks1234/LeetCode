class Solution {
public:
    static bool isAlpha(char c) {
        if (c != ' ' && iswalnum(c)) {
            return false;
        }
        return true;
    }
    bool isPalindrome(string s) {
      s.erase(remove_if(s.begin(), s.end(), isAlpha), s.end());
      if (s.size() < 2) {
        return true;
      }

      for(int i = 0; i < s.size()/2; i++) {
        if (tolower(s[i]) != tolower(s[s.size() - i - 1])) {
          return false;
        }
      }
      return true;
    }
};