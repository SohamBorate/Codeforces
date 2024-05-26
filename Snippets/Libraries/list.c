#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list_node {
    int n;
    struct list_node *next;
};

struct list_node* get(struct list_node *start, int index) {
    // set current node to start node
    struct list_node *current = start;
    struct list_node *item = NULL;

    // for i in 100
    for (int i = 0; i < (index + 1); i++) {
        // if item reached
        if (i == index) {
            item = current;
            break;
        } else {
            // if can go further
            if (current->next != NULL) {
                current = current->next;
            } else {
                break;
            }
        }
    }

    return item;
}

void remove_node(struct list_node *start, int index) {
    struct list_node *prev = get(start, index - 1);
    struct list_node *item = prev->next;
    struct list_node *after = item->next;
    free(item);
    prev->next = after;
}

void insert_node(struct list_node *start, struct list_node *item, int index) {
    struct list_node *prev = get(start, index - 1);
    struct list_node *after = prev->next;
    item->next = after;
    prev->next = item;
}

void append_node(struct list_node *start, struct list_node *item) {
    // set current node to start node
    struct list_node *current = start;
    // set temp node (pointer) to NULL
    struct list_node *temp = NULL;
    // while current node next is not null
    while (current != NULL) {
        // set temp node to current node next
        temp = current->next;
        // free current node
        free(current);
        // set current node to temp node
        current = temp;
    }
}

void print_list(struct list_node *start) {
    // set current node to start node
    struct list_node *current = start;
    // set temp node (pointer) to NULL
    struct list_node *temp = NULL;
    printf("{\n");
    // while current node next is not null
    while (current != NULL) {
        // set temp node to current node next
        temp = current->next;
        // free current node
        printf("  %i,\n", current->n);
        // set current node to temp node
        current = temp;
    }
    printf("}\n");
}

int list_size(struct list_node *start) {
    int size = 0;

    // set current node to start node
    struct list_node *current = start;
    // set temp node (pointer) to NULL
    struct list_node *temp = NULL;
    // while current node next is not null
    while (current != NULL) {
        // set temp node to current node next
        temp = current->next;
        // free current node
        printf("h\n");
        // set current node to temp node
        current = temp;
    }

    return size;
}

void destroy(struct list_node *start) {
    // set current node to start node
    struct list_node *current = start;
    // set temp node (pointer) to NULL
    struct list_node *temp = NULL;
    // while current node next is not null
    while (current != NULL) {
        // set temp node to current node next
        temp = current->next;
        // free current node
        free(current);
        printf("h\n");
        // set current node to temp node
        current = temp;
    }
}

int main() {
    // initiate start node
    struct list_node *start = malloc(sizeof(struct list_node));
    // set current node to start node
    struct list_node *current = start;
    // set temp node (pointer) to NULL
    struct list_node *temp = NULL;

    // for i in 100
    for (int i = 0; i < 10; i++) {
        // set current node char
        current->n = i;
        // create new node, temp node var points here
        temp = malloc(sizeof(struct list_node));
        // set current node next to temp node
        current->next = temp;
        // set current node to temp node
        current = temp;
    }

    printf("%i\n", (get(start, 6))->n);
    remove_node(start, 6);
    printf("%i\n", (get(start, 6))->n);
    struct list_node *to_be_inserted = malloc(sizeof(struct list_node));
    to_be_inserted->n = 6;
    insert_node(start, to_be_inserted, 6);
    printf("%i\n", (get(start, 6))->n);

    // print_list(start);
    printf("%i\n", list_size(start));
    destroy(start);

    free(temp);
    free(current);
    
    return 0;
}
