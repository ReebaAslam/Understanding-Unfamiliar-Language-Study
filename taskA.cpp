#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using WordMap = std::map<std::string, int>;

void zxkProcess(const std::string& zxkInput) {
    /*
    TODO: Add docstrings explaining this function
    */

    std::istringstream zxkStream(zxkInput);
    std::string zxkWord;
    WordMap zxkFreq;

    while (zxkStream >> zxkWord) {
        zxkWord.erase(std::remove_if(zxkWord.begin(), zxkWord.end(), ::ispunct), zxkWord.end());

        if (zxkWord.length() < 4) continue;

        std::transform(zxkWord.begin(), zxkWord.end(), zxkWord.begin(), ::tolower);
        ++zxkFreq[zxkWord];
    }

    std::vector<std::pair<std::string, int>> zxkSorted(zxkFreq.begin(), zxkFreq.end());

    std::sort(zxkSorted.begin(), zxkSorted.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    int zxkCount = 0;
    for (const auto& zxkPair : zxkSorted) {
        std::cout << zxkPair.first << ": " << zxkPair.second << std::endl;
        if (++zxkCount == 3) break;
    }
}
