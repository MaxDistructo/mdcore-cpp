#include <string>
#include <ostream>

bool openFile(std::string filename, std::ifstream& stream);
bool openFile(std::string filename, std::ofstream& stream);
bool writeFile(std::string filename, std::string contents);


