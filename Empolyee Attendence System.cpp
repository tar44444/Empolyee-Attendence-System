#include <iostream>
#include <cstring>

using namespace std;

class Employee
{
private:
    int eid;
    char *ename;
    char *designation;
    char *phone;

public:
    Employee()
    {
        eid = 0;
        ename = NULL;
        designation = NULL;
        phone = NULL;
    }

    Employee(int id, char *en, char *desig, char *ph)
    {
        eid = id;
        ename = new char[strlen(en) + 1];
        strcpy(ename, en);
        designation = new char[strlen(desig) + 1];
        strcpy(designation, desig);
        phone = new char[strlen(ph) + 1];
        strcpy(phone, ph);
    }

    void insert()
    {
    	cout << "---------------------------" << endl;
        cout << "Enter Employee ID:";
        cin >> eid;
        cout << "Enter Employee Name:";
        char en[30];
        cin >> en;
        ename = new char[strlen(en) + 1];
        strcpy(ename, en);
        cout << "Enter Designation:";
        char desig[30];
        cin >> desig;
        designation = new char[strlen(desig) + 1];
        strcpy(designation, desig);
        cout << "Enter Phone:";
        char ph[20];
        cin >> ph;
        phone = new char[strlen(ph) + 1];
        strcpy(phone, ph);
        cout << "Record Inserted Successfully!" << endl;
        cout << "---------------------------" << endl;
    }

    void setEid(int id)
    {
        eid = id;
    }

    void setEname(char en[])
    {
        ename = new char[strlen(en) + 1];
        strcpy(ename, en);
    }

    void setDesignation(char desig[])
    {
        designation = new char[strlen(desig) + 1];
        strcpy(designation, desig);
    }

    void setPhone(char ph[])
    {
        phone = new char[strlen(ph) + 1];
        strcpy(phone, ph);
    }

    int getEid()
    {
        return eid;
    }

    char *getEname()
    {
        return ename;
    }

    char *getDesignation()
    {
        return designation;
    }

    char *getPhone()
    {
        return phone;
    }

    void update(int tid)
    {
        if (eid == tid)
        {
        	cout << "---------------------------" << endl;
            cout << "Enter New Employee Name: ";
            char en[30];
            cin >> en;
            ename = new char[strlen(en) + 1];
            strcpy(ename, en);
            cout << "Enter New Designation: ";
            char desig[30];
            cin >> desig;
            designation = new char[strlen(desig) + 1];
            strcpy(designation, desig);
            cout << "Enter New Phone: ";
            char ph[20];
            cin >> ph;
            phone = new char[strlen(ph) + 1];
            strcpy(phone, ph);
            cout << "Record Updated Successfully!";
            cout << "---------------------------" << endl;
        }
        else
        {
            cout << "Employee ID not found for updating.";
        }
    }

    void display()
    {cout << "---------------------------" << endl;
        cout << "Employee ID: " << getEid() << endl;
        cout << "Employee Name: " << getEname() << endl;
        cout << "Designation: " << getDesignation() << endl;
        cout << "Phone: " << getPhone() << endl;
        cout << "---------------------------" << endl;
    }

    void displayRecord(int tid)
    {
        if (eid == tid)
        {
            display();
        }
        else
        {
            cout << "Employee ID not found for display.";
        }
    }

    ~Employee()
    {
        delete[] ename;
        delete[] designation;
        delete[] phone;
    }
};

class Attendance
{
    int eid;
    int day;
    int month;
    int status;

public:
    Attendance()
    {
        eid = 0;
        day = 0;
        month = 0;
        status = 0;
    }

    Attendance(int Id, int d, int m, int s)
    {
        eid = Id;
        day = d;
        month = m;
        status = s;
    }

    void setEid(int Id)
    {
        eid = Id;
    }

    void setDay(int d)
    {
        if (d >= 1 && d <= 31)
        {
            day = d;
        }
        else
        {
            cout << "Please enter a valid day.";
        }
    }

    void setMonth(int m)
    {
        if (m >= 1 && m <= 12)
        {
            month = m;
        }
        else
        {
            cout << "Please enter a valid month.";
        }
        cout << "---------------------------" << endl;
    }
    

    void setStatus(int s)
    
    {
    	
        if (s == 0 || s == 1)
        {
        	cout << "Enter New Attendance Status (0 for absent, 1 for present): ";
            status = s;
        }
        else
        {
            cout << "Please enter 0 for absent and 1 for present  status.";
        }
        cout << "---------------------------" << endl;
    }

    int getEid()
    {
        return eid;
    }

    int getDay()
    {
        return day;
    }

    int getMonth()
    {
        return month;
    }

    int getStatus()
    {
        return status;
    }

    void insert()
    {
    	cout << "---------------------------" << endl;
        cout << "Enter the eid:";
        cin >> eid;
        cout << "Enter the day:";
        cin >> day;
        cout << "Enter the month:";
        cin >> month;
        cout << "Enter the status(0 for absent, 1 for present):";
        
        cin >> status;
        cout << "---------------------------" << endl;
    }

    void display()
    {
    	cout << "---------------------------" << endl;
        cout << "The attendance of eid is:" << getEid() << endl;
        cout << "The day is:" << getDay() << endl;
        cout << "The month is:" << getMonth() << endl;
        cout << "The status is:" << getStatus() << endl;
        cout << "---------------------------" << endl;
    }
};

int main()
{
    int empCount = 0;
    int attendanceCount = 0;
    Employee *employees[100];
    Attendance *attendanceRecords[100];

    while (true)
    {
                 cout << "-----------Main Menu---------" << endl;
	  
		cout << "1. Add Employee" << endl;
        cout << "2. Display record of an Employee" << endl;
        cout << "3. Display All Employees" << endl;
        cout << "4. Delete record of a Employee" << endl;
        
        cout << "5. Mark Attendance" << endl;
        cout << "6. Update Attendance Status" << endl;
        cout << "7. Delete Record for attendance" << endl;
        cout << "8. Display All Attendance Records" << endl;
        cout << "9. Display Record of attendance of an Employee for given month" << endl;
        cout << "10. Display Record of attendance for given month" << endl;
        cout << "0. Exit" << endl;
        cout << "---------------------------" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            employees[empCount] = new Employee();
            employees[empCount]->insert();
            empCount++;
            break;
            
        case 2:
            int empId; 
            cout << "---------------------------" << endl;
            cout << "Enter Employee ID to display record: ";
            cin >> empId;
            for (int i = 0; i < empCount; i++)
            {
                if (employees[i]->getEid() == empId)
                {
                    employees[i]->display();
                    break;
                    cout << "---------------------------" << endl;
                }
            }
            break;

        case 3:
            for (int i = 0; i < empCount; i++)
            {
                employees[i]->display();
            }
            break;

        case 4:
        	cout << "---------------------------" << endl;
            cout << "Enter Employee ID to delete record: ";
            int delId;
            cin >> delId;
            for (int i = 0; i < empCount; i++)
            {
                if (employees[i]->getEid() == delId)
                {
                    delete employees[i];
                    for (int j = i; j < empCount - 1; j++)
                    {
                        employees[j] = employees[j + 1];
                    }
                    empCount--;
                    cout << "Record deleted successfully!" << endl;
                    break;
                    cout << "---------------------------" << endl;
                }
                
            }
            break;

        case 5:
            attendanceRecords[attendanceCount] = new Attendance();
            attendanceRecords[attendanceCount]->insert();
            attendanceCount++;
            break;

        case 6:
            int empIdToUpdate;
            cout << "---------------------------" << endl;
            cout << "Enter Employee ID to update attendance: ";
            cin >> empIdToUpdate;

            for (int i = 0; i < attendanceCount; i++)
            {
                if (attendanceRecords[i]->getEid() == empIdToUpdate)
                {
                    cout << "Enter New Attendance Status (0 for absent, 1 for present): ";
                    int newStatus;
                    cin >> newStatus;
                    attendanceRecords[i]->setStatus(newStatus);
                    cout << "Attendance Status Updated Successfully!" << endl;
                    break;
                    cout << "---------------------------" << endl;
                }
            }
            break;
 
        case 7:
        	cout << "---------------------------" << endl;
            cout << "Enter Employee ID to delete attendance record: ";
            int delAttId;
            cin >> delAttId;
            for (int i = 0; i < attendanceCount; i++)
            {
                if (attendanceRecords[i]->getEid() == delAttId)
                {
                    delete attendanceRecords[i];
                    for (int j = i; j < attendanceCount - 1; j++)
                    {
                        attendanceRecords[j] = attendanceRecords[j + 1];
                    }
                    attendanceCount--;
                    cout << "Attendance record deleted successfully!" << endl;
                    break;
                    cout << "---------------------------" << endl;
                }
            }
            break;

        case 8:
            for (int i = 0; i < attendanceCount; i++)
            {
                attendanceRecords[i]->display();
            }
            break;
        
        case 9:
        	cout << "---------------------------" << endl;
            cout << "Enter Employee ID to display record of attendance for given month: ";
            int empIdMonth;
            cin >> empIdMonth;
            cout << "Enter Month: ";
            int monthEmp;
            cin >> monthEmp;
            for (int i = 0; i < attendanceCount; i++)
            {
                if (attendanceRecords[i]->getEid() == empIdMonth && attendanceRecords[i]->getMonth() == monthEmp)
                {
                    attendanceRecords[i]->display();
                }
                cout << "---------------------------" << endl;
            }
            break;

        case 10:
        	cout << "---------------------------" << endl;
            cout << "Enter Month to display record of attendance for given month: ";
            int monthToDisplay;
            cin >> monthToDisplay;
            for (int i = 0; i < attendanceCount; i++)
            {
                if (attendanceRecords[i]->getMonth() == monthToDisplay)
                {
                    attendanceRecords[i]->display();
                }
                cout << "---------------------------" << endl;
            }
            break;

        case 0:
            for (int i = 0; i < empCount; i++)
            {
                delete employees[i];
            }

            for (int i = 0; i < attendanceCount; i++)
            {
                delete attendanceRecords[i];
            }

            cout << "Exiting the program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
    }

    return 0;
}


