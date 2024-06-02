class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stk, star;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                stk.push(i);
            }
            else if(s[i] == '*'){
                star.push(i);
            }
            else{ // s[i] == ')'
                if(!stk.empty()){
                    stk.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!stk.empty() && !star.empty()){
            if(star.top() < stk.top()){
                return false;
            }
            
            stk.pop();
            star.pop();
            
        }
        return stk.empty();
    }
};