#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front() {
        if (!head) {  
            cout << "List is empty." << endl ;
            return;
        }
        Node* temp = head;

        // if one node
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        cout << "front node was popped." << endl ;
    }

    void pop_back() {
        if (!tail) {  
            cout << "list is empty." << endl ;
            return;
        }
        Node* temp = tail;

        // if one node
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        cout << "back node was popped." << endl ;
    }

    void delete_pos(int position) {
        if (!head || position < 0) {
            cout << "Invalid position." << endl ;
            return;
        }

        Node* temp = head;

        // deleting head 
        if (position == 0) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;  
            delete temp;
            return;
        }

        for (int i = 0; i < position && temp; ++i) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Error" << endl ;
            return;
        }

        // deleting tail
        if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            return;
        }

        // deleting nodes which in the middle
        temp->prev->next = temp->next;
        if (temp->next) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void delete_val(int value) {

        // check
        if (!head) return; 
        Node* temp = head;

        while (temp && temp -> data != value)
            temp = temp->next;
        if (!temp) return; // value not found

        // delete node (head)
        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; 
        }
        // delete node (tail)
        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; 
        }

        delete temp;
        cout << "node which the value is" << value << "has been deleted." << endl ;
    }

    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    
}
