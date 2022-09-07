#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> dic;
// vector<string> ans;
void judge(string s){
	int n=dic.size();
    int l1=s.size();
    for(int i=0;i<n;i++){
        int l2=dic[i].size();
        if(l1==l2){
            if(s.compare(dic[i])==0){
                cout<<s<<" is correct"<<endl;
                return;
            }
        }
    }
    cout<<s<<':';
    for(int i=0;i<n;i++){
        int l2=dic[i].size();
        if(l1==l2){
            int cnt=0;
            for(int j=0;j<l1;j++){
                if(s[j]!=dic[i][j])
                    cnt++;
            }      
            if(cnt==1)
                cout<<' '<<dic[i];
        }
        else if(l1-l2==1){
            for(int k=0;k<l1;k++){
                string tmp=s;
                tmp.erase(k,1);//erase(int index,int num)
                int l=0;
                for(l=0;l<l2;l++){
                    if(tmp[l]!=dic[i][l])
                        break;
                }
                if(l==l2){
                    cout<<' '<<dic[i];
                    break;
                }
            }
        }
        else if(l2-l1==1){
            for(int k=0;k<l2;k++){
                string tmp=dic[i];
                tmp.erase(k,1);//erase(int index,int num)
                int l=0;
                for(l=0;l<l1;l++){
                    if(tmp[l]!=s[l])
                        break;
                }
                if(l==l1){
                    cout<<' '<<dic[i];
                    break;
                }
            }
        }
    }
    // if(!ans.empty()){
    //     for(int i=0;i<ans.size()-1;i++)
    //         cout<<ans[i]<<' ';
    //     cout<<ans[ans.size()-1]<<endl;
    // }
    cout<<endl;
}
int main(){
    char c;
    while(1){
        string s;
        cin>>s;
        if(s=="#")
            break;
        dic.push_back(s);
    }
    // for(int i=0;i<dic.size();i++)
    //     cout<<dic[i]<<endl;
    while(1){
        string s;
        cin>>s;
         if(s=="#")
            break;
        // ans.clear();
        judge(s);
    }
    return 0;
}