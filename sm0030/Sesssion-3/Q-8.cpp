#include <iostream>
#include <string>

int main() {
    std::string arr1[] = {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    std::string thirdLargest1 = "";
    int len1 = 0;
    int secondLen1 = 0;
    int thirdLen1 = 0;

    for (int i = 0; i < n1; ++i) {
        int currentLen = arr1[i].length();
        if (currentLen > len1) {
            thirdLen1 = secondLen1;
            secondLen1 = len1;
            len1 = currentLen;
        } else if (currentLen > secondLen1 && currentLen != len1) {
            thirdLen1 = secondLen1;
            secondLen1 = currentLen;
        } else if (currentLen > thirdLen1 && currentLen != secondLen1 && currentLen != len1) {
            thirdLen1 = currentLen;
        }
    }

    for (int i = 0; i < n1; ++i) {
        if (arr1[i].length() == thirdLen1) {
            thirdLargest1 = arr1[i];
            break;
        }
    }

    std::cout << "Array elements: ";
    for (const std::string& s : arr1) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    std::cout << "Third highest length string: " << thirdLargest1 << std::endl;

    std::string arr2[] = {"abc", "abc", "abc", "abc", "abc"};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    std::string thirdLargest2 = "";
    int len2 = 0;
    int secondLen2 = 0;
    int thirdLen2 = 0;

    for (int i = 0; i < n2; ++i) {
        int currentLen = arr2[i].length();
        if (currentLen > len2) {
            thirdLen2 = secondLen2;
            secondLen2 = len2;
            len2 = currentLen;
        } else if (currentLen > secondLen2 && currentLen != len2) {
            thirdLen2 = secondLen2;
            secondLen2 = currentLen;
        } else if (currentLen > thirdLen2 && currentLen != secondLen2 && currentLen != len2) {
            thirdLen2 = currentLen;
        }
    }

    for (int i = 0; i < n2; ++i) {
        if (arr2[i].length() == thirdLen2) {
            thirdLargest2 = arr2[i];
            break;
        }
    }

    std::cout << "Array elements: ";
    for (const std::string& s : arr2) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    std::cout << "Third highest length string: " << thirdLargest2 << std::endl;

    std::string arr3[] = {"abcd", "abcd", "abc"};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    std::string thirdLargest3 = "";
    int len3 = 0;
    int secondLen3 = 0;
    int thirdLen3 = 0;

    for (int i = 0; i < n3; ++i) {
        int currentLen = arr3[i].length();
        if (currentLen > len3) {
            thirdLen3 = secondLen3;
            secondLen3 = len3;
            len3 = currentLen;
        } else if (currentLen > secondLen3 && currentLen != len3) {
            thirdLen3 = secondLen3;
            secondLen3 = currentLen;
        } else if (currentLen > thirdLen3 && currentLen != secondLen3 && currentLen != len3) {
            thirdLen3 = currentLen;
        }
    }

    for (int i = 0; i < n3; ++i) {
        if (arr3[i].length() == thirdLen3) {
            thirdLargest3 = arr3[i];
            break;
        }
    }

    std::cout << "Array elements: ";
    for (const std::string& s : arr3) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    std::cout << "Third highest length string: " << thirdLargest3 << std::endl;

    return 0;
}