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
Node* middleLL(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* mergeTwoLL(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            temp->next = list1;
            temp = list1;
            list1= list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 =list2->next;
        }
    }
    if(list1) temp->next = list1;
    else temp->next = list2;
    return dummyNode->next;
}
Node* sortLL(Node* head){
    Node* middle = middleLL(head);
    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;

    left = sortLL(left);
    right = sortLL(right);
    return mergeTwoLL(left,right);
}
Node* convertArr2LL(vector<int> arr){
    if(arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node* head){
    while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}
int main() {
  vector<int> arr = {21,3,5,8,20};
  Node* head = convertArr2LL(arr); 
  head = sortLL(head);
  print(head);
  return 0;
}
