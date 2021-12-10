#include <stdio.h>
#include <stdlib.h>
#include "01SinglyLL.h"

int main()
{
    /* Creation */
    node* head = createLL();
    printf("Linked list created successfully! \nHead = %p \n", head);

    /* Display */
    displayLL(&head);

    /* Search */
    int k;
    printf("Enter value to be searched: ");
    scanf("%d", &k);
    node* ptr = searchLL(&head, k);
    (ptr != NULL)
        ? printf("Element found at index: %p \n", ptr)
        : printf("Element not found \n");
    
    /* Insertion at beginning */
    int beg;
    printf("Enter value to be inserted at beginning: ");
    scanf("%d", &beg);
    insertBeg(&head, beg);
    displayLL(&head);

    /* Insertion at end */
    int end;
    printf("Enter value to be inserted at end: ");
    scanf("%d", &end);
    insertEnd(&head, end);
    displayLL(&head);

    /* Insertion in SLL */
    int val, num;
    printf("Enter value to be inserted: ");
    scanf("%d", &val);
    printf("Enter value after which new value to be inserted: ");
    scanf("%d", &num);
    insertLL(&head, val, num);
    displayLL(&head);

    /* Deletion at beginning */
    deleteBeg(&head);
    displayLL(&head);

    /* Deletion at end */
    deleteEnd(&head);
    displayLL(&head);

    /* Deletion in SLL */
    printf("Enter value to be deleted: ");
    scanf("%d", &val);
    deleteLL(&head, val);
    displayLL(&head);

    return 0;
}