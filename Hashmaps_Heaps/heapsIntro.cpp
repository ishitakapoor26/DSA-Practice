// max heap=>default : priority_queue<int,vector<int>>
// min heap- priority_queue<int, vector<int>,greater<int>>

// push,pop: logn, top,size- O(1)

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    priority_queue<int,vector<int>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);
    cout<<pq.top()<<endl;
    pq.pop();
    priority_queue<int,vector<int>,greater<int>> pq_min;
    pq_min.push(2);
    pq_min.push(3);
    pq_min.push(1);
    cout<<pq_min.top()<<endl;
    pq_min.pop();
    return 0;
}