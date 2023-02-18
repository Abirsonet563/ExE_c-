#include<iostream>
#include<memory>

using namespace std;

struct Student {
    string name;
    string rollno;
    string course;
    string studentClass;
    string contact;
    shared_ptr<Student> next;
};

shared_ptr<Student> head = nullptr;

void enter() {
    int ch = 0;
    cout << "How many students do you want to enter?" << endl;
    cin >> ch;

    for (int i = 0; i < ch; i++) {
        auto newStudent = make_shared<Student>();
        cout << "\nEnter the data of student " << i+1 << endl << endl;
        cout << "Enter name: ";
        cin >> newStudent->name;
        cout << "Enter Roll no: ";
        cin >> newStudent->rollno;
        cout << "Enter course: ";
        cin >> newStudent->course;
        cout << "Enter class: ";
        cin >> newStudent->studentClass;
        cout << "Enter contact: ";
        cin >> newStudent->contact;

        // add the new student to the end of the list
        if (head == nullptr) {
            head = newStudent;
        } else {
            auto current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newStudent;
        }
    }
}

void show() {
    if (head == nullptr) {
        cout << "No data is entered" << endl;
    } else {
        auto current = head;
        int i = 0;
        while (current != nullptr) {
            cout << "\nData of Student " << ++i << endl << endl;
            cout << "Name: " << current->name << endl;
            cout << "Roll no: " << current->rollno << endl;
            cout << "Course: " << current->course << endl;
            cout << "Class: " << current->studentClass << endl;
            cout << "Contact: " << current->contact << endl;
            current = current->next;
        }
    }
}

void search() {
    if (head == nullptr) {
        cout << "No data is entered" << endl;
    } else {
        string rollno;
        cout << "Enter the roll no of student: " << endl;
        cin >> rollno;
        auto current = head;
        while (current != nullptr) {
            if (current->rollno == rollno) {
                cout << "Name: " << current->name << endl;
                cout << "Roll no: " << current->rollno << endl;
                cout << "Course: " << current->course << endl;
                cout << "Class: " << current->studentClass << endl;
                cout << "Contact: " << current->contact << endl;
                return;
            }
            current = current->next;
        }
        cout << "No student with the given roll no found." << endl;
    }
}

void update() {
    if (head == nullptr) {
        cout << "No data is entered" << endl;
    } else {
        string rollno;
        cout << "Enter the roll no of student which you want to update" << endl;
        cin >> rollno;

        auto current = head;
        while (current != nullptr) {
            if (current->rollno == rollno) {
                cout << "\nPrevious data" << endl << endl;
                cout << "Data of Student" << endl;
                cout << "Name: " << current->name << endl;
                cout << "Roll no: " << current->rollno << endl;
                cout << "Course: " << current->course << endl;
                cout << "Class: " << current->studentClass << endl;
                cout << "Contact: " << current->contact << endl;

                cout << "\nEnter new data" << endl << endl;
                cout << "Enter name: ";
                cin >> current->name;
                cout << "Enter Roll no: ";
                cin >> current->rollno;
                cout << "Enter course: ";
                cin >> current->course;
                cout << "Enter class: ";
                cin >> current->studentClass;
                cout << "Enter contact: ";
                cin >> current->contact;

                break;
            }
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Student with roll no " << rollno << " not found." << endl;
        }
    }
}

void deleterecord() {
    if (head == nullptr) {
        cout << "No data is entered" << endl;
        return;
    }

    int a;
    cout << "Press 1 to delete all record" << endl;
    cout << "Press 2 to delete specific record" << endl;
    cin >> a;

    if (a == 1) {
        head = nullptr;
        cout << "All record is deleted..!!" << endl;
    } else if (a == 2) {
        string rollno;
        cout << "Enter the roll no of student which you want to delete" << endl;
        cin >> rollno;

        if (head->rollno == rollno) {
            head = head->next;
            cout << "Your required record is deleted" << endl;
            return;
        }

        auto current = head;
        while (current->next != nullptr) {
            if (current->next->rollno == rollno) {
                auto toDelete = current->next;
                current->next = toDelete->next;
                cout << "Your required record is deleted" << endl;
                return;
            }
            current = current->next;
        }

        cout << "Record not found" << endl;
    } else {
        cout << "Invalid input" << endl;
    }
}


main()

{

	int value;

	while(true)

	{

	cout<<"\nPress 1 to enter data"<<endl;

	cout<<"Press 2 to show data"<<endl;

	cout<<"Press 3 to search data"<<endl;

	cout<<"Press 4 to update data"<<endl;

	cout<<"Press 5 to delete data"<<endl;

	cout<<"Press 6 to exit"<<endl;

	cin>>value;

	switch(value)

	{

		case 1:

			enter();

			break;

		case 2:

			show();

			break;

		case 3:

			search();

			break;

		case 4:

			update();

			break;

		case 5:

		deleterecord();

			break;

		case 6:

			exit(0);

			break;

		default:

			cout<<"Invalid input"<<endl;

			break;
				system("pause");

	}

}

}