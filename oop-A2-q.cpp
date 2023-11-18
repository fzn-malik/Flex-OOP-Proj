#include <iostream>

class Person
{
public:
    std::string name;
    int age;
    char gender;

public:
    Person(std::string name = "", int age = 0, char gender = ' ')
    {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }

    void setname(const std::string &name)
    {
        this->name = name;
    }

    std::string getname()
    {
        return name;
    }

    void setage(int age)
    {
        this->age = age;
    }

    int getage()
    {
        return age;
    }

    void setgender(char gender)
    {
        this->gender = gender;
    }

    char getgender()
    {
        return gender;
    }
};

class Adult : public Person
{
    std::string Occupation;
    std::string Qualification;
    std::string NIC;

public:
    Adult(const std::string &name = "", int age = 0, char gender = ' ',
          const std::string &Occupation = "", const std::string &Qualification = "",
          const std::string &NIC = "")
        : Person(name, age, gender), Occupation(Occupation), Qualification(Qualification), NIC(NIC) {}

    void setOccupation(const std::string &Occupation)
    {
        this->Occupation = Occupation;
    }

    std::string getOccupation()
    {
        return Occupation;
    }

    void setQualification(const std::string &Qualification)
    {
        this->Qualification = Qualification;
    }

    std::string getQualification()
    {
        return Qualification;
    }

    void setNIC(std::string NIC)
    {
        this->NIC = NIC;
    }

    std::string getNIC()
    {
        return NIC;
    }
};

class kid : public Person
{
    std::string B_form_number;

public:
    kid(const std::string &name = "", int age = 0, char gender = ' ', const std::string &B_form_number = "")
        : Person(name, age, gender), B_form_number(B_form_number) {}

    void setB_form_number(const std::string &B_form_number)
    {
        this->B_form_number = B_form_number;
    }

    std::string getB_form_number()
    {
        return B_form_number;
    }
};

class Bogie
{
public:
    int Bogie_ID;
    Bogie *next; // Pointer to the next bogie
    Adult *Adults;
    kid *kids;
    int numAdults;
    int numKids;
    std::string familyName;

public:
    Bogie(int id)
    {
        Bogie_ID = id;
        next = nullptr;
        Adults = nullptr; // Array
        kids = nullptr; // Array kids
        numAdults = 0; // Array, Adults, index 
        numKids = 0; // Arra, kids, index
        familyName = "";
    }
    bool AddPassengers(const Adult &adult, const kid &kid, const std::string &familyName)
    {
        if (numAdults + numKids < 10)
        {
            // Add adult if space is available
            if (numAdults < 4)
            {
                Adults[numAdults] = adult;
                numAdults++;
            }
            // Add kid if space is available
            if (numKids < 6)
            {
                kids[numKids] = kid;
                numKids++;
            }
            this->familyName = familyName;
            return true;
        }
        return false;
    }
    void Print()
    {
        std::cout << "Bogie ID: " << Bogie_ID;
        std::cout << std::endl;
        std::cout << "Family Name: " << familyName;
        std::cout << std::endl;
        std::cout << "Adults:";
        std::cout << std::endl;

        for (int i = 0; i < numAdults; i++)
        {
            std::cout << "Name: " << Adults[i].name;
            std::cout << std::endl;
            std::cout << "Age: " << Adults[i].age;
            std::cout << std::endl;
            std::cout << "Gender: " << Adults[i].gender;
            std::cout << std::endl;
        }

        std::cout << "Kids:";
        std::cout << std::endl;

        for (int i = 0; i < numKids; i++)
        {
            std::cout << "Name: " << kids[i].name;
            std::cout << std::endl;
            std::cout << "Age: " << kids[i].age;
            std::cout << std::endl;
            std::cout << "Gender: " << kids[i].gender;
            std::cout << std::endl;
        }
    }
    ~Bogie()
    {
        delete[] Adults;
        delete[] kids;
    }
};

class train
{
public:
    Bogie *engine;

public:
    train()
    {
        engine = nullptr;
    }
    void addBogie(int ID)
    {
        if (engine == nullptr) // If no boiges present
        {
            engine = new Bogie(ID); //  A new bogie is created and assigned as the engine
        }
        else
        {
            Bogie *currentBogie = engine; // Creates a pointer and assigns it the address of engine 
            // While loop to find the last bogie
            while (currentBogie->next != nullptr) 
            {
                currentBogie = currentBogie->next;
            }
            currentBogie->next = new Bogie(ID); // Adds a new bogie at the end
        }
    }

    bool removeBogie(int ID)
    {
        if (engine == nullptr)
        {
            return false;
        }

        if (engine->Bogie_ID == ID)
        {
            Bogie *newEngine = engine->next;
            delete engine;
            engine = newEngine;
            return true;
        }
        Bogie *currentBogie = engine;
        while (currentBogie->next != nullptr)
        {
            if (currentBogie->next->Bogie_ID == ID)
            {

                Bogie *toRemove = currentBogie->next;
                currentBogie->next = toRemove->next;
                delete toRemove;
                return true;
            }
            currentBogie = currentBogie->next;
        }
        return false;
    }

    void printTrain()
    {
        Bogie *currentBogie = engine;
        while (currentBogie != nullptr)
        {
            std::cout << "Bogie ID: " << currentBogie->Bogie_ID;
            std::cout << std::endl;
            currentBogie = currentBogie->next;
        }
    }

    bool SearchBogie(int ID)
    {
        Bogie *currentBogie = engine;
        while (currentBogie != nullptr)
        {
            if (currentBogie->Bogie_ID == ID)
            {
                return true;
            }
            currentBogie = currentBogie->next;
        }
        return false;
    }

    ~train()
    {
        Bogie *currentBogie = engine;
        while (currentBogie != nullptr)
        {
            Bogie *toRemove = currentBogie;
            currentBogie = currentBogie->next;
            delete toRemove;
        }
    }
};

int main(void)
{
    train myTrain;

    myTrain.addBogie(1);
    myTrain.addBogie(2);

    Adult adult1("Ali", 35, 'M');
    Adult adult2("Tess", 28, 'F');
    kid kid1("Tickles", 5, 'F');
    kid kid2("Jacob", 7, 'M');

    myTrain.engine->AddPassengers(adult1, kid1, "Bob");
    myTrain.engine->AddPassengers(adult2, kid2, "Marley");

    myTrain.printTrain();

    int bogieToFind = 2;
    if (myTrain.SearchBogie(bogieToFind))
    {
        std::cout << "Bogie " << bogieToFind << " found" << std::endl;
    }
    else
    {
        std::cout << "Bogie " << bogieToFind << " not found" << std::endl;
    }

    int bogieToRemove = 1;
    if (myTrain.removeBogie(bogieToRemove))
    {
        std::cout << "Bogie " << bogieToRemove << " removed" << std::endl;
    }
    else
    {
        std::cout << "Bogie " << bogieToRemove << " not found" << std::endl;
    }

    myTrain.printTrain();
}
