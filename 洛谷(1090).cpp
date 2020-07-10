#include<bits/stdc++.h>
using namespace std;
int n,i,m,k,s;
int main(){
    priority_queue<int>q;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>m;
        q.push(-m);
    }
    while(q.size()-1){
        k=-q.top();
        q.pop();
        k-=q.top();
        q.pop();
        s+=k;
        q.push(-k);
    }
    cout<<s;
    return 0;
}
