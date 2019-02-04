//Problem 1743: YYB吃苹果 
//Status: Accepted 
//Used Time: 34ms 
//Peak Memory: 496.0 KiB
#include <iostream>
#include <vector>
using namespace std;
typedef struct node{
    char value;
    int leftChild;
    int rightChild;
}Node;
vector<Node>tree;
void A(int num){
    if(num!=-1&&tree[num].value!=-1){
        cout<<tree[num].value;
        A(tree[num].leftChild);
        A(tree[num].rightChild);
    }
}
void B(int num){
    if(num!=-1&&tree[num].value!=-1){
        B(tree[num].leftChild);
        cout<<tree[num].value;
        B(tree[num].rightChild);
    }
}
void C(int num){
    if(num!=-1&&tree[num].value!=-1){
        C(tree[num].leftChild);
        C(tree[num].rightChild);
        cout<<tree[num].value;
    }
}
int main(void){
    char head,temp;
    int pos=0,end=0;
    bool flag=0;
    cin>>head;
    getchar();
    Node* ptr=new Node;
    ptr->value=head;
    ptr->leftChild=-1;
    ptr->rightChild=-1;
    tree.push_back(*ptr);
    end++;
    cin>>temp;
    while((temp<='z'&&temp>='a')||temp=='0'){
        if(tree[pos].value==-1){
            while(tree[pos].value==-1){
                pos++;
            }
        }
        if(temp=='0'){
            temp=-1;
        }
        ptr=new Node;
        ptr->value=temp;
        ptr->leftChild=-1;
        ptr->rightChild=-1;
        tree.push_back(*ptr);
        if(flag){
            tree[pos].rightChild=end;
        }
        else{
            tree[pos].leftChild=end;
        }
        end++;
        flag=(flag==0?1:0);
        getchar();
        if(!flag){
            pos++;
        }
        cin>>temp;
    }
    getchar();
    getchar();
    cin>>head;
    if(head=='A'){
        A(0);
    }
    else if(head=='B'){
        B(0);
    }
    else{
        C(0);
    }
}
