class Solution {
public:
    string minWindow(string s, string t) {
        int charNotFound = t.size();

        unordered_map<char, int> freq;

        for(char ch: t)
            freq[ch] ++;

        int start = 0, end = 0, minStart = 0, ans = INT_MAX;

        while(end < s.size()){
            if(freq[s[end]] > 0){
                charNotFound --;
            }
            freq[s[end]] --;

            while(charNotFound == 0){
                if((end - start + 1) < ans){
                    minStart = start;
                    ans = end - start + 1;
                }

                freq[s[start]] ++;

                if(freq[s[start]] > 0){
                    charNotFound ++;
                }
                
                start ++;
            }

            end ++;
        }

        return s.substr(minStart, ans == INT_MAX ? 0: ans);
    }
};