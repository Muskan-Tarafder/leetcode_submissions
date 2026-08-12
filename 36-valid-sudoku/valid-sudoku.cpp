class Solution {
public:
    bool checkCR(vector<vector<char>>& board,int i,int j,int val){
        for(int c=0;c<9;c++){
            if(c!=j && board[i][c]==val){
                return false;
            }
        }
        for(int r=0;r<9;r++){
            if(r!=i && board[r][j]== val){
                return false;
            }
        }
        return true;
    }
    bool checkSection(vector<vector<char>>& board,int i,int j,int val){
        int rstart,cstart;
        rstart=(i/3)*3;
        cstart=(j/3)*3;
        for(int r=rstart;r<rstart+3;r++){
            for(int c=cstart;c<cstart+3;c++){
                if((r!=i || c!=j) && board[r][c]== val){
                    return false;
                }
            }
        }
        return true;

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') {
                    continue;
                }

                char val = board[i][j];

                if(!checkCR(board, i, j, val)) {
                    return false;
                }

                if(!checkSection(board, i, j, val)) {
                    return false;
                } 
            }
        }
        return true;
    }
};