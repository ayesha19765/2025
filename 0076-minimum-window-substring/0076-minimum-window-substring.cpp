class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> req;

        for(char c: t){
            req[c] ++;
        }

        int needed = t.size(), start = 0, minLen = INT_MAX, minStart = 0;

        for(int end = 0; end < s.size(); end ++){
            
            if(req[s[end]] > 0){
                needed --;
            }

            req[s[end]] --;

            while(needed == 0){
                if(minLen > end - start + 1)
                {
                    minStart = start;
                    minLen = end - start + 1;
                }

                req[s[start]] ++;

                if(req[s[start]] > 0)
                    needed ++;

                start ++;
            }
        }

        if(minLen == INT_MAX)
            return "";
        
        return s.substr(minStart, minLen);
    }
};