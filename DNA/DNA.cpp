#include "DNA.h"


std::string DNA::findMatch(const std::string & input, const std::unordered_map<std::string, std::vector<int>> & dict, const std::vector<std::string> & strs) {
    // Return no match if input is empty
    if (input == "")
        return "No Match!";

    // vector to hold the count of each STR in the input
    std::vector<int> occurenceVector;

    // loop through the given strs
    for (const std::string & str: strs) {
        // init the index and occurence count to 0
        int index = 0;
        int occurences = 0;

        // if the str length is greater than the input length there can be no match
        if (input.length() < str.length()) {
            occurenceVector.push_back(occurences);
            continue;
        }

        // loop through the input 
        while (index <= input.length() - str.length()) {
            bool match = true;
            // loop through the alignments at input[index]
            for (int i = 0; i < str.length(); i++) {
                if (input[index + i] != str[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                // increment by str len -1 since we are looking for non overlapping substrings
                index += str.length() - 1;
                occurences++;
                match = true;
            }
            else {
                // increment by 1 to test the next alignment
                index += 1;
            }
        }
        std::cout << str << " , " << occurences << "\n";
        occurenceVector.push_back(occurences);
    }

    // go through the map
    for (auto it = dict.begin(); it != dict.end(); it++) {
        // if the person's str occurence matches our findings then return their name
        if (it->second == occurenceVector)
            return it->first;
    }

    return "No Match!";
}

std::string DNA::findMatch(const std::string & input, const std::vector<std::vector<int>> & names_occurrences, const std::vector<std::string> names, const std::vector<std::string> & strs) {
     if (input == "")
        return "No Match!";

    std::vector<int> occurenceVector;
    for (const std::string & str: strs) {
        int index = 0;
        int occurences = 0;
        if (input.length() < str.length()) {
            occurenceVector.push_back(occurences);
            continue;
        }
        while (index <= input.length() - str.length()) {
            bool match = true;
            for (int i = 0; i < str.length(); i++) {
                if (input[index + i] != str[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                index += str.length() - 1;
                occurences++;
                match = true;
            }
            else {
                index += 1;
            }
        }
        std::cout << str << " , " << occurences << "\n";
        occurenceVector.push_back(occurences);
    }


    for (size_t i = 0; i < std::min(names_occurrences.size(), names.size()); i++) {
        if (names_occurrences[i] == occurenceVector)
            return names[i];
    }

    return "No Match!";
}