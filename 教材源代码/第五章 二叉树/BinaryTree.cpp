#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

template<class T>
class TreeNode{
public:
    T val;
    TreeNode<T>*left,*right;
    TreeNode(T v=0,TreeNode<T>*l=nullptr,TreeNode<T>*r=nullptr):
        val(v),left(l),right(r){}
};

template<class T>
void visit(TreeNode<T>*root){
    cout<<root->val<<' ';
}

//1.递归深度优先遍历
template<class T>
void preOrder(TreeNode<T>*root){
    if(root){
        visit(root);
        preOrder(root->left);
        preOrder(root->right);
    }
}
template<class T>
void inOrder(TreeNode<T>*root){
    if(root){
        inOrder(root->left);
        visit(root);
        inOrder(root->right);
    }
}
template<class T>
void postOrder(TreeNode<T>*root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        visit(root);
    }
}

//2.非递归深度优先遍历
template<class T>
void nonRecPreOrder(TreeNode<T>*root){
    stack<TreeNode<T>*>st;
    TreeNode<T>*pointer=root;
    st.push(nullptr);
    while(pointer){
        visit(pointer);
        if(pointer->right)
            st.push(pointer->right);
        if(pointer->left)
            pointer=pointer->left;
        else{
            pointer=st.top();
            st.pop();
        }
    }
}
template<class T>
void nonRecInOrder(TreeNode<T>*root){
    stack<TreeNode<T>*>st;
    TreeNode<T>*pointer=root;
    while(pointer||!st.empty()){
        if(pointer){
            st.push(pointer);
            pointer=pointer->left;
        }
        else{
            pointer=st.top();
            st.pop();
            visit(pointer);
            pointer=pointer->right;
        }
    }
}
template<class T>
void nonRecPostOrder(TreeNode<T>*root){
    stack<pair<TreeNode<T>*,char> > st;
    TreeNode<T>*pointer=root;
    while(pointer||!st.empty()){
        if(pointer){
            st.push(make_pair(pointer,'L'));
            pointer=pointer->left;
        }
        else{
            pointer=st.top().first;
            if(st.top().second=='L'){
                st.top().second='R';
                pointer=pointer->right;
            }
            else{
                st.pop();
                visit(pointer);
                pointer=nullptr;
            }
        }
    } 
}

//3.广度优先遍历
template<class T>
void depthOrder(TreeNode<T>*root){
    TreeNode<T>*pointer=root;
    queue<TreeNode<T>*>q;
    q.push(pointer);
    while(!q.empty()){
        TreeNode<T>*p=q.front();
        q.pop();
        visit(p);
        if(p->left)
            q.push(p->left);
        if(p->right)
            q.push(p->right);
    }
}

//4.寻找结点的父结点
template<class T>
TreeNode<T>* parent(TreeNode<T>*cur,TreeNode<T>*pointer){//递归 starred
    if(!cur)
        return nullptr;
    if(cur->left==pointer||cur->right==pointer)
        return cur;
    TreeNode<T>*tmp;
    tmp=parent(cur->left,pointer);
    if(tmp)
        return tmp;
    tmp=parent(cur->right,pointer);
    if(tmp)
        return tmp;
    return nullptr;
}
template<class T>
TreeNode<T>* nonRecParent(TreeNode<T>*cur,TreeNode<T>*son){//非递归
    stack<TreeNode<T>*>st;
    st.push(nullptr);
    TreeNode<T>*pointer=cur;
    while(pointer){
        if(pointer->left==son||pointer->right==son)
            return pointer;
        if(pointer->right)
            st.push(pointer->right);
        if(pointer->left)
            pointer=pointer->left;
        else{
            pointer=st.top();
            st.pop();
        }
    }
    return nullptr;
}

//5.穿线二叉树
template<class T>
void Thread(TreeNode<T>*root,TreeNode<T>*&pre){//*&
    if(root){
        Thread(root->left,pre);
        if(!root->left)
            root->left=pre;
        if(!pre->right)
            pre->right=root;
        pre=root;
        Thread(root->right,pre);
    }
}

int main(){
    TreeNode<int>*a=new TreeNode<int>(1);
    TreeNode<int>*b=new TreeNode<int>(2);
    TreeNode<int>*c=new TreeNode<int>(3);
    TreeNode<int>*d=new TreeNode<int>(4);
    TreeNode<int>*e=new TreeNode<int>(5);
    TreeNode<int>*f=new TreeNode<int>(6);
    TreeNode<int>*g=new TreeNode<int>(7);
    TreeNode<int>*h=new TreeNode<int>(8);
    TreeNode<int>*i=new TreeNode<int>(9);
    TreeNode<int>*j=new TreeNode<int>(10);
    a->left=b;a->right=c;
    b->left=d;b->right=e;
    c->left=f;c->right=g;
    d->left=h;d->right=i;
    e->left=j;
    cout<<"前序遍历"<<endl;
    preOrder(a);cout<<endl;
    nonRecPreOrder(a);cout<<endl;
    cout<<"中序遍历"<<endl;
    inOrder(a);cout<<endl;
    nonRecInOrder(a);cout<<endl;
    cout<<"后序遍历"<<endl;
    postOrder(a);cout<<endl;
    nonRecPostOrder(a);cout<<endl;
    cout<<"层次遍历"<<endl;
    depthOrder(a);cout<<endl;
    cout<<"i的父结点"<<endl;
    visit(parent(a,i));cout<<endl;
    visit(nonRecParent(a,i));cout<<endl;
    cout<<"中序线索化"<<endl;
    Thread(a,a);
    visit(h->right);cout<<endl;
    visit(i->left);
    return 0;
}