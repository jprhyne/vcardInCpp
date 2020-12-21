#include <iostream>
#include <string>

// This program aims to parse specifically a vCard file from the purple List Handler plugin. Other libraries exist however, I had trouble making them portable across
// Linux and Windows machine (and the libraries are as old as a decade or another niche application so here we go reinventing the wheel, probably due to my ignorance

/*
 * Overview of what we need to do
 * We need a function that will take a path to a file
 * Build and return a structure of some kind (Probably an array/linked list of Cards)
 * Iterate through this array and return desired information (Or allow client to do this?)
 */

/**
 * Since we only care about the specific vcard file created by evolution
 * for contacts, we will use a struct with a set amount of fields instead
 * of a dictionary. This is a lazy choice but works with this particular
 * use case
 */
typedef struct vCard {
  // Name of the contact (Full Name).
  std::string name;
  // Phone number of contact
  std::string phoneNumber;
} vCard;

/**
 * Linked List implementation
 */
typedef struct Node {
  // pointer to the "next" node in the list
	Node *next;
  // The data being stored 
  vCard data;
} Node;

/**
 * Our linked list. Head is the first Node in the list.
 * A list is empty if and only if head == std::nullptr && size == 0
 */
typedef struct LinkedList {
  Node *head;
  int size;
} LinkedList;

// Function that creates our List from a given file



//Function that destroys our list (since we malloc the memory)
