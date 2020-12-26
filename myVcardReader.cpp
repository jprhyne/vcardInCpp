#include "myVcardReader.hpp"
#include <assert.h>

// This program aims to parse specifically a vCard file from the purple List Handler plugin. Other libraries exist however, I had trouble getting them working
// (and the libraries are as old as a decade or another niche application so here we go reinventing the wheel, probably due to my ignorance)

/**
 * Overview of what we need to do
 * We need a function that will take a path to a file
 * Build and return a structure of some kind (Probably an array/linked list of Cards)
 * Iterate through this array and return desired information (Or allow client to do this?)
 */

vCard::vCard(std::string newName, std::string newPhoneNumber)
{
  name = newName;
  phoneNumber = newPhoneNumber;
}

vCard::vCard()
{
  name = "";
  phoneNumber = "";
}

Node::Node(Node *nextNode, vCard *newData)
{
  next = nextNode;
  data = newData;
}

void LinkedList::add(vCard newData)
{
  vCard *tempCardPtr =(vCard *) malloc(sizeof(newData));
  new (tempCardPtr) vCard(newData);
  Node *tempNode = (Node *) malloc(sizeof(Node));
  tempNode->next = nullptr;
  tempNode->data = tempCardPtr;
  if (tail == nullptr) {
    tail = tempNode;
    head = tail;
  } else {
    tail->next = tempNode;
    tail = tail->next;
  }
}

void destroyNode(Node* nodeToDestroy)
{
  if (nodeToDestroy == nullptr)
    //This means the initial call used a null pointer so termination case
    return;
	if (nodeToDestroy->next != nullptr)
		destroyNode(nodeToDestroy->next);
  std::free(nodeToDestroy->next);
  std::free(nodeToDestroy->data);
}

//Function that destroys our list (since we malloc the memory)
void destroyLinkedList(LinkedList *listToDestroy)
{
	destroyNode(listToDestroy->head);
  free(listToDestroy->head);
	std::free(listToDestroy);
}


// Function that creates our List from a given file
/**
 * Creates a linked list of vCard structs from a file
 */
LinkedList *buildFromFile(std::string filename)
{
	std::ifstream file{ filename };

	if (!file) {
		std::cerr << "Cannot open " + filename + "for writing.\n";
		return (LinkedList *)nullptr;
	}
	// Create the List here
	LinkedList *vCardList = (LinkedList *) malloc(sizeof(LinkedList));
	vCardList->head = nullptr;
	vCardList->size = 0;
	while (file) {
		std::string line;
		std::getline(file, line);
    //Not recognizing the start of the VCARD. Maybe some kind of line ending issue?
    //Look at the actual characters in 'line'
		//Create a vCard here (We assume the file has "BEGIN::VCARD ... END:VCARD")

    //This is in case the file was created under a windows system or uses carriage returns for
    //whatever reason.
    int carriageReturnLoc = line.find_last_of('\r');
    line = line.substr(0, carriageReturnLoc);
		if (line == "BEGIN:VCARD") {
			// loop through the lines until we reach "END:VCARD". We will use a counter and terminate if we have more than 100 iterations
			// (prevent infinite loops and these vCards will never be that long)
			if (!file) {
				//Failure case. Terminate after freeing our memory
				std::cout << "Error.\n";
				destroyLinkedList(vCardList);
			}
			int count = 0;
			std::string vcardLine;
      std::string name;
      std::string phoneNumber = "";
			std::getline(file, vcardLine);
      carriageReturnLoc = vcardLine.find_last_of('\r');
      vcardLine = vcardLine.substr(0, carriageReturnLoc);
			while (count <= 100 && vcardLine != "END:VCARD") {
				if (!file) {
					//Failure case. Terminate after freeing our memory
					destroyLinkedList(vCardList);
				}
				//we must read in the line and check if it is one of the two that we need
				if (vcardLine.substr(0, 2) == "FN") {
					// Full name of contact
					name = vcardLine.substr(3, vcardLine.npos);
				} else if (vcardLine.substr(0,3) == "TEL") {
					// This line contains the phone number. We may also have several numbers for one contact (Cell, Work, etc) For now, we ignore all after the first
					// But we will support this behavior (Create a new vCard object?)
					if (phoneNumber != "")
						continue;
					// We search through the line to get the last ':' char and copy the rest of this line into a new string
					std::string tempLine = vcardLine.substr(vcardLine.find_last_of(':') + 1); //Doesn't do error checking if no ':' are present
          //Now, we need to create a new string containing everything except the '-' chars
          std::string phoneNumber = "";
          for (std::string::iterator it=tempLine.begin(); it!=tempLine.end(); ++it) {
            char currentChar = *it;
            if (currentChar != '-') {
              phoneNumber.append(1u, currentChar);
            }
          }
          //Now, we create the vCard object and add it to our list
          vCard tempCard(name, phoneNumber);
          //vCard *addingCard = 
          vCardList->add(tempCard);
				}
				count++;
				std::getline(file, vcardLine);
			}
		}
	}
  std::cout << "File done.\n";
  assert(vCardList->tail->next == nullptr);
	return vCardList;
}

