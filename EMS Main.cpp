#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

string full_data;
int salary;

const int MAX_EMPLOYEES = 30; //Maximum number of employees that can be managed 

//Arrays to store Employees Information
string emp_id[MAX_EMPLOYEES], emp_name[MAX_EMPLOYEES], emp_address[MAX_EMPLOYEES];
string emp_dob[MAX_EMPLOYEES], emp_doj[MAX_EMPLOYEES], emp_department[MAX_EMPLOYEES];
string emp_location[MAX_EMPLOYEES], emp_social_insurance[MAX_EMPLOYEES], emp_email[MAX_EMPLOYEES];

int emp_hours_worked[MAX_EMPLOYEES]; //Array to store hours worked by the employees

int total_employees = 0; //Tracks the total number of employees

//Salary rates per hour based on department
const int SOFTWARE_ENGINEERING_RATE = 22;
const int MARKETING_RATE = 18;
const int UX_RATE = 20;
const int HR_RATE = 17;
const int FINANCE_RATE = 24;

//Function to display the Welcome Banner
void displayBanner() {
    cout << "*********************************************" << endl;
    cout << "*                                           *" << endl;
    cout << "*      WELCOME TO THE EMPLOYEE SYSTEM       *" << endl;
    cout << "*                                           *" << endl;
    cout << "*********************************************" << endl;
}

//Function to display the main menu
void displayMenu() {
    cout << "\n--- Employee Management System Menu ---" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Display All Employees" << endl;
    cout << "3. Search Employee by ID" << endl;
    cout << "4. Update Employee Data" << endl;
    cout << "5. Delete All Employees" << endl;
    cout << "6. Calculate and Display Salaries" << endl;
    cout << "7. Calculate Salary by Employee ID" << endl;
    cout << "0. Exit" << endl;
}
//Function to add an Employee
int calculateSalary(const string& department, int hoursWorked) {
    int rate = 0;
    if (department == "Software Engineering") {
        rate = SOFTWARE_ENGINEERING_RATE;
    }
    else if (department == "Marketing") {
        rate = MARKETING_RATE;
    }
    else if (department == "UX") {
        rate = UX_RATE;
    }
    else if (department == "HR") {
        rate = HR_RATE;
    }
    else if (department == "Finance") {
        rate = FINANCE_RATE;
    }
    return rate * hoursWorked;

}
void addEmployee() {

    ifstream dat("employee data.txt");

    int num_employees;
    cout << "\nEnter the number of employees you want to add: ";
    cin >> num_employees;

    for (int i = total_employees; i < num_employees + total_employees; i++) {
        cout << "\n--- Enter the Details for Employee " << i + 1 << " ---" << endl;

        ofstream dat("employee data.txt", std::ios::app);

        cout << "Name: ";
        cin >> emp_name[i];

        dat << "Name: " << emp_name[i] << '\n';

        cout << "Address: ";
        cin >> emp_address[i];

        dat << "Address: " << emp_address[i] << '\n';

        cout << "Date of Birth (dd/mm/yyyy): ";
        cin >> emp_dob[i];

        dat << "Date of Birth (dd/mm/yyyy): " << emp_dob[i] << '\n';

        cout << "Employee ID: ";
        cin >> emp_id[i];

        dat << "Employee ID: " << emp_id[i] << '\n';

        cout << "Date of Joining (dd/mm/yyyy): ";
        cin >> emp_doj[i];

        dat << "Date of joining (dd/mm/yyyy): " << emp_doj[i] << '\n';

        cout << "Department(Software Engineering, Marketing, UX, HR or Finance): ";
        cin >> emp_department[i];

        dat << "Department: " << emp_department[i] << '\n';

        cout << "Work Location: ";
        cin >> emp_location[i];

        dat << "Work Location: " << emp_location[i] << '\n';

        cout << "Social Insurance Number: ";
        cin >> emp_social_insurance[i];

        dat << "Social Insurance Number: " << emp_social_insurance[i] << '\n';

        cout << "Email: ";
        cin >> emp_email[i];

        dat << "Email: " << emp_email[i] << '\n';

        cout << "Hours Worked: ";
        cin >> emp_hours_worked[i];

        dat << "Hours Worked: " << emp_hours_worked[i] << '\n';

        //Display Salary Information
        salary = calculateSalary(emp_department[i], emp_hours_worked[i]);

        dat << "Salary: " << salary << '\n' << '\n';
    }

    // Update the total number of employees
    total_employees += num_employees;

}

//Function to calculate Salary based on department and hours worked

//Function to display all Employees
void displayEmployees() {
    string line;
    ifstream dat("employee data.txt"); //Opening a File
    while (getline(dat, line))
    {
        full_data += line + "\n";
    }
    cout << full_data;
}
//Function to search and Employee by their ID
void searchEmployee() {
    if (total_employees == 0) {  // Check if there are employees to search
        cout << "No data available to search." << endl;
    }
    else {
        string search_id;
        cout << "Enter the Employee ID to search: ";
        cin >> search_id;

        for (int i = 0; i < total_employees; i++) {
            if (search_id == emp_id[i]) {

                cout << "\n--- Details for Employee ID: " << search_id << " ---" << endl;
                cout << "Name:" << emp_name[i] << endl;
                cout << "Address:" << emp_address[i] << endl;
                cout << "Date of Birth:" << emp_dob[i] << endl;

                cout << "\n** Work Details **" << endl;
                cout << "Employee ID:" << emp_id[i] << endl;
                cout << "Date of Joining:" << emp_doj[i] << endl;
                cout << "Department:" << emp_department[i] << endl;
                cout << "Work Location:" << emp_location[i] << endl;
                cout << "Social Insurance Number:" << emp_social_insurance[i] << endl;
                cout << "Hours Worked:" << emp_hours_worked[i] << endl;

                int salary = calculateSalary(emp_department[i], emp_hours_worked[i]);
                cout << "Salary: $" << salary << endl;

                cout << "\n** Contact Information **" << endl;
                cout << "Email: " << emp_email[i] << endl;
                return;
            }
        }
        cout << "Employee with ID " << search_id << " not found." << endl;
    }
}

//Function to update an Employee's Details
void updateEmployee() {
    if (total_employees == 0) {  // Check if there are employees to update
        cout << "No data available to update." << endl;
    }
    else {
        string update_id;
        cout << "Enter the Employee ID to update: ";
        cin >> update_id;

        for (int i = 0; i < total_employees; i++) {
            if (update_id == emp_id[i]) {
                cout << "\n--- Previous Data for Employee " << i + 1 << " ---" << endl;

                cout << "Name:" << emp_name[i] << endl;
                cout << "Address:" << emp_address[i] << endl;
                cout << "Date of Birth:" << emp_dob[i] << endl;

                cout << "\n** Enter New Data **" << endl;
                cout << "Name: ";
                cin >> emp_name[i];

                cout << "Address: ";
                cin >> emp_address[i];

                cout << "Date of Birth (dd/mm/yyyy): ";
                cin >> emp_dob[i];

                cout << "Employee ID: ";
                cin >> emp_id[i];

                cout << "Date of Joining (dd/mm/yyyy): ";
                cin >> emp_doj[i];

                cout << "Department: ";
                cin >> emp_department[i];

                cout << "Work Location: ";
                cin >> emp_location[i];

                cout << "Social Insurance Number: ";
                cin >> emp_social_insurance[i];

                cout << "Email: ";
                cin >> emp_email[i];

                cout << "Hours Worked: ";
                cin >> emp_hours_worked[i];

                return;
            }
        }
        cout << "Employee with ID " << update_id << " not found." << endl;
    }
}
//Function to delete all Employees Records 
void deleteEmployee() {
    if (total_employees == 0) {  // Check if there are employees to delete
        cout << "No data available to delete." << endl;
    }
    else {
        int confirmation;
        cout << "Are you sure you want to delete all employee data? (1 for Yes, 0 for No): ";
        cin >> confirmation;

        if (confirmation == 1) {
            total_employees = 0;
            cout << "All employee data has been deleted." << endl;
        }
        else {
            cout << "Deletion cancelled." << endl;
        }
    }
}

// Function to calculate and display salaries for all employees
void calculateAndDisplaySalaries() {
    if (total_employees == 0) {  // Check if there are employees to calculate salary
        cout << "No data available to calculate salary." << endl;
    }
    else {
        for (int i = 0; i < total_employees; i++) {
            int salary = calculateSalary(emp_department[i], emp_hours_worked[i]);
            cout << "\n--- Salary Details for Employee " << i + 1 << " ---" << endl;

            cout << "Name: " << emp_name[i] << endl;
            cout << "Department: " << emp_department[i] << endl;
            cout << "Hours Worked: " << emp_hours_worked[i] << endl;
            cout << "Salary: $" << salary << endl;
        }
    }
}

//Function to calculate Employee salary by thier ID 
void calculateSalaryByID() {
    if (total_employees == 0) {  // Check if there are employees to calculate salary
        cout << "No data available to calculate salary." << endl;
    }
    else {
        string search_id;
        cout << "Enter the Employee ID to calculate salary: ";
        cin >> search_id;

        // Loop to find the employee with the given ID
        for (int i = 0; i < total_employees; i++) {
            if (search_id == emp_id[i]) {  // If employee ID matches
                int salary = calculateSalary(emp_department[i], emp_hours_worked[i]);
                cout << "\n--- Salary Details for Employee ID: " << search_id << " ---" << endl;
                cout << "Name: " << emp_name[i] << endl;
                cout << "Department: " << emp_department[i] << endl;
                cout << "Hours Worked: " << emp_hours_worked[i] << endl;
                cout << "Salary: $" << salary << endl;
                return;
            }
        }
        cout << "Employee with ID " << search_id << " not found." << endl;
    }
}

//Main Function to display the menu and call the corresponding Function
int main() {
    int option;

    displayBanner();

    do {
        displayMenu();
        cout << "Please Select an Option:" << endl;
        cin >> option;

        switch (option) {
        case 1:
            addEmployee();
            break;
        case 2:
            displayEmployees();
            break;
        case 3:
            searchEmployee();
            break;
        case 4:
            updateEmployee();
            break;
        case 5:
            deleteEmployee();
            break;
        case 6:
            calculateAndDisplaySalaries();
            break;
        case 7:
            calculateSalaryByID();
            break;
        case 0:
            cout << "Exiting the system. Goodbye!" << endl;
            exit(0);
            break;
        default:
            cout << "Invalid selection. Please try again." << endl;
            break;
        }
    } while (option != 0);

    return 0;
}