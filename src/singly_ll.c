#include <stdio.h>
#include <stdlib.h>

/// @brief The Structure of the Node

/// @brief  - data: `int`
/// @brief  - next: `struct Node*`
struct Node {
    int data;
    struct Node* next;
};

/// @brief It insert a new node at the front of the LinkedList
/// @param data `The node to be inserted`
/// @param headRef `Head`
void InsertFront(int data, struct Node** headRef) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));

    node->data = data;
    node->next = *headRef;

    *headRef = node;
}

/// @brief It insert a new node at the end of the LinkedList
/// @param data `The node to be inserted`
/// @param headRef `Head`
void InsertEnd(int data, struct Node** headRef) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));

    node->data = data;
    node->next = NULL;

    if (*headRef == NULL) {
        *headRef = node;
        return;
    }

    struct Node* curr = *headRef;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = node;
}

/// @brief It insert a node after a certain node
/// @param data `The node to be inserted`
/// @param after `The given node will be inserted after this node`
/// @param headRef `Head`
void InsertAfter(int data, int after, struct Node** headRef) {
    if (*headRef == NULL) {
        printf("Head is already empty\n");
        return;
    }

    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* curr = *headRef;

    while (curr->next != NULL) {
        if (curr->data == after) {
            node->data = data;
            node->next = curr->next;
            curr->next = node;
            return;
        }
        curr = curr->next;
    }

    printf("Node with data %d not found\n", after); 
}

/// @brief Insert a node at the given index/position in the argugment
/// @param data `The node to be inserted`
/// @param position `The index where the given node to insert`
/// @param headRef `Head`
void InsertAtIndex(int data, int position, struct Node** headRef) {
    if (*headRef == NULL) {
        printf("Head is already empty\n");
        return;
    }

    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* curr = *headRef;

    node->data = data;

    if (position == 0) {
        node->next = curr;
        *headRef = node;
        return;
    }

    int indexCounter = 0;

    while (curr->next != NULL) {
        if (indexCounter == position - 1) {
            node->next = curr->next;
            curr->next = node;
            return;
        }

        indexCounter++;
        curr = curr->next;
    }
    
    printf("Position out of index\n");
}

/// @brief It delete the node at the given index/position in LinkedList
/// @param position `The index of the given node` 
/// @param headRef `Head` 
void DeleteAtIndex(int position, struct Node** headRef) {
    if (*headRef == NULL) {
        printf("Head is already empty\n");
        return;
    }

    struct Node* head = *headRef;

    if (position == 0) {
        *headRef = head->next;
        free(head);
        return;
    }

    for (int i = 0; i < position - 1 && head != NULL; i++) {
        head = head->next;
    }

    if (head == NULL || head->next == NULL) {
        printf("Index out of range\n");
        return;
    }

    struct Node* toDelete = head->next;
    head->next = toDelete->next;

    free(toDelete);
}

/// @brief  It just delete the front node from the LinkedList
/// @param headRef `Head`
void DeleteFront(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("Head is already empty\n");
        return;
    }

    struct Node* head = *headRef;
    *headRef = head->next;
    free(head);
}

/// @brief It just delete the last end from the LinkedList
/// @param headRef `Head`
void DeleteEnd(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("Head is already empty\n");
        return;
    }

    struct Node* temp = *headRef;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

/// @brief It just return the position of the given data in the argument
/// @param data `The node to find`
/// @param head `Head`
/// @return `Position of the node else -1`
int Find(int data, struct Node* head) {
	struct Node* curr = head;
	int positionCounter = 0;
   
	while (curr->next != NULL) {
		if (curr->data == data) {
			return positionCounter;
		}
		
		curr = curr->next;
		positionCounter++;
	}
	
	return -1;
}

/// @brief It will free the heap memory allocation
/// @param head `Head`
void FreeList(struct Node* head) {
    struct Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/// @brief It will print out all the items in the LinkedList
/// @param head `Head`
void PrintList(struct Node* head) {
    struct Node* curr = head;

    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main(void) {
    struct Node* node = NULL;

    InsertFront(1, &node);
    InsertFront(2, &node);
    InsertFront(3, &node);

    PrintList(node);

    InsertEnd(4, &node);
    InsertEnd(5, &node);
    PrintList(node);

    InsertAfter(6, 4, &node);
    InsertAfter(7, 6, &node);
    PrintList(node);
	
	int position = Find(1, node);
    if (position == -1) {
        printf("Node not found in the List");
    } else {
        printf("Position of 5: %d\n", position);
    }

    DeleteFront(&node);
    PrintList(node);

    DeleteEnd(&node);
    PrintList(node);

    printf("Insert At Index\n");

    InsertAtIndex(8, 3, &node);
    PrintList(node);
    
    InsertAtIndex(11, 0, &node);
    PrintList(node);

    printf("Delete At Index\n");

    DeleteAtIndex(5, &node);
    PrintList(node);
    
    DeleteAtIndex(3, &node);
    PrintList(node);

    FreeList(node);

    return 0;
}
