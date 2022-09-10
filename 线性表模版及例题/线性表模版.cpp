#include<iostream>

using namespace std;

template<class T>
class List{//线性表
public:
    void clear();
    bool isEmpty();
    bool append(const T value);
    bool insert(const int p,const T value);
    bool myDelete(const int p);
    bool getPos(int&p,const T value);
    bool getValue(const int p,T&value);
    bool setValue(const int p,const T value);
};
template<class T>
class arrList:public List<T>{//顺序表（向量）
private:
    T*aList;//存储顺序表的实例
    int maxLen;//顺序表实例的最大长度
    int curLen;//顺序表实例的当前长度
    int curPos;//当前处理位置
public:
    arrList(const int length){
        maxLen=length;
        aList=new T[maxLen];
        curLen=0;
        curPos=0;
    }
    ~arrList(){
        delete []aList;
    }
    void clear(){
        delete []aList;//清空顺序表
        curLen=0;
        curPos=0;
        aList=new T[maxLen];//重建一个新的
    }
    int length(){
        return curLen;
    }
    bool append(const T value){
        if(curLen>=maxLen){
            cout<<"List Overflow!"<<endl;
            return false;
        }
        else{
            aList[curLen]=value;
            curLen++;
            return true;
        }
    }
    bool insert(const int p,const T value){
        if(curLen>=maxLen){
            cout<<"List Overflow!"<<endl;
            return false;
        }
        else if(p<0||p>=curLen){
            cout<<"Wrong Input!"<<endl;
            return false;
        }
        else{
            for(int i=curLen-1;i>=p;i--){//移动curLen-p次
                aList[i+1]=aList[i];
            }
            curLen++;
            aList[p]=value;
            return true;
        }
    }
    bool myDelete(const int p){
        if(p<0||p>=curLen){
            cout<<"Wrong Input!"<<endl;
            return false;
        }
        else{
            for(int i=p;i<curLen-1;i++){//移动curlen-p-1次
                aList[i]=aList[i+1];
            }
            curLen--;
            return true;
        }
    }
    bool setValue(const int p,const T value){
        if(p<0||p>=curLen){
            cout<<"Wrong Input!"<<endl;
            return false;
        }
        else{
            aList[p]=value;
            return true;
        }
    }
    bool getValue(const int p,T&value){
        if(p<0||p>=curLen){
            cout<<"Wrong Input!"<<endl;
            value=-1;
            return false;
        }
        else{
            value=aList[p];
            return true;
        }
    }
    bool getPos(int&p,const T value){
        for(int i=0;i<curLen;i++){
            if(aList[i]==value){
                p=i;
                return true;
            }
        }
        p=-1;
        return false;
    }
    void print(){
        for(int i=0;i<curLen;i++){
            cout<<aList[i]<<' ';
        }
        cout<<endl;
        cout<<"curLen="<<curLen<<endl;
    }
};

arrList<int> myArrList(10);
int main(){
    myArrList.print();//初始状态检查
    for(int i=0;i<6;i++)
        myArrList.append(i);//添加元素
    myArrList.print();
    myArrList.clear();//清空
    myArrList.print();
    for(int i=0;i<6;i++)
        myArrList.append(i);//添加元素
    myArrList.print();cout<<myArrList.length()<<endl;
    myArrList.insert(8,10);//错误插入元素
    myArrList.print();
    myArrList.insert(0,5);//正确插入元素
    myArrList.print();
    myArrList.myDelete(0);//正确删除元素
    myArrList.print();
    myArrList.myDelete(6);//错误删除元素
    myArrList.setValue(0,5);//设置值
    myArrList.print();
    int posTest;
    int valueTest;
    if(myArrList.getValue(0,valueTest))//返回元素值
    cout<<"valueTest="<<valueTest<<endl;
    if(myArrList.getValue(-1,valueTest))//错误返回元素值
    cout<<"valueTest="<<valueTest<<endl;
    if(myArrList.getPos(posTest,2))//查找元素值
    cout<<"posTest="<<posTest<<endl;
    if(myArrList.getPos(posTest,8))//错误查找元素值
    cout<<"posTest="<<posTest<<endl;
    return 0;
}