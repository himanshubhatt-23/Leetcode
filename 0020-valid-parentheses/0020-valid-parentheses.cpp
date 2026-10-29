class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> f = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s) {
            if (f.find(c) == f.end())  stack.push(c);
            else if (!stack.empty() && f[c] == stack.top()) stack.pop();
            else  return false;
        }
        return stack.empty();        
    }
};