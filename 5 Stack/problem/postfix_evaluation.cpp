/*
Q: 4+(5+6)*8-1
A: 91
Q: (2+4)*(5+6)
A: 66
*/
#include<bits/stdc++.h>
using namespace std;

int prec(char ch){
    if(ch == '+' || ch == '-'){
        return 0;
    }
    else if(ch == '('){
        return -1;
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
        if(now >= '1' && now <= '9'){
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
            if(!st.empty())
            // cout<<"Top: "<<st.top()<<endl;
            while(st.size() && prec(st.top()) >= prec(now)){
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

    stack<int> stk;
    
    cout<<ans<<endl;

    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]>='1' && ans[i]<='9')
        {
            int x = ans[i]-'0';
            stk.push(x);
        }
        else
        {
            if(ans[i] == '+')
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                int sum = a+b;
                stk.push(sum);
            }
            else if(ans[i] == '-')
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                int dif = b-a;
                stk.push(dif);
            }
            else if(ans[i] == '*')
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                int mul = a*b;
                stk.push(mul);
            }
            else if(ans[i] == '/')
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                int div = a/b;
                stk.push(div);
            }
        }
    }

    cout<<stk.top()<<'\n';
    
    return 0;
}