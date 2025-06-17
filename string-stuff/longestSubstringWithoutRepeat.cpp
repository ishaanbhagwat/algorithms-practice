// Sliding window approach with fast/slow pointer => Fast pointer keeps track of current char, slow pointer keeps track of most recent non-repeat char
// TC: O(N) -> solution in 1 pass
// SC: O(1) -> constant space as we use bool array;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        bool charSet[256] = {false};
        int left = 0;
        int max_length = 0;

        for(int right = 0; right < s.length(); right++){
            // update left counter until window shrinks to remove repeat character
            while(charSet[s[right]]){
                charSet[s[left]] = false;
                left++;
            }

            charSet[s[right]] = true;
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};
