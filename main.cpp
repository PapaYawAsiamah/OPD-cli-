#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

//Define a class to represent a patient
class Patient {
public:
    int id;
    string name;
    int age;
    string gender;
    int roomNumber;
    float temperature;
    float weight;
    float height;

    // Constructor to initialize roomNumber to -1 (unassigned)
    Patient() : roomNumber(-1) {}

    //Function to provide patient's information
    void providePatientInfo() {
        cout << "What is the patient's name? ";
        cin >> name;
        cout << "How old is the patient? ";
        cin >> age;
        cout << "What is the patient's gender(Male/Female)? ";
        cin >> gender;
        cout << "What is the patient's temperature (in degree celcius)? ";
        cin >> temperature;
        cout << "What is the patient's weight(Kg)? ";
        cin >> weight;
        cout << "What is the patient's height(cm)? ";
        cin >> height;

    }

    // Function to assign room to a patient
    void assignRoom(int room) {
        roomNumber = room;
    }
};


const int MAX_PATIENTS = 100; // Maximum number of patients
const int MAX_ROOMS = 10; // maximum number of rooms

//Function to display information of all patients
void displayPatients(const vector<Patient>& patients) {
    for (size_t i = 0; i < patients.size(); i++) {
        cout << i + 1 << ": " << patients[i].name << ", Age: " << patients[i].age << ", Gender: " << patients[i].gender;
        if (patients[i].roomNumber != -1) {
            cout << ", Room Number: " << patients[i].roomNumber;
        }
        cout << endl;
    }
}

//Function to display the room assignments
void displayRooms(const vector<Patient>& patients) {
    cout << "\nRoom Assignments:\n";
    for (int room = 1; room <= MAX_ROOMS; ++room) {
        cout << "Room " << setw(2) << room << ": ";
        bool occupied = false;
        for (const auto& patient : patients) {
            if (patient.roomNumber == room) {
                cout << patient.name;
                occupied = true;
                break;
            }
        }
        if (!occupied) {
            cout << "Unoccupied";
        }
        cout << endl;
    }
}

//Function to assign room to patients
void assignRoomToPatient(vector<Patient>& patients) {
    char assignMore;
    do {
        int patientIndex;
        int roomNumber;

        displayPatients(patients);
        cout << "Select the patient number to assign a room: ";
        cin >> patientIndex;

        if (patientIndex > 0 && patientIndex <= patients.size()) {
            cout << "Enter the room number to assign to " << patients[patientIndex - 1].name << ": ";
            cin >> roomNumber;
            if (roomNumber > 0 && roomNumber <= MAX_ROOMS) {
                patients[patientIndex - 1].assignRoom(roomNumber);
                cout << "Room " << roomNumber << " assigned to " << patients[patientIndex - 1].name << "." << endl;
            } else {
                cout << "Invalid room number." << endl;
            }
        } else {
            cout << "Invalid patient number." << endl;
        }

        displayRooms(patients);
        cout << "Do you want to assign a room to another patient (Y/N)? ";
        cin >> assignMore;
    } while (assignMore == 'Y' || assignMore == 'y');
}

// The main function
int main() {
    vector<Patient> patients; // Vector to store patients

    //Welcome statement to accept user input
    char start;
    cout << "Welcome to the hospital. Press 'P' to add a new patient or 'R' to assign a room to a patient: ";
    cin >> start;

    char choice;
    if (start == 'P' || start == 'p') {
        do {
            if (patients.size() < MAX_PATIENTS) {
                Patient newPatient;
                newPatient.providePatientInfo();
                patients.push_back(newPatient);
                cout << "Add new patient (Y/N)? ";
                cin >> choice;

                if (choice == 'N' || choice == 'n') {
                    break;
                }
            } else {
                cout << "Patient list is full." << endl;
                break;
            }
        } while (choice == 'Y' || choice == 'y');
    }

    if ((start == 'R' || start == 'r') || (choice == 'N' || choice == 'n')) {
        if (patients.empty()) {
            cout << "No patients available to assign a room." << endl;
        } else {
            assignRoomToPatient(patients);
        }
    }

    // Display patient information
    for (size_t a = 0; a < patients.size(); a++) {
        cout << "Patient " << a + 1 << ": " << endl;
        cout << "Name: " << patients[a].name << endl;
        cout << "Age: " << patients[a].age << endl;
        cout << "Gender: " << patients[a].gender << endl;
        cout << "--------vitals----------"<<endl;
        cout << "temperature: " << patients[a].temperature << endl;
        cout << "weight: " << patients[a].weight << endl;
        cout << "height: " << patients[a].height << endl;



        if (patients[a].roomNumber != -1) {
            cout << "Room Number: " << patients[a].roomNumber << endl;
        }
        cout << "-----------------------" << endl;
    }

    // Display room assignments
    displayRooms(patients);

    return 0;
}
