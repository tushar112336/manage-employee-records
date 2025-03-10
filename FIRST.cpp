#include<iostream>
#include<fstream>  // For file handling
#include<iomanip>  // For formatted output
using namespace std;

class Employee
{
private:
    string name;
    int ID;
    int age;

public:
    // Function to add employee data to file
    void addData()
    {
        ofstream file("EMPLOYEE.txt",ios::app);  // Open file in write mode
        if (!file)
        {
            cout << "File Does Not Exist" << endl;
        }
        int n;
        cout << "How Many Records You Want To Add: ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Employee ID: ";
            cin >> ID;
            cout << "Enter Age: ";
            cin >> age;
            file << name << " " << ID << " " << age << endl;  // Write data to file
        }
        cout << n << " EMPLOYEE RECORDS ADDED SUCCESSFULLY" << endl;
        file.close();  // Close file
    }

    // Function to modify existing employee data
    void modifyData()
    {
        ifstream file("EMPLOYEE.txt");  // Open file for reading
        if (!file)
        {
            cout << "File Does Not Exist" << endl;
        }
        int idModify;
        bool found = false;
        cout << "Enter ID of Employee You Want To Modify: ";
        cin >> idModify;

        ofstream temp("TEMP.txt");  // Temporary file to store modified data
        while (file >> name >> ID >> age)    // Read file data
        {
            if (ID == idModify)    // If matching ID is found
            {
                cout << "Enter New Name: ";
                cin >> name;
                cout << "Enter New Age: ";
                cin >> age;
                cout << "Enter New Employee ID: ";
                cin >> ID;
                found = true;
            }
            temp << name << " " << ID << " " << age << endl;  // Write to temp file
        }
        file.close();
        temp.close();

        remove("EMPLOYEE.txt");  // Delete old file
        rename("TEMP.txt", "EMPLOYEE.txt");  // Rename temp file to original name

        if (found)
        {
            cout << "Record Updated Successfully" << endl;
        }
        else
        {
            cout << "Record Not Found" << endl;
        }
    }

    // Function to delete employee data
    void deleteData()
    {
        ifstream file("EMPLOYEE.txt");  // Open file for reading
        if (!file)
        {
            cout << "File Does Not Exist" << endl;
        }
        int idDelete;
        bool found = false;
        cout << "Enter ID of Employee You Want To Delete: ";
        cin >> idDelete;

        ofstream temp("TEMP.txt");  // Temporary file to store remaining data
        while (file >> name >> ID >> age)
        {
            if (ID == idDelete)
            {
                found = true;  // Skip writing this record (deleting it)
                continue;
            }
            temp << name << " " << ID << " " << age << endl;
        }
        file.close();
        temp.close();

        remove("EMPLOYEE.txt");  // Delete original file
        rename("TEMP.txt", "EMPLOYEE.txt");  // Rename temp file

        if (found)
        {
            cout << "Record Deleted Successfully" << endl;
        }
        else
        {
            cout << "Record Not Found" << endl;
        }
    }

    // Function to display all employee records
    void displayData()
    {
        ifstream file("EMPLOYEE.txt");  // Open file for reading
        if (!file)
        {
            cout << "File Does Not Exist" << endl;
        }
        cout << "\n--------EMPLOYEE DETAILS---------\n";
        while (file >> name >> ID >> age)
        {
            cout << "Name: " << name << " | ID: " << ID << " | Age: " << age << endl;
        }
        file.close();
    }
};

int main()
{
    Employee e1;
    int choice;
    do
    {
        // Display menu options
        cout << "\nMenu:\n";
        cout << "1. Add Data To Records\n";
        cout << "2. Modify Data To Records\n";
        cout << "3. Delete Data To Records\n";
        cout << "4. Display Data To Records\n";
        cout << "5. EXIT PROGRAM\n";
        cout << "ENTER CHOICE: ";
        cin >> choice;

        // Execute corresponding function based on user input
        switch (choice)
        {
        case 1:
            e1.addData();
            break;
        case 2:
            e1.modifyData();
            break;
        case 3:
            e1.deleteData();
            break;
        case 4:
            e1.displayData();
            break;
        case 5:
            cout << "-------EXITING PROGRAM-------" << endl;
            break;
        default:
            cout << "Enter Valid Choice" << endl;
        }
    }
    while (choice != 5);    // Continue loop until user chooses to exit

    return 0;
}
