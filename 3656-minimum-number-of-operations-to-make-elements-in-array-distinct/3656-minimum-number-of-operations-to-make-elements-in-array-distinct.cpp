class Solution {
public:
    int minimumOperations(vector<int>& sankhyao) {
        unordered_set<int> setVastu;
        int parinam = 0;

        while (!sankhyao.empty()) {
            setVastu.clear();
            bool sabAlag = true;
            for (int sankhya : sankhyao) {
                if (setVastu.count(sankhya)) {
                    sabAlag = false;
                    break;
                }
                setVastu.insert(sankhya);
            }
            if (sabAlag) {
                break;
            }
            sankhyao.erase(sankhyao.begin(), sankhyao.begin() + min(3, (int)sankhyao.size())); 
            parinam++;
        }

        return parinam;
    }
};
