#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums;
    vector<int> res;
    int n, count=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }else if(nums[i]==0){
                res.push_back(count);
                cout<<count<<" ";
                count=0;
            }
        }
        int max=0;
        for(int i=0;i<res.size();i++){
            if(res[i]>max){
                max=res[i];
            }
        }   
        cout<<max;
    return 0;
}