#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,n;
vector<pair<int, int> >rec;//rec[i]记录数字i的坐标
int ans[410][410];
int main(){
    cin>>N;
    n=2*N-1;
    rec.push_back(make_pair(-1,-1));//占第0位
    rec.push_back(make_pair(1,(n+1)/2));//注意几何关系
    ans[1][(n+1)/2]=1;
    for(int i=2;i<=n*n;i++){//按照a,b,c三条限制讨论
        if(rec[i-1].first==1&&rec[i-1].second!=n){
            rec.push_back(make_pair(n,rec[i-1].second+1));
            ans[n][rec[i-1].second+1]=i;
        }
        else if(rec[i-1].second==n&&rec[i-1].first!=1){
            rec.push_back(make_pair(rec[i-1].first-1,1));
            ans[rec[i-1].first-1][1]=i;
        }
        else if((rec[i-1].first==1&&rec[i-1].second==n)||(ans[rec[i-1].first-1][rec[i-1].second+1]!=0)){
            rec.push_back(make_pair(rec[i-1].first+1,rec[i-1].second));
            ans[rec[i-1].first+1][rec[i-1].second]=i;
        }
        else{//默认情况
            rec.push_back(make_pair(rec[i-1].first-1,rec[i-1].second+1));
            ans[rec[i-1].first-1][rec[i-1].second+1]=i;
        }
    }
    // for(auto i:rec){
    //     cout<<i.first<<' '<<i.second<<endl;
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[i][j];
            if(j!=n){
                cout<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}