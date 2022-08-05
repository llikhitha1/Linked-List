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
void loophere(node* head,node* tail,int position){
    if(position==0) return;
    struct node *start=head;
    for(int i=1;i<position;i++){
        start=start->next;
    }
    tail->next=start;
}
node* startpoint(node* head){
    if(head==NULL || head->next==NULL)  return NULL;
    struct node *slow=head,*fast=head,*start=head;
    while(fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            while(slow!=start){
                slow=slow->next;
                start=start->next;
            }
            return start;
        }
    }
    return 0;
}
int main(){
    int n,first,val;
    cin>>n;
    cin>>first;
    struct node *head,*tail;
    head=new node(first);
    tail=head;
    for(int i=0;i<n-1;i++){
        cin>>val;
        tail->next=new node(val);
        tail=tail->next;
    }
    int position;
    cin>>position;
    loophere(head,tail,position);
    cout<<startpoint(head)->data;
}