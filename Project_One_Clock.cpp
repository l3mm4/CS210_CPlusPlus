/* 
 * Project_One_Clock.cpp
 * Author: Sean Jette
 * Date: 17SEP2023
 */

#include "Project_One_Clock.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <limits>
using namespace std;

// Forward declaration for the function that adds one second to the current time
void addOneSecond();
// Forward declaration for the function that adds one minute to the current time
void addOneMinute();
// Forward declaration for the function that adds one hour to the current time
void addOneHour();

// Function to convert an unsigned integer into a two-digit string
string twoDigitString(unsigned int n) {
    // Initialize an empty string to hold the result
    string result;
    // If the input number is greater than or equal to 10
    if (n >= 10) {
        // Convert the number to a string and assign it to the result
        result = to_string(n);
    }
    else {
        // If the number is less than 10, prepend a "0" before converting the number to a string
        result = "0" + to_string(n);
    }
    // Return the resulting two-digit string
    return result;
}

// Function to create a string of a specific length with a specific character
string nCharString(size_t n, char c) {
    // Create a string of length 'n', each character being 'c'
    string result(n, c);
    // Return the resulting string
    return result;
}

// Function to format the time in 24-hour format
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    // Convert hours, minutes, and seconds to two-digit strings
    string hours = twoDigitString(h);
    string minutes = twoDigitString(m);
    string seconds = twoDigitString(s);
    // Concatenate the strings with colons in between
    string time = hours + ":" + minutes + ":" + seconds;
    // Return the resulting time string
    return time;
}

// Function to format the time in 12-hour format
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    // Convert hours, minutes, and seconds to two-digit strings
    string hours = twoDigitString(h % 12 == 0 ? 12 : h % 12); // Convert to 12-hour format
    string minutes = twoDigitString(m);
    string seconds = twoDigitString(s);
    // Determine whether it's AM or PM
    string period = (h < 12) ? "A M" : "P M";
    // Concatenate the strings with colons in between and add the period at the end
    string time = hours + ":" + minutes + ":" + seconds + " " + period;
    // Return the resulting time string
    return time;
}


// Function to print a menu with a given width
void printMenu(string strings[], unsigned int numStrings, unsigned int width) {
    // Limit the width to 26
    if (width > 26) {
        width = 26;
    }
    // Print a line of asterisks of length 'width'
    cout << nCharString(width, '*') << endl;
    // Loop through each string in the array
    for (unsigned int i = 0; i < numStrings; ++i) {
        // Print the item number and the string
        cout << "* " << i + 1 << " - " << strings[i] << nCharString(width - 7 - strings[i].length(), ' ');
        // End the line with an asterisk
        cout << "*" << endl;
        if (i < numStrings - 1) cout << endl;
    }
    // Print another line of asterisks of length 'width'
    cout << nCharString(width, '*') << endl;
}

// Function to display two clocks: one in 12-hour format and the other in 24-hour format
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    // Print 26 stars, 3 spaces, and another 26 stars
    cout << nCharString(26, '*') << nCharString(3, ' ') << nCharString(26, '*') << endl;
    // Print the 12-Hour Clock label
    cout << "*" << nCharString(6, ' ') << "12-Hour Clock" << nCharString(5, ' ') << "*" << nCharString(3, ' ');
    // Print the 24-Hour Clock label
    cout << "*" << nCharString(6, ' ') << "24-Hour Clock" << nCharString(5, ' ') << "*" << endl;
    // Print a blank line for spacing
    cout << endl;
    // Print the 12-hour time
    cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(6, ' ') << "*" << nCharString(3, ' ');
    // Print the 24-hour time
    cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(8, ' ') << "*" << endl;
    // Print 26 stars, 3 spaces, and another 26 stars
    cout << nCharString(26, '*') << nCharString(3, ' ') << nCharString(26, '*') << endl;
    // Print a blank line for spacing
    cout << endl;
}

// Function to get the user's menu choice
int getMenuChoice() {
    // Variable to store the user's choice
    int choice;
    // Variable to store the user's input
    string input;
    // Get the user's input as a string
    getline(cin, input);
    // Try to convert the input to an integer
    stringstream ss(input);
    ss >> choice;
    // If the conversion failed or the stream is not at the end (meaning there are extra characters), print an error message and return an error code
    if (ss.fail() || !ss.eof()) {
        cout << "Invalid input. Please enter a number between 1 and 4." << endl;
        return -1;
    }
    // If the choice is not between 1 and 4, print an error message and return an error code
    if (choice < 1 || choice > 4) {
        cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        return -1;
    }
    // Otherwise, return the user's choice
    return choice;
}

// Function to display the main menu and handle time input
void mainMenu() {
    // Array of menu items
    string menuItems[4] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
    // Variables to store hours, minutes, and seconds
    int h, m, s;
    // Flag to check if there is an error in the input
    bool isError = true;
    // Loop until a valid time is entered
    do {
        // Reset error flag
        isError = false;
        // Prompt user for time input
        cout << "Enter a time as hours, minutes, and seconds separated by spaces (example: 13 15 45): ";
        cin >> h >> m >> s;
        // Check if input is valid according to set parameters
        if (cin.fail() || h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
            // Display error message
            cout << "Invalid time entry. Please enter a valid initial time state." << endl;
            // Set error flag to true
            isError = true; 
        }
        cin.clear(); // clear the fail state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
    } while (isError == true); // Repeat if there was an error

    // Create a ClockTime instance with the entered hours, minutes, and seconds
    ClockTime ct(h, m, s);
    // Variable to store user's menu choice
    int choice;
    do {
        // Clear the console
        system("cls");
        // Dispaly the current time
        displayClocks(ct.getHour(), ct.getMinute(), ct.getSecond());
        // Print the menu items
        printMenu(menuItems, 4, 50);
        // Get the user's menu choice
        choice = getMenuChoice();
        // If the choice is -1, continue with the next iteration of the loop
        while (choice == -1) {
            choice = getMenuChoice();
        }
        // Perform an action based on the user's choice
        switch (choice) {
        case 1:
            // If the user chose 1, add one hour to the current time
            ct.addOneHour();
            break;
        case 2:
            // If the user chose 2, add one minute to the current time
            ct.addOneMinute();
            break;
        case 3:
            // If the user chose 3, add one second to the current time
            ct.addOneSecond();
            break;
        case 4:
            // If the user chose 4, exit the program
            cout << "..::Exiting Program::.." << endl;
            break;
        default:
            // If the user entered an invalid choice, print an error message
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            break;
        }
    } while (choice != 4); // Repeat until the user chooses to exit
}

int main() {
    // Call the main menu function
    mainMenu();
    // Return 0 to indicate successful execution
    return 0;
}