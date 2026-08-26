class Solution {
public:
    string shortestBeautifulSubstring(string str, int k) {
        int n = str.length();
        int mini = INT_MAX;
        string ans = "";
        for(int i = 0; i < n; i ++){
            
            int cnt = (str[i] == '1'), j = i;

            while(cnt < k){
                j ++;
                if(j == n)
                    break;
                cnt += (str[j] == '1');
            }

            if(cnt == k){
                int len = j - i + 1;
                if(len < mini || (len == mini && str.substr(i, len) < ans)){
                    mini = j - i + 1;
                    ans = str.substr(i, mini);
                }
            }
        }

        cout << mini << endl;
        return ans;
    }
};