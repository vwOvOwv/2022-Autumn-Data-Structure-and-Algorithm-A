#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

map<int,int>rec;
vector<int>xx,yy;
int n;
int main(){
    cin>>n;
    for(int j=1;j<=n;j++){
        rec.clear();
        xx.clear();
        yy.clear();
        int x,y;
        while(cin>>x>>y){//可能多次输入相同的指数
            if(y<0){
                break;
            }
            if(rec.find(y)!=rec.end()){
                rec[y]+=x;
            }
            else{
                rec[y]=x;
            }
        }
        while(cin>>x>>y){
            if(y<0){
                break;
            }
            if(rec.find(y)!=rec.end()){
                rec[y]+=x;
            }
            else{
                rec[y]=x;
            }
        }
        map<int,int>::reverse_iterator k=rec.rbegin();
        for(;k!=rec.rend();++k){//反向迭代器
            if((*k).second!=0){
                xx.push_back((*k).second);
                yy.push_back((*k).first);
            }
        }
        if(!xx.empty()){
            for(int i=0;i<xx.size()-1;i++){
                cout<<"[ "<<xx[i]<<' '<<yy[i]<<" ] ";
            }
            cout<<"[ "<<xx[xx.size()-1]<<' '<<yy[xx.size()-1]<<" ]"; 
        }
        if(j!=n)
            cout<<endl;
    }
    return 0;
}