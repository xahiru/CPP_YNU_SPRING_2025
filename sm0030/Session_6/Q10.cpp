#include <iostream>
#include <string>

int findFirstOccurrence(const std::string& txt, const std::string& pat) {
    int n = txt.length();
    int m = pat.length();

    if (m == 0) return 0; // Empty pattern is considered to occur at index 0

    for (int i = 0; i <= n - m; ++i) {
        bool match = true;
        for (int j = 0; j < m; ++j) {
            if (txt[i + j] != pat[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::string txt1 = "YunnanUniversity";
    std::string pat1 = "Fr";
    std::cout << "Input: txt = \"" << txt1 << "\", pat = \"" << pat1 << "\"" << std::endl;
    std::cout << "Output: " << findFirstOccurrence(txt1, pat1) << std::endl; 

    std::string txt2 = "YunnanUniversity";
    std::string pat2 = "nan";
    std::cout << "Input: txt = \"" << txt2 << "\", pat = \"" << pat2 << "\"" << std::endl;
    std::cout << "Output: " << findFirstOccurrence(txt2, pat2) << std::endl; 

    std::string txt3 = "YunnanUniversity";
    std::string pat3 = "gr";
    std::cout << "Input: txt = \"" << txt3 << "\", pat = \"" << pat3 << "\"" << std::endl;
    std::cout << "Output: " << findFirstOccurrence(txt3, pat3) << std::endl; 
    return 0;
}