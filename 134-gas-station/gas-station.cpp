class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalG=0;
        int currG=0;
        int n=gas.size();
        int stidx=0;
        for(int i=0;i<n;i++){
            currG+=gas[i]-cost[i];
            totalG+=gas[i]-cost[i];
            if(currG<0){
                stidx=i+1;
                currG=0;
            }
        }
        if(totalG<0){
            return -1;
        }
        return stidx;
    }
};