class Solution {
public:
    int secondHighest(string s) {
        priority_queue<int> hp;
        unordered_set<int> seen;
        for(auto &ch:s){
            if(isdigit(ch) && seen.find(ch-'0')==seen.end()){
                hp.push(ch-'0');
                seen.insert(ch-'0');
            }
        }
        if(hp.empty()){
            return -1;
        }
        hp.pop();
        if(hp.empty()){
            return -1;
        }
        return hp.top();
    }
};