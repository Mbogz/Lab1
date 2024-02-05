#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Course {
    std::string course_code;
    std::string course_name;
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    std::string registration_number;
    std::string name;
    int age;
    Course course;
    Grade grade;
};

std::vector<Student> students(40);

// Function to add marks and calculate grades
void add_marks_and_calculate_grades(int index) {
    std::cout << "Enter mark (0-100): ";
    int mark;
    std::cin >> mark;
    students[index].grade.mark = mark;
    if (mark > 69) {
        students[index].grade.the_grade = 'A';
    } else if (mark > 59) {
        students[index].grade.the_grade = 'B';
    } else if (mark > 49) {
        students[index].grade.the_grade = 'C';
    } else if (mark > 39) {
        students[index].grade.the_grade = 'D';
    } else {
        students[index].grade.the_grade = 'E';
    }
}

// Function to edit a student's details
void edit_student_details(int index) {
    std::cout << "Enter new registration number: ";
    std::cin >> students[index].registration_number;
    std::cout << "Enter new name: ";
    std::cin.ignore();
    std::getline(std::cin, students[index].name);
    std::cout << "Enter new age: ";
    std::cin >> students[index].age;
    std::cout << "Enter new course code: ";
    std::cin >> students[index].course.course_code;
    std::cout << "Enter new course name: ";
    std::cin.ignore();
    std::getline(std::cin, students[index].course.course_name);
}

// Function to display a student's details
void display_student_details(int index) {
    std::cout << "Registration number: " << students[index].registration_number << std::endl;
    std::cout << "Name: " << students[index].name << std::endl;
    std::cout << "Age: " << students[index].age << std::endl;
    std::cout << "Course code: " << students[index].course.course_code << std::endl;
    std::cout << "Course name: " << students[index].course.course_name << std::endl;
    std::cout << "Mark: " << students[index].grade.mark << std::endl;
    std::cout << "Grade: " << students[index].grade.the_grade << std::endl;
}

// Main function
int main() {
    int n;
    std::cout << "Enter number of students (max 40): ";
    std::cin >> n;
    if (n > 40) {
        std::cout << "Number of students exceeded the limit of 40." << std::endl;
        return 1;
    }
    for (int i = 0; i < n; i++) {
        std::cout << "Enter registration number for student " << i + 1 << ": ";
        std::cin >> students[i].registration_number;
        std::cout << "Enter name for student " << i + 1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, students[i].name);
        std::cout << "Enter age for student " << i + 1 << ": ";
        std::cin >> students[i].age;
        std::cout << "Enter course code for student " << i + 1 << ": ";
        std::cin >> students[i].course.course_code;
        std::cout << "Enter course name for student " << i + 1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, students[i].course.course_name);
        add_marks_and_calculate_grades(i);
    }
    int choice;
    while (true) {
        std::cout << "\n1. Edit student details\n2. Display student details\n3. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        if (choice == 1) {
            int index;
            std::cout << "Enter index of student to edit: ";
            std::cin >> index;
            if (index >= n) {
                std::cout << "Index out of bounds." << std::endl;
                continue;
            }
            edit_student_details(index);
        } else if (choice == 2) {
            int index;
            std::cout << "Enter index of student to display: ";
            std::cin >> index;
            if (index >= n) {
                std::cout << "Index out of bounds." << std::endl;
                continue;
            }
            display_student_details(index);
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid choice. Enter 1, 2, or 3." << std::endl;
        }
    }
    return 0;
}
