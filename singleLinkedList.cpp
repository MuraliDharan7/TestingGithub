#include <bits/stdc++.h>
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
Node* convertArr2LL(vector<int> arr) {
  if (arr.empty()) {  // Handle empty vector case
    return nullptr;
  }

  Node* head = new Node(arr[0]);
  Node* mover = head;
  for (int i = 1; i < arr.size(); i++) {  // Start from i = 1
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}
bool searchLL(Node* head, int key) {
  Node* temp = head;
  while (temp) {
    if (temp->data == key) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}
Node* removesHead(Node* head) {
  if (head == NULL) return head;
  Node* temp = head;
  head = head->next;
  delete temp;
  return head;
}
void print(Node* head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}
Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
Node* deletePosition(Node* head, int k){
  if(head == NULL) return head;
  if(k==1){
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
  }
  int count =0;
  Node* temp = head; 
  Node* prev = NULL;
  while(head != NULL){
    count++;
    if(count == k){
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}
Node* deleteEl(Node* head, int el){
  if(head == NULL) return head;
  if(head->data==el){
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
  }
  Node* temp = head;
  Node* prev = NULL;
  while(temp!= NULL){
    if(temp->data == el){
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev= temp;
    temp = temp->next;
  }
  return head;
}
Node* insertHead(Node* head, int val){
    Node* temp = new Node(val,head);
    return temp;
}
Node* insertTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp= temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}
Node* insertPosition(Node* head, int el, int k){
    if(head== NULL){
        if(k==1){
            return new Node(el);
        }
        else{
            return NULL;
        }
    }
    if(k==1){
        return new Node(el,head);
    }
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count ==(k-1)){
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp= temp->next;
    }
    return head;
}
Node* segregateOddEven(Node* head){
  if(head == NULL || head->next == NULL) return NULL;
  Node* odd = head;
  Node* even = head->next;
  Node* evenHead = even;
  while(even != NULL && even->next != NULL){
    odd->next = odd->next->next;
    even->next = even->next->next;

    odd = odd->next;
    even = even->next;
  }
  odd->next = evenHead;
  return head;
}
Node* kthNodefromEnd(Node* head, int N){
  Node* slow = head;
  Node* fast = head;
  for(int i =0; i<N; i++){
    fast = fast->next;
  }
  if(fast == NULL) return head->next;
  while(fast->next != NULL){
    fast = fast->next;
    slow = slow->next;
  }
  Node* newNode = slow->next;
  slow->next = slow->next->next;
  free(newNode);
  return head;
}
Node* dltMiddleNode(Node* head){
  if(head == NULL || head->next == NULL) return NULL;
  Node* slow = head;
  Node* fast = head;
  fast = head->next->next;
  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  slow->next = slow->next->next;
  return head;
}
int main() {
  vector<int> arr = {21,3,5,8,20};
  Node* head = convertArr2LL(arr); 
  head = dltMiddleNode(head);
  print(head);
  return 0;
}
