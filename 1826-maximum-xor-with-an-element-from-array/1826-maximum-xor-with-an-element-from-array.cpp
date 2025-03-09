class TrieNode{
public:
    TrieNode* child[2];
    TrieNode(){
       child[0] = child[1] = NULL;
    }
};

class Trie{
public:  
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(int num){
        TrieNode *curr = root;
        for(int i = 31; i >=0; i--){
            int bit = (num >> i) & 1;

            if(!curr->child[bit]){
                curr->child[bit] = new TrieNode();
            }

            curr = curr->child[bit];
        }
    }
    int findMax(int num){
        TrieNode *curr = root;
        
        int maxi = 0;

        for(int i = 31; i >=0; i--){
            int bit = (num >> i) & 1;

            if(curr->child[!bit]){
                curr = curr->child[!bit];
                maxi = maxi | (1 << i);
            }else{
                curr = curr->child[bit];
            }
        }

        return maxi;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int, int> > > offlineQueries;

        for (int i = 0; i < queries.size(); i++)
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});

        sort(offlineQueries.begin(), offlineQueries.end());

        int i = 0, n = nums.size();
        
        vector<int> ans(queries.size(), 0);
        Trie* t = new Trie();

        for(int k = 0; k < queries.size(); k++){
            int ai = offlineQueries[k].first;
            int xi = offlineQueries[k].second.first;
            int qIdx = offlineQueries[k].second.second;

            while(i < n && nums[i] <= ai){
                t->insert(nums[i]);
                i++;
            }

            if(i == 0) ans[qIdx] = -1;
            else ans[qIdx] = t->findMax(xi);
        }

        return ans;
    }
};