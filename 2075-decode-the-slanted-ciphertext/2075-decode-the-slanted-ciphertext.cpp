class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(encodedText.empty()) {
            return encodedText;
        }    

        int n = encodedText.size();
        int columns = (n + rows - 1) / rows;
        string result;

        for(int i = 0; i < columns; i++) {
            int r = 0, c = i;
            while(r < rows && c < columns) { 
                result += encodedText[r * columns + c];
                r++; 
                c++;
            }
        }

        while(!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};