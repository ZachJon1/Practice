# include <iostream>

using namespace std;

double GpaCalc(double score[], int numCourses){
    double grade[numCourses];

    double gpa, total = 0;

    // compute grade

    for (int i = 0; i < numCourses; i++){
        grade[i] = score[i] / 10;
    }

    // sum of grade

    for (int i =0; i < numCourses; i++){

        total +=grade[i];
    }

    // compute gpa
    gpa = total /numCourses;

    return gpa;
}

int main(){
    int numCourses;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    double score [numCourses];

    for (int i = 0; i < numCourses; i++){
        cout << "Enter the score fore each course: ";
        cin >> score[i];
    }

    cout << "The GPA is : " << GpaCalc(score, numCourses) << endl;
    
}