class Solution {
public:
    int partition(vector<vector<int>>& intervals,int low,int high){
        int pv=intervals[high][0];

        int i=low-1;
        for(int j=low;j<high;j++){
            if(intervals[j][0]<pv){
                i++;
                swap(intervals[i],intervals[j]);
            }
        }
        swap(intervals[i + 1], intervals[high]);
        return i+1;
    }
    void quick_sort(vector<vector<int>>& intervals,int low,int high){
        if(low<high){
            int part=partition(intervals,low,high);

            quick_sort(intervals,low,part-1);
            quick_sort(intervals,part+1,high);
        }
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        quick_sort(intervals,0,intervals.size()-1);
        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){

            vector<int>& last = ans.back();

            if(intervals[i][0] <= last[1]){
                last[1] = max(last[1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};