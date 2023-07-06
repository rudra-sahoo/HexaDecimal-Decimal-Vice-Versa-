#include <iostream>
#include <string>
#include <chrono> 
#include <thread>
#include <unordered_map>
#include <cmath>
#include <cctype>

bool isValidHexadecimal(const std::string& hexNumber) {
    std::string validCharacters = "123456789ABCDEF";

    // Check if each character is a valid hexadecimal digit
    for (char ch : hexNumber) {
        if (validCharacters.find(std::toupper(ch)) == std::string::npos) {
            return false;
        }
    }

    return true;
}

int convertToDecimal(const std::string& hexNumber) {
    std::unordered_map<char, int> hexValues = {
        {'0', 0},
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'A', 10},
        {'B', 11},
        {'C', 12},
        {'D', 13},
        {'E', 14},
        {'F', 15}
    };

    int decimalValue = 0;
    int power = 0;

    for (int i = hexNumber.length() - 1; i >= 0; --i) {
        char ch = std::toupper(hexNumber[i]);

        if (hexValues.find(ch) != hexValues.end()) {
            int value = hexValues[ch];
            decimalValue += value * pow(16, power);
            power++;
        }
    }

    return decimalValue;
}

int main() {
    std::cout << "Enter the Hexadecimal Number: ";
    std::string hexadecimalNumber;
    std::getline(std::cin, hexadecimalNumber);

    std::string prefix1 = "0x";
    std::string prefix2 = "0X";
    std::string text = "Checking this Number.........";
    std::string text1 = "This is a Hexadecimal Number.....";
    std::string text2 = "Converting to Decimal Number....... Please Wait!!!!!";
    std::string errorText = "This is not a valid Hexadecimal Number. Please enter a valid Hexadecimal Number.";

    if (hexadecimalNumber.substr(0, prefix1.size()) == prefix1 || hexadecimalNumber.substr(0, prefix2.size()) == prefix2) {
        std::string numberToConvert = hexadecimalNumber.substr(prefix1.size());
        if (isValidHexadecimal(numberToConvert) && numberToConvert != "0") {
            for (char c : text) {
                std::cout << c << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(75));  
            }
            std::cout << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            for (char c1 : text1) {
                std::cout << c1 << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(75));  
            }
            std::cout << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            for (char c2 : text2) {
                std::cout << c2 << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(75));  
            }
            std::cout << std::endl; 

            int decimalValue = convertToDecimal(numberToConvert);
            std::cout << "Decimal Version Of This Number is :: " << decimalValue << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(75)); 
            
            
        } else {
            for (char c : text) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(75));  
            }
            std::cout << "" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            for (char c4 : errorText) {
            std::cout << c4 << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(75));  
            }
        }
    } else {
        for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(75));  
        }
        std::cout << "" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        for (char c4 : errorText) {
        std::cout << c4 << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(75));  
        }
    }

    return 0;
}
