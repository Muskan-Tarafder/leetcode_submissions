class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int i,int j,int wst,vector<vector<bool>> &visited){
        if(wst>word.size()){
            return false;
        }
        if(wst==word.size()){
            return true;
        }
        if(i>=board.size() || i<0 || j>=board[0].size() || j<0){
            return false;
        }
        if(board[i][j]==word[wst] && visited[i][j]==false){
            // cout<<board[i][j]<<" "<<word[wst]<<endl;
            visited[i][j]=true;
            bool r=solve(board,word,i,j+1,wst+1,visited);
            bool b=solve(board,word,i+1,j,wst+1,visited);
            bool l=solve(board,word,i,j-1,wst+1,visited);
            bool u=solve(board,word,i-1,j,wst+1,visited);
            visited[i][j]=false;
            if(r||b||l||u){
                return true;
            }
            
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word==""){
            return false;
        }
        vector<vector<bool>> visited(board.size(),vector<bool> (board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    bool state=solve(board,word,i,j,0,visited);
                    if(state){
                        return state;
                    }
                }
            }
        }
        return false;
    }
};