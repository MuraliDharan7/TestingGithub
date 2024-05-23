 #include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* middleLL(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int getNthFromLast(Node *head, int n)
    {
           // Your code here
        int count =0;
        Node* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        int count1 = count - n;
        temp = head;
        int count2 =0;
        while(temp != head){
            count2++;
            if(count2=(count1+1)) return temp->data;
            temp = temp->next;
        }
        return -1;
    }
int main() {
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    
    
    int nthNode = getNthFromLast(head,2);
    
    cout << nthNode << endl;

    return 0;
}
