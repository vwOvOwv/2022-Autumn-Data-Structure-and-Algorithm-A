#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include <vector>

using namespace std;

template<class T>
void print(vector<T>v){
    for(auto i:v)
        cout<<i<<' ';
    cout<<endl;
}

template<class T>
void siftDown(vector<T>&minHeap,int pos){
    int n=minHeap.size();
    int i=pos,j=2*i+1;
    T tmp=minHeap[i];
    while(j<n){
        if(j+1<n&&minHeap[j]>minHeap[j+1])
            j++;
        if(tmp>minHeap[j]){
            minHeap[i]=minHeap[j];
            i=j;j=2*i+1;
        }
        else
            break;
    }
    minHeap[i]=tmp;
}

template<class T>
void siftUp(vector<T>&minHeap,int pos){
    int i=pos,j=(i-1)/2;
    T tmp=minHeap[i];
    while(i>0){
        if(tmp<minHeap[j]){
            minHeap[i]=minHeap[j];
            i=j;j=(i-1)/2;
        }
        else
            break;
    }
    minHeap[i]=tmp;
}

template<class T>
void buildHeap(vector<T>&minHeap){
    int n=minHeap.size();
    int start=n/2-1;
    for(int i=start;i>=0;i--){
        siftDown(minHeap,i);
    }
}

template<class T>
void insert(vector<T>&minHeap,T val){
    minHeap.push_back(val);
    siftUp(minHeap,minHeap.size()-1);
}

template<class T>
void _delete(vector<T>&minHeap,int pos){
    int n=minHeap.size();
    minHeap[pos]=minHeap[n-1];
    minHeap.pop_back();
    int i=pos,j=(i-1)/2;
    if(j>=0&&minHeap[i]<minHeap[j])
        siftUp(minHeap,i);
    else 
        siftDown(minHeap,i);
}

int main(){
    vector<int>minHeap;
    minHeap.push_back(10);
    minHeap.push_back(3);
    minHeap.push_back(7);
    minHeap.push_back(8);
    minHeap.push_back(1);
    minHeap.push_back(2);
    minHeap.push_back(9);
    minHeap.push_back(4);
    minHeap.push_back(6);
    minHeap.push_back(5);
    buildHeap(minHeap);print(minHeap);
    insert(minHeap,0);print(minHeap);
    _delete(minHeap,0);print(minHeap);
    return 0;
}