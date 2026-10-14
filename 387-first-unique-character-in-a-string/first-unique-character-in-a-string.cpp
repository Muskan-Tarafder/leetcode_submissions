#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        queue<char> Q;
        // FIXED: Used pair<int, int> to store {first_index, frequency}
        unordered_map<char, pair<int, int>> cnt;
        unordered_set<char> lst;
        
        for (int i = 0; i < s.size(); i++) {
            // FIXED: Changed to .contains()
            if (!lst.contains(s[i])) { 
                Q.push(s[i]); // FIXED: Changed to .push()
                lst.insert(s[i]);
                cnt[s[i]] = {i, 1}; // {index, count}
            } else {
                cnt[s[i]].second += 1; // Increment count
            }
        }
        
        while (!Q.empty()) {
            char ch = Q.front(); // FIXED: Changed to .front()
            
            // If the character at the front of the queue is unique, return its index
            if (cnt[ch].second == 1) {
                return cnt[ch].first;
            }
            // Otherwise, remove it from the queue and keep checking
            Q.pop();
        }
        
        return -1;
    }
};
