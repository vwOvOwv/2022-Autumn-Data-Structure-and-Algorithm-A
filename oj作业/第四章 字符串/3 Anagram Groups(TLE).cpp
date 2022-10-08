#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

map<int,vector<set<string> > >ans;
string s;
bool Compare(set<string> &s1,set<string> &s2){
    if(s1.size()>s2.size())
        return true;
    else if(s1.size()<s2.size())
        return false;
    else{
        int com=s1.begin()->compare(*(s2.begin()));
        if(com>0)
            return false;
        else 
            return true;
    }
}
int main(){
    cin.tie(0);
    iostream::sync_with_stdio (0);
    while(cin>>s&&s[0]!=EOF){
        bool success=0;
        int n=s.size();
        auto i=ans.find(n);
        if(i==ans.end()){
            success=1;
            set<string>tmp;
            tmp.insert(s);
            ans.insert(make_pair(n,vector<set<string> >(1,tmp)));
        }
        else{
            auto j=i->second.begin();
            for(;j!=i->second.end();++j){
                string tmp1=s,tmp2=*(j->begin());
                sort(tmp1.begin(),tmp1.end());
                sort(tmp2.begin(),tmp2.end());
                if(!tmp1.compare(tmp2)){
                    success=1;
                    j->insert(s);
                    break;
                }
            }
            if(!success){
                // cout<<"test: "<<s<<endl;
                set<string>tmp;
                tmp.insert(s);
                ans[n].push_back(tmp);
            }
        }
    }
    vector<set<string> >ans1;
    for(auto i:ans){
        for(auto j:i.second){
            ans1.push_back(j);
        }
    }
    sort(ans1.begin(),ans1.end(),Compare);
    int cnt=0;
    for(auto len:ans1){
        cnt++;
        cout<<"Group of size "<<len.size()<<": ";
        for(auto word:len){
            cout<<word<<' ';
        }
        cout<<'.'<<endl;
        if(cnt==5)
            break;
    }
    return 0;
}