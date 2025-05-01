#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/// Insert Data at the front of Node
void InsertFront(int data, struct Node** headRef) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));

    node->data = data;
    node->next = *headRef;

    *headRef = node;
}

/// Insert Data at the end of Node
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

/// Insert Data after a certain afterData of Node
void InsertAfter(int data, int after, struct Node** headRef) {
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

/// Return the position of the data in the node
int Find(int data, struct Node* head) {
	struct Node* curr = head;
	int positionCounter = 0;
   
	while (curr->next != NULL) {
		if (curr->data == data) {
			break;
		}
		
		curr = curr->next;
		positionCounter++;
	}
	
	return positionCounter;
}

void FreeList(struct Node* head) {
    struct Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

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
	printf("Position of 5: %d\n", position);

    FreeList(node);

    return 0;
}
