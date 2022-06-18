
//https://leetcode.com/problems/prefix-and-suffix-search/discuss/1185249/C%2B%2B-No-TRIE-A-HashMap-soln.

//The time and space complexity is actually O(N*L^3) since it hashes L^2 string for each word and each hash takes O(L) operations.
//Each entry also store the string in order to resolve collision so again O(L^2 * L) for each word.
class WordFilter {
   private:
    unordered_map<string, int> hashMap;

   public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string word = words[i];
            int wordSize = word.size();
            for (int j = 1; j <= wordSize; j++) {
                string p = word.substr(0, j);
                for (int k = 0; k < wordSize; k++) {
                    string s = word.substr(k, wordSize);
                    hashMap[p + "|" + s] = i + 1;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string s = prefix + "|" + suffix;
        return hashMap[s] - 1;
    }
};