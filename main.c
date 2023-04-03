/*
 * The size of the arrays is fixed,
 * Insertion of a new element / Deletion of a existing element in an array of elements is expensive
 * n a system, if we maintain a sorted list of IDs in an array id[] = [1000, 1010, 1050, 2000, 2040].
If we want to insert a new ID 1005, then to maintain the sorted order, we have to move all the elements after 1000 (excluding 1000).

 Advantages of Linked Lists over arrays:

    Dynamic Array.
    Ease of Insertion/Deletion.
    Insertion at the beginning is a constant time operation and takes O(1) time, as compared to arrays where
    inserting an element at the beginning takes O(n) time,where n is the number of elements in the array.

    Drawbacks of Linked Lists:

    Random access is not allowed. We have to access elements sequentially starting from the first node(head node). So we cannot do a binary search with linked lists efficiently with its default implementation.
    Extra memory space for a pointer is required with each element of the list.
    Not cache-friendly. Since array elements are contiguous locations, there is the locality of reference which is not there in the case of linked lists.
    It takes a lot of time in traversing and changing the pointers.
    Reverse traversing is not possible in singly linked lists.
    It will be confusing when we work with pointers.
    Direct access to an element is not possible in a linked list as in an array by index.
    Searching for an element is costly and requires O(n) time complexity.
    Sorting of linked lists is very complex and costly.
    Appending an element to a linked list is a costly operation, and takes O(n) time, where n is the number of elements in the linked list, as compared to arrays that take O(1) time.
 * */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Node {
    int32_t data;
    struct Node * next;
    //struct Node * prev;
} CVOR;

void print_list(struct Node * node) {
    while (node->next != NULL) {
        printf("%d", node->data);
        node = node->next;
    }
}

void print_list_recursively(CVOR * node) {
    if (node != NULL) {
        printf("%d\n",node->data);
    } else {
        return;
    }
    print_list_recursively(node->next);
}

void populate_list_rekurzivno(int num_size, CVOR ** head) {
    if (num_size <= 0 || (*head) == NULL) {
        return;
    }
    CVOR * novi = (CVOR*) malloc(sizeof(CVOR));
    if (novi != NULL) {
        novi->data = num_size;
        novi->next = NULL;
        (*head)->next = novi;
        populate_list_rekurzivno(--num_size, &(novi));
    }
}

void add_new_list_element(CVOR *node,CVOR **head) {
    if (head != NULL) {
        if((*head)->next != NULL) {
            add_new_list_element(node,&((*head)->next));
        } else{
            (*head)->next = node;
        }
    }
}

void delete_first_el(CVOR **head) {
    CVOR* tofree = (*head);
    *head = (*head)->next;
    free(tofree);
}

void delete_nth_element(CVOR **head, int32_t n) {
    if (head == NULL || n <=0) {
        return;
    }
    if (n == 2) {
        CVOR * temp = (*head)->next;
        (*head)->next = (*head)->next->next;
        free(temp);
    } else {
        delete_nth_element(&((*head)->next), --n);
    }
}

void reverse_list(CVOR ** head) {
    CVOR * last = NULL;
    while ((*head)->next != NULL) {
    }
}

typedef enum {
    drugi
}NESTO;

void fja(const void* a) {
    printf("%d\n",*(uint8_t *) a);
    const NESTO * b = (const NESTO*) a;
    printf("%d %d %d %d", *(b + 0),
           *(b + 1),
           *(b + 2),
           *(b + 3)
    );
    printf("\nsize: %d",(int)sizeof (int*));
}

#include <stdio.h>

void reverse_string(char * const str, char *newstr) {
    if (str == NULL) {
        return;
    }
    printf("aa");
    int str_len = 0;
    while (str[str_len] != '\0') {
        str_len++;
    }
    printf("%d",str_len);
    int i;
    int b = 0;
    for(i = str_len-1; i >= 0; i--) {
        newstr[b] = str[i];
        printf("\nbb%dbb%d\n",i,b);
        b++;
        printf(" dds %s  %s",newstr, str);

    }
    newstr[str_len] = '\0';
    printf("%s",newstr);
}

int izbroj_jedinice(int n) {
    int mask = 1;
    int retval = 0;
    while (n != 0) {
        if (n & mask) {
            retval++;
        }
        n = n >> 1;
    }
    return retval;
}

int check_bit(int n) {
    int mask1 = 1;
    mask1 = mask1 << 3;
    int mask2 = 1;
    mask2 = mask2 << 5;
    if ((n & mask1) && !(n & mask2)) {
        return 1;
    }
    return 0;
}

int main() {
    CVOR * head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;
    populate_list_rekurzivno(3,&head);
   // print_list_recursively(head);
    delete_first_el(&head);
    //print_list_recursively(head);
    CVOR * newel = (CVOR*) malloc(sizeof (CVOR));
    newel->data = 5;
    newel->next = NULL;
    add_new_list_element(newel,&head);
    //print_list_recursively(head);
    delete_nth_element(&head,2);
    print_list_recursively(head);

    NESTO b = drugi;
    fja((void *) &b);


    char  newstr[5];
    char * const old = "abc";
    reverse_string(old,newstr);
    printf("%s", newstr);

    printf("\n%d", izbroj_jedinice(15));

    return 0;
}
