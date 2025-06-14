
#include <stdio.h>
#include <string.h>

#define MAX 10

struct Appointment {
    int id;
    char name[50];
    int age;
    char gender[10];
    char doctor[50];
    char date [30];
};

int main() {
    struct Appointment appointments[MAX];
    int choice, count = 0, idToSearch, found;
    char nameToSearch[50];
    int doctorChoice;

    do {
        printf("\n===== Welcome to Laxmi Clinic =====\n");
        printf("1. Book Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Search by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
         case 1:
         if (count < MAX) {
        appointments[count].id = count + 1;

          printf("Enter name: ");
         gets(appointments[count].name);

        printf("Enter age: ");
       scanf("%d", &appointments[count].age);
       getchar();

      printf("Enter gender: ");
    gets(appointments[count].gender);

                    printf("Enter appointment date (e.g. 25-06-2025): ");
         gets(appointments[count].date);            
           printf("Choose doctor specialist:\n");
           printf("1. Dr. Mehta (Cardiologist)\n");
             printf("2. Dr. Sharma (Dentist)\n");
            printf("3. Dr. Patel (General Physician)\n");
              printf("Enter your choice (1-3): ");
               scanf("%d", &doctorChoice);
               getchar();

                    if (doctorChoice == 1) {
            strcpy(appointments[count].doctor, "Dr. Mehta (Cardiologist)");
             } else if (doctorChoice == 2) {
              strcpy(appointments[count].doctor, "Dr. Sharma (Dentist)");
    } else if (doctorChoice == 3) {
      strcpy(appointments[count].doctor, "Dr. Patel (General Physician)");
   } else {
                   strcpy(appointments[count].doctor, "Unknown");      }

                    printf("Appointment booked. ID: %d\n", appointments[count].id);
                    count++;
                } else {
                    printf("Appointment list full.\n");
                }
                break;

            case 2:
    if (count == 0) {
       printf("No appointments.\n");
            } else {
              for (int i = 0; i < count; i++) {
              printf("ID: %d | Name: %s | Age: %d | Gender: %s | Doctor: %s | Date: %s\n",
                     appointments[i].id,
                     appointments[i].name,
                    appointments[i].age,
                    appointments[i].gender,
                    appointments[i].doctor,
                   appointments[i].date);
                    }
                }
                break;

            case 3:
   printf("Enter name to search: ");
      gets(nameToSearch);
       found = 0;
                for (int i = 0; i < count; i++) {
           if (strcmp(appointments[i].name, nameToSearch) == 0) {
         printf("Appointment found: ID %d, Doctor %s, Date %s\n",
          appointments[i].id, appointments[i].doctor, appointments[i].date);
                 found = 1;
           break;
                    }
                }
         if (!found) {
    printf("No appointment found for %s.\n", nameToSearch);
                }
     break;

      case 4:
       printf("Exiting system.\n");
                break;

        default:
       printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}