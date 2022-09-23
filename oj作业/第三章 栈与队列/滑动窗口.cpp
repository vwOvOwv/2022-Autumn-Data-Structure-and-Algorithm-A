#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

vector<int>ans_maxi,ans_mini,nums;
deque<int>maxi,mini;//双端单调队列存坐标
//通过单调队列维护每一个窗口内数字的大小关系
int main(){
    int n,k,num;
    cin>>n>>k;
    for(int i=0;i<k;i++){//先处理第一个窗口
        cin>>num;
        nums.push_back(num);//记录数字
        while (!maxi.empty()&&nums[maxi.back()]<num)//若当前数字已经比队列末尾的数字小了那说明队列末尾的数字已经不可能是这个窗口里的最大元素了，直接弹出
            maxi.pop_back();
        maxi.push_back(i);
        while(!maxi.empty()&&maxi.front()<=i-k)//去掉窗口外的元素
            maxi.pop_front();
        while(!mini.empty()&&nums[mini.back()]>num)
            mini.pop_back();
        mini.push_back(i);
        while(!mini.empty()&&mini.front()<=i-k)
            mini.pop_front();
    }
    ans_maxi.push_back(maxi.front());
    ans_mini.push_back(mini.front());
    for(int i=k;i<n;i++){
        cin>>num;
        nums.push_back(num);
        while (!maxi.empty()&&nums[maxi.back()]<num)
            maxi.pop_back();
        maxi.push_back(i);
        while(!maxi.empty()&&maxi.front()<=i-k)
            maxi.pop_front();
        while(!mini.empty()&&nums[mini.back()]>num)
            mini.pop_back();
        mini.push_back(i);
        while(!mini.empty()&&mini.front()<=i-k)
            mini.pop_front();
        ans_maxi.push_back(maxi.front());
        ans_mini.push_back(mini.front());
    }
    for(int i=0;i<n-k+1;i++){
        cout<<nums[ans_mini[i]];
        if(i!=n-k)
            cout<<' ';
    }
    cout<<endl;
    for(int i=0;i<n-k+1;i++){
        cout<<nums[ans_maxi[i]];
        if(i!=n-k)
            cout<<' ';
    }
    return 0;
}