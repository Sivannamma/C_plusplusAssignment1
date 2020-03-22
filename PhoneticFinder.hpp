#include <string>
#include <vector>
namespace phonetic {
    std::string find(std::string text, std::string word);

    std::vector<std::string>split(std::string text);

    std::string containsMistaken(char ch);

    bool contains(std::string str, char ch);
}