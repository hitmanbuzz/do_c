#include <iostream>

class Node {
public:
    int data;
    Node* next;
    
    Node() {
        data = 0;
        next = nullptr;
    }
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
    Node* head;
    unsigned int size;
    
public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }
    ~LinkedList(); // Add destructor

    void InsertFront(int data);
    void InsertBack(int data);
    void InsertIndex(int data, unsigned int index);
    void DeleteFront();
    void DeleteBack();
    void DeleteIndex(unsigned int index);
    unsigned int get_size();
    void print();
};

void LinkedList::InsertFront(int data) {
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
    size++;
}

void LinkedList::InsertBack(int data) {
    Node* temp = head;

    Node* new_node = new Node(data);
    
    if (head == nullptr) {
        head = new_node;
        size++;
        return;
    }
    
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    
    temp->next = new_node; 
    size++;
}

void LinkedList::InsertIndex(int data, unsigned int index) {
    if (index > size) {
        std::cout << "Index is greater than the total size" << "\n";
        return;
    }

    Node* new_node = new Node(data);

    if (index == 0) {
        new_node->next = head;
        head = new_node;
        size++;
        return;
    }

    Node* temp = head;
    for (unsigned int i = 0; i < index - 1; ++i) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    size++;
}

void LinkedList::DeleteFront() {
    if (size == 0) {
        std::cout << "List is empty" << "\n";
        return;
    }
    
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}

void LinkedList::DeleteBack() {
    if (size == 0) {
        std::cout << "List is empty" << "\n";
        return;
    }
    
    if (size == 1) {
        delete head;
        head = nullptr;
        size--;
        return;
    }
    
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next; 
    }
    
    delete temp->next;
    temp->next = nullptr;
    size--;
}

void LinkedList::DeleteIndex(unsigned int index) {
   if (index >= size) {
       std::cout << "Index is greater than or equal to size" << "\n";
       return;
   } 
   
   if (index == 0) {
       Node* temp = head;
       head = head->next;
       delete temp;
       size--;
       return;
   }
   
   Node* temp = head;
   
   for (unsigned int i = 0; i < index - 1; i++) {
       temp = temp->next;
   }
  
   Node* nodeToDelete = temp->next;
   temp->next = temp->next->next;
   delete nodeToDelete;
   size--;
}

/// Returns a new linked list which has been reversed.
//
/// The original head doesn't get reversed
Node* LinkedList::Reverse() {
    if (size == 0) {
       std::cout << "List is empty";
       return head;
    }
    
    Node* prev = nullptr;
    Node* curr = head;
    
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

void LinkedList::print() {
    Node* temp = head;

    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "\n";
}

unsigned int LinkedList::get_size() {
    return size;
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    LinkedList list;

    list.InsertFront(5);
    list.InsertFront(6);
    list.InsertFront(8);
    
    list.InsertBack(10);

    list.print();

    list.InsertIndex(12, 3);
    list.print();
    
    list.InsertIndex(14, 0);
    list.print();
    
    // list.DeleteFront();
    // list.print();
    
    // list.DeleteBack();
    // list.print();
    
    // list.DeleteFront();
    // list.print();
    
    list.DeleteIndex(3);
    list.print();
    
    list.DeleteIndex(1);
    list.print();
    
    list.DeleteIndex(0);
    list.print();
    
    list.DeleteIndex(2);
    list.print();
    
    std::cout << "Reversed" << "\n";
    
    Node* reveresed = list.Reverse();
    while (reveresed) {
        std::cout << reveresed->data << " -> ";
        reveresed = reveresed->next;
    }
    
    std::cout << "\n";

    std::cout << "Linked List Size: " <<  list.get_size() << "\n";
    
    return 0;

}
