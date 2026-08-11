class Solution {
public:
    void  dfs(vector<vector<int>> &heights,set<pair<int, int>> &vis,int r,int c, int previous){
        if(r<0 ||r>=heights.size() || c<0 || c>=heights[0].size() || vis.find({r,c})!=vis.end() || previous>heights[r][c]){
            return;
        }
        
        vis.insert({r,c});
        dfs(heights,vis,r,c+1,heights[r][c]);
        dfs(heights,vis,r+1,c,heights[r][c]);
        dfs(heights,vis,r,c-1,heights[r][c]);
        dfs(heights,vis,r-1,c,heights[r][c]);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        set<std::pair<int, int>> pac;
        set<std::pair<int, int>> atl;
        int r=heights.size(),c=heights[0].size();
        for(int i=0;i<c;i++){
            dfs(heights,pac,0,i,heights[0][i]);
            dfs(heights,atl,r-1,i,heights[r-1][i]);
        }
        for(int i=0;i<r;i++){
            dfs(heights,pac,i,0,heights[i][0]);
            dfs(heights,atl,i,c-1,heights[i][c-1]);
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                vector<int> temp={i,j};
                if(pac.find({i, j}) != pac.end() && atl.find({i, j}) != atl.end()){
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};