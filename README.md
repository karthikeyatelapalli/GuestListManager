# Guest List Manager

This C program serves as a computerized guest list manager, enabling efficient management of visitor information in a restaurant setting. It supports adding, removing, and listing guests using a linked list structure, with phone numbers as unique identifiers to prevent duplicates.

## Features
- **Add Guests**: Insert new guest details into the list.
- **Remove Guests**: Remove an existing guest from the list by their phone number, first name, and last name.
- **View Guest List**: Display all registered guests with their details.
- **Clear List**: Clear the list at the end of the day, releasing all allocated memory.

## File Structure
This program is modular and consists of the following files:
- **`guest.h`**: Defines the `guest` structure and declares guest-related functions.
- **`guest.c`**: Implements the functions for managing the guest list.
- **`read_line.h`**: Declares the `read_line` function for safe input handling.
- **`read_line.c`**: Implements the `read_line` function.
- **`project10_guests.c`**: The main program that interacts with the user.

## How to Compile and Run
1. Compile the program:
   ```bash
   gcc project10_guests.c guest.c read_line.c -o guest_list_manager
