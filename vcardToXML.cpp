#include "pugixml.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

//This is probably bad practice but is easier since we mostly use
//std operations
using namespace std;

int main()
{
  cout << "Type file path to vcf file containing your contacts.\n";
  string vcfFile;
  getline(cin, vcfFile);
  // Now we check if the passed file has the correct extension
  if (vcfFile.rfind(".vcf") == vcfFile.npos) {
    cout << "File does not have the proper extension.\nDo you still want to use this as a vCard file? (y/[n])";
    string response;
    getline(cin, response);
    if (response != "y" && response != "Y") {
      exit(EXIT_SUCCESS);
    }
    // At this point we assume that the vcard file is valid
    // Read in the vCard file
  }
}
