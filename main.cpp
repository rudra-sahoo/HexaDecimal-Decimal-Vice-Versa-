#include <iostream>
#include <string>
#include <chrono> 
#include <thread>
#include <unordered_map>
#include <cmath>
#include <cctype>
#include <vector>
#include <algorithm>

bool isValidHexadecimal(const std::string& hexNumber) {
    std::string validCharacters = "123456789ABCDEF";

    //checking the number-_-
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
            decimalValue += value * std::pow(16, power);
            power++;
        }
    }

    return decimalValue;
}

std::string decimalToHexadecimal(int decimalNumber) {
    std::string hexadecimal;
    std::vector<char> hexDigits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    while (decimalNumber > 0) {
        int remainder = decimalNumber % 16;
        hexadecimal += hexDigits[remainder];
        decimalNumber /= 16;
    }

    std::reverse(hexadecimal.begin(), hexadecimal.end());  // Reverse the string to get the correct hexadecimal representation
    return hexadecimal;
}

int main() {
    std::cout << "Enter a Hexadecimal Number or a Decimal Number: ";
    std::string inputNumber;
    std::getline(std::cin, inputNumber);

    if (inputNumber.substr(0, 2) == "0x" || inputNumber.substr(0, 2) == "0X") {
        std::string numberToConvert = inputNumber.substr(2);

        if (isValidHexadecimal(numberToConvert) && numberToConvert != "0") {
            std::string text = "Checking this Number.........";
            std::string text1 = "This is a Hexadecimal Number.....";
            std::string text2 = "Converting to Decimal Number....... Please Wait!!!!!";

            for (char c : text) {
                std::cout << c << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(55));  
            }
            std::cout << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            for (char c1 : text1) {
                std::cout << c1 << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(55));  
            }
            std::cout << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            for (char c2 : text2) {
                std::cout << c2 << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(55));  
            }
            std::cout << std::endl;

            int decimalValue = convertToDecimal(numberToConvert);
            std::cout << "Decimal Version Of This Number is: " << decimalValue << std::endl;
        } else {
            std::string errorText = "This is not a valid Hexadecimal Number. Please enter a valid Hexadecimal Number.";
            for (char c : errorText) {
                std::cout << c << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(75));  
            }
            std::cout << std::endl;
        }
    } else {
        int decimalNumber = std::stoi(inputNumber);
        std::string hexadecimalNumber = decimalToHexadecimal(decimalNumber);
        std::string text10 = "Hexadecimal Version Of This Number is:  0X";
        for (char c10 : text10) {
            std::cout << c10 << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(55));  
        }
        std::cout << hexadecimalNumber << std::endl;
    }

    return 0;
}
