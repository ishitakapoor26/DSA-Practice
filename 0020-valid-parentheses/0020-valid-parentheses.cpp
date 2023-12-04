class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
    for (int i = 0; i < s.length(); i++) {
      char ob;
      if(s[i] == '{' || s[i] == '[' || s[i] == '(')
        st.push(s[i]);
      else{
          if(st.empty()) return false;
          if(s[i] == '}' || s[i] == ']' || s[i] == ')'){
           if (s[i] == '}')
            ob = '{';
            else if (s[i] == ']')
            ob = '[';
            else if (s[i] == ')')
          ob = '(';
            if (st.top() == ob) {
          st.pop();
            }else return false;
           }
      }
    }
    if(st.empty()) return true;
    return false;
    }
};