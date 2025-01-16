#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guest.h"
#include "read_line.h"  

// This function allows us to add new guests to the list.
// It determines whether there is already a guest with the same phone number.
// If not, a new guest is created and added to the end of the list.
struct guest *add_guest(struct guest *list) {
    char phone[PHONE_LEN + 1];
    printf("Enter phone number: ");
    read_line(phone, PHONE_LEN);

    // Here we check for if the guest already exists.struct guest *remove_guest(struct guest *list
    struct guest *p;
    for (p = list; p != NULL; p = p->next) {
        if (strcmp(phone, p->phone) == 0) {
            printf("Guest already exists.\n");
            return list;
        }
    }

    // Here we get the guest details.
    struct guest *new_guest = malloc(sizeof(struct guest));
    if (new_guest == NULL) {
        printf("Error: malloc failed.\n");
        return list;
    }
    strcpy(new_guest->phone, phone);
    printf("Enter guest's last name: ");
    read_line(new_guest->last, NAME_LEN);
    printf("Enter guest's first name: ");
    read_line(new_guest->first, NAME_LEN);
    printf("Enter party size: ");
    scanf("%d", &new_guest->party_size);
    while (getchar() != '\n');
    new_guest->next = NULL;

    // Here we add guest to the end of the list.
    if (list == NULL) {
        // Here the list is empty, now the new guest is on the list.
        return new_guest;
    } else {
        // Here we find the end of the list and add our new guest.
        struct guest *cur = list;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_guest;
        return list;
    }
}

// This is a function to remove a guest from the list.
struct guest *remove_guest(struct guest *list) {
    char phone[PHONE_LEN + 1], last[NAME_LEN + 1], first[NAME_LEN + 1];
    printf("Enter phone number: ");
    read_line(phone, PHONE_LEN);
    printf("Enter guest's last name: ");
    read_line(last, NAME_LEN);
    printf("Enter guest's first name: ");
    read_line(first, NAME_LEN);

    struct guest *cur = list, *prev = NULL;
    // Here we go through the list to locate and eliminate the designated guest.
    while (cur != NULL) {
        if (strcmp(cur->phone, phone) == 0 && strcmp(cur->last, last) == 0 && strcmp(cur->first, first) == 0) {
            if (prev == NULL) {
                list = cur->next;
            } else {
                prev->next = cur->next; // Here we bypass the guest to be removed.
            }
            free(cur); // Release the RAM used by the deleted guest.
            return list;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("Guest does not exist.\n");
    return list;
}

// This is a function to print the list of guests.
void print_list(struct guest *list) {
    struct guest *p = list;
    while (p != NULL) {
        printf("%-15s%-20s%-20s%5d\n", p->phone, p->last, p->first, p->party_size);
        p = p->next;
    }
}

// This is a function to clears the list of guests.
void clear_list(struct guest *list) {
    while (list != NULL) {
        struct guest *p = list;
        list = list->next;
        free(p);
    }
}

