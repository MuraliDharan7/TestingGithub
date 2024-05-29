#include<bits/stdc++.h>
using namespace std;
int addHelp(Node* temp){
    if(temp == NULL) return 1;

    int carry = addHelp(temp->next);
    temp->data += carry;
    if(temp->data < 10) return 0;
    temp->data = 0;
    return 1;
}

Node* addOne(Node* head){

    int carry = addHelp(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}