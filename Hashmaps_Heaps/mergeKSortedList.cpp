#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Pair{
    public:
    int li;
    int di;
    int val;

    Pair(int li, int di, int val){
        this->li=li;
        this->di=di;
        this->val=val;
    }
};

vector<int>* mergeKSortedList(vector<vector<int>>* arr){
    vector<int>* rv;
    priority_queue<Pair> pq;
    for(int i=0;i<arr->size();i++){
        Pair p= Pair(i,0,arr[i][0][0]);
        pq.push(p);
    }
    while(pq.size()>0){
        Pair p = pq.top();
        pq.pop();
        rv->push_back(p.val);
        p.di++;
        if(p.di<arr[p.li].size()){
            p.val = arr[p.li][p.di];
            pq.push(p);
        }
    }
    return rv;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        for(int j=0;j<num;j++){
            cin>>arr[i][j];
        }
    }

    return 0;
}
