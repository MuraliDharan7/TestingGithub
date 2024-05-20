#include <bits/stdc++.h>
using namespace std;

struct Node {
  public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1) {
      data = data1;
      next = next1;
      back = back1;
    }

    Node(int data1) {
      data = data1;
      next = nullptr;
      back = nullptr;
    }
};
Node* convertArr2DLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
Node* print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    return head;
}
Node* deleteHead(Node* head){
    if(head==NULL || head->next == NULL) return NULL;
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}
Node* deleteTail(Node* head){
    if(head== NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}
Node* deletekthElement(Node* head, int k){
    if(head == NULL){
        return NULL;
    }
    int count =0;
    Node* kthNode = head;
    while(kthNode != NULL){
        count++;
        if(count == k) break;
        kthNode = kthNode->next;
    }
    Node* prev = kthNode->back;
    Node* front = kthNode->next;
    if(prev == NULL && front == NULL){
        return NULL;
    }
    else if(prev == NULL){
        if(head==NULL || head->next == NULL) return NULL;
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        head->back = nullptr;
        return head;
    }
    else if(front == NULL){
        if(head== NULL || head->next == NULL){
        return NULL;
        }
        Node* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        Node* newTail= tail->back;
        newTail->next = nullptr;
        tail->back = nullptr;
        delete tail;
        return head;
    }
    prev->next = front;
    front->back = prev;
    kthNode->back= nullptr;
    kthNode->next = nullptr;
    delete kthNode;
    return head;
}
void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->back= nullptr;
    temp->next = nullptr;
    delete temp; 
}
Node* insertAtBegin(Node* head, int val){
    Node* newNode = new Node(val,head,nullptr);
    head->back = newNode;
    return newNode;
}
Node* insertAtTail(Node* head, int val){
    if(head -> next == NULL){
        Node* newNode = new Node(val,head,nullptr);
        head -> back = newNode;
        return newNode;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val,tail,prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}
Node* insertAtKth(Node* head, int el,int k){
    if(head == NULL) return NULL;
    if(k==1){
        Node* newNode = new Node(el,head,nullptr);
        head->back = newNode;
        return newNode;
    }
    int count =0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == k) break;
        temp = temp ->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(el,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
void insertAtNode(Node* node,int el){
    Node* prev = node->back;
    Node* newNode = new Node(el,node,prev);
    prev->next = newNode;
    node->back = newNode;
}
int lengthh(Node* head){
    int length = 0;
    while(head != NULL){
        length++;
        head = head->next;
    }
    return length;
}
Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* last = NULL;
    Node* current = head;
    while(current != NULL){
        last = current->back;
        current->back = current->next;
        current->next = last;

        current = current->back;
    }
    return last->back;
}
int main(){
    vector<int> arr = {2,5,7,49,25};
    Node* head = convertArr2DLL(arr);
    head = reverseDLL(head);
    print(head);
    return 0;
}