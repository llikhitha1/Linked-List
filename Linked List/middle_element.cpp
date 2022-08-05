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
int main(){
    int n,first,val;
    struct node *head=NULL,*tail=NULL;
    cin>>n;
    cin>>first;
    head = new node(first);
    tail = head;
    for(int i=0;i<n-1;i++){
        cin>>val;
        tail->next = new node(val);
        tail = tail->next;
    }
    struct node *fast=head,*slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"Middle element of Linked List is "<<slow->data;
    
}