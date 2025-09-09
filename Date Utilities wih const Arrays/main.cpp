#include <iostream>
#include <string>
#include <limits>
using namespace std;  // Avoid using this in header files

// Global array of day names
const std::string DaysOfWeek[7] = {
"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" 
};

// Global array of month names
const std::string MonthsOfYear[12] = { 
	"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" 
};

//function prototypes
int displayMenu();
void runMenu();

int main() {
    // Initialization
    runMenu();
    // Cleanup
    return 0;
}

// Function to display the menu
int displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Get Day Name by Number (1-7)\n";
    std::cout << "2. Get Month Name by Number (1-12)\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;

    // Validate input
    while (std::cin.fail()) {
        std::cin.clear();
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	    std::cout << "Invalid input. Please enter a new number: ";
        std::cin >> choice;
    }
    return choice;
}

int getValidatedInput(const std::string& prompt) {
    int num;
	std::cout << prompt;
	std::cin >> num;    

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a new number: ";
        std::cin >> num;
	}
	return num;
}

// Function to run the menu loop
void runMenu() {
    int choice; //The menu selection
    do {
        //Get a menu selection
        choice = displayMenu();
        //Carry out the menu selection (should call functions)
        switch (choice) {
        case 1: { // Get day name
            int dayNum = getValidatedInput("Enter a day number (1-7): ");
            if (dayNum >= 1 && dayNum <= 7) {
                std::cout << "The day is: "
                    << DaysOfWeek[dayNum - 1] << std::endl;
            }
            else {
                std::cout << "Invalid day number. Please enter a number between 1 and 7.\n";
            }
            break;
        }

        case 2: { // Get month name
            int monthNum = getValidatedInput("Enter a month number (1-12): ");
            if (monthNum >= 1 && monthNum <= 12) {
                std::cout << "The month is: "
                    << MonthsOfYear[monthNum - 1] << std::endl;
            }
            else {
                std::cout << "Invalid month number. Please enter a number between 1 and 12.\n";
            }
            break;
        }

        case 0: // Exit
            std::cout << "Exiting the program.\n" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;

            //End of menu selection if 0 was selected
        }

    }
    while (choice != 0);
}