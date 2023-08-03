#include <iostream>
#include <list>
#include <string>

using namespace std;

bool Manager_flag = true;
bool serving_table_flag = true;

class Dish
{
    private:
        string dishName;
        uint16_t dishPrice;
        int dishID;
    public:
        void createDish(string dishName, uint16_t price);
        int getDishID();
        string getDishName();
        uint16_t getDishPrice();
        void setDishName();
        void setDishPrice();
        void printDishInformation();
}; 

void Dish::createDish(string vice_dishName, uint16_t vice_dishPrice)
{
    static int ID = 0;
    dishID = ID;
    ID++;
    dishName = vice_dishName;
    dishPrice = vice_dishPrice;

}

int Dish::getDishID()
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
    cout<<"-----------------------------------------------------"<<endl;
}

class Manager
{
    private:
        list <Dish> DishDatabase;
        int numberOfTable;
    public:
        void manager_start();
        void manager_setNumberOfTable();
        void manager_addDish();
        void manager_deleteDish();
        void manager_changeDishInformation();
        void manager_menu();
        int manager_getNumberOfTable();
        list <Dish> manager_getDishDatabase();


};

void Manager::manager_start()
{
    cout<<"------------MANAGER FIELD!-------------"<<endl;
    cout<<"press 0 to set the number of table."<<endl;
    cout<<"press 1 to add dish."<<endl;
    cout<<"press 2 to delete dish."<<endl;
    cout<<"press 3 to change dish information."<<endl;
    cout<<"press 4 to dispay menu."<<endl;
    cout<<"press 5 to exit."<<endl;
    int options;
    cout<<"enter options: ";
    cin>>options;
    cout<<"******************************************************"<<endl;
    switch(options)
    {
        case 0:
            manager_setNumberOfTable();
            break;
        case 1:
            manager_addDish();
            break;
        case 2:
            manager_deleteDish();
            break;
        case 3:
            manager_changeDishInformation();
            break;
        case 4:
            manager_menu();
            break;
        case 5:
            Manager_flag = false;
    };
}

void Manager::manager_setNumberOfTable()
{
    cout<<"Enter the number of table: ";
    cin>>numberOfTable;
    cout<<"*****************************************"<<endl;
}

int Manager::manager_getNumberOfTable()
{
    return this->numberOfTable;
}
list <Dish> Manager::manager_getDishDatabase()
{
    return this->DishDatabase;
}
void Manager::manager_addDish()
{  
    string vice_dishName;
    uint16_t vice_dishPrice;
    cout<<"Enter dish name: ";
    cin>>vice_dishName;
    cout<<"Enter dish price: ";
    cin>>vice_dishPrice;
    cout<<"**************************************************"<<endl;
    Dish dish;
    dish.createDish(vice_dishName, vice_dishPrice);
    DishDatabase.push_back(dish);
}

void Manager::manager_changeDishInformation()
{
    for(auto temp: DishDatabase)
    {
        temp.printDishInformation();
    }

    int ID;
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

void Manager::manager_menu()
{
    for(auto temp: DishDatabase)
    {
        temp.printDishInformation();
    }
}

void Manager::manager_deleteDish()
{
    manager_menu();
    int ID;
    cout<<"Enter dish ID that you want to delete: ";
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

class TableInfor 
{
private:
    int tableNumber;
    bool tableStatus;
    list<Dish> dishList;

    typedef struct
    {
        int dishQuantity;
        Dish dish;
       
    }TypeDish;
    list<TypeDish> table_dishDatabase;

public:
    TableInfor(int vice_tableNumber, bool vice_tableStatus, list<Dish> vice_dishList);
    int table_getOrder();
    bool table_getStatus();
    void table_setStatus(bool status);
    void table_addDish();
    void table_changeDish();
    void table_deleteDish();
    void table_listDish();
    void table_getBill();
};

TableInfor::TableInfor(int vice_tableNumber, bool vice_tableStatus, list<Dish> vice_dishList)
{
    tableNumber = vice_tableNumber;
    tableStatus = vice_tableStatus;
    dishList = vice_dishList;
}

bool TableInfor::table_getStatus()
{
    return tableStatus;
}

int TableInfor::table_getOrder()
{
    return tableNumber;
}

void TableInfor::table_setStatus(bool status)
{
    tableStatus = status;
}

void TableInfor::table_addDish()
{
    for (auto temp : dishList)
    {
        temp.printDishInformation();
    }

    int ID;
    cout << "Enter Dish ID to serve: ";
    cin >> ID;
    int dishQuantity;
    cout << "Enter quantity: ";
    cin >> dishQuantity;
    cout<<"****************************************************************"<<endl;
    for (Dish temp : dishList)
    {
        if (temp.getDishID() == ID)
        {
            TypeDish typeDish;
            typeDish.dish = temp;
            typeDish.dishQuantity = dishQuantity;
            table_dishDatabase.push_back(typeDish);
            table_setStatus(true);      // having customer add ordered 
            break;
        }
    }
}

void TableInfor::table_changeDish()
{
    for(TypeDish item: table_dishDatabase)
    {
        item.dish.printDishInformation();
    }
    cout<<"Enter dish ID to change information: ";
    int id;
    cin>>id;
    cout<<"Enter new quantity: ";
    int new_quantity;
    cin>>new_quantity;
    cout<<"**************************************************"<<endl;
    for(TypeDish &item : table_dishDatabase)
    {
        if(item.dish.getDishID() == id)
        {
            item.dishQuantity = new_quantity;
            break;
        }
    }
}

void TableInfor::table_deleteDish()
{
    for(TypeDish item: table_dishDatabase)
    { 
        item.dish.printDishInformation();
    }
    cout<<"Enter dish ID to delete: ";
    int id;
    cin>>id;
    cout<<"**************************************************************"<<endl;
    list<TypeDish>::iterator it = table_dishDatabase.begin();
    for(TypeDish item : table_dishDatabase)
    {
        if(item.dish.getDishID() == id)
        {
            table_dishDatabase.erase(it);
            break;
        }
        ++it;
    }
}

void TableInfor::table_listDish()
{
    cout<<"table number: "<<tableNumber<<endl;
    for(TypeDish item: table_dishDatabase)
    { 
        item.dish.printDishInformation();
        cout<<"Quantity: "<<item.dishQuantity<<endl;
    }
    cout<<"********************************************************"<<endl;
}

void TableInfor::table_getBill()
{
    
    int total = 0;
    int STT = 1;
    for(TypeDish item: table_dishDatabase)
    { 
        cout<<"STT: "<<STT<<"\t"<<"Dish ID: "<<item.dish.getDishID()<<"\t"<<"dish name: "<<item.dish.getDishName()<<"\t"<<"cost: "<<item.dish.getDishPrice()<<"\t"<<"Quantity: "<<item.dishQuantity<<endl;
        cout<<"--------------------------------------------------"<<endl;
        STT++;
        total += item.dish.getDishPrice() * item.dishQuantity;
    }
    cout<<"total: "<< total<<endl;
    table_setStatus(false); // the table is empty
    table_dishDatabase.clear();
    
    
}

class Staff
{   
    private:
        int table_Number;
        list<TableInfor> list_Table;
    public:
        Staff(int _table_Number, list<Dish> _listDish);
        void staff_start();
        void staff_print_list_table_status();
        
    
};

Staff::Staff( int _table_Number , list<Dish> _listDish)
{
    table_Number = _table_Number;
    for(int i = 0; i < _table_Number; i++)
    {
        TableInfor table(i, false, _listDish);
        list_Table.push_back(table);
    }
}

void Staff::staff_start()
{
    cout<<"----------STAFF FIELD!------------"<<endl;
    staff_print_list_table_status();
    cout<<"Enter table ID to serve: ";
    int table_id;
    cin>>table_id;
    for(TableInfor &table : list_Table)
    {

        if(table.table_getOrder() == table_id)
        {           
            while (serving_table_flag)
            {
                cout<<"----------STAFF FIELD-----------"<<endl;
                cout<<"press 0 to add dish."<<endl;
                cout<<"press 1 to change dish information."<<endl;
                cout<<"press 2 to delete dish."<<endl;
                cout<<"press 3 to print list dish of table."<<endl;
                cout<<"press 4 to get bill."<<endl;
                cout<<"press 5 to exit."<<endl;
                cout<<"Enter options: ";
                int options;
                cin>>options;
                cout<<"***********************************************************"<<endl;
                switch(options)
                {
                    case 0:
                        table.table_addDish();
                        break;
                    case 1:
                        table.table_changeDish();
                        break;
                    case 2:
                        table.table_deleteDish();
                        break;
                    case 3:
                        table.table_listDish();
                        break;
                    case 4:
                        table.table_getBill();
                        
                        break;
                    case 5:
                        serving_table_flag = false;
                        break;
                        
                };
                
            }    
            serving_table_flag = true;       
            break;
        }
        
    }
    
}

void Staff::staff_print_list_table_status()
{
    for(TableInfor table : list_Table)
    {
        cout<<"table number: "<<table.table_getOrder()<<"\t"<<"status: "<<table.table_getStatus()<<endl;
    }
    cout<<"**************************************************"<<endl;
}


int main()
{
    while (1)
    {
        Manager Manager1;

        while (Manager_flag)
        {
            Manager1.manager_start();
        }
        Manager_flag = true;

        Staff Staff1(Manager1.manager_getNumberOfTable(), Manager1.manager_getDishDatabase());

        while (1)
        {   
            Staff1.staff_start();
        }
    }
    return 0;
}