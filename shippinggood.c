#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void firstlast(char *fname, char *lname) {
    int i, j;
    
    // Get first name
    while(1) {
        printf("Enter your first name: ");
        scanf("%s", fname);
        for(i = 0; fname[i] != '\0'; i++) {
            if(!isalpha(fname[i]) && fname[i] != ' ') {
                printf("False. Please enter only alphabetic characters.\n");
                break;
            }
        }
        if(fname[i] == '\0') {
            break;
        }
    }
    printf("First Name entered: %s\n", fname);
    
    // Get last name
    while(1) {
        printf("Enter your last name: ");
        scanf("%s", lname);
        for(j = 0; lname[j] != '\0'; j++) {
            if(!isalpha(lname[j]) && lname[j] != ' ') {
                printf("False. Please enter only alphabetic characters.\n");
                break;
            }
        }
        if(lname[j] == '\0') {
            break;
        }
    }
    printf("Last Name entered: %s\n", lname);
}

//ADDRESS
struct Address {
    int street_number;
    char street_name[100];
    char city[100];
    char unit_number[10];
};

struct Address getAddress() {
    struct Address addr;
    
    // get street number
    printf("Enter street number: ");
    while (scanf("%d", &addr.street_number) != 1) {
        printf("Invalid street number. Please enter a valid integer: ");
        while (getchar() != '\n'); // clear input buffer
    }
    while (getchar() != '\n'); // clear input buffer after successful input

    // get street name
    printf("Enter street name: ");
    fgets(addr.street_name, sizeof(addr.street_name), stdin);
    addr.street_name[strcspn(addr.street_name, "\n")] = '\0'; // remove newline character at the end
    while (strlen(addr.street_name) == 0 || !isalpha(addr.street_name[0])) {
        printf("Invalid street name. Please enter a valid alphabetic string with spaces: ");
        fgets(addr.street_name, sizeof(addr.street_name), stdin);
        addr.street_name[strcspn(addr.street_name, "\n")] = '\0'; // remove newline character at the end
    }

    // get city
    printf("Enter city: ");
    while (scanf("%99s", addr.city) != 1 || !isalpha(addr.city[0])) {
        printf("Invalid city. Please enter a valid alphabetic string: ");
        while (getchar() != '\n'); // clear input buffer
    }
    while (getchar() != '\n'); // clear input buffer after successful input

    // get unit number
    printf("Enter unit number (if applicable, otherwise type x): ");
    while (scanf("%9s", addr.unit_number) != 1 || (strcmp(addr.unit_number, "x") != 0 && strspn(addr.unit_number, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != strlen(addr.unit_number))) {
        printf("Invalid unit number. Please enter a valid alphanumeric string or 'x' if not applicable: ");
        while (getchar() != '\n'); // clear input buffer
    }
    while (getchar() != '\n'); // clear input buffer after successful input

    // display success message
    printf("Success! Your incomplete address is saved as %d %s, ", addr.street_number, addr.street_name);
    if (strcmp(addr.unit_number, "x") == 0) {
        printf("%s.\n", addr.city);
    } else {
        printf("Unit: %s, %s.\n", addr.unit_number, addr.city);
    }
    
    return addr;
}

//POSTAL 
char *postal() {
    char *code = malloc(8); // allocate memory for the code, including null terminator
    int valid = 0; // flag to indicate if the code is valid
    
    while (!valid) {
        printf("Please enter a Canadian postal code (e.g. M1V 0E7): ");
        
        // read input character by character until a newline is encountered
        int i = 0;
        char c;
        while ((c = getchar()) != '\n') {
            // add whitespace to string if there is room
            if (i < 7) {
                code[i] = c;
                i++;
            }
        }
        code[i] = '\0'; // add null terminator to end of string
        
        // check length of code
        if (strlen(code) != 7) {
            printf("Postal code must be formatted as \"XXX XXX\" with a space in between.\n");
            continue;
        }
        
        // check characters at each position
        for (i = 0; i < 7; i++) {
            if (i == 0 || i == 2 || i == 5) {
                if (!isalpha(code[i])) {
                    printf("Position %d must be a character.\n", i+1);
                    break;
                }
            } else if (i == 1 || i == 4 || i == 6) {
                if (!isdigit(code[i])) {
                    printf("Position %d must be a number.\n", i+1);
                    break;
                }
            } else if (i == 3) {
                if (code[i] != ' ') {
                    printf("Position %d must be a space.\n", i+1);
                    break;
                }
            }
            
            // code is valid if all checks pass
            if (i == 6) {
                valid = 1;
            }
        }
    }
    
    return code;
}

//PROVINCE and SUBTOTAL 
char* province() {
    const char *provinces[][2] = {{"Alberta", "5"}, {"British Colombia", "12"}, {"Manitoba", "12"}, {"New Brunswick", "15"}, {"Newfoundland and Labrador", "15"}, {"Northwest Territories", "5"}, {"Nova Scotia", "15"}, {"Nunavut", "5"}, {"Ontario", "13"}, {"Prince Edward Island", "15"}, {"Quebec", "15"}, {"Saskatchewan", "11"}, {"Yukon", "5"}};

    char province[100];
    int found = 0;

    while (!found) {
        printf("Please enter a Canadian province: ");
        fgets(province, 100, stdin);
        province[strcspn(province, "\n")] = '\0'; // remove newline character

        // Convert entered province to lowercase
        for (int i = 0; province[i]; i++) {
            province[i] = tolower(province[i]);
        }

        for (int i = 0; i < sizeof(provinces) / sizeof(provinces[0]); i++) {
            // Convert province in array to lowercase
            char lower_prov[strlen(provinces[i][0]) + 1];
            for (int j = 0; provinces[i][0][j]; j++) {
                lower_prov[j] = tolower(provinces[i][0][j]);
            }
            lower_prov[strlen(provinces[i][0])] = '\0';

            if (strcmp(lower_prov, province) == 0) {
                found = 1;
                char* result = malloc(strlen(provinces[i][0]) + strlen(provinces[i][1]) + 2);
                sprintf(result, "%s %s", provinces[i][0], provinces[i][1]);
                return result;
            }
        }

        if (!found) {
            printf("Invalid province. Please try again.\n");
        }
    }

    return NULL;
}

int main()
{
    char fname[50];
    char lname[50];
    firstlast(fname, lname);
    struct Address myAddress = getAddress();

    
    char *valid_postal_code = postal();
    char* province_data = province();
    char* province_name = strtok(province_data, " ");
    char* province_number = strtok(NULL, " ");
    
    printf("\n");
    
    if (strcmp(myAddress.unit_number, "x") != 0){
        printf("Hello %s %s, Thank you for ordering!\nWe will be delivering your package to\n%d %s, Unit: %s, %s %s, %s, Canada.\n",
           fname, lname, myAddress.street_number, myAddress.street_name,myAddress.unit_number, valid_postal_code, myAddress.city, province_name);
    }
    else{
    printf("Hello %s %s, Thank you for ordering!\nWe will be delivering your package to\n%d %s %s %s, %s, Canada.\n",
           fname, lname, myAddress.street_number, myAddress.street_name, valid_postal_code, myAddress.city, province_name);
    }
  
  
int subtotal = 190;  
double tax_multiplier = 1.0 + atof(province_number)/100.0;
double taxes = ( (subtotal+10 )* tax_multiplier) - (subtotal+10 );

printf("--------------CHECKOUT------------------\n");
printf("%-30s%10.2f\n", "Subtotal:", (float)subtotal);
printf("%-30s%10.2f\n", "Shipping:", 10.00);
printf("%-30s%10.2f\n", "Taxes:", taxes);
printf("----------------------------------------\n");
printf("%-30s%10.2f\n", "Total:", (double)(taxes + 10 + subtotal));
free(valid_postal_code);
free(province_data);
return 0;
}


