#include<bits/stdc++.h>
using namespace std;
Node* add2NumLL(Node* head1, Node* head2){
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    int carry =0;
    int sum =0;
    while(head1 != NULL || head2 != NULL){
        sum = carry;
        if(head1) sum += head1->data;
        if(head2) sum += head2->data;

        Node* newNode = new Node(sum%10);
        curr ->next = newNode;
        curr = newNode;
        carry = sum / 10;

        if(head1) head1 = head1->next;
        if(head2) head2 = head2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}