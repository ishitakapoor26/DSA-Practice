#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool canPlaceFlowers(vector<int> flowerbed, int n) {
        bool flag=true;
        stack<int> st;
        for(int flower: flowerbed){
            st.push(flower);
        }
        while(st.size()>1 && n>0){
            int n1= st.top();
            st.pop();
            if(st.top()!=n1){
                continue;
            }else{
                if(st.top()==0 && n1==0){
                    st.pop();
                    st.push(1);
                    n--;
                }else{
                    flag=false;
                    break;
                }
            }
        }
        st.pop();
        return flag && n==0 ?true:false;
    }