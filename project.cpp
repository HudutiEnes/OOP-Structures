/*This C++ program defines multiple structures for storing information related
to a hospital, including details about patients, doctors, appointments,
prescriptions, and bills. The code initializes the hospital with a set of
doctors and patients, and offers a menu of options for users to choose from,
such as printing hospital information, displaying doctor or patient lists,
searching for bills or prescriptions, and adding new patients or appointments.

The main function begins by creating a hospital with three doctors and three
patients, followed by the creation of three appointments for each of the doctors
and patients, as well as three prescriptions and bills for each patient. The
program presents a menu with nine options, each corresponding to a different
operation, such as printing hospital information, showing the list of doctors,
or adding a new patient. Depending on the user's choice, the program invokes
different functions to perform the selected operation.*/

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// define structures

struct Time {  //struct used for appointment time
  int Hour, Minute, Second;
};

struct Date {  //struct for dates of birth and appointment dates
  int day;
  int month;
  int year;
};

struct Doctor {  //struct for representing the doctor
  int id;
  string name;
  string specialty;
  void DoctorInfo();  //function for printing doctor info
};

struct Patient { //struct representing patient
  int id;
  string name;
  Date dob;
  string address;
  void PatientInfo(); //function for printing patient info
};

struct Hospital { //struct for hospital with doctors and patients in it
  string country;
  string city;
  string Hospitalname;
  Doctor doctors[3];
  Patient patients[10];
  static int numofpatients;
  static int numofappointments;
  void HospitalInfo(); //function for printing hospital info
};

int Hospital::numofpatients = 3;
int Hospital::numofappointments = 3;

struct Appointment { //struct representing time and date of appointment
  Date date;
  Time time;
  string doctor_name;
  int patient_id;
  void AppointmentList(Appointment); //function for printing table of appointments
};

struct Prescription {  //struct for representing prescriptions for patients
  string medication;
  string dosage;
  string doctor_name;
  string patient_name;
  static void printPrescription(Prescription);  //function for printing prescriptions
  void SearchPerscription(Patient[], Prescription[]); //function for searching prescriptions
};

struct Bill { //struct representing bill of an patient
  int amount;
  int patient_id;
  string patient_name;
  Date paymetTerm;
  static void PrintBill(Bill); //function for printing bill
  void SearchBill(Patient[], Bill[]); //function for searching bill
};

void AddPatient(Hospital *); // function for adding patient
void AddAppointment(Appointment[], Doctor[], Patient[], Hospital *); //function for adding appointments

// main function

int main() {

  Hospital tt = {"Macedonia", "Tetovo",
                 "Spitali i Tetoves"}; // creating a hospital
  Hospital *tptr = &tt;                // creating a pointer to a hospital

  //3 random doctors
  tptr->doctors[0] = {43253, "Emir Gashi", "Urology"};
  tptr->doctors[1] = {63241, "Altin Selmani",
                      "Otorinolaringology"};
  tptr->doctors[2] = {93412, "Admir Shehu", "Dermatology"};

  //3 random patients
  tptr->patients[0] = {1, "Afrim Kabashi", {1987, 5, 14}, "Struga"};
  tptr->patients[1] = {2, "Agim Sinani", {1995, 3, 26}, "Prishtin"};
  tptr->patients[2] = {3, "Edin Hasani", {2000, 10, 9}, "Shkupi"};

  Appointment appointments[5];

  // 3 appointments for each existing patient
  appointments[0] = {
      {2023, 4, 22}, {11, 00, 00}, tptr->doctors[0].name, tptr->patients[0].id};
  appointments[1] = {
      {2023, 4, 19}, {8, 45, 00}, tptr->doctors[1].name, tptr->patients[1].id};
  appointments[2] = {
      {2023, 5, 8}, {10, 30, 00}, tptr->doctors[2].name, tptr->patients[2].id};

  Prescription prescriptions[3];

  // 3 prescriptions for each patient
  prescriptions[0] = {"Ibuprofen", "200mg", tptr->doctors[0].name,
                      tptr->patients[0].name};
  prescriptions[1] = {"Paracetamol", "200mg", tptr->doctors[1].name,
                      tptr->patients[1].name};
  prescriptions[2] = {"Analgin", "200mg", tptr->doctors[2].name,
                      tptr->patients[2].name};

  Bill patientsBill[3];

  // 3 bills for each patient
  patientsBill[0] = {
      500, tptr->patients[0].id, tptr->patients[0].name, {24, 4, 2023}};
  patientsBill[1] = {
      700, tptr->patients[1].id, tptr->patients[1].name, {10, 5, 2023}};
  patientsBill[2] = {
      120, tptr->patients[2].id, tptr->patients[2].name, {18, 4, 2023}};


  //creating menu with do while loop
  int choice;
  do {
    cout << "\n\nMenu Options:" << endl;
    cout << "1. Print hospital info" << endl;
    cout << "2. Doctor list" << endl;
    cout << "3. Patient list" << endl;
    cout << "4. Search Bill" << endl;
    cout << "5. Search Prescription" << endl;
    cout << "6. Add new patient" << endl;
    cout << "7. Appointment table" << endl;
    cout << "8. Add new appointment" << endl;
    cout << "9. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "\n>>>> Hospital Info <<<<" << endl;
      tptr->HospitalInfo();
      cin.get();
      break;
    case 2:
      cout << "\n>>>> Doctor List <<<<" << endl;
      for (int i = 0; i < 3;
           i++) {
        tptr->doctors[i].DoctorInfo();  //printing list of 3 doctors
      }
      cin.get();
      break;
    case 3:
      cout << "\n>>>> Patient List <<<<" << endl;
      for (int i = 0; i < tptr->numofpatients; i++) { // printing list of patients
        tptr->patients[i].PatientInfo();
      }
      cin.get();
      break;
    case 4:
      for (int i = 0; i < tptr->numofpatients; i++) {
        tptr->patients[i].PatientInfo();
      }
      patientsBill->SearchBill(tptr->patients, patientsBill); // searching for bills of 3 patients
      cin.get();
      break;
    case 5:
      for (int i = 0; i < tptr->numofpatients; i++) {
        tptr->patients[i].PatientInfo();
      }
      prescriptions->SearchPerscription(tptr->patients, prescriptions); //searching for prescriptions of 3 patients
      cin.get();
      break;
    case 6:
      AddPatient(tptr); //function for adding a new patient in hospital
      cin.get();
      break;
    case 7:
      cout << "\n>>>> Appointment List <<<<" << endl;
      for (int i = 0; i < tptr->numofappointments; i++) { //printing table of appointments
        appointments[i].AppointmentList(appointments[i]);
      }
      cin.get();
      break;
    case 8:
      AddAppointment(appointments, tptr->doctors, tptr->patients, tptr); //function for adding new appointment
      cin.get();
      break;

    case 9:
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 9);

  return 0;
}

void Hospital::HospitalInfo() { //this function prints info of hospital
  cout << "\n Country : " << country;
  cout << "\n City : " << city;
  cout << "\n Name : " << Hospitalname;
  cout << "\n Number of patiens: " << Hospital::numofpatients << endl;
}

void Patient::PatientInfo() { //function for printing patiens info
  cout << "\nID : " << id;
  cout << " | Name: " << name;
  cout << " | Date of birth : " << dob.year << "." << dob.month << "."
       << dob.day;
  cout << " | Adress : " << address << endl;
}

void Doctor::DoctorInfo() {   //function for printing doctors info
  cout << "\nID : " << id;
  cout << "\nName : " << name;
  cout << "\nSpeciality: " << specialty << endl;
}

void Prescription::printPrescription(Prescription p) { //function for printing prescription
  cout << "\n\n>>>> Prescription Info <<<<";
  cout << "\nMedication : " << p.medication;
  cout << "\nDosage : " << p.dosage;
  cout << "\nDoctor name : " << p.doctor_name;
  cout << "\nPatient name : " << p.patient_name << endl;
}

void Bill::PrintBill(Bill b) { //function for printing bill
  cout << "\nPatient Name :" << b.patient_name;
  cout << "\nPatient id :" << b.patient_id;
  cout << "\nBill amount :" << b.amount << "€";
  cout << "\nTerm of payment: " << b.paymetTerm.day << "." << b.paymetTerm.month
       << "." << b.paymetTerm.year << endl;
}

void Bill::SearchBill(Patient patients[], Bill b[]) { //function for searching bill
  int id;

  cout << "\nEnter patient ID: ";
  cin >> id;

  bool found = false; // flag to track if the patient's bill has been found
  for (int i = 0; i < 3; i++) {
    if (id == patients[i].id) {
      PrintBill(b[i]);  //if entered id is same with patients id printing his bill
      found = true; //if we find 1 id than stop the loop
      break;
    }
  }

  if (!found) {
    cout << "\nPatient not found.\n"; //if id doesn't match than print this message
  }
}

void Prescription::SearchPerscription(Patient patients[], Prescription prescriptions[]) { //function for searching prescriptions
  int id;
  cout << "\nEnter patiens id : ";
  cin >> id;

  bool found = false;
  for (int i = 0; i < 3; i++) {
    if (patients[i].id == id) { //comparing entered id with patients id
      printPrescription(prescriptions[i]); //if it is same print prescription for that patient
      found = true; //flag for checking if prescription is found
      break;
    }
  }
  if (!found) {
    cout << "\nPatient not found.\n"; //if id's don't match print this message
  }
}

void Appointment::AppointmentList(Appointment appointment) { //function for printing table of appointments
  // Header row
  cout << "+------------+----------+------------------+-------------+\n";
  cout << "| Date       | Time     | Doctor           | Patient ID  |\n";
  cout << "+------------+----------+------------------+-------------+\n";

  // Data row
  cout << "| " << setw(2) << appointment.date.day << "/" << setw(2)
       << setfill('0') << appointment.date.month << "/" << setw(2)
       << setfill('0') << appointment.date.year << " | " << setw(2)
       << setfill('0') << appointment.time.Hour << ":" << setw(2)
       << setfill('0') << appointment.time.Minute << ":" << setw(2)
       << setfill('0') << appointment.time.Second << " | " << setw(15)
       << setfill(' ') << appointment.doctor_name << " | " << setw(11)
       << setfill(' ') << appointment.patient_id << " |\n";

  // Footer row
  cout << "+------------+----------+------------------+-------------+\n";
}

void AddPatient(Hospital *h) {
  // Check if the hospital has space for a new patient
  if (h->numofpatients >= 10) {
    cout << "Hospital is at full capacity." << endl;
    return;
  }

  // Get the next available patient ID
  int nextID = h->patients[h->numofpatients - 1].id + 1;

  // Prompt the user to enter patient information
  Patient newPatient;
  newPatient.id = nextID;
  cout << "Enter patient name: ";
  cin.ignore(); // ignore newline character from previous input
  getline(cin, newPatient.name);
  cout << "Enter patient date of birth (dd mm yyyy): ";
  cin >> newPatient.dob.day >> newPatient.dob.month >> newPatient.dob.year;
  cout << "Enter patient address: ";
  cin.ignore(); // ignore newline character from previous input
  getline(cin, newPatient.address);

  // Add the new patient to the hospital
  h->patients[h->numofpatients] = newPatient;
  h->numofpatients++;

  cout << "New patient added successfully." << endl;
}

void AddAppointment(Appointment appointments[], Doctor doctors[],
                    Patient patients[], Hospital *h) {
  Date date;
  Time time;
  string doctor_name;
  int patient_id;

  cout << "\nEnter the details for the new appointment:" << endl;
  cout << "Date (DD MM YYYY): ";
  cin >> date.day >> date.month >> date.year;
  cout << "Time (HH MM SS): ";
  cin >> time.Hour >> time.Minute >> time.Second;
  cout << "Doctor's name: ";
  cin.ignore();
  getline(cin, doctor_name);
  cout << "Patient ID: ";
  cin >> patient_id;

  // find the doctor's index in the array
  int doctor_index = -1;
  for (int i = 0; i < 3; i++) {
    if (doctors[i].name == doctor_name) {
      doctor_index = i;
      break;
    }
  }

  // find the patient's index in the array
  int patient_index = -1;
  for (int i = 0; i < 10; i++) {
    if (patients[i].id == patient_id) {
      patient_index = i;
      break;
    }
  }

  // add the new appointment to the array
  if (doctor_index != -1 && patient_index != -1 && h->numofappointments < 10) {
    appointments[h->numofappointments] = {date, time, doctor_name, patient_id};
    h->numofappointments++;
    cout << "Appointment added successfully." << endl;
  } else {
    cout << "Failed to add appointment. Please check the input values and try "
            "again."
         << endl;
  }
}
