#include "pugixml.hpp"
#include "./include/vcard.h"
#include "./include/text_io.h"
#include <iostream>
#include <string>

//This is probably bad practice but is easier since we mostly use
//pugi operations
using namespace pugi;

int main()
{
  std::cout << "Type file path to vcf file containing your contacts.\n";
  std::string vcfFile;
  std::getline(std::cin, vcfFile);
  std::cout << vcfFile;
}
