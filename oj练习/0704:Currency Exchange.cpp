#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Edge{
public:
    int to;
    double rate,commission;
    Edge(){}
    Edge(int t=0,double r=0,double c=0):
        to(t),rate(r),commission(c){}
};

int main(){
    int n,m,s;
    double start;
    cin>>n>>m>>s>>start;
    vector<vector<Edge> >rec;
}