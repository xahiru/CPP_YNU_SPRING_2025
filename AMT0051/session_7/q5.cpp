#include <iostream>
#include <string>
#include <algorithm>

bool areAnagrams(const std::string& str1, const std::string& str2) {
    std::string s1 = str1;
    std::string s2 = str2;

    s1.erase(remove_if(s1.begin(), s1.end(), ::isspace), s1.end());
    s2.erase(remove_if(s2.begin(), s2.end(), ::isspace), s2.end());
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    if (s1.length() != s2.length())
        return false;

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    return s1 == s2;
}

int main() {
    std::string str1 = "Listen";
    std::string str2 = "Silent";

    if (areAnagrams(str1, str2)) {
        std::cout << "Anagrams" << std::endl;
    } else {
        std::cout << "Not Anagrams" << std::endl;
    }

    return 0;
}
