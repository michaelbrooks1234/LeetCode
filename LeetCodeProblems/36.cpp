class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) { 
      int ySize = board.size();
      int xSize = board[0].size();

      vector<map<int, int>> horizontalMaps(xSize);
      vector<map<int, int>> verticalMaps(ySize);

      map<string, map<int, int>> mapOfMaps = {};

      for(int i = 0; i < ySize; i++) {
        for(int y = 0; y < xSize; y++) {
          if (isdigit(board[i][y]) == 0) {
              continue;
          }
          if (horizontalMaps[i][board[i][y]] > 0) {
            return false;
          }
          if (verticalMaps[y][board[i][y]] > 0) {
            return false;
          }

          string position = to_string((i)/3) + "," + to_string((y)/3);
          if (mapOfMaps[position][board[i][y]] > 0) {
            return false;
          }
          mapOfMaps[position][board[i][y]]++;
          verticalMaps[y][board[i][y]]++;
          horizontalMaps[i][board[i][y]]++;
        }
      }
      return true;
    }
};