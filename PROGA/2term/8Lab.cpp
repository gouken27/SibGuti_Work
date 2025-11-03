#include <iostream>
#include <iomanip>
using namespace std;
struct School {
    int number;
    int graduates;
    int admitted;
};
int main(){
    int n;
    cout << "Enter number of schools: ";
    cin >> n;
    School* schools = new School[n];
    for(int i = 0; i < n; i++){
        cout << "Enter school number, number of graduates and number admitted: ";
        cin >> schools[i].number >> schools[i].graduates >> schools[i].admitted;
    }
    int* indices = new int[n];
    for(int i = 0; i < n; i++){
        indices[i] = i;
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            double perc_i = static_cast<double>(schools[indices[i]].admitted) / schools[indices[i]].graduates;
            double perc_j = static_cast<double>(schools[indices[j]].admitted) / schools[indices[j]].graduates;
            if(perc_i > perc_j){
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }
    cout << "\nSchool\tGraduates\tPercentage admitted\n";
    for(int i = 0; i < n; i++){
        int idx = indices[i];
        double percentage = static_cast<double>(schools[idx].admitted) / schools[idx].graduates * 100;
        cout << schools[idx].number << "\t" << schools[idx].graduates << "\t\t"
             << fixed << setprecision(2) << percentage << "%" << "\n";
    }
    delete[] schools;
    delete[] indices;
    return 0;
}

/*2*/

#include <iostream>
#include <string>#include <iostream>
#include <string>
using namespace std;
struct Room {
    int roomNumber;
    double area;
    string faculty;
    int residents;
};
int main(){
    int n;
    cout << "Enter number of rooms: ";
    cin >> n;
    Room* rooms = new Room[n];
    for(int i = 0; i < n; i++){
        cout << "Enter room number, area, faculty, and number of residents for room " << i + 1 << ": ";
        cin >> rooms[i].roomNumber >> rooms[i].area >> rooms[i].faculty >> rooms[i].residents;
    }
    int facultyCount = 0;
    string* faculties = new string[n];
    for(int i = 0; i < n; i++){
        bool exists = false;
        for(int j = 0; j < facultyCount; j++){
            if(rooms[i].faculty == faculties[j]){
                exists = true;
                break;
            }
        }
        if(!exists){
            faculties[facultyCount++] = rooms[i].faculty;
        }
    }
    cout << "\nFaculty Summary:\n";
    cout << "Faculty\tRooms\tStudents\tAvg area per student\n";
    for(int i = 0; i < facultyCount; i++){
        int roomCount = 0;
        int totalStudents = 0;
        double totalArea = 0;
        for(int j = 0; j < n; j++){
            if(rooms[j].faculty == faculties[i]){
                roomCount++;
                totalStudents += rooms[j].residents;
                totalArea += rooms[j].area;
            }
        }
        double avgArea = (totalStudents > 0) ? totalArea / totalStudents : 0;
        cout << faculties[i] << "\t" << roomCount << "\t" << totalStudents << "\t\t" << avgArea << "\n";
    }
    delete[] rooms;
    delete[] faculties;
    return 0;
}


using namespace std;
struct Room {
    int roomNumber;
    double area;
    string faculty;
    int residents;
};
int main(){
    int n;
    cout << "Enter number of rooms: ";
    cin >> n;
    Room* rooms = new Room[n];
    for(int i = 0; i < n; i++){
        cout << "Enter room number, area, faculty, and number of residents for room " << i + 1 << ": ";
        cin >> rooms[i].roomNumber >> rooms[i].area >> rooms[i].faculty >> rooms[i].residents;
    }
    int facultyCount = 0;
    string* faculties = new string[n];
    for(int i = 0; i < n; i++){
        bool exists = false;
        for(int j = 0; j < facultyCount; j++){
            if(rooms[i].faculty == faculties[j]){
                exists = true;
                break;
            }
        }
        if(!exists){
            faculties[facultyCount++] = rooms[i].faculty;
        }
    }
    cout << "\nFaculty Summary:\n";
    cout << "Faculty\tRooms\tStudents\tAvg area per student\n";
    for(int i = 0; i < facultyCount; i++){
        int roomCount = 0;
        int totalStudents = 0;
        double totalArea = 0;
        for(int j = 0; j < n; j++){
            if(rooms[j].faculty == faculties[i]){
                roomCount++;
                totalStudents += rooms[j].residents;
                totalArea += rooms[j].area;
            }
        }
        double avgArea = (totalStudents > 0) ? totalArea / totalStudents : 0;
        cout << faculties[i] << "\t" << roomCount << "\t" << totalStudents << "\t\t" << avgArea << "\n";
    }
    delete[] rooms;
    delete[] faculties;
    return 0;
}