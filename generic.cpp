#include<bits/stdc++.h>
using namespace std;

class person_cmp{
    public:
    bool operator()(pair<string,int> a,pair<string,int> b){
        return a.second<b.second;
    }
};

int main(){
    int num_friends,num_transacitons;
    cin>>num_friends>>num_transacitons;

    string x,y;
    int amt;
    map<string,int>mp;
    while(num_transacitons--){
        cin>>x>>y>>amt;
        if(mp.count(x)==0) mp[x]=0;
        if(mp.count(y)==0) mp[y]=0;

        mp[x]-=amt;
        mp[y]+=amt;
    }

    multiset<pair<string,int>,person_cmp> m;

    for(auto x:mp){
        string person=x.first;
        int amount=x.second;

        m.insert(make_pair(person,amount));
    }

    int cnt=0;

    while(!m.empty()){ 
        auto  low=m.begin();
        auto  high= prev(m.end());

        string debit_person=low->first;
        int debit_amt = low->second;

        string credit_person=high->first;
        int credit_amt = high->second;

        m.erase(low);
        m.erase(high);

        int settle_amt=min(-debit_amt,credit_amt);

        cout<<debit_person<<" pays "<<-debit_amt<<" "<<credit_person<<"\n";

        debit_amt+=settle_amt;
        credit_amt-=settle_amt;

        if(debit_amt!=0) m.insert(make_pair(debit_person,debit_amt));

        if(credit_amt!=0) m.insert(make_pair(credit_person,credit_amt));

    }
}