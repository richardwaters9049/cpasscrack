# Password Strength Checker Project Report

## Overview

This project implements a **Password Strength Checker** in C++ that evaluates the complexity of a password entered by the user. The program provides a secure way of handling passwords, as the password is **hashed** using the **SHA-256** algorithm. Additionally, it displays a masked password input (`••••••••`) and reveals the cracked password after evaluation, followed by the password strength assessment.

## Features

- **Masked Password Input**: The password is masked (using `•` symbols) while the user types it in for privacy.
- **SHA-256 Hashing**: The password is hashed using the **OpenSSL SHA-256** algorithm.
- **Password Strength Evaluation**: The program checks for password complexity, ensuring it includes lowercase, uppercase, digits, and special characters.
- **Password Cracking Simulation**: After the user enters the password, the program reveals the plain-text password and displays its strength evaluation.

## Goals

- **Password Hashing**: Ensure that the user’s password is not stored in plain text.
- **Password Masking**: Display `•` characters while the user types their password for security purposes.
- **Password Strength Evaluation**: Evaluate the strength of the password based on its length and complexity (uppercase, lowercase, digits, and special characters).
- **User-Friendly Output**: Provide clear and user-friendly output about the password strength after entering the password.

## Setup and Installation

### Prerequisites

This project uses **OpenSSL** for password hashing. It also relies on **C++11** or later for compiling and running.

1. **Homebrew** (for macOS) should already be installed.
2. Install **OpenSSL** via Homebrew:

   ```bash
   brew install openssl@1.1
   ```

## Compilation Instructions

1. **Clone or Create the Project Directory**:

   - Create a new directory for the project:

     ```bash
     mkdir PassWordProject
     cd PassWordProject
     ```

2. **Create the C++ Source File**:

   - You can use any text editor, such as **Visual Studio Code**, to create the `password_strength.cpp` file with the code provided earlier.

3. **Compile the Code**:

   - To compile the program, run the following command:

     ```bash
     g++ -o password_strength password_strength.cpp -I/opt/homebrew/opt/openssl@1.1/include -L/opt/homebrew/opt/openssl@1.1/lib -lssl -lcrypto
     ```

4. **Run the Program**:

   - Once compiled, you can run the program with:

     ```bash
     ./password_strength
     ```

## How It Works

1. **Masked Password Input**:

   - The program uses terminal features to disable **echo** while the user types their password. Each character typed is shown as `•`, ensuring that the password is kept hidden.
   - The program waits until the user presses `Enter` to finish the password input.

2. **SHA-256 Hashing**:

   - After receiving the password, the program uses the **SHA-256** hash function from the **OpenSSL** library to generate a hashed version of the password. This hash is typically used for secure password storage.

3. **Strength Evaluation**:

   - The password's strength is evaluated using:
     - **Length**: The password should be at least 8 characters long.
     - **Complexity**: The password must include at least one lowercase letter, one uppercase letter, one digit, and one special character.

4. **Cracking and Output**:
   - The program prints the **cracked password** (the actual password entered by the user).
   - The program also displays the **password strength** based on the criteria mentioned above, such as:
     - **Weak (Too short)**
     - **Weak (Missing complexity)**
     - **Strong**

## Sample Output

### Scenario 1: Weak Password (Too Short)

Enter a password to evaluate: ••••••••
Password Cracked: 123
Password Strength: Weak (Too short)

### Scenario 2: Weak Password (Missing Complexity)

Enter a password to evaluate: ••••••••••
Password Cracked: password
Password Strength: Weak (Missing complexity)

### Scenario 3: Strong Password

Enter a password to evaluate: ••••••••••

Password Cracked: Password123!

Password Strength: Strong

## Code Explanation

Here’s a breakdown of how the key components work in the code:

1. **Masked Password Input**:

   - Using the `termios` library, the terminal settings are modified to hide the user input. Each character typed is masked with `•` until the user presses `Enter`.

2. **SHA-256 Hashing**:

   - The password is passed through the `SHA256()` function, which generates a hash. This hash could be used for securely storing passwords in a real-world scenario, without storing the original password.

3. **Password Strength Evaluation**:
   - The password's strength is evaluated using **regular expressions** to check if it contains:
     - At least one lowercase letter (`[a-z]`),
     - At least one uppercase letter (`[A-Z]`),
     - At least one number (`[0-9]`),
     - At least one special character (`[^a-zA-Z0-9]`).
   - If the password meets all criteria, it is considered "Strong"; otherwise, it is evaluated as "Weak".

## Future Improvements

- **Error Handling**: Improve error handling for invalid input or edge cases (e.g., input longer than expected).
- **Password Storage**: Implement a mechanism to securely store hashed passwords for authentication purposes.
- **User Interface**: Build a GUI or web-based interface for easier interaction.
- **Enhanced Evaluation**: Add more advanced password complexity checks (e.g., avoiding common passwords, dictionary words, etc.).

## Conclusion

This project demonstrates how to implement a basic **Password Strength Checker** using C++ and OpenSSL. The program evaluates the complexity of passwords, ensures secure handling through hashing, and provides user-friendly feedback on password strength. The masked input adds an extra layer of security and privacy for the user during password entry.

---

### How to Download the Report

- **Markdown File**: You can save this report as a markdown file by copying the contents into a file called `REPORT.md`:

```bash
echo "Paste the markdown content here" > REPORT.md



```
