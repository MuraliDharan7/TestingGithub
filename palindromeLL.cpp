#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};
Node* reverseLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* newNode = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newNode;
}
bool isPalindrome(Node* head){
    if(head == NULL || head->next == NULL) return true;
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newNode = reverseLL(slow->next);
    Node* first = head;
    Node* second = newNode;
    while(second != NULL){
        if(first->data != second->data){
            reverseLL(newNode);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newNode);
    return true;
}
int main() {
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    bool ans = isPalindrome(head);
    cout << ans;

    return 0;
}