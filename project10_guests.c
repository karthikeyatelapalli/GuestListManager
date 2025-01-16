
/*Description: Here this C code serves as a computerized guest list manager. Using a linked list structure, it efficiently manages 
 visitor information by enabling users to add new guests, remove existing ones, and examine the complete guest list. All of the 
 information about each guest including name, phone number, and party size is saved and readily accessible. The application's 
 intuitive user interface, powered by operation codes.*/

#include <stdio.h>
#include "guest.h"
#include "read_line.h"

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void) {
    char code;
    struct guest *new_list = NULL;
    printf("Operation Code: a for adding to the list at the end, r for removing from the list, p for printing the list; q for quit.\n");

    // This is a loop for the interface.
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');  // skips to end of line.
        switch (code) {
            case 'a': new_list = add_guest(new_list); // Here we add the guest to our list.
                      break;
            case 'r': new_list = remove_guest(new_list); // Here we remove a guest. 
                      break;
            case 'p': print_list(new_list); // Here we print the current list of guests.
                      break;
            case 'q': clear_list(new_list); // Here we quit the running code after we clear the list.
                      return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}
