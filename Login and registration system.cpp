#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function for Registration
void registerUser()
{
    string username, password;

    cout << "\n===== USER REGISTRATION =====\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "\nRegistration Successful!\n";
}

// Function for Login
void loginUser()
{
    string username, password;
    string storedUser, storedPass;
    bool found = false;

    cout << "\n===== USER LOGIN =====\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> storedUser >> storedPass)
    {
        if (username == storedUser && password == storedPass)
        {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "\nLogin Successful! Welcome, " << username << "!\n";
    else
        cout << "\nInvalid Username or Password!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n================================";
        cout << "\n LOGIN AND REGISTRATION SYSTEM";
        cout << "\n================================";
        cout << "\n1. Register";
        cout << "\n2. Login";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "\nThank You for Using the System!\n";
            break;

        default:
            cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 3);

    return 0;
}
