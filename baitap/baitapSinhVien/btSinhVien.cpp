#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef enum
{
    MALE,
    FEMALE
}TypeSex;

typedef enum
{
    EXCELLENT,
    GOOD,
    FAIR,
    POOR
}TypeRank;

class SinhVien
{
    private:
        uint8_t ID;
        string NAME;
        TypeSex SEX;
        uint8_t AGE;
        float MATH;
        float PHYSIC;
        float CHEMISTRY;
        float AVERAGE; 
        TypeRank RANK;
    
    public:
        SinhVien(string name, TypeSex sex, uint8_t age, float math, float physic, float chemistry);
        uint8_t getID();
        string getName();
        TypeSex getSex();
        uint8_t getAge();
        float getMath();
        float getPhysic();
        float getChemistry();
        float getAverage();
        TypeRank getRank();

        void changeName(string name);
        void changeSex(TypeSex sex);
        void changeAge(uint8_t age);
        void changeMath(float math);
        void changePhysic(float physic);
        void changeChemistry(float chemistry);


};

SinhVien::SinhVien(string name, TypeSex sex, uint8_t age, float math, float physic, float chemistry)
{
    static uint8_t id = 0;
    ID = id;
    id++;
    NAME = name;
    SEX = sex;
    AGE = age;
    MATH = math;
    PHYSIC = physic;
    CHEMISTRY = chemistry;
}

uint8_t SinhVien::getID()
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

uint8_t SinhVien::getAge()
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
    AVERAGE = (MATH + PHYSIC + CHEMISTRY)/3;
    return AVERAGE;
}

TypeRank SinhVien::getRank()
{
    if(AVERAGE >= 8)
    {
        RANK = EXCELLENT;
    }
    else if(AVERAGE >= 6.5)
    {
        RANK = GOOD;
    }
    else if(AVERAGE >= 5)
    {
        RANK = FAIR;
    }
    else
    {
        RANK = POOR;
    }
    return RANK;
}

void SinhVien::changeName(string name)
{
    NAME = name;
}

void SinhVien::changeSex(TypeSex sex)
{
    SEX = sex;
}

void SinhVien::changeAge(uint8_t age)
{
    AGE = age;
}

void SinhVien::changeMath(float math)
{
    MATH = math;
}

void SinhVien::changePhysic(float physic)
{
    PHYSIC = physic;
}

void SinhVien::changeChemistry(float chemistry)
{
    CHEMISTRY = chemistry;
}

class Menu
{
    private:
        list<SinhVien> Database;
    public: 
        void addStudent();
        void changeStudent();

};

void Menu::addStudent()
{
    string name;
    TypeSex sex;
    uint8_t age;
    float math;
    float physic;
    float chemistry;

    cout<<"Enter new student"<<endl;
    do
    {
        cout<<" Enter student name:";
        cin>>name;
        cout<<"Enter sex:\t 1:MALE \t 0:FEMALE";
        uint8_t number;
        cin>>number;
        if(number == 1)
        {
            sex = MALE;
        }
        else
        {
            sex = FEMALE;
        }
        cout<<"Enter age:";
        cin>>age;
        cout<<"enter math";
        cin>>math;
        cout<<"Enter physic:";
        cin>>math;
        cout<<"Enter chemistry";
        cin>>chemistry;
    }
    while
    (
        !(
            (math >= 0 && math <= 10) && 
            (physic >= 0 && physic <= 10) && 
            (chemistry >= 0 && chemistry <= 10) && 
            (age > 0 && age < 100)
        )
    );

    SinhVien sv(name, sex, age, math, physic, chemistry);
    Database.push_back(sv);

}

int main()
{
    return 0;
}