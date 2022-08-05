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
int main()
{
    int n,first,val;
    cin>>n;
    struct node *head=NULL,*tail=NULL;
    cin>>first;
    head=new node(first);
    tail=head;
    
    for(int i=0;i<n-1;i++){
        cin>>val;
        tail->next=new node(val);
        tail=tail->next;
    }
    struct node *dummy=NULL;
    
    while(head!=NULL){
        struct node *nxt=head->next;
        head->next=dummy;
        dummy=head;
        head=nxt;
    }
    for(int i=0;i<n;i++){
        cout<<dummy->data<<" ";
        dummy=dummy->next;
    }
}