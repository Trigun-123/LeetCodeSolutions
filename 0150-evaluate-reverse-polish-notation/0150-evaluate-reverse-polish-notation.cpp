class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(auto it : tokens) {
            if(it == "+") {
                int second = s.top(); 
                s.pop();
                int first = s.top(); 
                s.pop();
                s.push(first + second);
            } 
            else if(it == "-") {
                int second = s.top(); 
                s.pop();
                int first = s.top(); 
                s.pop();
                s.push(first - second);
            } 
            else if(it == "*") {
                int second = s.top(); 
                s.pop();
                int first = s.top(); 
                s.pop();
                s.push(first * second);
            } 
            else if(it == "/") {
                int second = s.top(); 
                s.pop();
                int first = s.top(); 
                s.pop();
                s.push(first / second);
            } 
            else {
                s.push(stoi(it));
            }
        }

        return s.top();        
    }
};