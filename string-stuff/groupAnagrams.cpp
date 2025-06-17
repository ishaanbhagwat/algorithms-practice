// HashMap + Freq Counter Solution | Use Freq Counter Key for Hashmap
// TC: O(N * K) - N is length of array and K is max length of string
// SC: O(N * K)
// More efficient solution than => HashMap + Sort, which is O(N * K log K)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string& str: strs){
            string key=get_frequency_key(str);
            mp[key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto& pair : mp){
            result.push_back(pair.second);
        }
        return result;
    }

private:
    string get_frequency_key(const string& str){
        int freq[26] = {0};
        for(char c : str){
            freq[c - 'a']++;
        }

        string key = "";
        for (int i=0; i<26; i++){
            if (freq[i] > 0){
                key += char('a' + i) + to_string(freq[i]);
            }
        }

        return key;
    }
};
