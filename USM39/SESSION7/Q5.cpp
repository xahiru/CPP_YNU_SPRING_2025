#include <iostream>
#include <string>
#include <algorithm>

bool areAnagrams(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) return false;
    std::string sorted1 = str1;
    std::string sorted2 = str2;
    std::sort(sorted1.begin(), sorted1.end());
    std::sort(sorted2.begin(), sorted2.end());
    return sorted1 == sorted2;
}

int main() {
    std::string str1 = "listen";
    std::string str2 = "silent";
    if (areAnagrams(str1, str2)) {
        std::cout << str1 << " and " << str2 << " are Anagrams" << std::endl;
    } else {
        std::cout << str1 << " and " << str2 << " are Not Anagrams" << std::endl;
    }
    return 0;
}
