//(49条消息) 什么是KMP算法（详解）_攻城狮百里的博客-CSDN博客_kmp算法
//https://blog.csdn.net/weixin_52622200/article/details/110563434?ops_request_misc=&request_id=&biz_id=102&utm_term=kmp%E7%AE%97%E6%B3%95&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-3-110563434.142%5Ev47%5Epc_rank_34_default_3,201%5Ev3%5Eadd_ask&spm=1018.2226.3001.4187

#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

int n;
string s;
int main(){
    int cnt=0;
    while(cin>>n){
        if(!n)break;
        cin>>s;
        cnt++;
        cout<<"Test case #"<<cnt<<endl;
        for(int i=2;i<=n;i++){
            string ss=s.substr(0,i);
            // cout<<"ss: "<<ss<<endl;
            /*for(int k=ss.length();k>=2;k--){//要找最大的k
                if(ss.length()%k==0){
                    int l=ss.length()/k;
                    string sss=ss.substr(0,l);//从index开始向后长为l的子串
                    // cout<<"sss: "<<sss<<endl;
                    string tmp=sss;
                    for(int r=0;r<k-1;r++){
                        sss+=tmp;
                    }
                    // cout<<"sss: "<<sss<<endl;
                    if(sss.compare(ss)==0){
                        cout<<i<<' '<<k<<endl;
                        break;
                    }
                }
            }8*/
            for(int l=1;l<=i/2;l++){//至少重复两次
                if(i%l==0){
                    string sss=ss.substr(0,l);
                    int k=i/l;
                    string tmp=sss;
                    for(int r=0;r<k-1;r++){
                        sss+=tmp;
                    }
                    if(sss.compare(ss)==0){
                        cout<<i<<' '<<k<<endl;
                        break;
                    }
                }
            }
        }
        cout<<endl;
    }
    return 0;
}