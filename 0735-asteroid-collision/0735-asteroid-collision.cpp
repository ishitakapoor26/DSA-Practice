class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      stack<int> st;
      for(int asteroid: asteroids){
      bool flag=true;
          while(!st.empty() && (st.top()>0 && asteroid<0)){
              if(abs(st.top())<abs(asteroid)){
                  st.pop();
                  continue;
              }else if(abs(st.top())==abs(asteroid)){
                  st.pop();
              }
              flag=false;
              break;
          }
          if(flag){
              st.push(asteroid);
          }
      }
      vector<int> res(st.size());
      for(int i=st.size()-1;i>=0;i--){
          res[i]=st.top();
          st.pop();
      }
      return res;
    }
};