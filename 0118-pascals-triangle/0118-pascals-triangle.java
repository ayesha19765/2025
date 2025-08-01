class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            List<Integer> curr = new ArrayList<>();
            int val = 1;
            for (int j = 0; j <= i; j++) {
                curr.add(val);
                val *= (i - j);
                val /= (j + 1);
            }
            ans.add(curr);
        }
        return ans;
    }
}