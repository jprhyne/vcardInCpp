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
    std::cout << "File does not have the proper extension.\nDo you still want to use this as a vCard file? (y/[n])";
    std::string response;
    std::getline(std::cin, response);
    if (response != "y" && response != "Y") {
      exit(EXIT_SUCCESS);
    }
    // At this point we assume that the vcard file is valid
    // Read in the vCard file
    buildFromFile(vcfFile);
  }
}
