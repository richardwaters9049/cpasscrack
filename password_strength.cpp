#include <iostream>
#include <string>
#include <regex>
#include <openssl/sha.h> // Include OpenSSL for SHA-256 hashing
#include <iomanip>
#include <sstream>
#include <termios.h>
#include <unistd.h>

// Function to read password with masked input (••••••••)
std::string readPassword() {
    std::string password;
    char ch;
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt); // Get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ECHO); // Disable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings

    std::cout << "Enter a password to evaluate: ";
    while (true) {
        ch = getchar(); // Get a character from input
        if (ch == '\n') {
            break; // Break on Enter key
        } else if (ch == 127) { // Backspace handling
            if (password.length() > 0) {
                password.pop_back(); // Remove last character
                std::cout << "\b \b"; // Erase the last dot on terminal
            }
        } else {
            password += ch; // Add character to password
            std::cout << "•"; // Display dot
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore terminal settings
    std::cout << std::endl; // Newline after entering password
    return password;
}

// Function to hash the password using SHA-256
std::string hashPassword(const std::string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(password.c_str()), password.size(), hash);

    std::ostringstream hashedPassword;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashedPassword << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return hashedPassword.str();
}

// Function to evaluate password strength
std::string evaluatePasswordStrength(const std::string& password) {
    if (password.length() < 8) {
        return "Weak (Too short)";
    }

    bool hasLower = std::regex_search(password, std::regex("[a-z]"));
    bool hasUpper = std::regex_search(password, std::regex("[A-Z]"));
    bool hasDigit = std::regex_search(password, std::regex("[0-9]"));
    bool hasSpecial = std::regex_search(password, std::regex("[^a-zA-Z0-9]"));

    if (hasLower && hasUpper && hasDigit && hasSpecial) {
        return "Strong";
    } else {
        return "Weak (Missing complexity)";
    }
}

int main() {
    std::string password = readPassword(); // Read masked password

    // Hash the password (you can use the hashed version for storage)
    std::string hashedPassword = hashPassword(password);

    // Evaluate password strength
    std::string strength = evaluatePasswordStrength(password);

    // Display the results
    std::cout << "Password Cracked: " << password << std::endl;
    std::cout << "Password Strength: " << strength << std::endl;

    return 0;
}