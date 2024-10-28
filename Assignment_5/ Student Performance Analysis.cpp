#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

const int NUM_STUDENTS = 10;
const int NUM_SUBJECTS = 4;
const std::string SUBJECT_NAMES[NUM_SUBJECTS] = {"Math", "Science", "English", "History"};

struct Student {
    int id;
    std::vector<double> grades;
    double averageGrade;
};

struct SubjectStats {
    double averageGrade;
    double highestGrade;
    double lowestGrade;
};

void calculateStudentStats(Student &student) {
    double sum = 0;
    for (double grade : student.grades) {
        sum += grade;
    }
    student.averageGrade = sum / NUM_SUBJECTS;
}

void calculateSubjectStats(const std::vector<Student> &students, std::vector<SubjectStats> &subjectStats) {
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        double sum = 0;
        subjectStats[i].highestGrade = std::numeric_limits<double>::lowest();
        subjectStats[i].lowestGrade = std::numeric_limits<double>::max();

        for (const Student &student : students) {
            sum += student.grades[i];
            if (student.grades[i] > subjectStats[i].highestGrade) {
                subjectStats[i].highestGrade = student.grades[i];
            }
            if (student.grades[i] < subjectStats[i].lowestGrade) {
                subjectStats[i].lowestGrade = student.grades[i];
            }
        }
        subjectStats[i].averageGrade = sum / NUM_STUDENTS;
    }
}

void displayReport(const std::vector<Student> &students, const std::vector<SubjectStats> &subjectStats) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nStudent | Math | Science | English | History | Average\n";
    std::cout << "----------------------------------------------------------\n";

    for (const Student &student : students) {
        std::cout << std::setw(7) << student.id << " | ";
        for (double grade : student.grades) {
            std::cout << std::setw(6) << grade << " | ";
        }
        std::cout << std::setw(7) << student.averageGrade << "\n";
    }

    std::cout << "\nSubject Statistics:\n";
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        std::cout << SUBJECT_NAMES[i] << " - "
                  << "Average: " << subjectStats[i].averageGrade << ", "
                  << "Highest Grade: " << subjectStats[i].highestGrade << ", "
                  << "Lowest Grade: " << subjectStats[i].lowestGrade << "\n";
    }
}

int main() {
    std::vector<Student> students(NUM_STUDENTS);
    std::vector<SubjectStats> subjectStats(NUM_SUBJECTS);

    // Input grades for each student and each subject
    for (int i = 0; i < NUM_STUDENTS; i++) {
        students[i].id = i + 1;
        students[i].grades.resize(NUM_SUBJECTS);
        std::cout << "Enter grades for Student " << students[i].id << ":\n";

        for (int j = 0; j < NUM_SUBJECTS; j++) {
            std::cout << SUBJECT_NAMES[j] << ": ";
            std::cin >> students[i].grades[j];
        }
        calculateStudentStats(students[i]);
    }

    // Calculate statistics for each subject
    calculateSubjectStats(students, subjectStats);

    // Display the report
    displayReport(students, subjectStats);

    return 0;
}
