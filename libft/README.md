*This project has been created as part of the curriculum of 42 by crubio-p*

## Description

Libft is a custom C library developed as part of the 42 curriculum.

The objective of this project is to recreate a collection of standard C library functions, as well as additional utility functions that can be reused in future projects. By implementing these functions from scratch, students gain a deeper understanding of memory management, strings, pointers, linked lists, and low-level programming concepts.

The library serves as a foundation for many later projects within the 42 curriculum.

---

## Features

### Part 1 – Reimplemented libc Functions

#### Character Classification

* `ft_isalpha` — Checks whether a character is alphabetic.
* `ft_isdigit` — Checks whether a character is a decimal digit.
* `ft_isalnum` — Checks whether a character is alphanumeric.
* `ft_isascii` — Checks whether a character belongs to the ASCII table.
* `ft_isprint` — Checks whether a character is printable.

#### String Manipulation

* `ft_strlen` — Returns the length of a string.
* `ft_strlcpy` — Copies a string into a destination buffer with size protection.
* `ft_strlcat` — Concatenates strings while preventing buffer overflow.
* `ft_strchr` — Finds the first occurrence of a character in a string.
* `ft_strrchr` — Finds the last occurrence of a character in a string.
* `ft_strncmp` — Compares two strings up to a specified number of characters.
* `ft_strnstr` — Searches for a substring within a limited portion of a string.
* `ft_strdup` — Allocates and returns a duplicate of a string.

#### Memory Manipulation

* `ft_memset` — Fills a memory area with a constant byte.
* `ft_bzero` — Sets a memory area to zero.
* `ft_memcpy` — Copies memory from one location to another.
* `ft_memmove` — Copies memory safely, even when regions overlap.
* `ft_memchr` — Searches for a byte within a memory block.
* `ft_memcmp` — Compares two memory blocks.
* `ft_calloc` — Allocates memory and initializes it to zero.

#### Conversion

* `ft_atoi` — Converts a string to an integer.

#### Character Conversion

* `ft_toupper` — Converts a lowercase letter to uppercase.
* `ft_tolower` — Converts an uppercase letter to lowercase.

---

### Part 2 – Additional Functions

#### String Utilities

* `ft_substr` — Extracts a substring from a string.
* `ft_strjoin` — Concatenates two strings into a newly allocated string.
* `ft_strtrim` — Removes specified characters from the beginning and end of a string.
* `ft_split` — Splits a string into an array of strings using a delimiter.
* `ft_itoa` — Converts an integer to a string.
* `ft_strmapi` — Creates a new string by applying a function to each character.
* `ft_striteri` — Applies a function to each character of a string in place.

#### File Descriptor Output

* `ft_putchar_fd` — Writes a character to a file descriptor.
* `ft_putstr_fd` — Writes a string to a file descriptor.
* `ft_putendl_fd` — Writes a string followed by a newline to a file descriptor.
* `ft_putnbr_fd` — Writes an integer to a file descriptor.

---

### Part 3 – Linked Lists

#### List Creation and Management

* `ft_lstnew` — Creates a new list node.
* `ft_lstadd_front` — Adds a node at the beginning of a list.
* `ft_lstsize` — Returns the number of nodes in a list.
* `ft_lstlast` — Returns the last node of a list.
* `ft_lstadd_back` — Adds a node at the end of a list.

#### List Operations

* `ft_lstdelone` — Deletes a single node using a provided delete function.
* `ft_lstclear` — Deletes and frees an entire list.
* `ft_lstiter` — Applies a function to each node of a list.
* `ft_lstmap` — Creates a new list by applying a function to each node.


## Library Architecture

The project is organized into several functional modules:

| Module               | Purpose                                   |
| -------------------- | ----------------------------------------- |
| Character Functions  | Character checks and conversions          |
| Memory Functions     | Raw memory manipulation                   |
| String Functions     | String handling and processing            |
| Conversion Functions | Data conversion between types             |
| Output Functions     | Writing data to file descriptors          |
| Linked Lists         | Generic singly linked list implementation |

All functions follow the 42 Norm and are written in standard C.

---

## Instructions

### Compilation

Compile the library:

```bash
make
```

This generates:

```text
libft.a
```

### Available Makefile Rules

Build mandatory part:

```bash
make
```

Remove object files:

```bash
make clean
```

Remove object files and library:

```bash
make fclean
```

Rebuild everything:

```bash
make re
```

### Using the Library

Include the header:

```c
#include "libft.h"
```

Compile with:

```bash
cc main.c libft.a
```

---

## Technical Decisions

* Reimplemented standard C library functions without relying on their original implementations.
* Special attention was given to memory safety and edge cases.
* Linked list functions use a generic `void *content` pointer to support arbitrary data types.
* All code follows the 42 Norm coding standard.

## Resources
### Official Documentation

* ISO C Standard Documentation
* Linux Manual Pages (`man`)
* GNU C Library Documentation

### Useful References

* https://man7.org/linux/man-pages/
* https://cplusplus.com/reference/cstring/
* https://github.com/WaRtr0/francinette-image

### Use of Artificial Intelligence

Artificial intelligence tools were used as supporting resources for:

* Understanding specific concepts of the C language.
* Clarifying memory management behavior.
* Verifying edge cases and implementation approaches.
* Helping in the writing of the documentation and translation.

All code was written, tested, and validated manually and with the "francinette" listed above.

---
