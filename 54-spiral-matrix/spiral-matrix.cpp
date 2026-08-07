class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0,right=matrix[0].size()-1,top=0,bottom=matrix.size()-1;
        vector<int> ans;

        while(top <= bottom && left <= right){

            int l = left;
            while(l <= right){
                ans.push_back(matrix[top][l]);
                l++;
            }
            top++;

            l = top;
            while(l <= bottom){
                ans.push_back(matrix[l][right]);
                l++;
            }
            right--;

            if(top <= bottom){
                l = right;
                while(l >= left){
                    ans.push_back(matrix[bottom][l]);
                    l--;
                }
                bottom--;
            }

            if(left <= right){
                l = bottom;
                while(l >= top){
                    ans.push_back(matrix[l][left]);
                    l--;
                }
                left++;
            }
        }

        return ans;
    }
};