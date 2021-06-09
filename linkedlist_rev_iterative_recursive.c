#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
        int num;
        struct node *next;
};

struct node *list_reverse_recursive(struct node* curr) {
        if(curr == NULL) {
                return curr;
        }

        struct node *lt;
        last = curr;
        curr = curr->next;
        last->next = NULL;

        while(curr != NULL) {
                struct node *tmp;
                tmp = curr->next;
                curr->next = last;
                last = curr;
                curr = tmp;
        }

        return last;
}

struct node *list_reverse_iterative(struct node* curr) {
        if(curr == NULL) {
                return curr;
        }

        struct node *last;
        last = curr;
        curr = curr->next;
        last->next = NULL;

        while(curr != NULL) {
                struct node *tmp;
                tmp = curr->next;
                curr->next = last;
                last = curr;
                curr = tmp;
        }

        return last;
}

void list_print(struct node* curr) {
        while (curr != NULL) {
                printf("%d -> ", curr->num);
                curr = curr->next;
        }
        printf("NULL\n");
}

int main() {
        int count, val;
        struct node *head, *curr;

        printf("Enter the number of values in the linked list, followed by the elements: ");
        scanf("%d", &count);

        if(count<=0)
                return -1;

        head = (struct node *) malloc(sizeof(struct node));
        scanf("%d", &head->num);
        head->next = NULL;
        curr = head;

        for(int i=0; i<count-1; i++) {
                curr->next = (struct node *) malloc(sizeof(struct node));
                curr = curr->next;
                scanf("%d", &curr->num);
                curr->next = NULL;
        }

        list_print(head);
        head = list_reverse_iterative(head);
        list_print(head);

        head = list_reverse_recursive(head);
        list_print(head);

        return 0;
}
