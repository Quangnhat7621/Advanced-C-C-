#include <iostream>
#include <list>
#include <string>

using namespace std;

class Dish
{
    private:
        string dishName;
        uint16_t dishPrice;
        uint8_t dishID;
    public:
        Dish(string dishName, uint16_t price);
        uint8_t getDishID();
        string getDishName();
        uint16_t getDishPrice();
        void setDishName();
        void setDishPrice();
        void printDishInformation();
}; 

Dish::Dish(string vice_dishName, uint16_t vice_dishPrice)
{
    static uint8_t ID = 0;
    dishID = ID;
    ID++;
    dishName = vice_dishName;
    dishPrice = vice_dishPrice;

}

uint8_t Dish::getDishID()
{
    return dishID;
}

string Dish::getDishName()
{
    return dishName;
}

uint16_t Dish::getDishPrice()
{
    return dishPrice;
}

void Dish::setDishName()
{
    cout<<"Enter dish name: ";
    cin>>dishName;
}

void Dish::setDishPrice()
{
    cout<<"Enter dish price: ";
    cin>>dishPrice;
}
void Dish::printDishInformation()
{
    cout<<"Dish ID: "<<dishID<<endl;
    cout<<"Dish name: "<<dishName<<endl;
    cout<<"Dish price: "<<dishPrice<<endl;
}

class Manager
{
    private:
        list <Dish> DishDatabase;
        uint8_t numberOfTable;
    public:
        void addDish();
        void deleteDish();
        void changeDishInformation();
        void menu();
        uint8_t getNumberOfTable();
        list <Dish> getDishDatabase();


};

uint8_t Manager::getNumberOfTable()
{
    return this->numberOfTable;
}
list <Dish> Manager::getDishDatabase()
{
    return this->DishDatabase;
}
void Manager::addDish()
{  
    string vice_dishName;
    uint16_t vice_dishPrice;
    cout<<"Enter dish name: ";
    cin>>vice_dishName;
    cout<<"Enter dish price: ";
    cin>>vice_dishPrice;

    Dish dish(vice_dishName, vice_dishPrice);

    DishDatabase.push_back(dish);
}

void Manager::changeDishInformation()
{
    for(auto temp: DishDatabase)
    {
        temp.printDishInformation();
    }

    uint8_t ID;
    cout<<"Enter dish ID that you want to change information: ";
    cin>>ID;
    for(auto &temp: DishDatabase)
    {
        if(temp.getDishID() == ID)
        {
            temp.setDishName();
            temp.setDishPrice();
            break;
        }
    }
    cout<<"ID is valid"<<endl;
}

void Manager::menu()
{
    for(auto temp: DishDatabase)
    {
        temp.printDishInformation();
    }
}

void Manager::deleteDish()
{
    menu();
    uint8_t ID;
    cout<<"Enter ID that you want to delete: ";
    cin>>ID;
    auto position = DishDatabase.begin();
    for(auto temp : DishDatabase)
    {
        if(temp.getDishID() == ID)
        {
            DishDatabase.erase(position);
            break;
        }
        position++;
    }
    cout<<"ID is valid"<<endl;

}

class TableStatus
{
    private:
        uint8_t tableOrder;
        bool tableStatus;
        list<Dish> dishList;
        typedef struct
        {
            Dish dish;
            uint8_t dishQuantity;
        }TypeDish;
        list <TypeDish> table_dishDatabase;

    public:
        TableStatus(uint8_t vice_tableOrder, bool vice_tableStatus, list<Dish> vice_dishLish);
        uint8_t getTableOrder();
        bool getTableStatus();
        void setTableStatus(bool status);
        void addDish(uint8_t vice_dishQuantity);
        void changeDish();
        void deleteDish();
        list <TypeDish> table_dishDatabase();
};

TableStatus::TableStatus(uint8_t vice_tableOrder, bool vice_tableStatus, list<Dish> vice_dishList)
{
    this->tableOrder = vice_tableOrder;
    this->tableStatus = vice_tableStatus;
    this->dishList = vice_dishList;
}

bool TableStatus::getTableStatus()
{
    return tableStatus;
}

uint8_t TableStatus::getTableOrder()
{
    return tableOrder;
}

void TableStatus::setTableStatus(bool status)
{
    this->tableStatus = status;
}

void TableStatus::addDish(uint8_t vice_dishQuantity)
{
    for(auto temp : dishList)
    {
        temp.printDishInformation();
    }
    
    uint8_t ID;
    cout<<"Enter ID to serve: ";
    cin>>ID;

    for(auto temp : dishList)
    {
        if(temp.getDishID() == ID)
        {
            TypeDish typedish(, vice_dishQuantity);
        }
    }


}