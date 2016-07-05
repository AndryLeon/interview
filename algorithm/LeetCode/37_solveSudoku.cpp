#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

class Solution {
public:
    int vi[9][9], vj[9][9], v[9][9];

    bool dfs(vector<string>& board,  int count){
        if(count == 81){
            return true;
        }
        int x = count/9, y = count%9;
        if(board[x][y] == '.'){
            for(int i = 0; i < 9; ++i){
                if(!vi[x][i] && !vj[y][i] && !v[(x/3)*3+y/3][i]){
                    vi[x][i] = 1;
                    vj[y][i] = 1;
                    v[(x/3)*3+y/3][i] = 1;
                    board[x][y] = '1'+ i;
                    if(dfs(board, count+1))
                        return true;
                    vi[x][i] = 0;
                    vj[y][i] = 0;
                    v[(x/3)*3+y/3][i] = 0;
                    board[x][y] = '.';
                }
            }
            return false;
        }
        else{
            return dfs(board,  count+1);
        }

    }

    void solveSudoku(vector<string>& board) {
        memset(vi, 0, sizeof(vi));
        memset(vj, 0, sizeof(vj));
        memset(v, 0, sizeof(v));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    vi[i][board[i][j]-'1'] = 1;
                    vj[j][board[i][j]-'1'] = 1;
                    v[(i/3)*3+j/3][board[i][j]-'1'] = 1;
                }
            }
        }
        dfs(board, 0);
    }
};

int main(){
    vector<string> board{
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };
    Solution s;
    s.solveSudoku(board);
    for(auto& x : board){
        cout << x << endl;
    }
}
