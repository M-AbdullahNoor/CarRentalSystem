#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;


const int MAX_CARS = 100;
const int MAX_USERS = 100;


string carNames[MAX_CARS];
int carPrices[MAX_CARS];
int carProfits[MAX_CARS];
bool carAvailability[MAX_CARS];
int totalCars = 0;
int totalProfit = 0;

string usernames[MAX_USERS];
string passwords[MAX_USERS];
string roles[MAX_USERS];
int totalUsers = 0;

string currentUser;
string currentRole;

// Function Prototypes
void loadUsers();
void saveUsers();
void loadCars();
void saveCars();
bool login();
void createAccount();
void changePassword();
void menuAdmin();
void menuWorker();
void menuCustomer();
void addCar();
void editCar();
void viewCars();
void bookCar();
void returnCar();
void searchCar();
void viewStats();
void header();

// Main function
int main() {
    loadUsers();
    loadCars();
     
     while (true)
     {
        system("cls");
        header();
     cout<<"1.Create Account:"<<endl;
     cout<<"2.Login"<<endl;
     cout<<"Select your option :";
     int op;
     cin>>op;
     if(op==1)
     {
         createAccount();
     }
     if(op==2)
     {
    while (true) {
        system("cls");
        header();
        if (login()) {
            if (currentRole == "admin") {
                menuAdmin();
            } else if (currentRole == "worker") {
                menuWorker();
            } else {
                menuCustomer();
            }
        } else {
            cout << "Invalid username or password. Press any key to try again...";
            getch();
        }
    }
     }
     else {
        cout<<"invalid Option Selected.Press any key to Select Again...";
        getch();
     }
     }
    return 0;
}

// Function Definitions

void header() {                                                                                                                      

cout<<"  /$$$$$$   /$$$$$$  /$$$$$$$        /$$$$$$$  /$$$$$$$$ /$$   /$$ /$$$$$$$$ /$$$$$$  /$$       "<<endl;
cout<<" /$$__  $$ /$$__  $$| $$__  $$      | $$__  $$| $$_____/| $$$ | $$|__  $$__//$$__  $$| $$       "<<endl;
cout<<"| $$  \\__/| $$  \\ $$| $$  \\ $$      | $$  \\ $$| $$      | $$$$| $$   | $$  | $$  \\ $$| $$      "<<endl;
cout<<"| $$      | $$$$$$$$| $$$$$$$/      | $$$$$$$/| $$$$$   | $$ $$ $$   | $$  | $$$$$$$$| $$      "<<endl;
cout<<"| $$      | $$__  $$| $$__  $$      | $$__  $$| $$__/   | $$  $$$$   | $$  | $$__  $$| $$      "<<endl;
cout<<"| $$    $$| $$  | $$| $$  \\ $$      | $$  \\ $$| $$      | $$\\  $$$   | $$  | $$  | $$| $$      "<<endl;
cout<<"|  $$$$$$/| $$  | $$| $$  | $$      | $$  | $$| $$$$$$$$| $$ \\  $$   | $$  | $$  | $$| $$$$$$$$"<<endl;
cout<<" \\______/ |__/  |__/|__/  |__/      |__/  |__/|________/|__/  \\__/   |__/  |__/  |__/|________/"<<endl;
cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
                                                                                               
                                                                                               
                                                                                               
                                                                                                                                                                    
}

bool login() {
    system("cls");
    header();
    cout << "Enter Username: ";
    cin >> currentUser;
    cout << "Enter Password: ";
    string pass;
    cin >> pass;

    for (int i = 0; i < totalUsers; i++) {
        if (usernames[i] == currentUser && passwords[i] == pass) {
            currentRole = roles[i];
            return true;
        }
    }
    return false;
}

void createAccount() {
    system("cls");
    header();
    cout << "Enter new username: ";
    cin >> usernames[totalUsers];
    cout << "Enter new password: ";
    cin >> passwords[totalUsers];
    cout << "Enter role (admin/customer/worker): ";
    cin >> roles[totalUsers];
    totalUsers++;
    saveUsers();
    cout << "Account created successfully! Press any key to continue...";

    getch();
    return;
}

void changePassword() {
    system("cls");
    header();
    cout << "Enter new password: ";
    string newPass;
    cin >> newPass;

    for (int i = 0; i < totalUsers; i++) {
        if (usernames[i] == currentUser) {
            passwords[i] = newPass;
            saveUsers();
            cout << "Password changed successfully! Press any key to continue...";
            getch();
            return;
        }
    }
}

void menuAdmin() {
    while (true) {
        system("cls");
        header();
        cout << "1. Add Car\n";
        cout << "2. Edit Car\n";
        cout << "3. View Cars\n";
        cout << "4. Book Car\n";
        cout << "5. Return Car\n";
        cout << "6. View Stats\n";
        cout << "7. Create Account\n";
        cout << "8. Change Password\n";
        cout << "9. Logout\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Clear input buffer
        if (choice == 1) {
            addCar();
        } else if (choice == 2) {
            editCar();
        } else if (choice == 3) {
            viewCars();
        } else if (choice == 4) {
            bookCar();
        } else if (choice == 5) {
            returnCar();
        } else if (choice == 6) {
            viewStats();
        } else if (choice == 7) {
            createAccount();
        } else if (choice == 8) {
            changePassword();
        } else if (choice == 9) {
            return;
        } else {
            cout << "Invalid choice!!";
            getch();
        }
    }
}

void menuWorker() {
    while (true) {
        system("cls");
        header();
        cout << "1. Add Car\n";
        cout << "2. Edit Car\n";
        cout << "3. View Cars\n";
        cout << "4. View Stats\n";
        cout << "5. Create Account\n";
        cout << "6. Change Password\n";
        cout << "7. Logout\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Clear input buffer
        if (choice == 1) {
            addCar();
        } else if (choice == 2) {
            editCar();
        } else if (choice == 3) {
            viewCars();
        } else if (choice == 4) {
            viewStats();
        } else if (choice == 5) {
            createAccount();
        } else if (choice == 6) {
            changePassword();
        } else if (choice == 7) {
            return;
        } else {
            cout << "Invalid choice!!!";
            getch();
        }
    }
}

void menuCustomer() {
    while (true) {
        system("cls");
        header();
        cout << "1. View Cars\n";
        cout << "2. Book Car\n";
        cout << "3. Return Car\n";
        cout << "4. Change Password\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Clear input buffer
        if (choice == 1) {
            viewCars();
        } else if (choice == 2) {
            bookCar();
        } else if (choice == 3) {
            returnCar();
        } else if (choice == 4) {
            changePassword();
        } else if (choice == 5) {
            return;
        }
    }
}

void addCar() {
    system("cls");
    header();
    if (totalCars < MAX_CARS) {
        cout << "Enter Car Name: ";
        getline(cin, carNames[totalCars]);
        cout << "Enter Car Price: ";
        cin >> carPrices[totalCars];
        cout << "Enter Profit per Rent: ";
        cin >> carProfits[totalCars];
        cin.ignore(); // Clear input buffer
        carAvailability[totalCars] = true;
        totalCars++;
        saveCars();
        cout << "Car added successfully! Press any key to continue...";
        getch();
    } else {
        cout << "Car limit reached! Press any key to continue...";
        getch();
    }
}

void editCar() {
    system("cls");
    header();
    cout << "Enter the car number (0 to " << totalCars - 1 << "): ";
    int carIndex;
    cin >> carIndex;
    cin.ignore(); // Clear input buffer

    if (carIndex >= 0 && carIndex < totalCars) {
        cout << "Enter new Car Name: ";
        getline(cin, carNames[carIndex]);
        cout << "Enter new Car Price: ";
        cin >> carPrices[carIndex];
        cout << "Enter new Profit per Rent: ";
        cin >> carProfits[carIndex];
        cin.ignore(); // Clear input buffer
        saveCars();
        cout << "Car updated successfully! Press any key to continue...";
        getch();
    } else {
        cout << "Invalid car number! Press any key to continue...";
        getch();
    }
}

void viewCars() {
    system("cls");
    header();
    cout << "Available Cars:\n";
    for (int i = 0; i < totalCars; i++) {
        if (carAvailability[i]) {
            cout << "Car " << i << ": " << carNames[i] << " - Price: " << carPrices[i] << endl;
        }
    }
    cout << "Press any key to continue...";
    getch();
}

void bookCar() {
    system("cls");
    header();
    cout << "Enter car number to book (0 to " << totalCars - 1 << "): ";
    int carIndex;
    cin >> carIndex;

    if (carIndex >= 0 && carIndex < totalCars && carAvailability[carIndex]) {
        carAvailability[carIndex] = false;
        totalProfit += carProfits[carIndex];
        saveCars();
        cout << "Car booked successfully! Press any key to continue...";
        getch();
    } else {
        cout << "Invalid car number or car is not available! Press any key to continue...";
        getch();
    }
}

void returnCar() {
    system("cls");
    header();
    cout << "Enter car number to return (0 to " << totalCars - 1 << "): ";
    int carIndex;
    cin >> carIndex;

    if (carIndex >= 0 && carIndex < totalCars && !carAvailability[carIndex]) {
        carAvailability[carIndex] = true;
        saveCars();
        cout << "Car returned successfully! Press any key to continue...";
        getch();
    } else {
        cout << "Invalid car number or car is not rented! Press any key to continue...";
        getch();
    }
}

void searchCar() {
    system("cls");
    header();
    cout << "Enter car name to search: ";
    cin.ignore(); 
    string searchName;
    getline(cin, searchName);

    bool found = false;
    for (int i = 0; i < totalCars; i++) {
        if (carNames[i] == searchName) {
            cout << "Car " << i << ": " << carNames[i] << " - Price: " << carPrices[i] << " - Profit: " << carProfits[i] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Car not found! Press any key to continue...";
    } else {
        cout << "Press any key to continue...";
    }
    getch();
}

void viewStats() {
    system("cls");
    header();
    cout << "Total Profit: " << totalProfit << endl;
    cout << "Total Cars Rented: " << endl;
    int rentedCars = 0;
    for (int i = 0; i < totalCars; i++) {
        if (!carAvailability[i]) rentedCars++;
    }
    cout << rentedCars << endl;
    cout << "Press any key to continue...";
    getch();
}



void loadUsers() {
    ifstream file("users.txt");
    while (file >> usernames[totalUsers] >> passwords[totalUsers] >> roles[totalUsers]) {
        totalUsers++;
    }
    file.close();
}

void saveUsers() {
    ofstream file("users.txt");
    for (int i = 0; i < totalUsers; i++) {
        file << usernames[i] << " " << passwords[i] << " " << roles[i] << endl;
    }
    file.close();
}

void loadCars() {
    ifstream file("cars.txt");
    while (getline(file, carNames[totalCars])) {
        file >> carPrices[totalCars] >> carProfits[totalCars] >> carAvailability[totalCars];
        file.ignore(); 
        totalCars++;
    }
    file.close();
}

void saveCars() {
    ofstream file("cars.txt");
    for (int i = 0; i < totalCars; i++) {
        file << carNames[i] << endl;
        file << carPrices[i] << " " << carProfits[i] << " " << carAvailability[i] << endl;
    }
    file.close();
}
