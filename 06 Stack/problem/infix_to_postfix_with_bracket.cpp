/*
Queston: a+(b+c)*d-e 
Answer: abc+d*+e-
Q: (a+b)*(c+d)
A: ab+cd+*
*/

#include<bits/stdc++.h>
using namespace std;

int prec(char ch){
    if(ch == '+' || ch == '-'){
        return 0;
    }
    return 1;
}

int main()
{
    string s;
    cin>>s;
    stack<char> st;
    string ans = "";

    for(int i=0;i<s.size();i++){
        char now = s[i];
        if(now >= 'a' && now <= 'z'){
            ans += now;
        }
        else if(now == '('){
            st.push(now);
        }
        else if(now == ')'){
            while(st.size() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if(st.size())st.pop();
        }
        else{
            while(st.size() && prec(st.top()) >= prec(now) && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.push(now);
        }
    }

    while (st.size())
    {
        ans += st.top();
        st.pop();
    }

    cout<<ans<<'\n';
    
    return 0;
}