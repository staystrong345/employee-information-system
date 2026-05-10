
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>  // Added for tolower
using namespace std;

struct Employee {
    string name;
    string id;
    string department;
    double salary;
    double tax;
    double netPay;
};

// convert string to lowercase.When people search by name, it should work for both lowercase and capital letters
string toLower(const string& str) {
    string result = str;
    for (char& c : result) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return result;
}

double calculateTax(double salary) {
    if (salary >= 10500) return salary * 0.35;
    if (salary >= 8500)  return salary * 0.30;
    if (salary >= 6500)  return salary * 0.25;
    if (salary >= 4500)  return salary * 0.20;
    if (salary >= 2500)  return salary * 0.15;
    if (salary >= 1000)  return salary * 0.10;
    return 0.0;
}

void recordStaff(vector<Employee>& staff) {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    cin.ignore(); // Clear newline after numeric input

    for (int i = 0; i < n; i++) {
        Employee emp;
        cout << "\nEnter details for employee " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, emp.name);
        cout << "ID: ";
        getline(cin, emp.id);
        cout << "Department: ";
        getline(cin, emp.department);
        cout << "Salary: ";
        cin >> emp.salary;
        cin.ignore(); // Clear newline

        emp.tax = calculateTax(emp.salary);
        emp.netPay = emp.salary - emp.tax;
        staff.push_back(emp);
    }
}

void displayEmployee(const Employee& emp) {
     cout << "**********************************************************************\n";
    cout << "                Addis Ababa Science and Technology University\n";
    cout << "                         Employee Information\n";
    cout << "**********************************************************************\n";
    cout << left << setw(15) << "Name"
         << setw(12) << "ID"
         << setw(12) << "Salary"
         << setw(12) << "Tax"
         << setw(12) << "Net Pay" << "\n";
    cout << "-----------------------------------------------------------------\n";
    
    cout << left << setw(15) << emp.name
         << setw(12) << emp.id
         << setw(12) << static_cast<int>(emp.salary)
         << setw(12) << static_cast<int>(emp.tax)
         << setw(12) << static_cast<int>(emp.netPay) << "\n";
}

void displayAllStaff(const vector<Employee>& staff) {
    if (staff.empty()) {
        cout << "No employees to display.\n";
        return;
    }

    cout << "**********************************************************************\n";
    cout << "                Addis Ababa Science and Technology University\n";
    cout << "                         Employee Information\n";
        cout << "**********************************************************************\n";
    cout << left << setw(15) << "Name"
         << setw(12) << "ID"
         << setw(12) << "Salary"
         << setw(12) << "Tax"
         << setw(12) << "Net Pay" << "\n";
    cout << "-----------------------------------------------------------------\n";

    for (const auto& emp : staff) {
        cout << left << setw(15) << emp.name
             << setw(12) << emp.id
             << setw(12) << static_cast<int>(emp.salary)
             << setw(12) << static_cast<int>(emp.tax)
             << setw(12) << static_cast<int>(emp.netPay) << "\n";
    }
}

void searchStaff(const vector<Employee>& staff) {
    if (staff.empty()) {
        cout << "No employees recorded.\n";
        return;
    }

    string query;
    cout << "Enter employee name or ID to search: ";
    getline(cin, query);

    if (query.empty()) {
        cout << "Search input cannot be empty.\n";
        return;
    }

    string lowerQuery = toLower(query);
    bool found = false;

    for (const auto& emp : staff) {
        // Exact match for ID (case-sensitive)
        if (emp.id == query) {
            displayEmployee(emp);
            found = true;
            break;
        }
        // Case-insensitive match for name
        if (toLower(emp.name) == lowerQuery) {
            displayEmployee(emp);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee not found.\n";
    }
}

int main() {
    vector<Employee> staff;
    int choice;

    do {
        cout << "\n=== AASTU EMPLOYEE INFORMATION SYSTEM ===\n";
        cout << "1. Record Staff\n";
        cout << "2. Display All Staff\n";
        cout << "3. Search Staff\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // Clear newline after numeric input

        switch (choice) {
            case 1:
                recordStaff(staff);
                break;
            case 2:
                displayAllStaff(staff);
                break;
            case 3:
                searchStaff(staff);
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}