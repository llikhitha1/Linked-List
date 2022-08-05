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
node* removenth(node* head,int nth){
    struct node *start = new node(0);
    start->next=head;
    struct node *slow=start,*fast=start;
    for(int i=0;i<nth;i++){
        fast=fast->next;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return start->next;
}
int main()
{
    int n,first,val;
    cin>>n;
    cin>>first;
    struct node *head=NULL,*tail=NULL;
    head = new node(first);
    tail=head;
    for(int i=0;i<n-1;i++){
        cin>>val;
        tail->next=new node(val);
        tail=tail->next;
    }
    int nth;
    cin>>nth;
    struct node *newhead=NULL;
    newhead=removenth(head,nth);
    while(newhead!=NULL){
        cout<<newhead->data<<" ";
        newhead=newhead->next;
    }
}
