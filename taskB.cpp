#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cctype>
#include <string>

using GroupMap = std::map<char, std::vector<std::string>>;

void lmnOrganize(const std::string& lmnInput) {
    /*
    TODO: Add docstrings explaining this function
    */
    std::istringstream lmnStream(lmnInput);
    std::string lmnWord;
    GroupMap lmnGroups;

    while (lmnStream >> lmnWord) {
        lmnWord.erase(std::remove_if(lmnWord.begin(), lmnWord.end(), ::ispunct), lmnWord.end());
        if (lmnWord.length() < 4) continue;
        std::transform(lmnWord.begin(), lmnWord.end(), lmnWord.begin(), ::tolower);
        char firstChar = lmnWord[0];
        lmnGroups[firstChar].push_back(lmnWord);
    }

    for (const auto& lmnPair : lmnGroups) {
        const auto& lmnVec = lmnPair.second;
        int totalLength = std::accumulate(lmnVec.begin(), lmnVec.end(), 0,
            [](int sum, const std::string& word) {
                return sum + word.length();
            });
        double avgLength = static_cast<double>(totalLength) / lmnVec.size();

        std::cout << "Group '" << lmnPair.first << "' (avg len: " << avgLength << "): ";
        for (const auto& w : lmnVec) {
            std::cout << w << " ";
        }
        std::cout << std::endl;
    }
}