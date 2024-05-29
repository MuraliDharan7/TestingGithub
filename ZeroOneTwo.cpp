#include<bits/stdc++.h>
using namespace std;

struct Node {
  public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
      data = data1;
      next = next1;
    }

    Node(int data1) {
      data = data1;
      next = nullptr;
    }
};
Node* zero12Sort(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data ==1){
            one->next = temp;
            one = temp;
        }
        else {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next)?oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two ->next = NULL;
    
    return zeroHead->next;
}
int main() {
    // Create nodes
    Node* head = new Node(2);
    head->next = new Node(0);
    head->next->next= new Node(2);
    head->next->next->next = new Node(0);
    head->next->next->next->next= new Node(0);

    head = zero12Sort(head);
    while(head!= NULL){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}