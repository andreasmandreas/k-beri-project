#include <stdio.h>
#include <string.h>

/*
 * Need to implement the following:
 * Functions (there are as of Release 1)
 * Decision tables
 * Arrays, Strings, Data Dictionaries
 * Pointers
 * Parameter Passing
*/

//Function for converting rateToEur[]

//Structure for Products & balance codes

typedef struct {
    char name[50];   // e.g., "Eau de Luxe"
    char brand[50]; // e.g., "Chanel"
    float price;           // e.g., 120.50
    int sex;           // "Male" = 1    &&  "Female" = 0
    int stock;             // e.g., 15 bottles available
    float discount; // e.g., how big is the discount
} Perfume;

typedef struct {
    int code;
    float value;
    int used; // 0 = not used, 1 = redeemed
} BalanceCode;




//ANDREAS & SASHA - ADMIN PANEL - IMPLEMENT viewCodes(), addPerfume(), viewProducts(), setDiscount(), addBalanceCode() work this with Britten! ;

//BRITTEN - USER PANEL - Implement addBalance() - work this with Andreas! , viewProducts();

//DIMA - SRS, ERROR HANDLING, FILE HANDLING LATER, EVERYTHING TO CHECK AT THE END

//HENRIK - FLOWCHARTS, USER STORIES (3 new ones related to the functions that
// other will implement), Implementation Options for Release 2 (SRS) & Decision Tables (SRS);

//SASHA - Data Dictionary (SRS) & Acceptance Criteria for Release 2 (SRS);

Perfume inventory[100];
int perfumeCount = 0;

BalanceCode codes[100];
int codeCount = 0;

float userBalance = 0.0f;

Perfume userinventory[100];

void viewProducts();

void defaultCodes() {
    codes[0] = (BalanceCode){ 135791, 10, 0 };
    codes[1] = (BalanceCode){ 246802, 50, 0 };
    codes[2] = (BalanceCode){ 753197, 100, 0 };
    codes[3] = (BalanceCode){ 579135, 200, 0 };
    codes[4] = (BalanceCode){ 864202, 75, 0 };
    codes[5] = (BalanceCode){ 468024, 67, 0 };
    codeCount = 6;
}

void addBalance() {
    int enteredCode;
    int found = 0;

    printf("Enter your balance code: \n");
    scanf("%6d", &enteredCode);

    for (int i = 0; i < codeCount; i++) {
        if (enteredCode == codes[i].code) {
            printf("Code found! \n");
            float value = codes[i].value;
            printf("Value: %f\n", value);

        }
    }


}


void addBalance() {
    char enteredCode[7];
    int found = 0;

    printf("Enter your balance code: ");
    scanf("%6s", enteredCode);

    for (int i = 0; i < codeCount; i++) {
        if (strcmp(codes[i].code, enteredCode) == 0) {
            if (codes[i].used == 0) {
                userBalance += codes[i].value;
                codes[i].used = 1;
                printf("Code accepted! Your balance increased by %.2f EUR.\n", codes[i].value);
                printf("Your new balance: %.2f EUR\n", userBalance);
            } else {
                printf("This code has already been used!\n");
            }
            found = 1;
            break;
        }
        
    }
    if (!found) {
    printf("Code does not exist!\n");
    }
}

// Add perfume menu for admin
void addPerfume() {
    char name[50];
    printf("Perfume Name: \n");
    scanf("%49s", &name);

    char brand[50];
    printf("Perfume Brand: \n");
    scanf("%49s", &brand);

    float price;
    printf("Enter price: \n");
    scanf("%f", &price);

    int sex;
    printf("Sex (1 for Male, 0 for Female): \n");
    scanf("%d", &sex);

    int stock;
    printf("Amount in stock: \n");
    scanf("%d", &stock);

    int a = perfumeCount;
    strcpy(inventory[a].name, name);
    strcpy(inventory[a].brand, brand);
    inventory[a].price = price;
    inventory[a].sex = sex;
    inventory[a].stock = stock;
    perfumeCount += 1;

    viewProducts();
}

// Add hardcoded perfumes
void defaultPerfumes() {
    inventory[0] = (Perfume){"Sauvage EDT", "Dior", 137, 1, 100, 0};
    inventory[1] = (Perfume){"Elixir EDP", "Yves Saint Laurent", 75, 1, 50, 0};
    inventory[2] = (Perfume){"Born In Roma EDT", "Valentino", 80, 1, 40, 0};
    inventory[3] = (Perfume){"No. 5 EDP", "Chanel", 135, 0, 20, 0};
    inventory[4] = (Perfume){"Black Opium EDP", "Yves Saint Laurent", 70, 0, 40, 0};
    perfumeCount = 5;
}


// ^ Brand - Name - EDT or EDP - Masculine or Female
// e.g Dior - Sauvage - EDT - Masculine


// Checks if the user made a valid input
int validNumber(void) {
    int x;
    while (1) {
        // Only integers are allowed!
        if (scanf("%d", &x) == 1) {
            return x;
        }
        else {
            printf("ERROR: Not a valid input! Try again.\n");
            printf("INPUT: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {} //Error handling when an input doesn't work!
        }
    }
}

// Displays the welcome banner and asks for the user role
int welcomeDialog() {
    printf("___________                                        \n");
    printf("\\_   _____/___________     ____      ____   ____  \n");
    printf(" |    __) \\_  __ \\__  \\   / ___\\   _/ __ \\_/ __ \\ \n");
    printf(" |     \\   |  | \\/ __ \\_/ /_/  >  \\  ___/\\  ___/ \n");
    printf(" \\___  /   |__|  (____  /\\___  / /\\ \\___  >\\___  >\n");
    printf("     \\/               \\/_____/  \\/     \\/     \\/  \n");
    printf("\n");
    printf("Welcome to the Frag.ee Store! \n\n"
        "**************************************************\n\n"
        "Type '1' if you're a CUSTOMER navigating through the site\n"
        "or type '2' if you're an STOREKEEPER and want some changes!\n\n"
        "**************************************************\n"
        "Happy shopping! :)\n");
    printf("INPUT: ");
    return validNumber();
}

// Customer viewing products
void viewProducts() {
    printf("Available Perfumes\n");
    printf("%-5s %-25s %-20s %-8s %-8s %-8s\n", "No.", "Name", "Brand", "Price", "Stock", "Sex");
    
    for (int i = 0; i < perfumeCount; i++) {
        char sex[7];
        if (inventory[i].sex == 1) {
            strcpy(sex, "Male");
        }
        else {
            strcpy(sex, "Female");
        }

        printf("%-5d %-25s %-20s EUR%-7.2f  %-8d %-8s\n",
            i + 1,
            inventory[i].name,
            inventory[i].brand,
            inventory[i].price,
            inventory[i].stock,
            sex);
    }

}


// Placeholder for customer functionality
void customerMenu() {
    printf("You are now in the customer section. You can browse and make purchases.\n");

    int userChoice;
    do {
        printf("\n--- Customer Panel ---\n");
        printf("1. Add a product to shopping cart\n");
        printf("2. View all products\n");
        printf("3. View shopping cart\n");
        printf("4. Add balance\n");
        printf("5. Exit to main menu\n");
        printf("INPUT: ");

        if (scanf("%d", &userChoice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("ERROR: Please enter a number.\n");
            continue;
        }

        switch (userChoice) {
        case 1:
            // addProducts();
            break;
        case 2:
            viewProducts();
            break;
        case 3:
            // viewShoppingCart();
            break;
        case 4:
            addBalance();
            break;
        case 5:
            printf("Exiting customer panel. Goodbye!\n");
            break;
        default:
            printf("ERROR: Invalid choice. Please try again.\n");
            break;
        }
        // Exit after handling options 1,2,3
        if (userChoice >= 1 && userChoice <= 3) {
            break;  // exit the menu loop after performing the action
        }
    } while (userChoice != 4); 
}

// Storekeeper menu functionality
void storekeeperMenu() {
    int adminChoice;

    printf("\n--- Storekeeper Panel ---\n");
    printf("What would you like to do?\n");
    printf("1. Add a new product\n");
    printf("2. View all products\n");
    printf("3. Set discount\n");
    printf("4. Add balance code\n");
    printf("5. Exit to main menu\n");
    printf("INPUT: ");

    if (scanf("%d", &adminChoice) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {} // flush bad input
        printf("ERROR: Please enter a number.\n");
        return;
    }

    switch (adminChoice) {
    case 1:
        // addPerfume();
        break;
    case 2:
        viewProducts();
        break;
    case 3:
        // setDiscount();
        break;
    case 4:
        // addBalanceCode();
        break;
    case 5:
        printf("Exiting admin panel. Goodbye!\n");
        return;
    default:
        printf("ERROR: Invalid choice. Please try again.\n");
        break;
    }
}


// Password gate for storekeeper access
void storeKeeperPassCheck() {
    char adminPass[20];
    const char correctPassword[] = "admin123";

    printf("Insert the admin password to access the panel!\n");
    // Use scanf for a single-word password
    scanf("%19s", adminPass); //Reads the first 19 characters in the buffer

    if (strcmp(adminPass, correctPassword) == 0) {
        printf("Correct password, welcome to the admin panel!\n");
        storekeeperMenu();
    }
    else {
        printf("ERROR: Wrong password, access denied!\n");
        storeKeeperPassCheck();
    }
}
// Routes user based on their chosen role
void roleSelect(int roleChoice) {
    while (1) {
        if (roleChoice == 1) {
            printf("You are a customer :)\n");
            customerMenu();
            break;
        }
        else if (roleChoice == 2) {
            printf("You are a storekeeper :)\n");
            storeKeeperPassCheck();
            break;
        }
        else {
            printf("ERROR: Not a valid number!\n");
            printf("INPUT: ");
            roleChoice = validNumber();
        }
    }
}

// Entry point
int main(void) {
    defaultPerfumes();
    defaultCodes();
    const int roleChoice = welcomeDialog();
    roleSelect(roleChoice);
    return 0;
}
