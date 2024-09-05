#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void countdown(int minutes) {
    int totalSeconds = minutes * 60;  // Convert minutes to seconds
    for (int i = totalSeconds; i >= 0; --i) {
        int displayMinutes = i / 60;  // Get the remaining minutes
        int displaySeconds = i % 60;  // Get the remaining seconds
        cout << "\rTime remaining: " << displayMinutes << " minutes "
                  << displaySeconds << " seconds " << flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Wait for 1 second
    }
    cout << "\nTime's up!" << endl;
}

int main() {
    int focusTime = 25;  // Focus duration in minutes
    int shortBreak = 5;  // Short break duration in minutes
    int longBreak = 15;  // Long break duration in minutes
    char choice;

    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Focus (25 minutes)" << endl;
        cout << "2. Short Break (5 minutes)" << endl;
        cout << "3. Long Break (15 minutes)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "\nFocus time for " << focusTime << " minutes." << endl;
                countdown(focusTime);
                break;

            case '2':
                cout << "\nTaking a short break for " << shortBreak << " minutes." << endl;
                countdown(shortBreak);
                break;

            case '3':
                cout << "\nTaking a long break for " << longBreak << " minutes." << endl;
                countdown(longBreak);
                break;

            case '4':
                cout << "\nExiting Pomodoro Timer. Goodbye!" << endl;
                break;

            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }

    } while (choice != '4');

    return 0;
}
