#include "PhoneticFinder.hpp"
#include <string>
#include <vector>
#include <stdexcept>

std::string mistakenWords[] = {"vVwW", "bBfFpP", "gGjJ", "cCkKqQ", "sSzZ", "dDtT", "oOuU", "iIyY"};

namespace phonetic {
    std::string find(std::string text, std::string word) {
        int len = word.length();
        int counter = 0;
        std::string ans = "";
        std::string str = "";
        std::vector<std::string> words = split(text);

        for (int i = 0; i < words.size(); ++i) {
            // if the len of the string in the specific cell equals to the len of the word
            // we got means its optional word for check
            if (words[i].length() == len) {
                for (int j = 0; j < word.length(); j++) {
                    // returns the  possibility in the mistaken word from the arr
                    str = containsMistaken(word[j]);

                    if (contains(str, words[i][j])) {
                        counter++;
                    }
                        // move to next word
                    else {
                        counter = 0;
                        break;
                    }
                }
            }
            // if we found the word.
            if (counter == len) {
                return words[i];
            }
        }

        if (ans.length() == 0) { // if we didnt find the word
            throw std::invalid_argument("did not find the word "+word+"in the text");

        }
        return "";
    }

    std::vector<std::string> split(std::string text) {
        bool toCount = false; // variable to know when we can count a word
        std::string str = "";
        // array of strings
        std::vector<std::string> words;

        for (int i = 0; i < text.length(); ++i) {
            // if we reached a char that is not a space ,concat it to right cell
            if (text[i] != 32) {
                toCount = true;
                str += text[i];
            }
                // if we reached a space it means we finished concating a word,move to next cell
            else if (text[i] == 32 && toCount) {
                words.push_back(str);
                str = "";
                toCount = false;

            }
            if (i == text.length() - 1 && text[i] != 32) {
                words.push_back(str);
            }

        }

        return words;
    }

    std::string containsMistaken(char ch) {
        std::string ans = "";
        std::string c = "";
        for (int i = 0; i < sizeof(mistakenWords) / sizeof(mistakenWords[0]); i++) {
            if (contains(mistakenWords[i], ch)) {
                return mistakenWords[i];
            }

        }
        // if we didnt find the word in the mistakenWords,
        // return the string with upper/lower case of the char.
        if (ch >= 65 && ch <= 90) {
            c = ch + 32;
            ans = ch + c;
            return ans;
        } else {
            c = ch - 32;
            ans = ch + c;
            return ans;
        }

    }

    bool contains(std::string str, char ch) {
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == ch) {
                return true;
            }
        }
        return false;
    }


}