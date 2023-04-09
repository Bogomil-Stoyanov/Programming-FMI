#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

class Student
{

private:
    char *name;
    int age;

public:
    Student()
    {
        age = 0;
        name = nullptr;
    }

    Student(const char *name, int age)
    {
        this->age = age;

        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
    }

    Student &operator=(const Student &other)
    {
        if (this != &other)
        {
            delete[] name;

            this->name = new char[strlen(other.name) + 1];
            strcpy_s(this->name, strlen(other.name) + 1, other.name);

            this->age = other.age;
        }

        return *this;
    }

    ~Student()
    {
        delete[] name;
    }
};

class Uni
{

public:
    char *name;
    std::vector<Student> students;

    Uni()
    {
        name = nullptr;
    }

    Uni(const char *name)
    {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
        saveUni();
    }

    ~Uni()
    {
        delete[] name;
        students.clear();
    }

    void addStudent(Student student)
    {
        students.push_back(student);
    }

    void serialize() const
    {
        size_t size = strlen(name) + 11;
        char filename[size] = {0};
        strcat(filename, "binary_");
        strcat(filename, name);
        strcat(filename, ".bin");

        std::ofstream out(filename, std::ios::binary);

        if (!out)
            return;

        size = strlen(name) + 1;
        out.write((const char *)&size, sizeof(size_t));
        out.write(name, size);

        int studentsCount = students.size();
        out.write((const char *)&studentsCount, sizeof(int));

        for (size_t i = 0; i < studentsCount; i++)
        {
            out.write((const char *)&students[i], sizeof(students[i]));
        }

        out.close();
    }

    void saveUni()
    {
        std::ofstream out("universities.txt", std::ios::app | std::ios::out);

        if (!out)
            return;

        out << name << '\n';

        out.close();
    }

    void readUnis()
    {
        std::ifstream in("universities.txt");
        char buffer[1024];
        while (in.getline(buffer, 100))
        {
            std::cout << buffer << std::endl;
        }
    }
};

int main()
{
    Uni un1("Uni1");
    Uni un2("Uni2");
    Uni un3("Uni3");

    un1.readUnis();
    un1.serialize();
}
