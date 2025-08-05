class Solution {
private:
    bool isMatched(char open, char close) {
        if((open == '(' && close == ')') || (open == '[' && close == ']') ||
           (open == '{' && close == '}')
        )
            return true;
        else
            return false;
    }
   
public:
    bool isValid(string str) {
        int n = str.length();
        stack<char> st;
    
        for(int i = 0; i < n; i++) {
            if(str[i] == '(' || str[i] == '[' || str[i] == '{')
                st.push(str[i]);
            else {
                if(st.empty())
                    return false;
        
                char ch = st.top();
                st.pop();
        
                if(!isMatched(ch, str[i])) 
                    return false;
            }
        }
        return st.empty();
    }
};