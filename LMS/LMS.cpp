/*//////////////////////////////////////Credits///////////////////////////////////////////////////////////////////////////////
                                    LEARNING MANAGEMENT SYSTEM
                           DEVELEPED BY:
                                            GROUP 06
                                    WAQAS AHMAD     (20021519-029)
                                    USAMA RAFAQAT   (20021519-047)
                                    HASSAN TAHIR    (20021519-083)
                                    MUHAMMAD DAUD   (20021519-148)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
using namespace std;

//////////////////////////////////////Miscellanious Functions//////////////////////////////////////////////////////////////
int markMyAttendance(string username)
{
    ofstream fout;
    string temp = username + ".dat";
    fout.open(temp.c_str(), ios::app);
    int op;
    cout << "\t\tEnter 1 to mark as Present or 2 to mark as Absent: \n\t\t";
    cin >> op;
    while (cin.fail())
    {
        cout << "\t\tError!!" << endl;
        cout << "\t\tEnter 1 to mark as Present or 2 to mark as Absent: \n\t\t";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> op;
    }
    switch (op)
    {
    case 1:
        fout << "P\n";
        break;

    case 2:
        fout << "A\n";
        break;

    default:
        cout << "\t\tInvalid Option!!\n";
        system("PAUSE");
        system("CLS");
        break;
    }

    cout << "\t\t Your Attendance has been marked for today !!\n";
    return 0;
}
int countMyAttendance(string username)
{
    ifstream fin;
    string temp = username + ".dat";
    fin.open(temp.c_str());
    if (fin)
    {
        int presenceCount = 0;
        int absenceCount = 0;
        string line;
        while (getline(fin, line))
        {
            if (line == "P")
                presenceCount++;

            if (line == "A")
                absenceCount++;
        }
        int total;
        total = presenceCount + absenceCount;
        cout << "\t\tYour attendace count is " << total << endl;
        int per;
        per = presenceCount / total;
        per = per * 100;
        cout << "\t\tYour Attendance Percentage is: " << per << "% \n";
        return 0;
    }
    if (fin.fail()) // check for file open failure
    {
        cout << "No Record Found" << endl;
    }
    else if (fin.peek() == std::ifstream::traits_type::eof())
    {
        cout << "No Record Found\n";
    }
    fin.close();
    return 0;
}
bool check_number(int no)
{
    if (no <= 0)
        return false;
    return true;
}
bool checkString(string s)
{
    if (!s.empty())
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] == ' ')))
            {
                return true;
            }
        }
    }
    return false;
}
bool checkCNIC(string s)
{
    if (!s.empty())
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (!((s[i] >= '0' && s[i] <= '9') || (s[i] == '-') && (s[5] == '-') && (s[13] == '-') && (s.length() == 15)))
            {
                return true;
            }
        }
    }
    return false;
}
bool check_studentAge(int age)
{
    if (age > 18 && age < 30)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool check_teacherAge(int age)
{
    if (age > 25 && age < 50)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool check_Choice(int a)
{
    if (a >= 1 && a <= 3)
    {
        return false;
    }
    else
    {
        return true;
    }
}
string gender_Choice(int a)
{
    string gender;
    while (check_Choice(a))
    {
        if (a == 1)
        {
            gender = "Male";
            return gender;
        }
        else if (a == 2)
        {
            gender = "Female";
            return gender;
        }
        else if (a == 3)
        {
            gender = "Others";
            return gender;
        }
        else
        {
            gender = "Empty";
            return gender;
        }
    }
    return gender;
}
bool check_rollNO(string s)
{
    if (!s.empty())
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (!((s.at(i) >= '1' && s.at(i) <= '9') || s.at(i) == '-') && (s[8] == '-') && (s.length() == 12))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
char section_Choice(char a)
{
    char section;
    if (a == 1)
    {
        section = 'A';
        return section;
    }
    else if (a == 2)
    {
        section = 'B';
        return section;
    }
    else if (a == 3)
    {
        section = 'C';
        return section;
    }
    return section;
}
bool check_Group(int a)
{
    if (a > 0 && a < 10)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool check_Semester(int a)
{
    if (a > 0 && a <= 8)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool check_CGPA(double a)
{
    if (a >= 0 & a <= 4)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool check_CNIC(string s)
{
    if (!s.empty())
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (!((s.at(i) >= '0' && s.at(i) <= '9') || s.at(i) == '-'))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
bool check_ID(string s)
{
    if (!s.empty())
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (!((s.at(i) >= 'a' && s.at(i) <= 'z') || (s.at(i) >= 'A' && s.at(i) <= 'Z') || s.at(i) == '-' || s.at(i) == '_' || (s.at(i) >= '1' && s.at(i) <= '9')))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
bool check_Credit(int a)
{
    if (a > 0 && a <= 4)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool checkPassword(string s)
{
    if (!s.empty())
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 0 && s[i] <= 9) || (s[i] == '-') || (s[i] == '_')))
            {
                return true;
            }
        }
    }
    return false;
}

/////////////////////////////////////////Login Attempts///////////////////////////////////////////////////////////////////////
class loginAttempt
{
private:
    int count;
    loginAttempt *ptr;

public:
    void set_Count(int count)
    {
        this->count = count;
    }
    void set_PTR(loginAttempt *ptr)
    {
        this->ptr = ptr;
    }
    int get_Count()
    {
        return count;
    }
    loginAttempt *get_PTR()
    {
        return ptr;
    }
};
class Stack
{
private:
    int size = 0;
    loginAttempt *top;
    loginAttempt *next;
    loginAttempt *current;

public:
    Stack()
    {
        top = next = current = NULL;
    }
    void Reset()
    {
        top = NULL;
        size = 0;
    }
    void plusOne()
    {
        size++;
        next = new loginAttempt;
        next->set_Count(size);
        if (top == NULL)
        {
            top = next;
            current = next;
            next->set_PTR(NULL);
        }
        else
        {
            top = next;
            next->set_PTR(current);
            current = next;
        }
    }
    void Peek()
    {
        if (top == NULL)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << top->get_Count() << endl;
        }
    }
};

////////////////////////////////////////Person Class/////////////////////////////////////////////////////////////////////////
class Person
{
private:
    string firstName;
    string lastName;
    string cnic;
    string address;
    long long int phoneNo;
    int age;
    string gender;

public:
    Person()
    {
        set_Person("Empty", "Empty", "Empty", "Empty", 0, 0, "Empty");
    }
    void set_Person(string firstName, string lastName, string cnic, string address, long long int phoneNo, int age, string gender)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->cnic = cnic;
        this->address = address;
        this->phoneNo = phoneNo;
        this->age = age;
        this->gender = gender;
    }
    void set_firstName(string firstName)
    {
        this->firstName = firstName;
    }
    void set_lastName(string lastName)
    {
        this->lastName = lastName;
    }
    void set_CNIC(string cnic)
    {
        this->cnic = cnic;
    }
    void set_Address(string address)
    {
        this->address = address;
    }
    void set_phoneNo(long long int phoneNo)
    {
        this->phoneNo = phoneNo;
    }
    void set_Age(int age)
    {
        this->age = age;
    }
    void set_Gender(string gender)
    {
        this->gender = gender;
    }
    string get_firstName()
    {
        return firstName;
    }
    string get_lastName()
    {
        return lastName;
    }
    string get_CNIC()
    {
        return cnic;
    }
    string get_Address()
    {
        return address;
    }
    string get_Gender()
    {
        return gender;
    }
    int get_Age()
    {
        return age;
    }
    long long int get_phoneNo()
    {
        return phoneNo;
    }
};

////////////////////////////////////////Quiz Classes////////////////////////////////////////////////////////////////////////
class quizModel
{
private:
    string quizTitle, teacherLogin, courseCode;
    int quizNo;
    int semester;
    int group;
    char section;
    string file;
    quizModel *ptr;

public:
    string get_teacherLogin()
    {
        return teacherLogin;
    }
    void set_teacherLogin(string teacherLogin)
    {
        this->teacherLogin = teacherLogin;
    }
    string get_courseCode()
    {
        return courseCode;
    }
    void set_courseCode(string courseCode)
    {
        this->courseCode = courseCode;
    }
    string get_quizTitle()
    {
        return quizTitle;
    }
    void set_quizTitle(string quizTitle)
    {
        this->quizTitle = quizTitle;
    }
    string get_File()
    {
        return file;
    }
    void set_File(string file)
    {
        this->file = file;
    }
    char get_Section()
    {
        return section;
    }
    void set_Section(char section)
    {
        this->section = section;
    }
    int get_quizNo()
    {
        return quizNo;
    }
    void set_quizNo(int quizNo)
    {
        this->quizNo = quizNo;
    }
    int get_Group()
    {
        return group;
    }
    void set_Group(int group)
    {
        this->group = group;
    }
    int get_Semester()
    {
        return semester;
    }
    void set_Semester(int semester)
    {
        this->semester = semester;
    }
    quizModel *get_PTR()
    {
        return ptr;
    }
    void set_PTR(quizModel *ptr)
    {
        this->ptr = ptr;
    }
};
class quizData
{
private:
    int size = 0;
    quizModel *start;
    quizModel *next;
    quizModel *current;

public:
    quizData()
    {
        set_Start(NULL);
        set_Current(NULL);
        set_Next(NULL);
    }
    quizModel *get_Start()
    {
        return start;
    }
    void set_Start(quizModel *x)
    {
        start = x;
    }
    quizModel *get_Current()
    {
        return current;
    }
    void set_Current(quizModel *x)
    {
        current = x;
    }
    quizModel *get_Next()
    {
        return next;
    }
    void set_Next(quizModel *x)
    {
        next = x;
    }
    void display()
    {
        if (start == NULL)
        {
            cout << "\t\tNo Record Found.\n";
        }
        else
        {
            current = start;
            for (int i = 1; i <= size; i++)
            {
                cout << "\t\tQuiz " << i << endl;
                cout << "\t\tQuiz Title: " << current->get_quizTitle() << "\n";
                cout << "\t\tQuiz No: " << current->get_quizNo() << endl;
                cout << "\t\tSection: " << current->get_Section() << endl;
                cout << "\t\tGroup " << current->get_Group() << endl;
                cout << "\t\tSemester: " << current->get_Semester() << endl;
                cout << "\t\tCourse Code: " << current->get_courseCode() << endl;
                cout << "\t\tTeacher: " << current->get_teacherLogin() << endl;
                cout << "\t\tFile Name: " << current->get_File() << endl;
                cout << endl
                     << endl;
                current = current->get_PTR();
            }
        }
    }
    void writeFile()
    {
        ofstream studentFile;
        studentFile.open("Quizes.csv");
        if (size == 0)
        {
            studentFile << "";
        }
        else
        {
            current = start;
            for (int i = 1; i <= size - 1; i++)
            {
                studentFile << current->get_quizTitle() << ",";
                studentFile << current->get_quizNo() << ",";
                studentFile << current->get_Section() << ",";
                studentFile << current->get_Group() << ",";
                studentFile << current->get_Semester() << ",";
                studentFile << current->get_courseCode() << ",";
                studentFile << current->get_teacherLogin() << ",";
                studentFile << current->get_File() << ",";
                studentFile << endl;
                current = current->get_PTR();
            }
            studentFile << current->get_quizTitle() << ",";
            studentFile << current->get_quizNo() << ",";
            studentFile << current->get_Section() << ",";
            studentFile << current->get_Group() << ",";
            studentFile << current->get_Semester() << ",";
            studentFile << current->get_courseCode() << ",";
            studentFile << current->get_teacherLogin() << ",";
            studentFile << current->get_File() << ",";
            studentFile.close();
        }
    }
    void createNode_Teacher(string teacher)
    {
        ifstream File("Quizes.csv");
        string section;
        string quizTitle, quizNo, group, skipline, semester, file, teacherLogin, courseCode;
        if (File.fail()) // check for file open failure
        {
            cout << "Error opening file" << endl;
        }
        else if (File.peek() == std::ifstream::traits_type::eof())
        {
            File.close();
        }
        else
        {
            while (File.good())
            {
                next = new quizModel;

                getline(File, quizTitle, ',');

                getline(File, quizNo, ',');

                getline(File, section, ',');

                getline(File, group, ',');

                getline(File, semester, ',');

                getline(File, courseCode, ',');

                getline(File, teacherLogin, ',');

                getline(File, file, ',');

                getline(File, skipline);

                if (teacherLogin == teacher)
                {
                    next->set_Group(stoi(group));
                    next->set_quizTitle(quizTitle);
                    next->set_quizNo(stoi(quizNo));
                    next->set_Section(section[0]);
                    next->set_File(file);
                    next->set_courseCode(courseCode);
                    next->set_teacherLogin(teacherLogin);
                    next->set_Semester(stoi(semester));
                    next->set_PTR(NULL);
                    if (start == NULL)
                    {
                        start = next;
                        current = next;
                        size++;
                    }
                    else
                    {
                        current->set_PTR(next);
                        current = next;
                        size++;
                    }
                }
            }
            File.close();
        }
    }
    void createNode_Student(char s_section, int s_semester, int s_group)
    {
        ifstream File("Quizes.csv");
        string section;
        string quizTitle, quizNo, group, skipline, semester, file, teacherLogin, courseCode;
        if (File.fail()) // check for file open failure
        {
            cout << "Error opening file" << endl;
        }
        else if (File.peek() == std::ifstream::traits_type::eof())
        {
            File.close();
        }
        else
        {
            while (File.good())
            {
                next = new quizModel;

                getline(File, quizTitle, ',');

                getline(File, quizNo, ',');

                getline(File, section, ',');

                getline(File, group, ',');

                getline(File, semester, ',');

                getline(File, courseCode, ',');

                getline(File, teacherLogin, ',');

                getline(File, file, ',');

                getline(File, skipline);

                if (section[0] == s_section && stoi(semester) == s_semester && s_group == stoi(group))
                {
                    next->set_Group(stoi(group));
                    next->set_quizTitle(quizTitle);
                    next->set_quizNo(stoi(quizNo));
                    next->set_Section(section[0]);
                    next->set_File(file);
                    next->set_courseCode(courseCode);
                    next->set_teacherLogin(teacherLogin);
                    next->set_Semester(stoi(semester));
                    next->set_PTR(NULL);
                    if (start == NULL)
                    {
                        start = next;
                        current = next;
                        size++;
                    }
                    else
                    {
                        current->set_PTR(next);
                        current = next;
                        size++;
                    }
                }
            }
            File.close();
        }
    }
    void createNode()
    {
        ifstream File("Quizes.csv");
        string section;
        string quizTitle, quizNo, group, skipline, semester, file, teacherLogin, courseCode;
        char x;
        if (File.fail()) // check for file open failure
        {
            cout << "Error opening file" << endl;
        }
        else if (File.peek() == std::ifstream::traits_type::eof())
        {
            File.close();
        }
        else
        {
            while (File.good())
            {
                next = new quizModel;

                getline(File, quizTitle, ',');

                getline(File, quizNo, ',');

                getline(File, section, ',');

                getline(File, group, ',');

                getline(File, semester, ',');

                getline(File, courseCode, ',');

                getline(File, teacherLogin, ',');

                getline(File, file, ',');

                getline(File, skipline);

                x = section[0];
                next->set_Group(stoi(group));
                next->set_quizTitle(quizTitle);
                next->set_quizNo(stoi(quizNo));
                next->set_Section(section[0]);
                next->set_File(file);
                next->set_courseCode(courseCode);
                next->set_teacherLogin(teacherLogin);
                next->set_Semester(stoi(semester));
                next->set_PTR(NULL);
                if (start == NULL)
                {
                    start = next;
                    current = next;
                    size++;
                }
                else
                {
                    current->set_PTR(next);
                    current = next;
                    size++;
                }
            }
            File.close();
        }
    }
    void quizFile(string file)
    {
        ifstream File(file + ".txt");
        if (File.fail()) // check for file open failure
        {
            cout << "Error File not found" << endl;
        }
        else if (File.peek() == std::ifstream::traits_type::eof())
        {
            cout << "File is empty\n";
            File.close();
        }
        else
        {
            string myText;
            while (getline(File, myText))
            {
                cout << "\t\t" << myText;
            }
        }
    }
    void insert_Teacher(string teacher)
    {
        next = new quizModel;
        string quizTitle, file;
        char section;
        int quizNo, group;
        int semester = 1;
        int creditHours = 1;
        cout << "\t\tEnter Quiz Title: \n\t\t";
        cin.ignore();
        getline(cin, quizTitle);
        while (checkString(quizTitle))
        {
            cout << "\t\tError!!\n\t\tEnter Quiz Title: \n\t\t";
            getline(cin, quizTitle);
        }
        next->set_quizTitle(quizTitle);
        next->set_quizNo(size);
        do
        {
            if (check_Semester(semester))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Semester to assign quiz to: \n\t\t";
            cin >> semester;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> semester;
            }
        } while (check_Semester(semester));
        next->set_Semester(semester);
        int ch = 1;
        do
        {
            if (check_Choice(ch))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Section to assign quiz to: \n\t\t[Enter 1 to select Section A, 2 to select Section B or 3 for section C]: \n\t\t";
            cin >> ch;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> ch;
            }
        } while (check_Choice(ch));
        section = section_Choice(ch);
        next->set_Section(section);
        next->set_teacherLogin(teacher);
        cout << "\t\tEnter Name of Question File of Quiz: \n\t\t";
        getline(cin, file);
        cin.ignore();
        ifstream File(file + ".txt");
        while (File.fail() || File.peek() == std::ifstream::traits_type::eof())
        {
            cout << "\t\tError!! Please Try Again\n\t\t";
            getline(cin, file);
        }
        File.close();
        next->set_File(file);
        next->set_PTR(NULL);
        if (start == NULL)
        {
            size++;
            start = next;
            current = start;
        }
        else
        {
            size++;
            current = start;
            while (current->get_PTR() != NULL)
            {
                current = current->get_PTR();
            }
            current->set_PTR(next);
            current = next;
        }
        writeFile();
    }
    void deleteStart()
    {
        if (start == NULL)
        {
            cout << "No Record Found\n";
        }
        else
        {
            quizModel *temp;
            temp = start;
            start = start->get_PTR();
            delete (temp);
        }
    }
    void deleteSpecific()
    {
        string roll;
        cout << "\t\tEnter Quiz Title to search Quiz By: \n\t\t";
        cin.ignore();
        getline(cin, roll);
        while (checkString(roll))
        {
            cout << "\t\tError!!\n\t\tEnter Quiz Title to search Quiz By: \n\t\t";
            getline(cin, roll);
        }
        int flag = 0;
        current = start;
        int count = 0;
        for (int i = 1; i <= size; i++)
        {
            if (current->get_quizTitle() == roll)
            {
                count++;
                flag = 1;
                break;
            }
            count++;
            current = current->get_PTR();
        }
        if (flag == 1)
        {
            if (count == 1)
            {
                deleteStart();
            }
            else if (count == size)
            {
                deleteEnd();
            }
            else
            {
                current = start;
                for (int i = 1; i < count - 1; i++)
                {
                    current = current->get_PTR();
                }
                quizModel *temp;
                temp = current->get_PTR();
                current->set_PTR(current->get_PTR()->get_PTR());
                delete (temp);
            }
            size--;
            cout << "\t\tData Deleted Successfully..\n";
        }
        if (flag == 0)
        {
            cout << "\t\tNo Record Found By That Title. Please Try Again\n";
        }
        writeFile();
    }
    void deleteEnd()
    {
        if (start == NULL)
        {
            cout << "No Record Found\n";
        }
        else if (start->get_PTR() == NULL)
        {
            deleteStart();
        }
        else if (current == start->get_PTR())
        {
            quizModel *temp = NULL;
            temp = current;
            start->set_PTR(NULL);
            delete (temp);
            current = start;
        }
        else
        {
            current = start;
            for (int i = 1; i <= size - 2; i++)
            {
                current = current->get_PTR();
            }
            quizModel *temp = NULL;
            temp = current->get_PTR();
            current->set_PTR(NULL);
            delete (temp);
        }
    }
    void update()
    {
        int op;
        while (op != 3)
        {
            system("CLS");
            cout << "\t\tWhat would you like to update\n";
            cout << "\t\t1. Quiz Title\n";
            cout << "\t\t2. Quiz File\n";
            cout << "\t\t3. Exit\n";
            cin >> op;
            while (cin.fail())
            {
                cout << "\t\tError!!" << endl;
                cout << "\t\tEnter which operation you want to perform [1-3]: \n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> op;
            }
            switch (op)
            {
            case 1:
                update_Title();
                break;

            case 2:
                update_File();
                break;

            case 3:
                writeFile();
                break;

            default:
                cout << "\n\t\tInvalid Option. Please try again.\n\t\t";
                system("PAUSE");
                system("CLS");
                break;
            }
        }
    }
    void update_Title()
    {
        string password;
        cout << "\t\tEnter Assignment Title: \n\t\t";
        cin.ignore();
        getline(cin, password);
        while (checkString(password))
        {
            cout << "\t\tError!!\n\t\tEnter Assignment Title: \n\t\t";
            cin.ignore();
            getline(cin, password);
        }
        current->set_quizTitle(password);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_File()
    {
        string loginID;
        cout << "\t\tEnter File Name: \n\t\t";
        cin.ignore();
        getline(cin, loginID);
        ifstream File(loginID + ".txt");
        while (File.fail() || File.peek() == std::ifstream::traits_type::eof())
        {
            if (File.fail() || File.peek() == std::ifstream::traits_type::eof())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
            }
            getline(cin, loginID);
        }
        current->set_File(loginID);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void search_Title()
    {
        string rollNo;
        int flag = 0;
        cout << "\t\tEnter Quiz Title to search a title by: \n\t\t";
        cin >> rollNo;
        current = start;
        for (int i = 1; i <= size; i++)
        {
            if (current->get_quizTitle() == rollNo)
            {
                cout << "\t\tRecord Found\n";
                cout << "\t\tAssigment Title: " << current->get_quizTitle() << "\n";
                cout << "\t\tFile: " << current->get_File() << endl;
                cout << "\t\tSemester: " << current->get_Semester() << endl;
                flag++;
                int ch;
                cout << "\t\tWould you like to update this data:\n\t\t1. Yes\n\t\t2. No\n\t\t";
                cin >> ch;
                switch (ch)
                {
                case 1:
                    update();
                    break;

                default:
                    break;
                }
            }
            current = current->get_PTR();
        }
        if (flag == 0)
        {
            cout << "\t\tNo record found by that title\n";
        }
    }
};

////////////////////////////////////////Assignment Classes//////////////////////////////////////////////////////////////////
class assignmentModel
{
private:
    string assignmentTitle, teacherLogin;
    int assignmentNo;
    int semester;
    int group;
    char section;
    string file;
    assignmentModel *ptr;

public:
    string get_teacherLogin()
    {
        return teacherLogin;
    }
    void set_teacherLogin(string teacherLogin)
    {
        this->teacherLogin = teacherLogin;
    }
    string get_assignmentTitle()
    {
        return assignmentTitle;
    }
    void set_assignmentTitle(string assignmentTitle)
    {
        this->assignmentTitle = assignmentTitle;
    }
    string get_File()
    {
        return file;
    }
    void set_File(string file)
    {
        this->file = file;
    }
    char get_Section()
    {
        return section;
    }
    void set_Section(char section)
    {
        this->section = section;
    }
    int get_assignmentNo()
    {
        return assignmentNo;
    }
    void set_assignmentNo(int assignmentNo)
    {
        this->assignmentNo = assignmentNo;
    }
    int get_Group()
    {
        return group;
    }
    void set_Group(int group)
    {
        this->group = group;
    }
    int get_Semester()
    {
        return semester;
    }
    void set_Semester(int semester)
    {
        this->semester = semester;
    }
    assignmentModel *get_PTR()
    {
        return ptr;
    }
    void set_PTR(assignmentModel *ptr)
    {
        this->ptr = ptr;
    }
};
class assignmentData
{
private:
    assignmentModel *start;
    assignmentModel *next;
    assignmentModel *current;

public:
    int size = 0;
    assignmentData()
    {
        set_Start(NULL);
        set_Current(NULL);
        set_Next(NULL);
    }
    assignmentModel *get_Start()
    {
        return start;
    }
    void set_Start(assignmentModel *x)
    {
        start = x;
    }
    assignmentModel *get_Current()
    {
        return current;
    }
    void set_Current(assignmentModel *x)
    {
        current = x;
    }
    assignmentModel *get_Next()
    {
        return next;
    }
    void set_Next(assignmentModel *x)
    {
        next = x;
    }
    void display()
    {
        if (start == NULL)
        {
            cout << "\t\tNo Record Found.\n";
        }
        else
        {
            current = start;
            for (int i = 1; i <= size; i++)
            {
                cout << "\t\tAssignment " << i << endl;
                cout << "\t\tAssignment Title: " << current->get_assignmentTitle() << "\n";
                cout << "\t\tAssignment No: " << current->get_assignmentNo() << endl;
                cout << "\t\tSection: " << current->get_Section() << endl;
                cout << "\t\tGroup " << current->get_Group() << endl;
                cout << "\t\tSemester: " << current->get_Semester() << endl;
                cout << "\t\tTeacher: " << current->get_teacherLogin() << endl;
                cout << "\t\tFile Name: " << current->get_File() << endl;
                cout << endl
                     << endl;
                current = current->get_PTR();
            }
        }
    }
    void writeFile()
    {
        ofstream studentFile;
        studentFile.open("Assignments.csv");
        if (size == 0)
        {
            studentFile << "";
        }
        else
        {
            current = start;
            for (int i = 1; i <= size - 1; i++)
            {
                studentFile << current->get_assignmentTitle() << ",";
                studentFile << current->get_assignmentNo() << ",";
                studentFile << current->get_Section() << ",";
                studentFile << current->get_Group() << ",";
                studentFile << current->get_Semester() << ",";
                studentFile << current->get_teacherLogin() << ",";
                studentFile << current->get_File() << ",";
                studentFile << endl;
                current = current->get_PTR();
            }
            studentFile << current->get_assignmentTitle() << ",";
            studentFile << current->get_assignmentNo() << ",";
            studentFile << current->get_Section() << ",";
            studentFile << current->get_Group() << ",";
            studentFile << current->get_Semester() << ",";
            studentFile << current->get_teacherLogin() << ",";
            studentFile << current->get_File() << ",";
            studentFile.close();
        }
    }
    void createNode_Teacher(string teacher)
    {
        ifstream File("Assignments.csv");
        string section;
        string assignmentTitle, assignmentNo, group, skipline, semester, file, teacherLogin;
        char x;
        if (File.fail()) // check for file open failure
        {
            cout << "Error opening file" << endl;
        }
        else if (File.peek() == std::ifstream::traits_type::eof())
        {
            File.close();
        }
        else
        {
            while (File.good())
            {
                next = new assignmentModel;

                getline(File, assignmentTitle, ',');

                getline(File, assignmentNo, ',');

                getline(File, section, ',');

                getline(File, group, ',');

                getline(File, semester, ',');

                getline(File, teacherLogin, ',');

                getline(File, file, ',');

                getline(File, skipline);

                if (teacherLogin == teacher)
                {
                    next->set_Group(stoi(group));
                    next->set_assignmentTitle(assignmentTitle);
                    next->set_assignmentNo(stoi(assignmentNo));
                    next->set_Section(section[0]);
                    next->set_File(file);
                    next->set_teacherLogin(teacherLogin);
                    next->set_Semester(stoi(semester));
                    next->set_PTR(NULL);
                    if (start == NULL)
                    {
                        start = next;
                        current = next;
                        size++;
                    }
                    else
                    {
                        current->set_PTR(next);
                        current = next;
                        size++;
                    }
                }
            }
            File.close();
        }
    }
    void createNode_Student(char s_section, int s_semester, int s_group)
    {
        ifstream File("Assignments.csv");
        string section;
        string assignmentTitle, assignmentNo, group, skipline, semester, file, teacherLogin;
        char x;
        if (File.fail()) // check for file open failure
        {
            cout << "Error opening file" << endl;
        }
        else if (File.peek() == std::ifstream::traits_type::eof())
        {
            File.close();
        }
        else
        {
            while (File.good())
            {
                next = new assignmentModel;

                getline(File, assignmentTitle, ',');

                getline(File, assignmentNo, ',');

                getline(File, section, ',');

                getline(File, group, ',');

                getline(File, semester, ',');

                getline(File, teacherLogin, ',');

                getline(File, file, ',');

                getline(File, skipline);

                if (section[0] == s_section && stoi(semester) == s_semester && s_group == stoi(group))
                {
                    next->set_Group(stoi(group));
                    next->set_assignmentTitle(assignmentTitle);
                    next->set_assignmentNo(stoi(assignmentNo));
                    next->set_Section(section[0]);
                    next->set_File(file);
                    next->set_teacherLogin(teacherLogin);
                    next->set_Semester(stoi(semester));
                    next->set_PTR(NULL);
                    if (start == NULL)
                    {
                        start = next;
                        current = next;
                        size++;
                    }
                    else
                    {
                        current->set_PTR(next);
                        current = next;
                        size++;
                    }
                }
            }
            File.close();
        }
    }
    void createNode()
    {
        ifstream File("Assignments.csv");
        string section;
        string assignmentTitle, assignmentNo, group, skipline, semester, file, teacherLogin;
        char x;
        if (File.fail()) // check for file open failure
        {
            cout << "Error opening file" << endl;
        }
        else if (File.peek() == std::ifstream::traits_type::eof())
        {
            File.close();
        }
        else
        {
            while (File.good())
            {
                next = new assignmentModel;

                getline(File, assignmentTitle, ',');

                getline(File, assignmentNo, ',');

                getline(File, section, ',');

                getline(File, group, ',');

                getline(File, semester, ',');

                getline(File, teacherLogin, ',');

                getline(File, file, ',');

                getline(File, skipline);

                next->set_Group(stoi(group));
                next->set_assignmentTitle(assignmentTitle);
                next->set_assignmentNo(stoi(assignmentNo));
                next->set_Section(section[0]);
                next->set_File(file);
                next->set_teacherLogin(teacherLogin);
                next->set_Semester(stoi(semester));
                next->set_PTR(NULL);
                if (start == NULL)
                {
                    start = next;
                    current = next;
                    size++;
                }
                else
                {
                    current->set_PTR(next);
                    current = next;
                    size++;
                }
            }
            File.close();
        }
    }
    void assignmentFile(string file)
    {
        ifstream File(file + ".txt");
        if (File.fail()) // check for file open failure
        {
            cout << "Error File not found" << endl;
        }
        else if (File.peek() == std::ifstream::traits_type::eof())
        {
            cout << "File is empty\n";
            File.close();
        }
        else
        {
            string myText;
            while (getline(File, myText))
            {
                cout << "\t\t" << myText;
            }
        }
    }
    void insert_Teacher(string teacher)
    {
        next = new assignmentModel;
        string assignmentTitle, file;
        char section;
        int assignmentNo, group;
        int semester = 1;
        int creditHours = 1;
        cout << "\t\tEnter Assignment Title: \n\t\t";
        cin.ignore();
        getline(cin, assignmentTitle);
        while (checkString(assignmentTitle))
        {
            cout << "\t\tError!!\n\t\tEnter Assignment Title: \n\t\t";
            getline(cin, assignmentTitle);
        }
        next->set_assignmentTitle(assignmentTitle);
        next->set_assignmentNo(size);
        do
        {
            if (check_Semester(semester))
            {
                cout << "\t\tError!!\n";
            }
            cout << "\t\tEnter Semester to assign assignment to: \n\t\t";
            cin >> semester;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> semester;
            }
        } while (check_Semester(semester));
        int ch = 1;
        do
        {
            if (check_Choice(ch))
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
            }
            cout << "\t\tEnter Section to assign assignment to: \n\t\t[Enter 1 to select Section A, 2 to select Section B or 3 for section C]: \n\t\t";
            cin >> ch;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> ch;
            }
        } while (check_Choice(ch));
        section = section_Choice(ch);
        next->set_Section(section);
        next->set_teacherLogin(teacher);
        cout << "\t\tEnter Name of Question File of Assignment: \n\t\t";
        cin.ignore();
        getline(cin, file);
        ifstream File(file + ".txt");
        while (File.fail() || File.peek() == std::ifstream::traits_type::eof())
        {
            if (File.fail() || File.peek() == std::ifstream::traits_type::eof())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
            }
            getline(cin, file);
        }
        next->set_File(file);
        next->set_PTR(NULL);
        if (start == NULL)
        {
            size++;
            current = start;
        }
        else
        {
            size++;
            current = start;
            while (current->get_PTR() != NULL)
            {
                current = current->get_PTR();
            }
            current->set_PTR(next);
            current = next;
        }
        writeFile();
    }
    void deleteStart()
    {
        if (start == NULL)
        {
            cout << "No Record Found\n";
        }
        else
        {
            assignmentModel *temp;
            temp = start;
            start = start->get_PTR();
            delete (temp);
        }
    }
    void deleteSpecific()
    {
        string roll;
        cout << "\t\tEnter Assignment Title to search Assignment By: \n\t\t";
        cin.ignore();
        getline(cin, roll);
        while (checkString(roll))
        {
            cout << "\t\tError!!\n\t\tEnter Assignment Title to search Assignment By: \n\t\t";
            getline(cin, roll);
        }
        int flag = 0;
        current = start;
        int count = 0;
        for (int i = 1; i <= size; i++)
        {
            if (current->get_assignmentTitle() == roll)
            {
                count++;
                flag = 1;
                break;
            }
            count++;
            current = current->get_PTR();
        }
        if (flag == 1)
        {
            if (count == 1)
            {
                deleteStart();
            }
            else if (count == size)
            {
                deleteEnd();
            }
            else
            {
                current = start;
                for (int i = 1; i < count - 1; i++)
                {
                    current = current->get_PTR();
                }
                assignmentModel *temp;
                temp = current->get_PTR();
                current->set_PTR(current->get_PTR()->get_PTR());
                delete (temp);
            }
            size--;
            cout << "\t\tData Deleted Successfully..\n";
        }
        if (flag == 0)
        {
            cout << "\t\tNo Record Found By That Title. Please Try Again\n";
        }
        writeFile();
    }
    void deleteEnd()
    {
        if (start == NULL)
        {
            cout << "No Record Found\n";
        }
        else if (start->get_PTR() == NULL)
        {
            deleteStart();
        }
        else if (current == start->get_PTR())
        {
            assignmentModel *temp = NULL;
            temp = current;
            start->set_PTR(NULL);
            delete (temp);
            current = start;
        }
        else
        {
            current = start;
            for (int i = 1; i <= size - 2; i++)
            {
                current = current->get_PTR();
            }
            assignmentModel *temp = NULL;
            temp = current->get_PTR();
            current->set_PTR(NULL);
            delete (temp);
        }
    }
    void update()
    {
        int op;
        while (op != 3)
        {
            system("CLS");
            cout << "\t\tWhat would you like to update\n";
            cout << "\t\t1. Assignment Title\n";
            cout << "\t\t2. Assignment File\n";
            cout << "\t\t3. Exit\n";
            cin >> op;
            while (cin.fail())
            {
                cout << "\t\tError!!" << endl;
                cout << "\t\tEnter which operation you want to perform [1-3]: \n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> op;
            }
            switch (op)
            {
            case 1:
                update_Title();
                break;

            case 2:
                update_File();
                break;

            case 3:
                writeFile();
                break;

            default:
                cout << "\n\t\tInvalid Option. Please try again.\n\t\t";
                system("PAUSE");
                system("CLS");
                break;
            }
        }
    }
    void update_Title()
    {
        string password;
        cout << "\t\tEnter Assignment Title: \n\t\t";
        cin.ignore();
        getline(cin, password);
        while (checkString(password))
        {
            cout << "\t\tError!!\n\t\tEnter Assignment Title: \n\t\t";
            cin.ignore();
            getline(cin, password);
        }
        current->set_assignmentTitle(password);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_File()
    {
        string loginID;
        cout << "\t\tEnter File Name: \n\t\t";
        cin.ignore();
        getline(cin, loginID);
        ifstream File(loginID + ".txt");
        while (File.fail() || File.peek() == std::ifstream::traits_type::eof())
        {
            if (File.fail() || File.peek() == std::ifstream::traits_type::eof())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
            }
            getline(cin, loginID);
        }
        current->set_File(loginID);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void search_Title()
    {
        string rollNo;
        int flag = 0;
        cout << "\t\tEnter Assignment Title to search a title by: \n\t\t";
        cin >> rollNo;
        current = start;
        for (int i = 1; i <= size; i++)
        {
            if (current->get_assignmentTitle() == rollNo)
            {
                cout << "\t\tRecord Found\n";
                cout << "\t\tAssigment Title: " << current->get_assignmentTitle() << "\n";
                cout << "\t\tFile: " << current->get_File() << endl;
                cout << "\t\tSemester: " << current->get_Semester() << endl;
                flag++;
                int ch;
                cout << "\t\tWould you like to update this data:\n\t\t1. Yes\n\t\t2. No\n\t\t";
                cin >> ch;
                switch (ch)
                {
                case 1:
                    update();
                    break;

                default:
                    break;
                }
            }
            current = current->get_PTR();
        }
        if (flag == 0)
        {
            cout << "\t\tNo record found by that title\n";
        }
    }
};

///////////////////////////////////////Course Classes/////////////////////////////////////////////////////////////////////
class courseModel
{
private:
    string courseTitle, courseCode;
    int semester;
    int creditHours;
    courseModel *ptr;

public:
    string get_courseTitle()
    {
        return courseTitle;
    }
    void set_courseTitle(string courseTitle)
    {
        this->courseTitle = courseTitle;
    }
    string get_courseCode()
    {
        return courseCode;
    }
    void set_courseCode(string courseCode)
    {
        this->courseCode = courseCode;
    }
    int get_creditHours()
    {
        return creditHours;
    }
    void set_creditHours(int creditHours)
    {
        this->creditHours = creditHours;
    }
    int get_Semester()
    {
        return semester;
    }
    void set_Semester(int semester)
    {
        this->semester = semester;
    }
    courseModel *get_PTR()
    {
        return ptr;
    }
    void set_PTR(courseModel *ptr)
    {
        this->ptr = ptr;
    }
};
class courseData
{
private:
    courseModel *start;
    courseModel *next;
    courseModel *current;
    courseModel *temp;

public:
    int size = 0;
    courseData()
    {
        set_Start(NULL);
        set_Current(NULL);
        set_Next(NULL);
    }
    courseModel *get_Start()
    {
        return start;
    }
    void set_Start(courseModel *x)
    {
        start = x;
    }
    courseModel *get_Current()
    {
        return current;
    }
    void set_Current(courseModel *x)
    {
        current = x;
    }
    courseModel *get_Next()
    {
        return next;
    }
    void set_Next(courseModel *x)
    {
        next = x;
    }
    bool check_Code(string roll)
    {
        current = start;
        for (int i = 1; i <= size; i++)
        {
            if (roll == current->get_courseCode())
            {
                return false;
            }
            current = current->get_PTR();
        }
        return true;
    }
    void display()
    {
        if (start == NULL)
        {
            cout << "\t\tNo Record Found.\n";
        }
        else
        {
            current = start;
            for (int i = 1; i <= size; i++)
            {
                cout << "\t\tCourse " << i << endl;
                cout << "\t\tCourse Title: " << current->get_courseTitle() << "\n";
                cout << "\t\tCourse Code: " << current->get_courseCode() << endl;
                cout << "\t\tCredit Hours: " << current->get_creditHours() << endl;
                cout << "\t\tSemester: " << current->get_Semester() << endl;
                cout << endl
                     << endl;
                current = current->get_PTR();
            }
        }
    }
    void createNode_Teacher(string teacher)
    {
        ifstream File(teacher + ".csv");
        string courseTitle, courseCode, creditHours, skipline, semester;

        if (File.fail()) // check for file open failure
        {
            cout << "Error opening file" << endl;
        }
        else if (File.peek() == std::ifstream::traits_type::eof())
        {
            File.close();
        }
        else
        {
            while (File.good())
            {
                next = new courseModel;

                getline(File, courseTitle, ',');

                getline(File, courseCode, ',');

                getline(File, creditHours, ',');

                getline(File, semester, ',');

                getline(File, skipline);

                next->set_creditHours(stoi(creditHours));
                next->set_courseTitle(courseTitle);
                next->set_courseCode(courseCode);
                next->set_Semester(stoi(semester));
                next->set_PTR(NULL);

                if (start == NULL)
                {
                    start = next;
                    current = next;
                    size++;
                }
                else
                {
                    current->set_PTR(next);
                    current = next;
                    size++;
                }
            }
            File.close();
        }
    }
    void createNode_Student(int s_semester)
    {
        ifstream File("Courses.csv");
        string courseTitle, courseCode, creditHours, skipline, semester;

        if (File.fail()) // check for file open failure
        {
            cout << "Error opening file" << endl;
        }
        else if (File.peek() == std::ifstream::traits_type::eof())
        {
            File.close();
        }
        else
        {
            while (File.good())
            {
                next = new courseModel;

                getline(File, courseTitle, ',');

                getline(File, courseCode, ',');

                getline(File, creditHours, ',');

                getline(File, semester, ',');

                getline(File, skipline);

                if (stoi(semester) == s_semester)
                {
                    next->set_creditHours(stoi(creditHours));
                    next->set_courseTitle(courseTitle);
                    next->set_courseCode(courseCode);
                    next->set_Semester(stoi(semester));
                    next->set_PTR(NULL);

                    if (start == NULL)
                    {
                        start = next;
                        current = next;
                        size++;
                    }
                    else
                    {
                        current->set_PTR(next);
                        current = next;
                        size++;
                    }
                }
            }
            File.close();
        }
    }
    void writeFile()
    {
        ofstream studentFile;
        studentFile.open("Courses.csv");
        if (size == 0)
        {
            studentFile << "";
        }
        else
        {
            current = start;
            for (int i = 1; i <= size - 1; i++)
            {
                studentFile << current->get_courseTitle() << ",";
                studentFile << current->get_courseCode() << ",";
                studentFile << current->get_creditHours() << ",";
                studentFile << current->get_Semester() << ",";
                studentFile << endl;
                current = current->get_PTR();
            }
            studentFile << current->get_courseTitle() << ",";
            studentFile << current->get_courseCode() << ",";
            studentFile << current->get_creditHours() << ",";
            studentFile << current->get_Semester() << ",";
            studentFile.close();
        }
    }
    void writeFile(string teacher)
    {
        ofstream studentFile;
        studentFile.open(teacher + ".csv");
        current = start;
        studentFile << temp->get_courseTitle() << ",";
        studentFile << temp->get_courseCode() << ",";
        studentFile << temp->get_creditHours() << ",";
        studentFile << temp->get_Semester() << ",";
        studentFile.close();
    }
    void createNode()
    {
        ifstream File("Courses.csv");
        string courseTitle, courseCode, creditHours, skipline, semester;

        if (File.fail()) // check for file open failure
        {
            cout << "Error opening file" << endl;
        }
        else if (File.peek() == std::ifstream::traits_type::eof())
        {
            File.close();
        }
        else
        {
            while (File.good())
            {
                next = new courseModel;

                getline(File, courseTitle, ',');

                getline(File, courseCode, ',');

                getline(File, creditHours, ',');

                getline(File, semester, ',');

                getline(File, skipline);

                next->set_creditHours(stoi(creditHours));
                next->set_courseTitle(courseTitle);
                next->set_courseCode(courseCode);
                next->set_Semester(stoi(semester));
                next->set_PTR(NULL);
                if (start == NULL)
                {
                    start = next;
                    current = next;
                    size++;
                }
                else
                {
                    current->set_PTR(next);
                    current = next;
                    size++;
                }
            }
            File.close();
        }
    }
    void insertEnd()
    {
        string courseTitle, courseCode;
        int creditHours = 1;
        int semester = 1;
        next = new courseModel;
        cout << "\t\tEnter Course Title: \n\t\t";
        cin.ignore();
        getline(cin, courseTitle);
        while (checkString(courseTitle))
        {
            cout << "\t\tError!!\n\t\tEnter Course Title: \n\t\t";
            cin.ignore();
            getline(cin, courseTitle);
        }
        next->set_courseTitle(courseTitle);
        cout << "\t\tEnter Course Code: \n\t\t";
        getline(cin, courseCode);
        while (check_Code(courseCode))
        {
            cout << "\t\tError!!\n\t\tEnter Course Code: \n\t\t";
            getline(cin, courseCode);
        }
        next->set_courseCode(courseCode);
        do
        {
            if (check_Credit(creditHours))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Credit Hours: \n\t\t";
            cin >> creditHours;
            while (cin.fail())
            {
                cout << "Error" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> creditHours;
            }
        } while (check_Credit(creditHours));
        next->set_creditHours(creditHours);
        do
        {
            if (check_Semester(semester))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Course's Semester: \n\t\t";
            cin >> semester;
            while (cin.fail())
            {
                cout << "Error" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> semester;
            }
        } while (check_Semester(semester));
        next->set_Semester(semester);
        next->set_PTR(NULL);
        if (start == NULL)
        {
            size++;
            start = next;
            current = start;
        }
        else
        {
            size++;
            current = start;
            while (current->get_PTR() != NULL)
            {
                current = current->get_PTR();
            }
            current->set_PTR(next);
            current = next;
        }
        writeFile();
    }
    bool checkCode(string code)
    {
        current = start;
        for (int i = 1; i <= size; i++)
        {
            if (code == current->get_courseCode())
            {
                temp = current;
                return false;
            }
            current = current->get_PTR();
        }
        return true;
    }
    void insertTeacher()
    {
        createNode();
        string courseCode;
        cout << "\t\tEnter Course Code You want to assign to teacher: \n\t\t";
        cin.ignore();
        getline(cin, courseCode);
        while (checkCode(courseCode))
        {
            cout << "\t\tError!!\n\t\tEnter Course Code: \n\t\t";
            getline(cin, courseCode);
        }
        temp = current;
    }
    void deleteStart()
    {
        if (start == NULL)
        {
            cout << "\t\tNo Record Found\n\t\t";
        }
        else
        {
            courseModel *temp;
            temp = start;
            start = start->get_PTR();
            delete (temp);
        }
    }
    void deleteSpecific()
    {
        string roll;
        cout << "\t\tEnter Course Code to search Course By: \n\t\t";
        cin.ignore();
        getline(cin, roll);
        while (checkCode(roll))
        {
            cout << "\t\tError!!\n\t\tEnter Course Code to search Course By: \n\t\t";
            getline(cin, roll);
        }
        int flag = 0;
        current = start;
        int count = 0;
        for (int i = 1; i <= size; i++)
        {
            if (current->get_courseCode() == roll)
            {
                count++;
                flag = 1;
                break;
            }
            count++;
            current = current->get_PTR();
        }
        if (flag == 1)
        {
            if (count == 1)
            {
                deleteStart();
            }
            else if (count == size)
            {
                deleteEnd();
            }
            else
            {
                current = start;
                for (int i = 1; i < count - 1; i++)
                {
                    current = current->get_PTR();
                }
                courseModel *temp;
                temp = current->get_PTR();
                current->set_PTR(current->get_PTR()->get_PTR());
                delete (temp);
            }
            size--;
            cout << "\t\tNode Deleted Successfully\n";
            writeFile();
        }
        if (flag == 0)
        {
            cout << "\t\tNo Record Found By That Title. Please Try Again\n";
        }
    }
    void deleteEnd()
    {
        if (start == NULL)
        {
            cout << "\t\tNo Record Found\n\t\t";
        }
        else if (start->get_PTR() == NULL)
        {
            deleteStart();
        }
        else if (current == start->get_PTR())
        {
            courseModel *temp = NULL;
            temp = current;
            start->set_PTR(NULL);
            delete (temp);
            current = start;
        }
        else
        {
            current = start;
            for (int i = 1; i <= size - 2; i++)
            {
                current = current->get_PTR();
            }
            courseModel *temp = NULL;
            temp = current->get_PTR();
            current->set_PTR(NULL);
            delete (temp);
        }
    }
    void update()
    {
        int op;
        while (op != 11)
        {
            system("CLS");
            cout << "\t\tWhat would you like to update\n";
            cout << "\t\t1. Course Title\n";
            cout << "\t\t2. Course Code\n";
            cout << "\t\t3. Credit Hours\n";
            cout << "\t\t4. Semester\n";
            cout << "\t\t5. Exit\n";
            cin >> op;
            while (cin.fail())
            {
                cout << "\t\tError!!" << endl;
                cout << "\t\tEnter which operation you want to perform [1-11]: \n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> op;
            }
            switch (op)
            {
            case 1:
                update_courseTitle();
                break;

            case 2:
                update_courseCode();
                break;

            case 3:
                update_Credit();
                break;

            case 4:
                update_Semester();
                break;

            case 5:
                writeFile();
                break;

            default:
                cout << "\n\t\tInvalid Option. Please try again.\n\t\t";
                system("PAUSE");
                system("CLS");
                break;
            }
        }
    }
    void update_Semester()
    {
        int b = 1;
        do
        {
            if (check_Semester(b))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Course's Semester: \n\t\t";
            cin >> b;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> b;
            }
        } while (check_Semester(b));
        current->set_Semester(b);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_courseTitle()
    {
        string password;
        cout << "\t\tEnter Course Title: \n\t\t";
        cin.ignore();
        getline(cin, password);
        while (checkString(password))
        {
            cout << "\t\tError!!\n\t\tEnter Course Title: \n\t\t";
            cin.ignore();
            getline(cin, password);
        }
        current->set_courseTitle(password);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_courseCode()
    {
        string loginID;
        cout << "\t\tEnter Course Code: \n\t\t";
        cin.ignore();
        getline(cin, loginID);
        while (check_Code(loginID))
        {
            cout << "\t\tEnter Course Code: \n\t\t";
            getline(cin, loginID);
        }
        current->set_courseCode(loginID);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_Credit()
    {
        int age = 1;
        do
        {
            if (check_Credit(age))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Course's Credit Hours: \n\t\t";
            cin >> age;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> age;
            }
        } while (check_Credit(age));
        current->set_creditHours(age);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void search_Login()
    {
        string rollNo;
        int flag = 0;
        cout << "\t\tEnter course code to search a course by: \n\t\t";
        cin >> rollNo;
        current = start;
        for (int i = 1; i <= size; i++)
        {
            if (current->get_courseCode() == rollNo)
            {
                cout << "\t\tRecord Found\n";
                cout << "\t\tCourse Title: " << current->get_courseTitle() << "\n";
                cout << "\t\tCourse Code: " << current->get_courseCode() << endl;
                cout << "\t\tCredit Hours: " << current->get_creditHours() << endl;
                cout << "\t\tSemester: " << current->get_Semester() << endl;
                flag++;
                int ch;
                cout << "\t\tWould you like to update this data:\n\t\t1. Yes\n\t\t2. No\n\t\t";
                cin >> ch;
                switch (ch)
                {
                case 1:
                    update();
                    break;

                default:
                    break;
                }
            }
            current = current->get_PTR();
        }
        if (flag == 0)
        {
            cout << "\t\tNo course found by that code\n";
        }
    }
};

///////////////////////////////////////Student Classes/////////////////////////////////////////////////////////////////////
class StudentModel : public Person
{
private:
    string rollNo, password;
    char section;
    double cgpa;
    int group;
    int semester;
    StudentModel *ptr;

public:
    StudentModel()
    {
        rollNo = password = "Empty";
        section = '0';
        cgpa = group = 0;
    }
    void set_Student(string rollNo, string password, char section, double cgpa, int group, int semester)
    {
        this->rollNo = rollNo;
        this->password = password;
        this->section = section;
        this->cgpa = cgpa;
        this->group = group;
        this->semester = semester;
    }
    void set_rollNo(string rollNo)
    {
        this->rollNo = rollNo;
    }
    void set_Password(string password)
    {
        this->password = password;
    }
    void set_Section(char section)
    {
        this->section = section;
    }
    void set_CGPA(double cgpa)
    {
        this->cgpa = cgpa;
    }
    void set_Group(int group)
    {
        this->group = group;
    }
    void set_Semester(int Semester)
    {
        this->semester = semester;
    }
    string get_Password()
    {
        return password;
    }
    string get_RollNo()
    {
        return rollNo;
    }
    char get_Section()
    {
        return section;
    }
    double get_CGPA()
    {
        return cgpa;
    }
    int get_Group()
    {
        return group;
    }
    int get_Semester()
    {
        return semester;
    }
    StudentModel *get_PTR()
    {
        return ptr;
    }
    void set_PTR(StudentModel *x)
    {
        ptr = x;
    }
};
class StudentData
{
private:
    Stack l2;
    string roll;
    char pass[32];
    char section;
    int group, semester;
    StudentModel *start, *current, *next;

public:
    int size = 0;
    StudentData()
    {
        set_Start(NULL);
        set_Current(NULL);
        set_Next(NULL);
    }
    StudentModel *get_Start()
    {
        return start;
    }
    void set_Start(StudentModel *x)
    {
        start = x;
    }
    StudentModel *get_Current()
    {
        return current;
    }
    void set_Current(StudentModel *x)
    {
        current = x;
    }
    StudentModel *get_Next()
    {
        return next;
    }
    void set_Next(StudentModel *x)
    {
        next = x;
    }
    bool checkRoll(string roll)
    {
        createNode();
        current = start;
        for (int i = 1; i <= size; i++)
        {
            if (roll == current->get_RollNo())
            {
                return false;
            }
            current = current->get_PTR();
        }
        return true;
    }
    bool check_CNIC(string roll)
    {
        current = start;
        for (int i = 1; i <= size; i++)
        {
            if (roll == current->get_CNIC())
            {
                return false;
            }
            current = current->get_PTR();
        }
        return true;
    }
    void display()
    {
        if (start == NULL)
        {
            cout << "No Record Found.\n";
        }
        else
        {
            current = start;
            for (int i = 1; i <= size; i++)
            {
                cout << "\t\tStudent " << i << endl;
                cout << "\t\tFirst Name: " << current->get_firstName() << "\n";
                cout << "\t\tLast Name: " << current->get_lastName() << endl;
                cout << "\t\tCNIC: " << current->get_CNIC() << "\n";
                cout << "\t\tPhone Number: " << current->get_phoneNo() << endl;
                cout << "\t\tAddress: " << current->get_Address() << "\n";
                cout << "\t\tAge: " << current->get_Age() << endl;
                cout << "\t\tGender: " << current->get_Gender() << "\n";
                cout << "\t\tRoll Number: " << current->get_RollNo() << endl;
                cout << "\t\tPassword: " << current->get_Password() << endl;
                cout << "\t\tSection: " << current->get_Section() << endl;
                cout << "\t\tGroup: " << current->get_Group() << endl;
                cout << "\t\tSemester: " << current->get_Semester() << endl;
                cout << "\t\tCGPA: " << current->get_CGPA() << endl;
                cout << endl
                     << endl;
                current = current->get_PTR();
            }
        }
    }
    void writeFile()
    {
        ofstream studentFile;
        studentFile.open("Students.csv");
        if (size == 0)
        {
            studentFile << "";
        }
        else if (size == 1)
        {
            studentFile << current->get_firstName() << ",";
            studentFile << current->get_lastName() << ",";
            studentFile << current->get_CNIC() << ",";
            studentFile << current->get_Address() << ",";
            studentFile << current->get_phoneNo() << ',';
            studentFile << current->get_Age() << ',';
            studentFile << current->get_Gender() << ",";
            studentFile << current->get_RollNo() << ",";
            studentFile << current->get_Password() << ",";
            studentFile << current->get_Section() << ",";
            studentFile << current->get_Group() << ",";
            studentFile << current->get_Semester() << ",";
            studentFile << current->get_CGPA() << ",";
        }
        else
        {
            current = start;
            for (int i = 1; i <= size - 1; i++)
            {
                studentFile << current->get_firstName() << ",";
                studentFile << current->get_lastName() << ",";
                studentFile << current->get_CNIC() << ",";
                studentFile << current->get_Address() << ",";
                studentFile << current->get_phoneNo() << ',';
                studentFile << current->get_Age() << ',';
                studentFile << current->get_Gender() << ",";
                studentFile << current->get_RollNo() << ",";
                studentFile << current->get_Password() << ",";
                studentFile << current->get_Section() << ",";
                studentFile << current->get_Group() << ",";
                studentFile << current->get_Semester() << ",";
                studentFile << current->get_CGPA() << ",";
                studentFile << endl;
                current = current->get_PTR();
            }
            studentFile << current->get_firstName() << ",";
            studentFile << current->get_lastName() << ",";
            studentFile << current->get_CNIC() << ",";
            studentFile << current->get_Address() << ",";
            studentFile << current->get_phoneNo() << ',';
            studentFile << current->get_Age() << ',';
            studentFile << current->get_Gender() << ",";
            studentFile << current->get_RollNo() << ",";
            studentFile << current->get_Password() << ",";
            studentFile << current->get_Section() << ",";
            studentFile << current->get_Group() << ",";
            studentFile << current->get_Semester() << ",";
            studentFile << current->get_CGPA() << ",";
            studentFile.close();
        }
    }
    void Login()
    {
        system("CLS");
        cout << "\n\t\t";
        for (int i = 0; i < 90; i++)
        {
            cout << "\xB1";
        }
        l2.plusOne();
        cout << "\t\t\t\t\t";
        cout << "\n\n\t\tLogin Attempt:";
        l2.Peek();
        cout << "\n";
        cout << "\t\tEnter your roll number:\n\t\t";
        cin >> roll;
        while (check_rollNO(roll))
        {
            cout << "\t\tError!!\n\t\tPlease Enter Your Roll Number in the format (XXXXXXXX-XXX): \n\t\t";
            cin >> roll;
        }
        int flag = 0;
        current = start;
        for (int i = 1; i <= size; i++)
        {
            if (current->get_RollNo() == roll)
            {
                section = current->get_Section();
                group = current->get_Group();
                semester = current->get_Semester();
                flag = 1;
            }
            current = current->get_PTR();
        }
        if (flag == 0)
        {
            system("CLS");
            cout << "\n\t\t\t\tWrong Credentials. Please check your roll number and password and try again.\n";
            cout << "\n\t\t\t\t\t\tLoading";
            for (int i = 0; i < 25; i++)
            {
                Sleep(20);
                cout << "\xB1";
            }
            cout << "\n\n\t\t\t\t\t\t";
            system("PAUSE");
        }
        else
        {
            cout << "\t\tEnter your password:\n\t\t";
            int i = 0;
            char a;
            for (i = 0;;)
            {
                a = getch();
                if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || (a == '-') || (a == '_'))

                {
                    pass[i] = a;
                    ++i;
                    cout << "*";
                }
                if (a == '\b' && i >= 1)

                {
                    cout << "\b \b";
                    --i;
                }
                if (a == '\r')
                {
                    pass[i] = '\0';
                    break;
                }
            }
            int flag = 0;
            current = start;
            for (int i = 1; i <= size; i++)
            {
                if (current->get_RollNo() == roll && current->get_Password() == pass)
                {
                    section = current->get_Section();
                    group = current->get_Group();
                    semester = current->get_Semester();
                    flag = 1;
                }
                current = current->get_PTR();
            }
            if (flag == 1)
            {
                system("CLS");
                l2.Reset();
                cout << "\n\t\t\t\tLogin Successfull................\n";
                cout << "\n\t\t\t\tLoading";
                for (int i = 0; i < 25; i++)
                {
                    Sleep(20);
                    cout << "\xB1";
                }
                Menu();
            }
            else
            {
                system("CLS");
                cout << "\n\t\t\t\tWrong Credentials. Please check your roll number and password and try again.\n";
                cout << "\n\t\t\t\t\t\tLoading";
                for (int i = 0; i < 25; i++)
                {
                    Sleep(20);
                    cout << "\xB1";
                }
                cout << "\n\n\t\t\t\t\t\t";
                system("PAUSE");
            }
        }
    }
    void showInfo()
    {
        if (start == NULL)
        {
            cout << "\t\tEmpty Record.\n";
        }
        else
        {
            current = start;
            int flag = 0;
            for (int i = 1; i <= size; i++)
            {
                if (roll == current->get_RollNo())
                {
                    cout << "\t\tFirst Name: " << current->get_firstName() << "\n";
                    cout << "\t\tLast Name: " << current->get_lastName() << endl;
                    cout << "\t\tCNIC: " << current->get_CNIC() << "\n";
                    cout << "\t\tPhone Number: " << current->get_phoneNo() << endl;
                    cout << "\t\tAddress: " << current->get_Address() << "\n";
                    cout << "\t\tAge: " << current->get_Age() << endl;
                    cout << "\t\tGender: " << current->get_Gender() << "\n";
                    cout << "\t\tRoll Number: " << current->get_RollNo() << endl;
                    cout << "\t\tPassword: " << current->get_Password() << endl;
                    cout << "\t\tSection: " << current->get_Section() << endl;
                    cout << "\t\tGroup: " << current->get_Group() << endl;
                    cout << "\t\tSemester: " << current->get_Semester() << endl;
                    cout << "\t\tCGPA: " << current->get_CGPA() << endl;
                    flag++;
                }
                current = current->get_PTR();
            }
        }
    }
    void Menu()
    {
        system("CLS");
        assignmentData l1;
        courseData l2;
        quizData l3;
        l3.createNode_Student(semester, section, group);
        l2.createNode_Student(semester);
        l1.createNode_Student(semester, section, group);
        int op = -1;
        while (op != 6)
        {
            cout << "\n\t\t";
            for (int i = 0; i < 90; i++)
            {
                cout << "\xB1";
            }
            cout << "\n\n\t\t\t\t\t\t";
            cout << "Student Menu\n\n";
            cout << "\t\t1. View your information\n\t\t2. View Courses\n\t\t3. View Assignments\n\t\t4. View Quizes\n\t\t5. View Attendance\n\t\t6. Logout";
            cout << "\n\n\t\tEnter the operation you want to perform [1-5]: \n";
            cout << "\t\t";
            cin >> op;
            while (cin.fail())
            {
                cout << "\t\tError!!" << endl;
                cout << "\t\tEnter which operation you want to perform [1-5]: \n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> op;
            }
            switch (op)
            {
            case 1:
                showInfo();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 2:
                l2.display();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 3:
                l1.display();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 4:
                l3.display();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 5:
                countMyAttendance(roll);
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 6:
                break;

            default:
                cout << "\t\tInvalid Option!! Please Try Again\n\t\t";
                system("PAUSE");
                system("CLS");
                break;
            }
        }
    }
    void createNode()
    {
        ifstream File("Students.csv");
        string group, semester, cnic, address, age, gender;
        string firstName, roll, lastName, skipline, password;
        string section, phoneNo;
        string cgpa;

        if (File.fail()) // check for file open failure
        {
            cout << "Error opening file" << endl;
        }
        else if (File.peek() == std::ifstream::traits_type::eof())
        {
        }
        else
        {
            while (File.good())
            {
                next = new StudentModel;

                getline(File, firstName, ',');

                getline(File, lastName, ',');

                getline(File, cnic, ',');

                getline(File, address, ',');

                getline(File, phoneNo, ',');

                getline(File, age, ',');

                getline(File, gender, ',');

                getline(File, roll, ',');

                getline(File, password, ',');

                getline(File, section, ',');

                getline(File, group, ',');

                getline(File, semester, ',');

                getline(File, cgpa, ',');

                getline(File, skipline);
                next->set_Person(firstName, lastName, cnic, address, stoll(phoneNo), stoi(age), gender);
                next->set_Student(roll, password, section[0], stoi(cgpa), stoi(group), stoi(semester));
                next->set_PTR(NULL);
                if (start == NULL)
                {
                    start = next;
                    current = next;
                    size++;
                }
                else
                {
                    current->set_PTR(next);
                    current = next;
                    size++;
                }
            }
        }
        File.close();
    }
    void insertEnd()
    {
        int group = 5;
        int semester = 1;
        int age = 20;
        string cnic, address, gender;
        string firstName, roll, lastName, password;
        string section;
        long long int phoneNo = 0;
        double cgpa = 1.00;
        next = new StudentModel;
        cout << "\t\tEnter Student's First Name: \n\t\t";
        cin.ignore();
        getline(cin, firstName);
        while (checkString(firstName))
        {
            cout << "\t\tError!!\n\t\tEnter Student's First Name: \n\t\t";
            cin.ignore();
            getline(cin, firstName);
        }
        cout << "\t\tEnter Student's Last Name: \n\t\t";
        getline(cin, lastName);
        while (checkString(lastName))
        {
            cout << "\t\tError!!\n\t\tEnter Student's Last Name: \n\t\t";
            getline(cin, lastName);
        }
        cout << "\t\tEnter Student's CNIC: \n\t\t";
        cin >> cnic;
        while (check_CNIC(cnic))
        {
            cout << "\t\tError!!\n\t\tEnter Student's CNIC: \n\t\t";
            cin >> cnic;
        }
        cout << "\t\tEnter Student's Address: \n\t\t";
        cin.ignore();
        getline(cin, address);
        while (checkString(address))
        {
            cout << "\t\tError!!\n\t\tEnter Student's Address: \n\t\t";
            cin.ignore();
            getline(cin, address);
        }
        do
        {
            if (check_number(phoneNo))
            {
                cout << "\t\tError!!\n";
            }
            cout << "\t\tEnter Student's Phone Number: \n\t\t";
            cin >> phoneNo;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> phoneNo;
            }
        } while (check_number(phoneNo));
        do
        {
            if (check_studentAge(age))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Student's Age: \n\t\t";
            cin >> age;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> age;
            }
        } while (check_studentAge(age));
        int a = 1;
        do
        {
            if (check_Choice(a))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tChoose Student's Gender: [Enter 1 For Male, 2 For Female, 3 For Others]\n\t\t";
            cin >> a;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> a;
            }
        } while (check_Choice(a));
        gender = gender_Choice(a);
        cout << "\t\tEnter Student's Roll Number: \n\t\t";
        cin.ignore();
        getline(cin, roll);
        while (check_rollNO(roll))
        {
            cout << "\t\tEnter Student's Roll Number: \n\t\t";
            getline(cin, roll);
        }
        int b = 1;
        do
        {
            if (check_Choice(b))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tChoose Student's Section [Enter 1 for A, 2 for B or 3 for C]: \n\t\t";
            cin >> b;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> b;
            }
        } while (check_Choice(b));

        section = section_Choice(b);
        do
        {
            if (check_Group(group))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Student's Group: \n\t\t";
            cin >> group;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> group;
            }
        } while (check_Group(group));

        do
        {
            if (check_Semester(semester))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Student's Semester: \n\t\t";
            cin >> semester;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> semester;
            }
        } while (check_Semester(semester));

        do
        {
            if (check_CGPA(cgpa))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Student's CGPA: \n\t\t";
            cin >> cgpa;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> cgpa;
            }
        } while (check_CGPA(cgpa));
        next->set_Person(firstName, lastName, cnic, address, phoneNo, age, gender);
        next->set_Student(roll, roll, section[0], cgpa, group, semester);
        next->set_PTR(NULL);
        if (start == NULL)
        {
            start = next;
            current = start;
            size++;
        }
        else
        {
            size++;
            current = start;
            while (current->get_PTR() != NULL)
            {
                current = current->get_PTR();
            }
            current->set_PTR(next);
            current = next;
        }
        cout << "\t\tData inserted successfully.\n\t\t";
        writeFile();
    }
    void update()
    {
        int op;
        while (op != 14)
        {
            system("CLS");
            cout << "\t\tWhat would you like to update\n";
            cout << "\t\t1. First Name\n";
            cout << "\t\t2. Last Name\n";
            cout << "\t\t3. CNIC\n";
            cout << "\t\t4. Address\n";
            cout << "\t\t5. Phone Number\n";
            cout << "\t\t6. Age\n";
            cout << "\t\t7. Gender\n";
            cout << "\t\t8. Roll Number\n";
            cout << "\t\t9. Password\n";
            cout << "\t\t10. Section\n";
            cout << "\t\t11. Group\n";
            cout << "\t\t12. Semester\n";
            cout << "\t\t13. CGPA\n";
            cout << "\t\t14. Exit\n";
            cin >> op;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Enter a Number\n"
                     << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> op;
            }
            switch (op)
            {
            case 1:
                update_firstName();
                break;

            case 2:
                update_lastName();
                break;

            case 3:
                update_CNIC();
                break;

            case 4:
                update_Address();
                break;

            case 5:
                update_phoneNo();
                break;

            case 6:
                update_Age();
                break;

            case 7:
                update_Gender();
                break;

            case 8:
                update_rollNo();
                break;

            case 9:
                update_Password();
                break;

            case 10:
                update_section();
                break;

            case 11:
                update_Group();
                break;

            case 12:
                update_Semester();
                break;

            case 13:
                update_CGPA();
                break;

            case 14:
                writeFile();
                break;

            default:
                cout << "\t\tInvalid Option!! Please Try Again\n\t\t";
                system("PAUSE");
                system("CLS");
                break;
            }
        }
    }
    void update_Semester()
    {
        int semester = 1;
        do
        {
            if (check_Semester(semester))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Student's Semester: \n\t\t";
            cin >> semester;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> semester;
            }
        } while (check_Semester(semester));
        current->set_Semester(semester);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_Group()
    {
        int group = 1;
        do
        {
            if (check_Group(group))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Student's Group: \n\t\t";
            cin >> group;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> group;
            }
        } while (check_Group(group));
        current->set_Group(group);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_CGPA()
    {
        double cgpa = 1.00;
        do
        {
            if (check_CGPA(cgpa))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Student's CGPA: \n\t\t";
            cin >> cgpa;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> cgpa;
            }
        } while (check_CGPA(cgpa));
    }
    void update_section()
    {
        char section;
        int b = 1;
        do
        {
            if (check_Choice(b))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tChoose Student's Section [Enter 1 for A, 2 for B or 3 for C]: \n\t\t";
            cin >> b;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> b;
            }
        } while (check_Choice(b));

        section = section_Choice(b);
        current->set_Section(section);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_Password()
    {
        string password;
        cout << "\t\tEnter Student's Password: \n\t\t";
        cin.ignore();
        getline(cin, password);
        while (checkPassword(password))
        {
            cout << "\t\tError!!\n\t\tEnter Student's Password: \n\t\t";
            cin.ignore();
            getline(cin, password);
        }
        current->set_Password(password);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_rollNo()
    {
        string rollNo;
        cout << "\t\tEnter Student's Roll Number: \n\t\t";
        cin.ignore();
        getline(cin, roll);
        while (checkRoll(roll))
        {
            cout << "\t\tEnter Student's Roll Number: \n\t\t";
            getline(cin, roll);
        }
        current->set_rollNo(rollNo);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_Gender()
    {
        string gender;
        cout << "\t\tChoose Student's Gender: [Enter 1 For Male, 2 For Female, 3 For Others]\n\t\t";
        int a = 1;
        do
        {
            if (check_Choice(a))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tChoose Student's Gender: [Enter 1 For Male, 2 For Female, 3 For Others]\n\t\t";
            cin >> a;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> a;
            }
        } while (check_Choice(a));
        gender = gender_Choice(a);
        current->set_Gender(gender);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_Age()
    {
        int age = 20;
        do
        {
            if (check_studentAge(age))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Student's Age: \n\t\t";
            cin >> age;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> age;
            }
        } while (check_studentAge(age));
        current->set_Age(age);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_phoneNo()
    {
        long long int phoneNo = 0;
        do
        {
            if (check_number(phoneNo))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Student's Phone Number: \n\t\t";
            cin >> phoneNo;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> phoneNo;
            }
        } while (check_number(phoneNo));
        current->set_phoneNo(phoneNo);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_Address()
    {
        string address;
        cout << "\t\tEnter Student's Address: \n\t\t";
        cin.ignore();
        getline(cin, address);
        while (checkString(address))
        {
            cout << "\t\tError!!\n\t\tEnter Student's Address: \n\t\t";
            cin.ignore();
            getline(cin, address);
        }
        current->set_Address(address);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_firstName()
    {
        string firstName;
        cout << "\t\tEnter Student's First Name: \n\t\t";
        cin.ignore();
        getline(cin, firstName);
        while (checkString(firstName))
        {
            cout << "\t\tError!!\n\t\tEnter Student's First Name: \n\t\t";
            cin.ignore();
            getline(cin, firstName);
        }
        current->set_firstName(firstName);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_lastName()
    {
        string lastName;
        cout << "\t\tEnter Student's Last Name: \n\t\t";
        cin.ignore();
        getline(cin, lastName);
        while (checkString(lastName))
        {
            cout << "\t\tError!!\n\t\tEnter Student's Last Name: \n\t\t";
            cin.ignore();
            getline(cin, lastName);
        }
        current->set_lastName(lastName);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_CNIC()
    {
        string cnic;
        cout << "\t\tEnter Student's CNIC: \n\t\t";
        cin.ignore();
        getline(cin, cnic);
        while (checkCNIC(cnic))
        {
            cout << "\t\tError!!\n\t\tEnter Student's CNIC: \n\t\t";
            cin.ignore();
            getline(cin, cnic);
        }
        current->set_CNIC(cnic);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void deleteStart()
    {
        if (start == NULL)
        {
            cout << "\t\tNo Record Found\n\t\t";
        }
        else
        {
            StudentModel *temp;
            temp = start;
            start = start->get_PTR();
            delete (temp);
        }
    }
    void deleteSpecific()
    {
        string roll;
        cout << "\t\tEnter Roll Number to search Student By: \n\t\t";
        cin.ignore();
        getline(cin, roll);
        while (check_rollNO(roll))
        {
            cout << "\t\tError!!\n\t\tEnter Roll Number to search Student By: \n\t\t";
            getline(cin, roll);
        }
        int flag = 0;
        current = start;
        int count = 0;
        for (int i = 1; i <= size; i++)
        {
            if (current->get_RollNo() == roll)
            {
                count++;
                flag = 1;
                break;
            }
            count++;
            current = current->get_PTR();
        }
        if (flag == 1)
        {
            if (count == 1)
            {
                deleteStart();
            }
            else if (count == size)
            {
                deleteEnd();
            }
            else
            {
                current = start;
                for (int i = 1; i < count - 1; i++)
                {
                    current = current->get_PTR();
                }
                StudentModel *temp;
                temp = current->get_PTR();
                current->set_PTR(current->get_PTR()->get_PTR());
                delete (temp);
            }
            size--;
            cout << "\t\tNode Deleted Succeffully...\n";
        }
        if (flag == 0)
        {
            cout << "\t\tNo Record Found By That Title. Please Try Again\n";
        }
        writeFile();
    }
    void deleteEnd()
    {
        if (start == NULL)
        {
            cout << "\t\tNo Record Found\n\t\t";
        }
        else if (start->get_PTR() == NULL)
        {
            deleteStart();
        }
        else if (current == start->get_PTR())
        {
            StudentModel *temp = NULL;
            temp = current;
            start->set_PTR(NULL);
            delete (temp);
            current = start;
        }
        else
        {
            current = start;
            for (int i = 1; i <= size - 2; i++)
            {
                current = current->get_PTR();
            }
            StudentModel *temp = NULL;
            temp = current->get_PTR();
            current->set_PTR(NULL);
            delete (temp);
        }
    }
    void search_rollNo()
    {
        string rollNo;
        int flag = 0;
        cout << "\t\tEnter roll number to search a student by: \n\t\t";
        cin >> rollNo;
        current = start;
        for (int i = 1; i <= size; i++)
        {
            if (current->get_RollNo() == rollNo)
            {
                cout << "\t\tRecord Found\n";
                cout << "\t\tFirst Name: " << current->get_firstName() << "\n";
                cout << "\t\tLast Name: " << current->get_lastName() << endl;
                cout << "\t\tRoll Number: " << current->get_RollNo() << endl;
                cout << "\t\tSection: " << current->get_Section() << endl;
                cout << "\t\tGroup: " << current->get_Group() << endl;
                cout << "\t\tCGPA: " << current->get_CGPA() << endl;
                flag++;
                int ch;
                cout << "\t\tWould you like to update this data:\n\t\t1. Yes\n\t\t2. No\n\t\t";
                cin >> ch;
                switch (ch)
                {
                case 1:
                    update();
                    break;

                default:
                    break;
                }
            }
            current = current->get_PTR();
        }
        if (flag == 0)
        {
            cout << "\t\tNo student found by that roll number\n";
        }
    }
};

///////////////////////////////////////Teacher Classes/////////////////////////////////////////////////////////////////////
class teacherModel : public Person
{
private:
    string loginID, password;
    char section;
    teacherModel *ptr;

public:
    string get_LoginID()
    {
        return loginID;
    }
    void set_LoginID(string x)
    {
        loginID = x;
    }
    char get_Section()
    {
        return section;
    }
    void set_Section(char x)
    {
        section = x;
    }
    string get_Password()
    {
        return password;
    }
    void set_Password(string x)
    {
        password = x;
    }
    teacherModel *get_PTR()
    {
        return ptr;
    }
    void set_PTR(teacherModel *ptr)
    {
        this->ptr = ptr;
    }
};
class teacherData
{
private:
    courseData c1;
    Stack l3;
    string login;
    char pass[32];
    teacherModel *start;
    teacherModel *next;
    teacherModel *current;

public:
    teacherModel l1;
    int size = 0;
    teacherData()
    {
        set_Start(NULL);
        set_Current(NULL);
        set_Next(NULL);
    }
    teacherModel *get_Start()
    {
        return start;
    }
    void set_Start(teacherModel *x)
    {
        start = x;
    }
    teacherModel *get_Current()
    {
        return current;
    }
    void set_Current(teacherModel *x)
    {
        current = x;
    }
    teacherModel *get_Next()
    {
        return next;
    }
    void set_Next(teacherModel *x)
    {
        next = x;
    }
    bool checkLogin(string roll)
    {
        current = start;
        for (int i = 1; i <= size; i++)
        {
            if (roll == current->get_LoginID())
            {
                return false;
            }
            current = current->get_PTR();
        }
        return true;
    }
    bool check_CNIC(string roll)
    {
        current = start;
        for (int i = 1; i <= size; i++)
        {
            if (roll == current->get_CNIC())
            {
                return false;
            }
            current = current->get_PTR();
        }
        return true;
    }
    void attendance()
    {
        StudentData s1;
        string roll;
        do
        {
            cout << "\t\tEnter roll number of student whose attendance you want to update: \n\t\t";
            cin >> roll;
        } while (s1.checkRoll(roll));
        markMyAttendance(roll);
    }
    void display()
    {
        if (start == NULL)
        {
            cout << "\t\tNo Record Found.\n";
        }
        else
        {
            current = start;
            for (int i = 1; i <= size; i++)
            {
                cout << "\t\tTeacher " << i << endl;
                cout << "\t\tFirst Name: " << current->get_firstName() << "\n";
                cout << "\t\tLast Name: " << current->get_lastName() << endl;
                cout << "\t\tCNIC: " << current->get_CNIC() << "\n";
                cout << "\t\tPhone Number: " << current->get_phoneNo() << endl;
                cout << "\t\tAddress: " << current->get_Address() << "\n";
                cout << "\t\tAge: " << current->get_Age() << endl;
                cout << "\t\tGender: " << current->get_Gender() << "\n";
                cout << "\t\tLogin ID: " << current->get_LoginID() << endl;
                cout << endl
                     << endl;
                current = current->get_PTR();
            }
        }
    }
    void writeFile()
    {
        ofstream studentFile;
        studentFile.open("Teachers.csv");
        if (size == 0)
        {
            studentFile << "";
        }
        else
        {
            current = start;
            for (int i = 1; i <= size - 1; i++)
            {
                studentFile << current->get_firstName() << ",";
                studentFile << current->get_lastName() << ",";
                studentFile << current->get_CNIC() << ",";
                studentFile << current->get_Address() << ",";
                studentFile << current->get_phoneNo() << ',';
                studentFile << current->get_Age() << ',';
                studentFile << current->get_Gender() << ",";
                studentFile << current->get_LoginID() << ",";
                studentFile << current->get_Password() << ",";
                studentFile << endl;
                current = current->get_PTR();
            }
            studentFile << current->get_firstName() << ",";
            studentFile << current->get_lastName() << ",";
            studentFile << current->get_CNIC() << ",";
            studentFile << current->get_Address() << ",";
            studentFile << current->get_phoneNo() << ',';
            studentFile << current->get_Age() << ',';
            studentFile << current->get_Gender() << ",";
            studentFile << current->get_LoginID() << ",";
            studentFile << current->get_Password() << ",";
            studentFile.close();
        }
    }
    void createNode()
    {
        ifstream File("Teachers.csv");
        string firstName, lastName, ID, cnic, address, phoneNo, age, gender, skipline, password;

        if (File.fail()) // check for file open failure
        {
            cout << "Error opening file" << endl;
        }
        else if (File.peek() == std::ifstream::traits_type::eof())
        {
            File.close();
        }
        else
        {
            while (File.good())
            {
                next = new teacherModel;

                getline(File, firstName, ',');

                getline(File, lastName, ',');

                getline(File, cnic, ',');

                getline(File, address, ',');

                getline(File, phoneNo, ',');

                getline(File, age, ',');

                getline(File, gender, ',');

                getline(File, ID, ',');

                getline(File, password, ',');

                getline(File, skipline);

                next->set_Person(firstName, lastName, cnic, address, stoll(phoneNo), stoi(age), gender);
                next->set_LoginID(ID);
                next->set_Password(password);
                next->set_PTR(NULL);
                if (start == NULL)
                {
                    start = next;
                    current = next;
                    size++;
                }
                else
                {
                    current->set_PTR(next);
                    current = next;
                    size++;
                }
            }
            File.close();
        }
    }
    void Login()
    {
        system("CLS");
        cout << "\n\t\t";
        for (int i = 0; i < 90; i++)
        {
            cout << "\xB1";
        }
        l3.plusOne();
        cout << "\t\t\t\t\t";
        cout << "\n\n\t\tLogin Attempt:";
        l3.Peek();
        cout << "\n";
        cout << "\t\tEnter your Login ID:\n\t\t";
        cin >> login;
        int flag = 0;
        current = start;
        for (int i = 1; i <= size; i++)
        {
            if (current->get_LoginID() == login)
            {
                flag = 1;
            }
            current = current->get_PTR();
        }
        if (flag == 0)
        {
            system("CLS");
            cout << "\n\t\t\t\tWrong Credentials. Please check your roll number and password and try again.\n";
            cout << "\n\t\t\t\t\t\tLoading";
            for (int i = 0; i < 25; i++)
            {
                Sleep(20);
                cout << "\xB1";
            }
            cout << "\n\n\t\t\t\t\t\t";
            system("PAUSE");
        }
        else
        {
            cout << "\t\tEnter your password:\n\t\t";
            int i = 0;
            char a;
            for (i = 0;;)
            {
                a = getch();
                if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || (a == '-') || (a == '_'))

                {
                    pass[i] = a;
                    ++i;
                    cout << "*";
                }
                if (a == '\b' && i >= 1)

                {
                    cout << "\b \b";
                    --i;
                }
                if (a == '\r')
                {
                    pass[i] = '\0';
                    break;
                }
            }
            int flag = 0;
            current = start;
            for (int i = 1; i <= size; i++)
            {
                if (current->get_LoginID() == login && current->get_Password() == pass)
                {
                    flag = 1;
                }
                current = current->get_PTR();
            }
            if (flag == 1)
            {
                system("CLS");
                l3.Reset();
                cout << "\n\t\t\t\tLogin Successfull................\n";
                cout << "\n\t\t\t\tLoading";
                for (int i = 0; i < 25; i++)
                {
                    Sleep(20);
                    cout << "\xB1";
                }
                Menu();
            }
            else
            {
                system("CLS");
                cout << "\n\t\t\t\tWrong Credentials. Please check your roll number and password and try again.\n";
                cout << "\n\t\t\t\t\t\tLoading";
                for (int i = 0; i < 25; i++)
                {
                    Sleep(20);
                    cout << "\xB1";
                }
                cout << "\n\n\t\t\t\t\t\t";
                system("PAUSE");
            }
        }
    }
    void insertEnd()
    {
        courseData c1;
        int group = 5;
        int semester = 1;
        int age = 40;
        string cnic, address, gender;
        string firstName, roll, lastName, password;
        char section;
        long long int phoneNo = 0;
        double cgpa = 1.00;
        next = new teacherModel;
        cout << "\t\tEnter Teacher's First Name: \n\t\t";
        cin.ignore();
        getline(cin, firstName);
        while (checkString(firstName))
        {
            cout << "\t\tError!!\n\t\tEnter Teacher's First Name: \n\t\t";
            cin.ignore();
            getline(cin, firstName);
        }
        cout << "\t\tEnter Teacher's Last Name: \n\t\t";
        getline(cin, lastName);
        while (checkString(lastName))
        {
            cout << "\t\tError!!\n\t\tEnter Teacher's Last Name: \n\t\t";
            getline(cin, lastName);
        }
        cout << "\t\tEnter Teacher's CNIC: \n\t\t";
        cin >> cnic;
        while (check_CNIC(cnic))
        {
            cout << "\t\tError!!\n\t\tEnter Teacher's CNIC: \n\t\t";
            cin >> cnic;
        }
        cout << "\t\tEnter Teacher's Address: \n\t\t";
        cin.ignore();
        getline(cin, address);
        while (checkString(address))
        {
            cout << "\t\tError!!\n\t\tEnter Teacher's Address: \n\t\t";
            cin.ignore();
            getline(cin, address);
        }
        do
        {
            if (check_number(phoneNo))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Teacher's Phone Number: \n\t\t";
            cin >> phoneNo;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> phoneNo;
            }
        } while (check_number(phoneNo));
        do
        {
            if (check_teacherAge(age))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Teacher's Age: \n\t\t";
            cin >> age;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> age;
            }
        } while (check_teacherAge(age));
        int a = 1;
        do
        {
            if (check_Choice(a))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tChoose Teacher's Gender: [Enter 1 For Male, 2 For Female, 3 For Others]\n\t\t";
            cin >> a;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> a;
            }
        } while (check_Choice(a));
        gender = gender_Choice(a);
        cout << "\t\tEnter Teacher's User Name: \n\t\t";
        cin.ignore();
        getline(cin, roll);
        while (checkLogin(roll))
        {
            cout << "\t\tEnter Teacher's User Name: \n\t\t";
            getline(cin, roll);
        }
        cout << "\t\tEnter Teacher's Password: \n\t\t";
        getline(cin, password);
        while (checkPassword(password))
        {
            cout << "\t\tError!!\n\t\tEnter Teacher's Password: \n\t\t";
            cin.ignore();
            getline(cin, firstName);
        }
        int b = 1;
        do
        {
            if (check_Choice(b))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tChoose Teacher's Section [Enter 1 for A, 2 for B or 3 for C]: \n\t\t";
            cin >> b;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> b;
            }
        } while (check_Choice(b));

        section = section_Choice(b);
        next->set_Person(firstName, lastName, cnic, address, phoneNo, age, gender);
        next->set_Section(section);
        next->set_Password(password);
        next->set_LoginID(roll);
        next->set_PTR(NULL);
        if (start == NULL)
        {
            start = next;
            current = start;
            size++;
        }
        else
        {
            size++;
            current = start;
            while (current->get_PTR() != NULL)
            {
                current = current->get_PTR();
            }
            current->set_PTR(next);
            current = next;
        }
        c1.insertTeacher();
        c1.writeFile(roll);
        cout << "\t\tData inserted successfully.\n\t\t";
        writeFile();
    }
    void showInfo()
    {
        if (start == NULL)
        {
            cout << "\t\tEmpty Record.\n";
        }
        else
        {
            current = start;
            int flag = 0;
            for (int i = 1; i <= size; i++)
            {
                if (login == current->get_LoginID())
                {
                    cout << "\t\tFirst Name: " << current->get_firstName() << "\n";
                    cout << "\t\tLast Name: " << current->get_lastName() << endl;
                    cout << "\t\tCNIC: " << current->get_CNIC() << "\n";
                    cout << "\t\tPhone Number: " << current->get_phoneNo() << endl;
                    cout << "\t\tAddress: " << current->get_Address() << "\n";
                    cout << "\t\tAge: " << current->get_Age() << endl;
                    cout << "\t\tGender: " << current->get_Gender() << "\n";
                    cout << "\t\tLogin ID: " << current->get_LoginID() << endl;
                    flag++;
                }
                current = current->get_PTR();
            }
        }
    }
    void deleteStart()
    {
        if (start == NULL)
        {
            cout << "\t\tNo Record Found\n\t\t";
        }
        else
        {
            teacherModel *temp;
            temp = start;
            start = start->get_PTR();
            delete (temp);
        }
    }
    void deleteSpecific()
    {
        string roll;
        cout << "\t\tEnter User Name to search Teacher By: \n\t\t";
        cin.ignore();
        getline(cin, roll);
        while (checkLogin(roll))
        {
            cout << "\t\tError!!\n\t\tEnter User Name to search Teacher By: \n\t\t";
            getline(cin, roll);
        }
        int flag = 0;
        current = start;
        int count = 0;
        for (int i = 1; i <= size; i++)
        {
            if (current->get_LoginID() == roll)
            {
                count++;
                flag = 1;
                break;
            }
            count++;
            current = current->get_PTR();
        }
        if (flag == 1)
        {
            if (count == 1)
            {
                deleteStart();
            }
            else if (count == size)
            {
                deleteEnd();
            }
            else
            {
                current = start;
                for (int i = 1; i < count - 1; i++)
                {
                    current = current->get_PTR();
                }
                teacherModel *temp;
                temp = current->get_PTR();
                current->set_PTR(current->get_PTR()->get_PTR());
                delete (temp);
            }
            size--;
            cout << "\t\tData Deleted Successfully...\n";
        }
        if (flag == 0)
        {
            cout << "\t\tNo Record Found By That Title. Please Try Again\n";
        }
        writeFile();
    }
    void deleteEnd()
    {
        if (start == NULL)
        {
            cout << "\t\tNo Record Found\n\t\t";
        }
        else if (start->get_PTR() == NULL)
        {
            deleteStart();
        }
        else if (current == start->get_PTR())
        {
            teacherModel *temp = NULL;
            temp = current;
            start->set_PTR(NULL);
            delete (temp);
            current = start;
        }
        else
        {
            current = start;
            for (int i = 1; i <= size - 2; i++)
            {
                current = current->get_PTR();
            }
            teacherModel *temp = NULL;
            temp = current->get_PTR();
            current->set_PTR(NULL);
            delete (temp);
        }
    }
    void Menu()
    {
        system("CLS");
        int op = -1;
        while (op != 12)
        {
            assignmentData al1;
            quizData al2;
            courseData al3;
            al3.createNode_Teacher(login);
            al1.createNode_Teacher(login);
            al2.createNode_Teacher(login);
            cout << "\n\t\t";
            for (int i = 0; i < 90; i++)
            {
                cout << "\xB1";
            }
            cout << "\n\n\t\t\t\t\t\t";
            cout << "Teacher Menu";
            cout << "\n\n\t\t";
            cout << "1. View your information\n\t\t2. Create a New Assignment\n\t\t3. Create A New Quiz\n\t\t4. View Assignments Assigned by You\n\t\t5. View Quizzes Assigned by Your\n\t\t6. View Courses\n\t\t7. Search Quiz\n\t\t8. Search Assignment\n\t\t9. Delete Quiz\n\t\t10. Delete Assignment\n\t\t11. Mark Attendance\n\t\t12. Logout\n";
            cout << "\n\n\t\t";
            cout << "Enter the operation you want to perform [1-9] : \n";
            cout << "\t\t";
            cin >> op;
            while (cin.fail())
            {
                cout << "\t\tError!!" << endl;
                cout << "\t\tEnter which operation you want to perform [1-9]: \n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> op;
            }
            switch (op)
            {
            case 1:
                showInfo();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 2:
                al1.insert_Teacher(login);
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 3:
                al2.insert_Teacher(login);
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 4:
                al1.display();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 5:
                al2.display();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 6:
                al3.display();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 7:
                al2.search_Title();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 8:
                al1.search_Title();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 9:
                al2.deleteSpecific();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 10:
                al1.deleteSpecific();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 11:
                attendance();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 12:
                break;
            default:
                cout << "\t\tInvalid Option!! Please Try Again\n\t\t";
                system("PAUSE");
                system("CLS");
                break;
            }
        }
    }
    void update()
    {
        int op;
        while (op != 5)
        {
            system("CLS");
            cout << "\t\tWhat would you like to update\n";
            cout << "\t\t1. First Name\n";
            cout << "\t\t2. Last Name\n";
            cout << "\t\t3. CNIC\n";
            cout << "\t\t4. Address\n";
            cout << "\t\t5. Phone Number\n";
            cout << "\t\t6. Age\n";
            cout << "\t\t7. Gender\n";
            cout << "\t\t8. User Name\n";
            cout << "\t\t9. Password\n";
            cout << "\t\t10. Section\n";
            cout << "\t\t11. Exit\n";
            cin >> op;
            while (cin.fail())
            {
                cout << "\t\tError!!" << endl;
                cout << "\t\tEnter which operation you want to perform [1-11]: \n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> op;
            }
            switch (op)
            {
            case 1:
                update_firstName();
                break;

            case 2:
                update_lastName();
                break;

            case 3:
                update_CNIC();
                break;

            case 4:
                update_Address();
                break;

            case 5:
                update_phoneNo();
                break;

            case 6:
                update_Age();
                break;

            case 7:
                update_Gender();
                break;

            case 8:
                update_loginID();
                break;

            case 9:
                update_Password();
                break;

            case 10:
                update_section();
                break;

            case 11:
                writeFile();
                break;

            default:
                cout << "\n\t\tInvalid Option. Please try again.\n\t\t";
                system("PAUSE");
                system("CLS");
                break;
            }
        }
    }
    void update_section()
    {
        char section;
        int b = 1;
        do
        {
            if (check_Choice(b))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tChoose Teacher's Section [Enter 1 for A, 2 for B or 3 for C]: \n\t\t";
            cin >> b;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> b;
            }
        } while (check_Choice(b));

        section = section_Choice(b);
        current->set_Section(section);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_Password()
    {
        string password;
        cout << "\t\tEnter Teacher's Password: \n\t\t";
        cin.ignore();
        getline(cin, password);
        while (checkPassword(password))
        {
            cout << "\t\tError!!\n\t\tEnter Teacher's Password: \n\t\t";
            cin.ignore();
            getline(cin, password);
        }
        current->set_Password(password);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_loginID()
    {
        string loginID;
        cout << "\t\tEnter Teacher's User Name: \n\t\t";
        cin.ignore();
        getline(cin, loginID);
        while (checkLogin(loginID))
        {
            cout << "\t\tEnter Teacher's User Name: \n\t\t";
            getline(cin, loginID);
        }
        current->set_LoginID(loginID);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_Gender()
    {
        string gender;
        cout << "\t\tChoose Teacher's Gender: [Enter 1 For Male, 2 For Female, 3 For Others]\n\t\t";
        int a = 1;
        do
        {
            if (check_Choice(a))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tChoose Teacher's Gender: [Enter 1 For Male, 2 For Female, 3 For Others]\n\t\t";
            cin >> a;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> a;
            }
        } while (check_Choice(a));
        gender = gender_Choice(a);
        current->set_Gender(gender);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_Age()
    {
        int age = 20;
        do
        {
            if (check_teacherAge(age))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Teacher's Age: \n\t\t";
            cin >> age;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> age;
            }
        } while (check_teacherAge(age));
        current->set_Age(age);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_phoneNo()
    {
        long long int phoneNo = 0;
        do
        {
            if (check_number(phoneNo))
            {
                cout << "\t\tError\n";
            }
            cout << "\t\tEnter Teacher's Phone Number: \n\t\t";
            cin >> phoneNo;
            while (cin.fail())
            {
                cout << "\t\tError!! Please Try Again\n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> phoneNo;
            }
        } while (check_number(phoneNo));
        current->set_phoneNo(phoneNo);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_Address()
    {
        string address;
        cout << "\t\tEnter Teacher's Address: \n\t\t";
        cin.ignore();
        getline(cin, address);
        while (checkString(address))
        {
            cout << "\t\tError!!\n\t\tEnter Teacher's Address: \n\t\t";
            cin.ignore();
            getline(cin, address);
        }
        current->set_Address(address);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_firstName()
    {
        string firstName;
        cout << "\t\tEnter Teacher's First Name: \n\t\t";
        cin.ignore();
        getline(cin, firstName);
        while (checkString(firstName))
        {
            cout << "\t\tError!!\n\t\tEnter Teacher's First Name: \n\t\t";
            cin.ignore();
            getline(cin, firstName);
        }
        current->set_firstName(firstName);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_lastName()
    {
        string lastName;
        cout << "\t\tEnter Teacher's Last Name: \n\t\t";
        cin.ignore();
        getline(cin, lastName);
        while (checkString(lastName))
        {
            cout << "\t\tError!!\n\t\tEnter Teacher's Last Name: \n\t\t";
            cin.ignore();
            getline(cin, lastName);
        }
        current->set_lastName(lastName);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void update_CNIC()
    {
        string cnic;
        cout << "\t\tEnter Teacher's CNIC: \n\t\t";
        cin.ignore();
        getline(cin, cnic);
        while (check_CNIC(cnic))
        {
            cout << "\t\tError!!\n\t\tEnter Teacher's CNIC: \n\t\t";
            cin.ignore();
            getline(cin, cnic);
        }
        current->set_CNIC(cnic);
        cout << "\t\tData updated successfully.\n\t\t";
    }
    void search_Login()
    {
        string rollNo;
        int flag = 0;
        cout << "\t\tEnter Login ID to search a teacher by: \n\t\t";
        cin >> rollNo;
        current = start;
        for (int i = 1; i <= size; i++)
        {
            if (current->get_LoginID() == rollNo)
            {
                cout << "\t\tRecord Found\n";
                cout << "\t\tFirst Name: " << current->get_firstName() << "\n";
                cout << "\t\tLast Name: " << current->get_lastName() << endl;
                cout << "\t\tUser Name: " << current->get_LoginID() << endl;
                cout << "\t\tSection: " << current->get_Section() << endl;
                flag++;
                int ch;
                cout << "\t\tWould you like to update this data:\n\t\t1. Yes\n\t\t2. No\n\t\t";
                cin >> ch;
                switch (ch)
                {
                case 1:
                    update();
                    break;

                default:
                    break;
                }
            }
            current = current->get_PTR();
        }
        if (flag == 0)
        {
            cout << "\t\tNo teacher found by that Login ID\n";
        }
    }
};

///////////////////////////////////////Admin Classes///////////////////////////////////////////////////////////////////////
class adminNode
{
private:
    string loginID;
    string password;
    adminNode *ptr;

public:
    adminNode()
    {
        loginID = password = "<<Empty>>";
    }
    string getLoginID()
    {
        return loginID;
    }
    void set_LoginID(string x)
    {
        loginID = x;
    }
    string get_lastName()
    {
        return password;
    }
    void set_Password(string x)
    {
        password = x;
    }
    adminNode *get_PTR()
    {
        return ptr;
    }
    void set_PTR(adminNode *x)
    {
        ptr = x;
    }
};
class adminLogin
{
private:
    int size = 0;
    adminNode *start, *current, *next;
    Stack l1;

public:
    adminLogin()
    {
        set_Start(NULL);
        set_Current(NULL);
        set_Next(NULL);
    }
    adminNode *get_Start()
    {
        return start;
    }
    void set_Start(adminNode *x)
    {
        start = x;
    }
    adminNode *get_Current()
    {
        return current;
    }
    void set_Current(adminNode *x)
    {
        current = x;
    }
    adminNode *get_Next()
    {
        return next;
    }
    void set_Next(adminNode *x)
    {
        next = x;
    }
    void adminMenu()
    {
        system("CLS");
        int op = -1;
        StudentData am1;
        courseData am2;
        teacherData am3;
        am2.createNode();
        am1.createNode();
        am3.createNode();
        while (op != 13)
        {
            cout << "\n\t\t";
            for (int i = 0; i < 90; i++)
            {
                cout << "\xB1";
            }
            cout << "\n\n\t\t\t\t\t\t";
            cout << "Admin Menu\n\n";
            cout << "\t\t1. Display All Student Data\n\t\t2. Insert New Student Data\n\t\t3. Delete Student Data\n\t\t4. Display All Course Data\n\t\t5. Insert New Course Data\n\t\t6. Delete Course Data\n\t\t7. Display All Teacher Data\n\t\t8. Insert Teacher Data\n\t\t9. Delete Teacher Data\n\t\t10. Search Student Data\n\t\t11. Search Teacher Data\n\t\t12. Search Course Data\n\t\t13. Exit\n";
            cout << "\n\t\tEnter the operation you want to perform: [1-7]\n\t\t";
            cin >> op;
            while (cin.fail())
            {
                cout << "\t\tError!!" << endl;
                cout << "\t\tEnter which operation you want to perform [1-5]: \n\t\t";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> op;
            }
            switch (op)
            {
            case 1:
                am1.display();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 2:
                am1.insertEnd();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 3:
                am1.deleteSpecific();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 4:
                am2.display();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 5:
                am2.insertEnd();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 6:
                am2.deleteSpecific();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 7:
                am3.display();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 8:
                am3.insertEnd();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 9:
                am3.deleteSpecific();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 10:
                am1.search_rollNo();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 11:
                am3.search_Login();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 12:
                am2.search_Login();
                cout << "\t\t";
                system("PAUSE");
                system("CLS");
                break;

            case 13:
                break;

            default:
                cout << "\t\tInvalid Option!! Please Try Again\n\t\t";
                system("PAUSE");
                system("CLS");
                break;
            }
        }
    }
    void createNode()
    {
        ifstream File("adminLogin.csv");
        string login, password, skipline;

        if (File.is_open())
        {
            while (File.good())
            {
                next = new adminNode;
                getline(File, login, ',');

                getline(File, password, ',');

                getline(File, skipline);

                next->set_LoginID(login);
                next->set_Password(password);
                next->set_PTR(NULL);
                if (start == NULL)
                {
                    start = next;
                    current = next;
                    size++;
                }
                else
                {
                    current->set_PTR(next);
                    current = next;
                    size++;
                }
            }
        }
        else
        {
            cout << string("Error Message!\n");
        }
    }
    void Login()
    {
        string loginCheck;
        system("CLS");
        cout << "\n\t\t";
        for (int i = 0; i < 90; i++)
        {
            cout << "\xB1";
        }
        l1.plusOne();
        cout << "\t\t\t\t\t";
        cout << "\n\n\t\tLogin Attempt:";
        l1.Peek();
        cout << "\n";
        cout << "\t\tEnter your login:\n\t\t";
        cin >> loginCheck;
        int flag = 0;
        current = start;
        for (int i = 1; i <= size; i++)
        {
            if (current->getLoginID() == loginCheck)
            {
                flag++;
            }
            current = current->get_PTR();
        }
        if (flag == 0)
        {
            system("CLS");
            cout << "\n\t\t\t\tWrong Credentials. Please check your roll number and try again.\n";
            cout << "\n\t\t\t\t\t\tLoading";
            for (int i = 0; i < 25; i++)
            {
                Sleep(20);
                cout << "\xB1";
            }
            cout << "\n\n\t\t\t\t\t\t";
            system("PAUSE");
        }
        else
        {
            cout << "\t\tEnter your password:\n\t\t";
            char pass[32];
            int i = 0;
            char a;
            for (i = 0;;)
            {
                a = getch();
                if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))

                {
                    pass[i] = a;
                    ++i;
                    cout << "*";
                }
                if (a == '\b' && i >= 1)

                {
                    cout << "\b \b";
                    --i;
                }
                if (a == '\r')
                {
                    pass[i] = '\0';
                    break;
                }
            }
            int flag = 0;
            current = start;
            for (int i = 1; i <= size; i++)
            {
                if (current->getLoginID() == loginCheck && current->get_lastName() == pass)
                {
                    flag++;
                }
                current = current->get_PTR();
            }
            if (flag == 0)
            {
                system("CLS");
                cout << "\n\t\t\t\tWrong Credentials. Please check your roll number and password and try again.\n";
                cout << "\n\t\t\t\t\t\tLoading";
                for (int i = 0; i < 25; i++)
                {
                    Sleep(20);
                    cout << "\xB1";
                }
                cout << "\n\n\t\t\t\t\t\t";
                system("PAUSE");
            }
            else
            {
                system("CLS");
                l1.Reset();
                cout << "\n\t\t\t\tLogin Successfull................\n";
                cout << "\n\t\t\t\tLoading";
                for (int i = 0; i < 25; i++)
                {
                    Sleep(20);
                    cout << "\xB1";
                }
                adminMenu();
            }
        }
    }
};

/////////////////////////////////////Main Function////////////////////////////////////////////////////////////////////////
int main()
{
    StudentData s1;
    adminLogin a1;
    teacherData t1;
    int op = -1;
    a1.createNode();
    s1.createNode();
    t1.createNode();
    cout << "\n\t\t";
    for (int i = 0; i < 90; i++)
    {
        Sleep(1);
        cout << "\xB1";
    }
    cout << "\t\t\t\t\t";
    cout << "\n\n";
    cout << "\t\t\t\t\t  LEARNING MANAGEMENT SYSTEM  ";
    cout << "\n\n";
    cout << "\t\t\t";
    cout << "Prepared by:\n\n";
    cout << "\t\t\t\t\t";
    cout << "\tGroup 6\n\n";
    cout << "\t\t\t\t";
    cout << "\tWaqas Ahmad   (20021519-029)\n\n";
    cout << "\t\t\t\t";
    cout << "\tUsama Rafaqat (20021519-047)\n\n";
    cout << "\t\t\t\t";
    cout << "\tHassan Tahir  (20021519-083)\n\n";
    cout << "\t\t\t\t";
    cout << "\tMuhammad Daud (20021519-148)\n\n";
    cout << "\n\t\t";
    system("PAUSE");

    while (op != 4)
    {
        system("CLS");
        cout << "\n\t\t";
        for (int i = 0; i < 90; i++)
        {
            cout << "\xB1";
        }
        cout << "\n\n\t\t\t\t\t\t";
        cout << "LOGIN FORM\n";
        cout << "\n\t\t";
        cout << "1. Login as Student";
        cout << "\n\t\t";
        cout << "2. Login as Teacher";
        cout << "\n\t\t";
        cout << "3. Login as Admin";
        cout << "\n\t\t";
        cout << "4. Exit";
        cout << "\n\n\t\t";
        cout << "Enter which operation you want to perform [1-4]: ";
        cout << "\n\t\t";
        cin >> op;
        while (cin.fail())
        {
            cout << "\t\tError!!" << endl;
            cout << "\t\tEnter which operation you want to perform [1-4]: \n\t\t";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> op;
        }
        switch (op)
        {
        case 1:
            s1.Login();
            break;

        case 2:
            t1.Login();
            break;

        case 3:
            a1.Login();
            break;
        case 4:
            break;

        default:
            cout << "\t\tInvalid Opertion. Please try again\n\t\t";
            system("PAUSE");
            system("CLS");
            break;
        }
    }
    return 0;
}