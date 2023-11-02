#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std;
    const int finePerDay = 1;
    vector<string> books;
    vector<int> dueDates;

    while (true) {
        int choice;
        cout << "Library System Menu:" << endl;
        cout << "1. Issue a book" << endl;
        cout << "2. Return a book" << endl;
        cout << "3. Exit" << std::endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cin.ignore();
            string title;
            cout << "Enter the title of the book: ";
            getline(cin, title);

            books.push_back(title);
            dueDates.push_back(3); // Initialize with 3 days before fine.

            cout << "Book '" << title << "' issued successfully." << endl;
            cout << "Due date: " << dueDates.back() << " days from today." << endl;
        }
        else if (choice == 2) {
            cin.ignore();
            string title;
            cout << "Enter the title of the book to return: ";
            getline(cin, title);

            bool bookFound = false;
            int returnDate = 0;
            for (size_t i = 0; i < books.size(); i++) {
                if (books[i] == title) {
                    bookFound = true;
                    cout << "Enter the return date (days from due date): ";
                    cin >> returnDate;

                    if (returnDate <= dueDates[i]) {
                        cout << "Book '" << title << "' returned on time. No fines incurred." << endl;
                    }
                    else {
                        int daysLate = returnDate - dueDates[i];
                        int fine = daysLate * finePerDay;
                        cout << "Fine for returning " << daysLate << " days late: $" << fine << endl;
                    }

                    books.erase(books.begin() + i);
                    dueDates.erase(dueDates.begin() + i);
                    break;
                }
            }

            if (!bookFound) {
                cout << "The book is not found or has not been issued." << endl;
            }
        }
        else if (choice == 3) {
            cout << "Exiting the Library System. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

 return 0;
}