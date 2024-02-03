#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node{
    int data;
    struct Node *next;
};

struct HashTable{
    struct Node *chain[SIZE];
};

void init(struct HashTable *ht){
    for (int i = 0; i < SIZE; i++){
        ht->chain[i] = NULL;
    }
}

void insert(struct HashTable *ht, int value){
    int key = value % SIZE;

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (ht->chain[key] == NULL){
        ht->chain[key] = newNode;
    }

    else{
        struct Node *temp = ht->chain[key];
        while (temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Entered value %d added to hash table\n", value);
}

void printHashTable(struct HashTable *ht){
    for (int i = 0; i < SIZE; i++){
        printf("chain[%d]-->", i);
        struct Node *temp = ht->chain[i];

        while (temp != NULL){
            printf("%d -->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void main()
{
    struct HashTable ht;
    init(&ht);

    int num, val;
    printf("Enter the number of elements: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        insert(&ht, val);
    }

    printf("\n\nThe hash table is:\n\n");
    printHashTable(&ht);
}
