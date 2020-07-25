/******HAPPY CODING******
Codechef: ritik_tanwar
*********WITH************
CodeForces:illuminatiiiii
*********RITIK**********/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int num_friends,num_trasactions;
    cin>>num_friends>>num_trasactions;
    int x,y,amount;
    int net[100005]={0};
    while(num_trasactions--){
        cin>>x>>y>>amount;
        net[x]-=amount;
        net[y]+=amount;
    }
    multiset<int>m;
    for(int i=0;i<num_friends;i++){
        // cout<<net[i]<<" ";
        if(net[i]!=0) m.insert(net[i]);
    }
    // cout<<"\n";
    // for(auto x:m){
    //         cout<<x<<" ";
    // }
    // cout<<"\n";
    int cnt=0;
    while(!m.empty()){
        auto low=m.begin();
        auto high=prev(m.end());

        int debit=*low;
        int credit=*high;

        m.erase(low);
        m.erase(high);

        int settle_amt=min(-debit,credit);
        cnt++;

        debit+=settle_amt;
        credit-=settle_amt;

        if(debit!=0 ) {
            m.insert(debit);
        }
        if(credit!=0) m.insert(credit);
        // for(auto x:m){
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
    }
    cout<<cnt;
    return 0;
}