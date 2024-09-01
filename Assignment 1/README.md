# DSA Assignment 1

**NAME: Vedansh Agrawal**
**ROLL NO.: 2021112010**

>Ubuntu 20.04.3 LTS

## Question 1:
Question 1 deals with doubly-linked-list.

Following is the various functions coded in the program

1. Insert - to insert a node (containing data) at the end of the linked list.
> `insert <data>`
2. Insert at - to insert a node (containing data) at any given position in the list.
> `insert_at <data> <index>`
3. Delete - to delete the node at the specified index
> `delete <index>`
4. Find - to find and display the index of the first occurence of the given element
> `find <elmt>`
5. Prune - deletes all odd-indexed nodes in the list
> `prune`
6. Print - prints all the data in the linked list in order
> `print`
7. Print reverse - prints all the data in the reverse order
> `print_reverse`
8. Get size - prints the no. of elements in the list
> `get_size`



## Question 2:
In this program, we implement the ADT of an n-dimensional complex number, i.e., a vector of n floating-point numbers.

The functionality of the ADT can be used as follows:

1. Addition - to add two n-dimensional complex numbers
> `ADD <n>`

> `<n space-separated floating-point numbers for the first complex number>`

> `<n space-separated floating-point numbers for the second complex number>`

2. Subtraction - to subtract one n-dimensional complex number from another
> `SUB <n>`

> `<n space-separated floating-point numbers for the first complex number>`

> `<n space-separated floating-point numbers for the second complex number>`

3. Magnitude - to find magnitude of the given complex number
> `MOD <n>`

> `<n space-separated floating-point numbers denoting the complex number>`

4. Dot product - to find dot product of two given complex numbers
> `DOT <n>`

> `<n space-separated floating-point numbers for the first complex number>`

> `<n space-separated floating-point numbers for the second complex number>`

5. Cos similarity - to find the cosine similarity of two given complex numbers
> `COS <n>`

> `<n space-separated floating-point numbers for the first complex number>`

> `<n space-separated floating-point numbers for the second complex number>`

To avoid naming conflicts with the math function cos(), the user-defined function has been named as COS().

All the above commands are case-sensitive.

## Question 3:
This multi-file program is the implementation of an ADT for a music player.

The functionality of the music player is as follows:

1. Add song - adds a song to the end of the playqueue
> `ADD <name of song> <name of artist> <duration of song>`
2. Remove song - removes song at specified index
> `REMOVE <index>`
3. Play song - plays the first song in the playqueue and removes it from the list
> `PLAY`
4. Get current song - to find the song that is currently playing
> `GET`
5. insert song - This inserts a song to Queue
>`INSERT <name of song>`

All above commands are case-sensitive. On entering EXIT the program terminates.
