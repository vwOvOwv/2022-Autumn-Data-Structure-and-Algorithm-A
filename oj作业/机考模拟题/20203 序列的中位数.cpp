#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>rec(n+1);
    for(int i=1;i<=n;i++){
        cin>>rec[i];
    }
    for(int k=1;k<=n;k+=2){
        sort(rec.begin()+1,rec.begin()+k+1);
        int mid=(1+k)/2;
        cout<<rec[mid]<<endl;
    }
    return 0;
}