#include <iostream>

enum Grade {
    POOR = 2,
    TROIKA,
    GOOD,
    VERY_GOOD,
    EXCELLENT
};

enum Subject {
    A1,
    DIS,
    DS,
    UP
};

struct GradeSubject {
    Subject subject;
    Grade grade;
};

struct GradeBook {
    char *name;
    char *facNum;
    int gradesCount;
    GradeSubject *grades;
};

void addGradeForSubject(GradeBook *gradeBook, Subject subject, Grade grade) {
    for(int i = 0; i < gradeBook->gradesCount; i++) {
        if(gradeBook->grades[i].subject == subject) {
            gradeBook->grades[i].grade = grade;
            return;
        }
    }
    gradeBook->grades[gradeBook->gradesCount].subject = subject;
    gradeBook->grades[gradeBook->gradesCount].grade = grade;
    gradeBook->gradesCount++;
}

void sortGrades(GradeBook *gradeBook) {
    for(int i = 0; i < gradeBook->gradesCount; i++) {
        for(int j = i + 1; j < gradeBook->gradesCount; j++) {
            if(gradeBook->grades[i].grade > gradeBook->grades[j].grade) {
                GradeSubject tmp = gradeBook->grades[i];
                gradeBook->grades[i] = gradeBook->grades[j];
                gradeBook->grades[j] = tmp;
            }
        }
    }
}

double averageGrade(GradeBook *gradeBook, bool aditionalCheck = false) {
    double sum = 0;
    int countF = 0;
    for(int i = 0; i < gradeBook->gradesCount; i++) {
        if (aditionalCheck) {
            sum += gradeBook->grades[i].grade;
            continue;
        }
        if (gradeBook->grades[i].grade != POOR) {
            sum += gradeBook->grades[i].grade;
        } else {
            countF++;
        }
    }
    return sum / (gradeBook->gradesCount - countF);
}

void print(GradeBook *gradeBook) {
    std::cout << "Name: " << gradeBook->name << std::endl;
    std::cout << "Faculty number: " << gradeBook->facNum << std::endl;
    std::cout << "Grades: " << std::endl;
    for(int i = 0; i < gradeBook->gradesCount; i++) {
        std::cout << gradeBook->grades[i].subject << " " << gradeBook->grades[i].grade << std::endl;
    }
}

bool canGraduate(GradeBook *gradeBook) {
    int failedCount = 0;
    for(int i = 0; i < gradeBook->gradesCount; i++) {
        if (gradeBook->grades[i].grade == POOR) {
            failedCount++;
        }
    }
    if (failedCount > 4) {
        return false;
    }
    if (failedCount == 4) {
        return averageGrade(gradeBook) >= 4;
    }
    return true;
}

bool canGetScholarshit(GradeBook *gradeBook) {
    if (!canGraduate(gradeBook)) {
        return false;
    }
    return averageGrade(gradeBook) >= 5;
}

int main() {
    GradeBook *gradeBook = new GradeBook();
    gradeBook->name = "Panaiot";
    gradeBook->facNum = "0MI800069";
    gradeBook->gradesCount = 0;

    gradeBook->grades = new GradeSubject[3];
    addGradeForSubject(gradeBook, A1, EXCELLENT);
    addGradeForSubject(gradeBook, DS, VERY_GOOD);
    addGradeForSubject(gradeBook, DIS, GOOD);
    addGradeForSubject(gradeBook, UP, TROIKA);

    sortGrades(gradeBook);

    std::cout << "Will pass: " << std::boolalpha << canGraduate(gradeBook) << std::endl;
    std::cout << "Will get scholarship: " << std::boolalpha << canGetScholarshit(gradeBook) << std::endl;

    print(gradeBook);

    delete gradeBook->name;
    delete gradeBook->facNum;
    delete[] gradeBook->grades;
    delete gradeBook;
}
