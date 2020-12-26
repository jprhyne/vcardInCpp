#include "pugixml.hpp"
#include "myVcardReader.hpp"

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif


int main()
{
  std::cout << "Type file path to vcf file containing your contacts.\n";
  std::string vcfFile;
  std::getline(std::cin, vcfFile);
  // Now we check if the passed file has the correct extension
  if (vcfFile.rfind(".vcf") == vcfFile.npos) {
    std::cout << "File does not have the proper extension.\nDo you still want to use this as a vCard file? [y/N]";
    std::string response;
    std::getline(std::cin, response);
    if (response != "y" && response != "Y") {
      exit(EXIT_SUCCESS);
    }
  }
    // At this point we assume that the vcard file is valid
    // Read in the vCard file
    LinkedList *myList = buildFromFile(vcfFile);
    std::cout << "Do you have an existing xml file from List Handler? [y/N]";
    std::string response;
    std::getline(std::cin, response);
    bool existingFile = true;
    if (response != "y" && response != "Y") 
      existingFile = false;

    pugi::xml_document xmlDoc;
    if (existingFile) {
      //Read in the existing xml file and append this information
    } else {

      //Create a new xml file with a, hopefully, correct header information
      auto declarationNode = xmlDoc.append_child(pugi::node_declaration);
      declarationNode.append_attribute("version") = "1.0";
      declarationNode.append_attribute("encoding") = "UTF-8";

      auto root = xmlDoc.append_child("exported_buddy_list");
      auto childNode = root.append_child("config");
      auto grandChildNode = childNode.append_child("config-version");
      grandChildNode.append_attribute("version") = "2";

      grandChildNode = childNode.append_child("config-type");
      grandChildNode.append_attribute("type") = "buddy-list";

      grandChildNode = childNode.append_child("prpl");
      grandChildNode.append_attribute("id") = "prpl-mm-sms";

      grandChildNode = childNode.append_child("source");
      grandChildNode.append_attribute("account") = "SMS";

      childNode = root.append_child("privacy");
      childNode = root.append_child("blist");

      grandChildNode = childNode.append_child("group");
      grandChildNode.append_attribute("name") = "Buddies";

      for (Node *currentNode = myList->head; currentNode != nullptr; currentNode = currentNode->next) {
        auto finalChildNode = grandChildNode.append_child("buddy");
        finalChildNode.append_attribute("screenname") = currentNode->data->phoneNumber.c_str();
        finalChildNode.append_attribute("alias") = currentNode->data->name.c_str();
      } 
      bool saveSuccess = xmlDoc.save_file("tempFile.xml");
      if (!saveSuccess)
        std::cerr << "Could not open file for writing.\n";
    }
    destroyLinkedList(myList);
}
