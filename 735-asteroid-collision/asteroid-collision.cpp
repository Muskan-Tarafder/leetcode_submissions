class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int i=0;
        while(i<asteroids.size()){
            if(asteroids[i]>0){
                ans.push_back(asteroids[i]);
            }
            else if(asteroids[i]<0){
                int f=0;
                while(!ans.empty()){
                    int n=ans.size();
                    if(ans[n-1]<0){
                        break;
                    }
                    else if(ans[n-1]>abs(asteroids[i])){
                        f=1;
                        break;
                    }else if(ans[n-1]<abs(asteroids[i])){
                        ans.pop_back();
                    }else{
                        ans.pop_back();
                        f=1;
                        break;
                    }
                }
                if(f==0){
                    ans.push_back(asteroids[i]);
                }
            }
            i++;
        }
        return ans;
    }
};