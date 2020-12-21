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
 * Since we only care about
 */
typedef struct vCard {
	string name;
	string phoneNumber;
} vCard;

typedef struct Node {
	Node *next;

} Node;
