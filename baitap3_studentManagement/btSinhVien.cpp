#include <iostream>
#include <string>
#include <list>
#include <stdbool.h>
#include<fstream>


using namespace std;

typedef enum
{
    MALE,
    FEMALE
} TypeSex;

typedef enum
{
    EXCELLENT,
    GOOD,
    FAIR,
    POOR
} TypeRank;

class SinhVien
{
    private:
        int ID;
        string NAME;
        TypeSex SEX;
        int AGE;
        float MATH;
        float PHYSIC;
        float CHEMISTRY;
        float AVERAGE;
        TypeRank RANK;

    public:
        SinhVien(string name, TypeSex sex, int age, float math, float physic, float chemistry);
        int getID();
        string getName();
        TypeSex getSex();
        int getAge();
        float getMath();
        float getPhysic();
        float getChemistry();
        float getAverage();
        TypeRank getRank();

        void changeName();
        void changeSex();
        void changeAge();
        void changeMath();
        void changePhysic();
        void changeChemistry();

        void information();
};

SinhVien::SinhVien(string name, TypeSex sex, int age, float math, float physic, float chemistry)
{
    static int id = 0;
    ID = id;
    id++;
    NAME = name;
    SEX = sex;
    AGE = age;
    MATH = math;
    PHYSIC = physic;
    CHEMISTRY = chemistry;
}

int SinhVien::getID()
{
    return ID;
}

string SinhVien::getName()
{
    return NAME;
}

TypeSex SinhVien::getSex()
{
    return SEX;
}

int SinhVien::getAge()
{
    return AGE;
}

float SinhVien::getMath()
{
    return MATH;
}

float SinhVien::getPhysic()
{
    return PHYSIC;
}

float SinhVien::getChemistry()
{
    return CHEMISTRY;
}

float SinhVien::getAverage()
{
    AVERAGE = (MATH + PHYSIC + CHEMISTRY) / 3;
    return AVERAGE;
}

TypeRank SinhVien::getRank()
{
    if (AVERAGE >= 8)
    {
        RANK = EXCELLENT;
    }
    else if (AVERAGE >= 6.5)
    {
        RANK = GOOD;
    }
    else if (AVERAGE >= 5)
    {
        RANK = FAIR;
    }
    else
    {
        RANK = POOR;
    }
    return RANK;
}

void SinhVien::changeName()
{
    string name;
    cout<<"enter name: ";
    cin>>name;
    SinhVien::NAME = name;
}

void SinhVien::changeSex()
{
    TypeSex sex;
    int number;
    cout << "Enter sex:\t 0:MALE \t 1:FEMALE";
    cin >> number;
    if (number == 1)
    {
        sex = FEMALE;
    }
    else
    {
        sex = MALE;
    }
    SEX = sex;
}

void SinhVien::changeAge()
{
    int age;
    cout<<"enter age: ";
    cin>>age;
    AGE = age;
}

void SinhVien::changeMath()
{
    float math;
    cout<<"enter math grade: ";
    cin>>math;
    MATH = math;
}

void SinhVien::changePhysic()
{
    float physic;
    cout<<"enter physic grade: ";
    cin>>physic;
    PHYSIC = physic;
}

void SinhVien::changeChemistry()
{
    float chemistry;
    cout<<"enter chemistry grade: ";
    cin>>chemistry;
    CHEMISTRY = chemistry;
}

void SinhVien::information()
{
    cout<<"-------------------------------------------------------------"<<endl;
    cout << "ID: " << (int)ID << endl;
    cout << "name: " << NAME << endl;
    cout << "sex: " << SEX << endl;
    cout << "age: " << AGE << endl;
    cout << "math: " << MATH << endl;
    cout << "physic: " << PHYSIC << endl;
    cout << "chemsistry: " << CHEMISTRY << endl;
}

class Menu
{
private:
    list<SinhVien> Database;

public:
    // Menu();
    void addStudent();
    void changeStudentInformation();
    void deleteStudentByID();
    void findStudentByName();
    void sortStudentByGPA();
    void sortStudentByName();
    void displayList();
    void witeTxtFile();

};

// Menu::Menu()
// {   int options;
//     cout<<"choose options!"<<endl;
//     cout<<"press 0 to add a new student"<<endl;
//     cout<<"press 1 to update student's information by ID"<<endl;
//     cout<<"press 2 to delete student by ID"<<endl;
//     cout<<"press 3 to find student by name"<<endl;
//     cout<<"press 4 to sort students by GPA"<<endl;
//     cout<<"press 5 to sort students by name"<<endl;
//     cout<<"press 6 to display students list"<<endl;
//     cout<<"press 7 to write students list into student.txt file"<<endl;
//     cout<<"enter options: ";
//     cin>>options;
//     switch (options)
//     {
//     case 0:
//         addStudent();
//         break;
//     case 1:
//         changeStudentInformation();
//         break;
//     case 2:
//         deleteStudentByID();
//     case 6:
//         displayList();
//     }
// }

void Menu::addStudent()
{
    string name;
    TypeSex sex;
    int age;
    float math;
    float physic;
    float chemistry;

    int number;
    bool first_fill_in = true;
    cout << "Enter new student" << endl;
    do
    {
        if(first_fill_in == false)
        cout<<"Enter student information again!"<<endl;
        cout << " Enter student name:";
        cin >> name;
        cout << "Enter sex:\t 0:MALE \t 1:FEMALE";

        cin >> number;
        if (number == 1)
        {
            sex = FEMALE;
        }
        else
        {
            sex = MALE;
        }
        cout << "Enter age:";
        cin >> age;
        cout << "enter math:";
        cin >> math;
        cout << "Enter physic:";
        cin >> physic;
        cout << "Enter chemistry";
        cin >> chemistry;
        first_fill_in = false;
    } while (
        !(
            (math >= 0 && math <= 10) &&
            (physic >= 0 && physic <= 10) &&
            (chemistry >= 0 && chemistry <= 10) &&
            (age > 0 && age < 100) &&
            (number == 1 || number == 0)
                ));
    if (number == 1)
    {
        cout << "male" << endl;
    }
    else
    {
        cout << "female" << endl;
    }
    SinhVien sv(name, sex, age, math, physic, chemistry);
    Database.push_back(sv);
}
void Menu::displayList()
{
    for (SinhVien item : Database)
    {
        item.information();
    }
}

void Menu::changeStudentInformation()
{
    int ID;
    cout<<"change student information"<<endl;
    cout<<"enter student ID that you want to change: ";
    cin>>ID;
    for(SinhVien &item : Database)
    {
        if(item.getID() == ID)
        {

            cout<<"entered ID"<<endl;
            cout<<"choose options:"<<endl;
            cout<<"press 0 to change name."<<endl;
            cout<<"press 1 to change sex."<<endl;
            cout<<"press 2 to change age."<<endl;
            cout<<"press 3 to change math grade."<<endl;
            cout<<"press 4 to change physic grade."<<endl;
            cout<<"press 5 to change chemistry grade."<<endl;
            cout<<"press 6 to choose all options."<<endl;
            cout<<"press other number to back!"<<endl;
            
            cout<<"enter options:";
            int options;
            cin>>options;
            cout<<"************************************************************\n"<<endl;
            switch (options)
            {
            case 0:
                item.changeName();
                break;
            case 1:
                item.changeSex();
                break;
            case 2:
                item.changeAge();
                break;
            case 3:
                item.changeMath();
                break;
            case 4:
                item.changePhysic();
                break;
            case 5:
                item.changeChemistry();
                break;
            case 6:
                item.changeName();
                item.changeSex();
                item.changeAge();
                item.changeMath();
                item.changePhysic();
                item.changeChemistry();
                break;
            default:
                break;
            
            }

            
        }
    
    }
    cout<<"there is no suitable ID"<<endl;
}

void Menu::deleteStudentByID()
{
    int id;
    cout<<"enter student ID that will be deleted: ";
    cin>>id;
    auto position = Database.begin();
    for(SinhVien item: Database)
    {
        
        if(item.getID() == id)
        {
            Database.erase(position);
            break;
        }
        position++;
    }
}

void Menu::findStudentByName()
{
    bool state = false;
    string name;
    cout<<"Enter student name to find: ";
    cin>>name;
    for(SinhVien item : Database)
    {
        if(item.getName() == name)
        {
            item.information();
            state = true;
            break;
        }
    }
    if(state == false)
    {
        cout<<"incorrect name input"<<endl;
    }
    
}



void Menu::sortStudentByGPA()
{

    Database.sort([](SinhVien a, SinhVien b){return a.getAverage() < b.getAverage();});


}

void Menu::sortStudentByName()
{
    Database.sort([]( SinhVien a, SinhVien b) {
        return a.getName() < b.getName();
    });
}

void Menu::witeTxtFile()
{
    ofstream outputFile("student.txt");
    if(outputFile.is_open())
    {
        outputFile<<"ID"<<"\t"<<"student_name"<<"\t"<<"student_age"<<"\t"<<"math_grade"<<"\t"<<"physic_grade"<<"\t"<<"chemistry_grade"<<endl;

        for(SinhVien student:Database)
        {
            outputFile<<student.getID()<<"\t"<<student.getName()<<"\t\t"<<student.getAge()<<"\t\t"<<student.getMath()<<"\t\t"<<student.getPhysic()<<"\t\t"<<student.getChemistry()<<endl;
        }
        outputFile.close();
    }
}

typedef enum
{   
    ADD_STUDENT,
    UPDATE_INFORMATION,
    DELETE_BY_ID,
    FIND_BY_NAME,
    SORT_BY_GPA,
    SORT_BY_NAME,
    DISPLAY_LIST,
    WRITE_FILE
} TypeOptions;

int main()
{

    Menu menu1;

    while(1)
    {
        int options;
        cout<<"*******************************************************"<<endl;
        cout<<"choose options!"<<endl;
        cout<<"press 0 to add a new student"<<endl;
        cout<<"press 1 to update student's information by ID"<<endl;
        cout<<"press 2 to delete student by ID"<<endl;
        cout<<"press 3 to find student by name"<<endl;
        cout<<"press 4 to sort students by GPA"<<endl;
        cout<<"press 5 to sort students by name"<<endl;
        cout<<"press 6 to display students list"<<endl;
        cout<<"press 7 to write students list into student.txt file"<<endl;
        cout<<"enter options: ";
        cin>>options;

        cout<<"***********************************************************\n"<<endl;
        switch (options)
        {
        case ADD_STUDENT:
            menu1.addStudent();
            break;
        case UPDATE_INFORMATION:
            menu1.changeStudentInformation();
            break;
        case DELETE_BY_ID:
            menu1.deleteStudentByID();
            break;
        case FIND_BY_NAME:
            menu1.findStudentByName();
            break;
        case SORT_BY_GPA: 
            menu1.sortStudentByGPA();
            break;
        case SORT_BY_NAME:
            menu1.sortStudentByName();
            break;
        case DISPLAY_LIST:
            menu1.displayList();
            break;
        case WRITE_FILE:
            menu1.witeTxtFile();
            break;
        }
    }

    return 0;
}