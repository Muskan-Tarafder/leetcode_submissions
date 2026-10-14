#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0; // Pointer to update the array in-place
        int i = 0;     // Pointer to scan through characters

        while (i < chars.size()) {
            char current_char = chars[i];
            int count = 0;

            // Count the consecutive repetitions of the current character
            while (i < chars.size() && chars[i] == current_char) {
                count++;
                i++;
            }

            // Write the character itself
            chars[write++] = current_char;

            // If the group length is greater than 1, write its string digits
            if (count > 1) {
                string count_str = to_string(count);
                for (char digit : count_str) {
                    chars[write++] = digit;
                }
            }
        }

        // Return the new length of the compressed vector
        return write;
    }
};
