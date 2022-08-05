#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};
node *merge2list(node *a,node *b){
    node *temp=NULL;
    if(a==NULL) return b;
    if(b==NULL) return a;
    if(a->data > b->data) {
        swap(a,b);
    }
    node *res=a;
    while(a!=NULL && b!=NULL){
        node *temp=NULL;
        while(a!=NULL && a->data <= b->data){
            temp=a;
            a=a->next;
        }
        temp->next=b;
        swap(a,b);
    }
    return res;
}
int main()
{
    int m,n,val,val1,first,first1;
    cin>>m;
    cin>>first;
    struct node *head,*tail,*head1,*tail1;
    head=new node(first);
    tail=head;
    for(int i=0;i<m-1;i++){
        cin>>val;
        tail->next=new node(val);
        tail=tail->next;
    }
    cin>>n;
    cin>>first1;
    head1=new node(first1);
    tail1=head1;
    for(int i=0;i<n-1;i++){
        cin>>val1;
        tail1->next=new node(val1);
        tail1=tail1->next;
    }
    node *fin=merge2list(head,head1);
    while(fin!=NULL){
        cout<<fin->data<<" ";
        fin=fin->next;
    }
}
