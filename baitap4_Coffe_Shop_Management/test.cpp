class TableStatus: public Manager
{
    private:
        int tableOrder;
        bool tableStatus;
        list<Dish> dishList;
        typedef struct
        {   
            int dishQuantity;
            Dish dish;
        } TypeDish;
        list <TypeDish> table_dishDatabase;

    public:
        TableStatus(int vice_tableOrder, bool vice_tableStatus, list<Dish> vice_dishLish);
        int getTableOrder();
        bool getTableStatus();
        void setTableStatus(bool status);
        void addDish();
        void changeDish();
        void deleteDish();
        list <TypeDish> table_dishDatabase();
};

TableStatus::TableStatus(int vice_tableOrder, bool vice_tableStatus, list<Dish> vice_dishList)
{
    this->tableOrder = vice_tableOrder;
    this->tableStatus = vice_tableStatus;
    this->dishList = vice_dishList;
}

bool TableStatus::getTableStatus()
{
    return tableStatus;
}

int TableStatus::getTableOrder()
{
    return tableOrder;
}

void TableStatus::setTableStatus(bool status)
{
    this->tableStatus = status;
}

void TableStatus::addDish()
{
    
    for(auto temp : dishList)
    {
        temp.printDishInformation();
    }
    
    int ID;
    cout<<"Enter ID to serve: ";
    cin>>ID;
    int dishQuantity;
    cout<<"enter quantity:";
    cin>>dishQuantity;
    
    for(Dish temp : dishList)
    {
        if(temp.getDishID() == ID)
        {
            TypeDish typeDish;
            typeDish.dish = temp;
            typeDish.dishQuantity = dishQuantity;
            table_dishDatabase.push_pack(typeDish);

        }
    }


}