#ifndef GUEST_H
#define GUEST_H

#define NAME_LEN 30
#define PHONE_LEN 20

// Here we define the structure which stores the guest information.
// Here every guest have a phone number, party size, last name, and first name.
// Here additionally, a pointer to the following guest is included, forming a linked list.
struct guest {
    char phone[PHONE_LEN + 1];
    char last[NAME_LEN + 1];
    char first[NAME_LEN + 1];
    int party_size;
    struct guest *next;
};

// These are the functions that we use in this program.
// add_guest: Enables the addition of an additional guest.
// remove_guest: Eliminates a current guest from the roster.
// print_list: Shows the list of all guests.
// clear_list: Removes everything from the list and frees up memory.
struct guest *add_guest(struct guest *list);
struct guest *remove_guest(struct guest *list);
void print_list(struct guest *list);
void clear_list(struct guest *list);

#endif
