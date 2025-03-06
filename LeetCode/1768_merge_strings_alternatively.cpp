class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";

        int i = 0;
        int j = 0;
        int size1 = word1.size();
        int size2 = word2.size();
        
        while (i < size1 || j < size2) {
            if (i < size1) s += word1[i++];
            if (j < size2) s += word2[j++];
        }

        return s;
    }
};