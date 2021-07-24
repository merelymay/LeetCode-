// 79. 单词搜索
// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/word-search
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include "pub_head.h"
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, i, j, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string word, int index, vector<vector<int>>& visited) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index]) {
            return false;
        }
        visited[i][j] = 1;   
        bool res = dfs(board, i-1, j, word, index+1, visited) || dfs(board, i, j-1, word, index+1, visited) || dfs(board, i, j+1, word, index+1, visited) || dfs(board, i+1, j, word, index+1, visited);
        visited[i][j] = 0;
        return res;
        
    }
};


int main() {
    // char ch[3][4] = {{'a','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<char> vec = {'a','B','C','E', 'S','F','C','S', 'A','D','E','E'};
    int k = 0;
    vector<vector<char>> board(3, vector<char>(4));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            board[i][j] = vec[k++];
        }
    }
    Solution s;
    bool res = s.exist(board, "SEE"); 
    return 0;
}