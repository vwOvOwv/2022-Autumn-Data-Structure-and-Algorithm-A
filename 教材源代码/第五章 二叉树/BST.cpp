#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include <vector>

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

template<class T>
void inOrder(TreeNode<T>*root){
    if(root){
        inOrder(root->left);
        visit(root);
        inOrder(root->right);
    }
}

template<class T>
TreeNode<T>* search(T val,TreeNode<T>*root){
    TreeNode<T>*pointer=root;
    while(pointer){
        if(pointer->val>val)
            pointer=pointer->left;
        else if(pointer->val<val)
            pointer=pointer->right;
        else
            return pointer;
    }
    return nullptr;
}

template<class T>
bool insert(T val,TreeNode<T>*root){
    TreeNode<T>*tmp=search(val,root);
    if(tmp)
        return false;
    TreeNode<T>*pointer=root;
    while(pointer){
        if(pointer->val>val){
            if(pointer->left)
                pointer=pointer->left;
            else
                break;
        }
        else if(pointer->val<val){
            if(pointer->right)
                pointer=pointer->right;
            else
                break;
        }
    }
    TreeNode<T>*t=new TreeNode<T>(val);
    if(pointer->val>val)
        pointer->left=t;
    else
        pointer->right=t;
    return true;
}

template<class T>
TreeNode<T>* deleteMin(TreeNode<T>*&root){//*&
   if(root->left)
        return deleteMin(root->left);
    else{
        TreeNode<T>*tmp=root;
        root=root->right;
        return tmp;
    }
}

template<class T>
void deleteNode(TreeNode<T>*&root,T val){//*&
    if(root){
        if(root->val<val)
            deleteNode(root->right,val);
        else if(root->val>val)
            deleteNode(root->left,val);
        else{
            TreeNode<T>*tmp=root;//tmp为要删除的结点
            if(!root->left&&root->right){
                root=root->right;
            }
            else if(root->left&&!root->right){
                root=root->left;
            }
            else{
                tmp=deleteMin(root->right);//更新tmp
                root->val=tmp->val;
            }
            delete(tmp);//要删掉！！！
        }
    }
}

int main(){
    TreeNode<int>*a=new TreeNode<int>(6);
    TreeNode<int>*root=a;
    insert(4,a);
    insert(9,a);
    cout<<insert(9,a)<<endl;
    insert(3,a);
    insert(1,a);
    insert(13,a);
    insert(8,a);
    inOrder(a);cout<<endl;
    deleteNode(a,4);
    deleteNode(a,9);
    inOrder(a);cout<<endl;
    visit(search(3,root));
    return 0;
}