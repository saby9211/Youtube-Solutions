#include <bits/stdc++.h>
using namespace std;


bool StringCompare(string s, string t) {
	stack<char> stk1, stk2;

    for(auto &ch : s) {
        if(ch != '#') {
            stk1.push(ch);
        }
        else {
            if(!stk1.empty()) {
                stk1.pop();
            }
        }
    }

    for(auto &ch : t) {
        if(ch != '#') {
            stk2.push(ch);
        }
        else {
            if(!stk2.empty()) {
                stk2.pop();
            }
        }
    } 
    return (stk1 == stk2);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	if (StringCompare(s, t))
		cout << "Yes";
	else
		cout << "No";
}