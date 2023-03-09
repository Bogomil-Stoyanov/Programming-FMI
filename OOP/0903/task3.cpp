#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Dog
{
private:
    char *name;
    char gender;
    int age;

public:
   
    Dog(const char *name)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->gender = 'M';
        this->age = 0;
    }

    
    Dog(const char *name, char gender, unsigned int age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->gender = gender;
        if (age <= 720)
        {
            this->age = age;
        }
        else
        {
            age = 0;
        }
    }

    ~Dog()
    {
        delete[] name;
    }

    void grow()
    {
        age++;
    }

    char getGender() const
    {
        return gender;
    }

    int getAge() const
    {
        return age;
    }

    void display() const
    {
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << " months" << endl;
    }
};

class Shelter {
private:
    vector<Dog*> dogs;

public:

    Shelter() {}

  
    ~Shelter() {
        for (Dog* dog : dogs) {
            delete dog;
        }
    }

    void addDog(Dog* dog) {
        if (dogs.size() <= 15) {
            dogs.push_back(dog);
        } else {
            cout << "Sorry, the shelter is full." << endl;
        }
    }

    void releaseDog(int index) {
        if (index >= 0 && index < dogs.size()) {
            delete dogs[index];
            dogs.erase(dogs.begin() + index);
        }
    }

    void releaseAllDogs(){
        for(int i =0;i<dogs.size();i++){
            delete dogs[i];
            dogs.erase(dogs.begin() + i);
        }
    }

    void displayAllDogs() const {
        for (int i = 0; i < dogs.size(); i++) {
            cout << "Dog #" << i+1 << ":" << endl;
            dogs[i]->display();
            cout << endl;
        }
    }
};

int main(){
     Dog* dog1 = new Dog("Buddy", 'M', 12);
    Dog* dog2 = new Dog("Daisy", 'F', 24);
    Dog* dog3 = new Dog("Max", 'M', 6);
    Dog* dog4 = new Dog("Lucy", 'F', 36);
    Dog* dog5 = new Dog("Charlie", 'M', 18);


    Shelter shelter;
    shelter.addDog(dog1);
    shelter.addDog(dog2);
    shelter.addDog(dog3);
    shelter.addDog(dog4);
    shelter.addDog(dog5);
    
    shelter.addDog(new Dog("Molly", 'F', 9));
    shelter.addDog(new Dog("Rocky", 'M', 42));
    shelter.addDog(new Dog("Roxy", 'F', 30));
    shelter.addDog(new Dog("Bailey", 'M', 15));
    shelter.addDog(new Dog("Luna", 'F', 27));
    shelter.addDog(new Dog("Cooper", 'M', 21));
    shelter.addDog(new Dog("Zoe", 'F', 48));
    shelter.addDog(new Dog("Jack", 'M', 3));
    shelter.addDog(new Dog("Sadie", 'F', 54));

   
    cout << "All dogs in the shelter:" << endl;
    shelter.displayAllDogs();

    
    shelter.releaseDog(1);

   
    cout << "Dogs in the shelter after releasing one:" << endl;
    shelter.displayAllDogs();

    shelter.releaseAllDogs();

    return 0;
}