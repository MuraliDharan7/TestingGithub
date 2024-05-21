#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};
Node* reverseLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* prev = NULL;
    Node* temp = head;
    while(temp!= NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
int main() {
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    
    Node* reverseofLL = reverseLL(head);

    
    while (reverseofLL != NULL) {
        cout << reverseofLL->data << endl;
        reverseofLL = reverseofLL->next;
    }

    return 0;
}