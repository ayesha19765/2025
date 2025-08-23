class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());

        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        set.erase(beginWord);

        while(!q.empty()){
            auto currNode = q.front();
            q.pop();

            if(currNode.first == endWord) return currNode.second;
            for(int i = 0; i < currNode.first.size(); i++){
                string original = currNode.first;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    original[i] = ch;
                    if(set.find(original)!=set.end()){
                        q.push({original, currNode.second + 1});
                        set.erase(original);
                    }
                }
            }
            
        }

        return 0;
    }
}; 
