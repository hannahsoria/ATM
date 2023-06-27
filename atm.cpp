#include <stdio.h>
#include <time.h>

int main() {
    int pin = 1234, option, enteredPin, count = 0, amount = 1;
    float balance = 5000;
    int countinueTransaction = 1;

    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t\t   %s", ctime(&now));
    printf("\n\t\t\t      =====================*Welcome to Hannah's ATM*=====================");

    while(pin != enteredPin) {
        printf("\nPlease enter your pin: ");
        scanf("%d", &enteredPin);
        /* incorrect pin entered */
        if (enteredPin != pin) {
            printf("Invalid Pin");
        }
        /*increase count of how many times pin is entered*/
        count++;
        if (count == 3 && pin != enteredPin) {
            return(0);
        }
    }
    /* while the transaction is happening*/
    while(countinueTransaction != 0){
        printf("\n\t\t\t      ====================*Avaliable Transactions*====================");
        printf("\n\n\t\t1.Withdrawl");
        printf("\n\t\t2.Deposit");
        printf("\n\t\t3.Check Balance");
        printf("\n\n\tPlease select the option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                /* multiple of 5 only */
                while(amount % 5 != 0) {
                    printf("\n\t\tEnter the amount: ");
                    scanf("%d", &amount);
                    if (amount % 5 != 0)
                    printf("\n\t The amount should be a multiple of 5");
                }
                /* invalid amount */
                if (balance < amount) {
                    printf("\n\t Sorry insufficient balance");
                    amount = 1;
                    break;
                } else {
                    /* valid amount */
                    balance -= amount;
                    printf("\n\t\tYou have withdrawn $%d. Your new balance is %.2f", amount, balance);
                    amount = 1;
                    printf("\n\t\t\t ====================*Thank you for banking with Hannah's ATM*====================");
                    break;
                }
            case 2:
                printf("\n\t\t Please enter the amount :");
                scanf("%d", &amount);
                balance += amount;
                amount =1;
                printf("\n\t\tYou have deposited $%d, Your new balance is %.2f", amount, balance);
                printf("\n\t\t\t ====================*Thank you for banking with Hannah's ATM*====================");
                break;
            
            case 3:
                printf("\n\t\tYour balance is $%.2f", balance);
                break;

            default:
                printf("\n\t\tInvalid option");
        }
        /* option to contiue the transaction */
        printf("\n\t\tDo you wish to perform amnother transaction? Press 1[Yes] or 0[No]");
        scanf("%d", &countinueTransaction);
        if (countinueTransaction == 0) {
            printf("\n\t\t\t ====================*Thank you for banking with Hannah's ATM*====================");
        }
    }
}

