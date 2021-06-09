#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
        int num;
        struct node *next;
};

bool list_search_recursive(struct node* curr, int val) {
        if(curr == NULL) {
                return false;
        }

        if(curr->num == val) {
                return true;
        }

        return list_search_recursive(curr->next, val);
}

bool list_search_iterative(struct node* curr, int val) {
        while(curr != NULL) {
                if(curr->num == val) {
                        return true;
                }
                curr = curr->next;
        }
        return false;
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

        printf("Enter the value to be searched in the linked list");
        scanf("%d", &val);
        if(list_search_iterative(head, val))
                printf("%d was found in list\n");
        else
                printf("%d was not found in list\n");

        if(list_search_recursive(head, val))
                printf("%d was found in list\n");
        else
                printf("%d was not found in list\n");

        return 0;
}
