class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for(char ch: s){
            freq[ch] ++;
        }

        priority_queue<pair<int, char>> maxHeap;

        for(auto &[ch, cnt]: freq){
            maxHeap.push({cnt, ch});
        }

        string res = "";

        pair<int, char> prev = {0, '#'};

        while(!maxHeap.empty()){
            auto [cnt, ch] = maxHeap.top();

            maxHeap.pop();

            if(prev.first)
                maxHeap.push(prev);

            res += ch;

            prev = {cnt - 1, ch};
        }

        return res.size() == s.size() ? res : "";
    }
};