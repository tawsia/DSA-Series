#include<bits/stdc++.h>
using namespace std;

bool isRedundant(string &s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

         if(ch == '(' || ch == '+' ||ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                bool isRedundant = true;



                while(st.top() != '('){
                    char ele = st.top();
                    if(ele ==  '+' ||ele == '-' || ele == '*' || ele == '/'){
                        isRedundant= false;
                    }
                    st.pop();
                }
                if(isRedundant == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
void findRedundant(string& s)
{
    bool ans = isRedundant(s);
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";
}
 
int main()
{
    string s = "((a+b))";
    findRedundant(s);
    return 0;
}
