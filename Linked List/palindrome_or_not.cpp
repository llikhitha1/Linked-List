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
node *reversel(node *head){
    struct node *dummy=NULL;
    
    while(head!=NULL){
        struct node *nxt=head->next;
        head->next=dummy;
        dummy=head;
        head=nxt;
    }
    return dummy;
}
bool ispalindrome(node *head){
    if(head==NULL || head->next==NULL) return true;
    node *slow=head;
    node *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reversel(slow->next);
    slow=slow->next;
    while(slow->next!=NULL){
        if(head->data!=slow->data){
            return false;
        }
        head=head->next;
        slow=slow->next;
    }
    return true;
}
int main()
{
    int m,val,first;
    node *head,*tail,*head1,*tail1;
    cin>>m;
    cin>>first;
    head=new node(first);
    tail=head;
    for(int i=0;i<m-1;i++){
        cin>>val;
        tail->next=new node(val);
        tail=tail->next;
    }
    if(ispalindrome(head)){
        cout<<"LL is a palindrome";
    }
    else{
        cout<<"LL is not a palindrome";
    }
    
}
