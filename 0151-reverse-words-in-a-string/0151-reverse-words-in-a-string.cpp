class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> words;
        int i = 0;

        while(i < n) {
            while(i < n && s[i] == ' ') // Skips leading spaces
                i++; 
            
            string word = "";
            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            if (!word.empty())
                words.push_back(word);
        }

        string result = ""; // Joins in reverse order
        for(int j = words.size() - 1; j >= 0; j--) {
            result += words[j];
            if(j != 0)
                result += ' ';
        }
        return result;
    }
};
