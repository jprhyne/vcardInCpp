#pragma once

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif

#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

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
  //Constructor
  vCard();
  vCard(std::string name, std::string phoneNumber);
  vCard(const vCard &v2) {name = v2.name; phoneNumber=v2.phoneNumber;}
}vCard;

/**
 * Linked List implementation
 */
typedef struct Node {
  // pointer to the "next" node in the list
	Node *next;
  // The data being stored
	vCard *data;

  Node(Node *nextNode, vCard *newData);
  Node(const Node &n2) {next=n2.next; data=n2.data;}
} Node;

/**
 * Our linked list. Head is the first Node in the list.
 * A list is empty if and only if head == std::nullptr && size == 0
 *
 * A better practice would be to make a class and use getter methods to prevent
 * the user from modifying the list
 */
typedef struct LinkedList {
  Node *head;
  Node *tail;
  int size;

  void add(vCard);
} LinkedList;

void destroyLinkedList(LinkedList *name); //def in myVcardReader.cpp

LinkedList *buildFromFile(std::string); //def in myVcardReader.cpp


