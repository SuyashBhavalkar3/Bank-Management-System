#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

struct tranction_history // To store Tranction Histor
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    long long int amount;
    char org_reciever_username[40], tranction_type[20], org_sender_username[40], reciever_username[40], sender_username[40], initial_deposite[20];
};

struct User // To store User Data
{
    char username[50], fname[20], lname[20], fathname[20], email[20], password[50], contact[12], lable;
    int date, month, year;
    long long int balance;
};

int check_username_exists(char User[]) // To check that if username exists or not
{
    struct User u1;
    FILE *fp;
    fp = fopen("username.txt", "rb");

    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if ((strcmp(User, u1.username) == 0))
            return 1;
    }

    fclose(fp);
}

int check_pass_exists(char pass[])
{
    struct User u1;
    FILE *fp;
    fp = fopen("username.txt", "rb");

    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if ((strcmp(pass, u1.password) == 0))
            return 1;
    }
    fclose(fp);
}

void initial_update_passbook(char *username, struct User *U, struct tranction_history *th) 
{   // To add the initial details in passbook 
    char filename[60];
    snprintf(filename, sizeof(filename), "%s_passbook.txt", username);
    FILE *fp = fopen(filename, "a"); 
    if (fp == NULL)
    {
        printf("Error in opening passbook file for user: %s\n", username);
        return;
    }
    fprintf(fp, "\n+-----------------------------------------------+\n");
    fprintf(fp, "|                   PASSBOOK                    |\n");
    fprintf(fp, "+-----------------------------------------------+\n");
    fprintf(fp, "| Username       : %-28s |\n", U->username);
    fprintf(fp, "|-----------------------------------------------|\n");
    fprintf(fp, "| First Name     : %-28s |\n", U->fname);
    fprintf(fp, "| Father's Name  : %-28s |\n", U->fathname);
    fprintf(fp, "| Last Name      : %-28s |\n", U->lname);
    fprintf(fp, "| Email ID       : %-28s |\n", U->email);
    fprintf(fp, "| Contact Number : %-28s |\n", U->contact);
    fprintf(fp, "| Date of Birth  : %02d-%02d-%04d                   |\n", U->date, U->month, U->year);
    fprintf(fp, "|-----------------------------------------------|\n");
    fprintf(fp, "| Initial Balance        : %-20lld |\n", U->balance);
    fprintf(fp, "| Account Type   : %-28s |\n", U->lable == 'S' ? "Saving Account" : "Current Account");
    fprintf(fp, "+-----------------------------------------------+\n");
    fprintf(fp, "\n+--------------------- TRANSACTION HISTORY ---------------------+\n\n");
    fprintf(fp, "%-19s | %-15s | %-15s |\n", "Date:Time", "Amount (Rs)", "Transaction Type");
    fprintf(fp, "--------------------| --------------- | ---------------  |\n");

    fprintf(fp, "%02d-%02d-%04d %02d:%02d:%02d | %-15lld | %-15s\n",
            th->day, th->month, th->year, th->hour, th->minute, th->second,
            th->amount, th->tranction_type);
    fprintf(fp, "\n");
    fclose(fp);
}

void update_passbook(char *username, struct tranction_history *th, long long int *current_balance)
{
    char filename[60];
    snprintf(filename, sizeof(filename), "%s_passbook.txt", username); // Create filename

    FILE *fp = fopen(filename, "a"); // Open file in append mode
    if (fp == NULL)
    {
        printf("Error in opening passbook file for user: %s\n", username);
        return;
    }

    // Write transaction history to the file
    fprintf(fp, "%02d-%02d-%04d %02d:%02d:%02d | %-10lld      | %-10s       | Current Balance : %-10lld ",
            th->day, th->month, th->year, th->hour, th->minute, th->second,
            th->amount, th->tranction_type, *current_balance);

    if (strcmp(th->org_sender_username, username) == 0 && strcmp(th->tranction_type, "transfer") == 0)
    {
        fprintf(fp, "| Receiver: %-10s ", th->reciever_username);
        fprintf(fp, "\n");
    }
    else if (strcmp(th->org_reciever_username, username) == 0 && strcmp(th->tranction_type, "transfer") == 0)
    {
        fprintf(fp, "| Sender: %-10s ", th->sender_username);
        fprintf(fp, "\n");
    }
    else
    {
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void Create_Account(void)
{
    char ch;
    FILE *fp, *fp2;
    struct User u1;
    struct tranction_history TH1;

    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);

    fp = fopen("username.txt", "ab+");
    fp2 = fopen("t_h.txt", "ab");

    printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

    printf("\n\nFIRST NAME.. ");
    scanf("%s", &u1.fname);

    printf("\n\nFATHER's NAME.. ");
    scanf("%s", &u1.fathname);

    printf("\n\n\nLAST NAME.. ");
    scanf("%s", &u1.lname);

    printf("\n\n\nEmail ID.. ");
    scanf("%s", &u1.email);

    printf("\n\n\nContact Number... ");
    scanf("%s", &u1.contact);
    printf("\n\n\nDate Of Birth... ");
    scanf("%d", &u1.date);
    printf("\n\nBirth Month.. ");
    scanf("%d", &u1.month);
    printf("\n\n\nBirth Year.. ");
    scanf("%d", &u1.year);

// #Use Of goto
Entre_username:
    printf("\n\n\nEntre User Name(Without Space).. ");
    scanf("%s", &u1.username);
    while (check_username_exists(u1.username))
    {
        printf("User name already exists , Entre unique username !\n");
        goto Entre_username;
    }

Entre_pass:
    printf("\n\nEntre PASSWORD(Without Space)..");
    scanf("%s", u1.password);
    while (check_pass_exists(u1.password))
    {
        printf("Password Already exists , Entre Unique password \n");
        goto Entre_pass;
    }
    int account_type_option;
    do
    {
        printf("Which Account You Want To Open , Entre Your Option \n 1 . Saving Account  \n 2 . Current Account");
        scanf("%d", &account_type_option);
        switch (account_type_option)
        {
        case 1:
            u1.lable = 'S';
            printf("The Minimum Balance For Saving Account Is 1000 Rs. \n ");
            printf("Deposite The Minimum Balance Amount In Account (Amount Can Be greater Than Min Balance amount )\n");
            scanf("%lld", &u1.balance);
            TH1.year = localTime->tm_year + 1900;
            TH1.month = localTime->tm_mon + 1;
            TH1.day = localTime->tm_mday;
            TH1.hour = localTime->tm_hour;
            TH1.minute = localTime->tm_min;
            TH1.second = localTime->tm_sec;
            TH1.amount = u1.balance;
            strcpy(TH1.org_sender_username, u1.username);
            strcpy(TH1.tranction_type, "deposite");
            break;
        case 2:
            u1.lable = 'C';
            printf("The Minimum Balance For Current Account Is 500 Rs. \n ");
            printf("Deposite The Minimum Balance Amount In Account (Amount Can Be greater Than Min Balance amount )\n");
            scanf("%lld", &u1.balance);
            TH1.year = localTime->tm_year + 1900;
            TH1.month = localTime->tm_mon + 1;
            TH1.day = localTime->tm_mday;
            TH1.hour = localTime->tm_hour;
            TH1.minute = localTime->tm_min;
            TH1.second = localTime->tm_sec;
            TH1.amount = u1.balance;
            strcpy(TH1.org_sender_username, u1.username);

            strcpy(TH1.tranction_type, "deposite");
            strcpy(TH1.initial_deposite, "initial_deposite");

            break;
        default:
            printf("Entre Valid Option !\n");
        };

    } while ((account_type_option != 1) && (account_type_option != 2));
    fwrite(&u1, sizeof(u1), 1, fp);
    fwrite(&TH1, sizeof(TH1), 1, fp2);

    fflush(fp);
    fflush(fp2);
    fclose(fp);
    fclose(fp2);
    initial_update_passbook(u1.username, &u1, &TH1);
}

void display(char username1[])
{
    int flag = 0;
    FILE *fp, *fp2;
    struct User u1;
    struct tranction_history TH1;

    fp = fopen("username.txt", "rb");
    if (fp == NULL)
    {
        printf("Error in opening user file\n");
        return;
    }

    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if (strcmp(username1, u1.username) == 0)
        {
            printf("\n+-----------------------------------------------+\n");
            printf("|                   PASSBOOK                    |\n");
            printf("+-----------------------------------------------+\n");
            printf("| Username       : %-28s |\n", u1.username);
            printf("|-----------------------------------------------|\n");
            printf("| First Name     : %-28s |\n", u1.fname);
            printf("| Father's Name  : %-28s |\n", u1.fathname);
            printf("| Last Name      : %-28s |\n", u1.lname);
            printf("| Email ID       : %-28s |\n", u1.email);
            printf("| Contact Number : %-28s |\n", u1.contact);
            printf("| Date of Birth  : %02d-%02d-%04d               |\n", u1.date, u1.month, u1.year);
            printf("|-----------------------------------------------|\n");
            printf("| Balance        : %-28lld |\n", u1.balance);
            printf("| Account Type   : %-28s |\n", u1.lable == 'S' ? "Saving Account" : "Current Account");
            printf("+-----------------------------------------------+\n");

            // Display transaction history
            fp2 = fopen("t_h.txt", "rb");
            if (fp2 == NULL)
            {
                printf("Error in opening transaction history file\n");
                fclose(fp);
                return;
            }

            printf("\n+--------------------- TRANSACTION HISTORY ---------------------+\n");
            while (fread(&TH1, sizeof(TH1), 1, fp2))
            {
                if (strcmp(TH1.org_sender_username, username1) == 0 || strcmp(TH1.org_reciever_username, username1) == 0)
                {
                    printf("| Date       : %02d-%02d-%04d %02d:%02d:%02d                      \n", TH1.day, TH1.month, TH1.year, TH1.hour, TH1.minute, TH1.second);
                    printf("| Amount     : %-44lld \n", TH1.amount);
                    printf("| Transaction Type   : %-28s \n", TH1.tranction_type);
                    if (strcmp(TH1.org_sender_username, username1) == 0 && strcmp(TH1.tranction_type, "transfer") == 0)
                    {
                        printf("| Reciever Username : %-28s \n", TH1.reciever_username);
                    }
                    if (strcmp(TH1.org_reciever_username, username1) == 0 && strcmp(TH1.tranction_type, "transfer") == 0)
                    {
                        printf("| Sender Username   : %-28s \n", TH1.sender_username);
                    }
                    printf("+--------------------------------------------------------------+\n");
                }
            }

            flag = 1; // User found
            break;
        }
    }
    fclose(fp2);
    if (flag == 0)
    {
        printf("Invalid Username\n");
    }

    fclose(fp);
}

void deposite(char UserName[], char Password[])
{
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    char username[50], password[50];
    struct User U;
    struct tranction_history TH1;
    long long temp_deposite_amount = 0;
    FILE *fp, *fp2;
    fp = fopen("username.txt", "rb+");
    fp2 = fopen("t_h.txt", "ab");
    if (fp == NULL || fp2 == NULL)
    {
        printf("Error in opening file");
        return;
    }
    printf("\n\nEnter User Name... ");
    scanf("%s", username);
    printf("\n\nEnter Password... ");
    scanf("%s", password);
    if (strcmp(username, UserName) == 0 && strcmp(password, Password) == 0)
    {
        int flag = 0;
        while (fread(&U, sizeof(U), 1, fp))
        {
            if ((strcmp(username, U.username) == 0) && (strcmp(password, U.password) == 0))
            {
                printf("Previous Balance= %lld \n", U.balance);
                printf("\nEnter The amount you want to deposit...\n");
                scanf("%lld", &temp_deposite_amount);

                U.balance += temp_deposite_amount;

                // Update transaction history
                TH1.year = localTime->tm_year + 1900;
                TH1.month = localTime->tm_mon + 1;
                TH1.day = localTime->tm_mday;
                TH1.hour = localTime->tm_hour;
                TH1.minute = localTime->tm_min;
                TH1.second = localTime->tm_sec;
                TH1.amount = temp_deposite_amount;

                strcpy(TH1.org_sender_username, U.username);
                strcpy(TH1.tranction_type, "deposite");

                fseek(fp, -sizeof(U), SEEK_CUR);
                fwrite(&U, sizeof(U), 1, fp);
                fwrite(&TH1, sizeof(TH1), 1, fp2); 
                printf("Your Current balance Becomes %lld\n", U.balance);
                update_passbook(U.username, &TH1, &U.balance);
                flag = 1;
                break;
            }
        }
    }
    else
    {
        printf("Invalid User name or password\n");
    }
    fclose(fp);
    fclose(fp2);
}

void withdraw(char UserName[], char Password[])
{
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);

    char username[50], password[50];
    struct User U;
    struct tranction_history TH1;
    long long int temp_withdraw_amount = 0, result;
    FILE *fp, *fp2;
    fp = fopen("username.txt", "rb+");
    fp2 = fopen("t_h.txt", "ab");
    if (fp == NULL || fp2 == NULL)
    { 
        printf("Error in opening file");
        return;
    }

    printf("\n\nEnter User Name... ");
    scanf("%s", username);
    printf("\n\nEnter Password... ");
    scanf("%s", password);
    if (strcmp(username, UserName) == 0 && strcmp(password, Password) == 0)
    {

        int flag = 0;
        while (fread(&U, sizeof(U), 1, fp))
        {
            if ((strcmp(username, U.username) == 0) && (strcmp(password, U.password) == 0))
            {
                printf("Your previous balance was %lld\n", U.balance);
                if (U.lable == 'S')
                {
                    printf("You Can Withdraw Upto 50,000 Rs only \n");
                } 

            Entre_amount:
                printf("\nEnter The amount you want to Withdraw...\n");
                scanf("%lld", &temp_withdraw_amount);
                result = U.balance - temp_withdraw_amount;
                if (result < 0)
                {
                    int option;
                    printf("Insufficient bank balance\n");
                    do
                    {
                        printf("Still, do you want to withdraw the amount? Enter your desired option\n Yes = 1\n No = 0\n");
                        scanf("%d", &option);

                        switch (option)
                        {
                        case 1:
                            goto Entre_amount;
                            break;
                        default:
                            printf("Wrong option!\n");
                        }
                    } while (option == 1);
                }
                else if (result > 50000 && U.lable == 'S')
                {
                    int option;
                    printf("Maximum Withdraw Limit Exceeded!\n");
                    printf("Do you want to enter the amount again?\n");
                    printf("1. Yes\n2. No\n");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        goto Entre_amount;
                        break;
                    }
                }
                else
                {
                    U.balance = result;
                    printf("You withdrew %lld successfully!\n", temp_withdraw_amount);
                    printf("Your current balance is %lld\n", U.balance);

                    // Update transaction history
                    TH1.year = localTime->tm_year + 1900;
                    TH1.month = localTime->tm_mon + 1;
                    TH1.day = localTime->tm_mday;
                    TH1.hour = localTime->tm_hour;
                    TH1.minute = localTime->tm_min;
                    TH1.second = localTime->tm_sec;
                    TH1.amount = temp_withdraw_amount;
                    strcpy(TH1.org_sender_username, U.username);
                    strcpy(TH1.tranction_type, "withdraw");
                    update_passbook(U.username, &TH1, &U.balance);
                    fseek(fp, -sizeof(U), SEEK_CUR);
                    fwrite(&U, sizeof(U), 1, fp);
                    fwrite(&TH1, sizeof(TH1), 1, fp2); 
                    fflush(stdin);
                }

                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
        }
    }
    else
    {
        printf("Invalid User name or password\n");
        fclose(fp);
        fclose(fp2);
        return;
    }
    fclose(fp);
    fclose(fp2);
}

void kyc(char USER[])
{
    int i = 0;
    struct User U1;
    FILE *fp = fopen("username.txt", "rb+");

    while (fread(&U1, sizeof(U1), 1, fp))
    {

        if (strcmp(USER, U1.username) == 0)
        {
            printf("Which Details You Want to Update ?\n");
            printf("  0. Exit  \n 1 . username \n 2 . password \n 3 . First name \n 4 .  Father's Name \n 5 .  Last Name \n 6 .  Email \n 7 . Contact  \n 8 . Birth Date \n 9 . Birth month \n 10 . Birth Year \n");
            int kyc_option;
            do
            {
                printf("Entre Your Option ");
                scanf("%d", &kyc_option);
                switch (kyc_option)
                {
                case 0:
                    break;
                case 1:
                    printf("\nEntre The New Username ");
                    scanf("%s", U1.username);
                    break;
                case 2:
                    printf("\nEntre The New Password ");
                    scanf("%s", U1.password);
                    break;
                case 3:
                    printf("\nEntre The First Name ");
                    scanf("%s", U1.fname);
                    break;
                case 4:
                    printf("\nEntre The Father's Name ");
                    scanf("%s", U1.fathname);
                    break;
                case 5:
                    printf("\nEntre The Last Name ");
                    scanf("%s", U1.lname);
                    break;
                case 6:
                    printf("\nEntre The New Email Id ");
                    scanf("%s", U1.email);
                    break;
                case 7:
                    printf("\nEntre The New Contact Number ");
                    scanf("%s", U1.contact);
                    break;
                case 8:
                    printf("\nEntre The New Birth Date  ");
                    scanf("%d", &U1.date);
                    break;
                case 9:
                    printf("\nEntre The New Birth Month ");
                    scanf("%d", &U1.month);
                    break;
                case 10:
                    printf("\nEntre The New Birth Year ");
                    scanf("%d", &U1.year);
                    break;
                }

            } while (kyc_option >= 1 && kyc_option <= 10);

            fseek(fp, -sizeof(U1), SEEK_CUR);
            fwrite(&U1, sizeof(U1), 1, fp);
            fflush(stdin);
            break;
        }
    }
    fclose(fp);
}

void transfer(char sender_username[], char sender_password[])
{
    FILE *fp2;
    struct tranction_history TH1;
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    fp2 = fopen("t_h.txt", "ab");

    int temp_transfer_amount, succsesful_transfer = 1;
    char reciever_username[50];
    struct User Sender, Reciever;
    FILE *fp = fopen("username.txt", "rb+");
    int reciever_name_again, reciever_flag = 1;
    do
    {

        printf("Entre Reciever's Username :  ");
        scanf("%s", reciever_username);
        if (check_username_exists(reciever_username) == 0)
        {
            printf("Reciever Does Not Exists ! \n");
            printf("Do You Want TO Entre Reciever's Name Again ? \n 1 . Yes  \n 2 . No");
            scanf("%d", &reciever_name_again);
            reciever_flag = 0;
        }
        else
        {
            reciever_flag = 1;
            reciever_name_again = 0;
        };
    } while (reciever_name_again == 1);

    if (reciever_flag == 1)
    {

        while (fread(&Sender, sizeof(Sender), 1, fp)) // Updating Sender's Account
        {
            int amount_again = 0, max_transfer_exeded_option = 0;
            if (strcmp(sender_username, Sender.username) == 0 && strcmp(sender_password, Sender.password) == 0)
            {
                long long int result;
                printf("Your Previous Balance Was : %d   \n", Sender.balance);
                do
                {
                    if (Sender.lable == 'S')
                    {
                        printf("You Can Transfer Upto 50,000 Rs only \n");
                    }
                    printf("Entre The Amount You Want To Transfer :  ");
                    scanf("%d", &temp_transfer_amount);

                    if (temp_transfer_amount > Sender.balance)
                    {
                        printf("Insufficient Balance !\n");
                        printf("Do You Want To Entre Amount Again ?  \n 1 . Yes  \n 2 . No !\n");
                        scanf("%d", &amount_again);
                        succsesful_transfer = 0;
                    }
                    else if ((Sender.balance - temp_transfer_amount) > 50000 && Sender.lable == 'S')
                    {
                        printf("Maximum Transfer Limit Exceeded !\n");
                        printf("Do You Want To Entre Amount Again ?\n");
                        printf("1 . Yes  \n 2 . No \n");
                        scanf("%d", &max_transfer_exeded_option);
                    }
                    else
                    {
                        Sender.balance -= temp_transfer_amount;
                        printf("Your Current Balance Becomes : %d  ", Sender.balance);
                        fseek(fp, -sizeof(Sender), SEEK_CUR);
                        fwrite(&Sender, sizeof(Sender), 1, fp);
                        fflush(stdin);

                        amount_again = 0;
                        fclose(fp);

                        succsesful_transfer = 1; 

                        TH1.year = localTime->tm_year + 1900;
                        TH1.month = localTime->tm_mon + 1;
                        TH1.day = localTime->tm_mday;
                        TH1.hour = localTime->tm_hour;
                        TH1.minute = localTime->tm_min;
                        TH1.second = localTime->tm_sec;
                        TH1.amount = temp_transfer_amount;

                        strcpy(TH1.org_sender_username, Sender.username);
                        strcpy(TH1.reciever_username, reciever_username);
                        strcpy(TH1.tranction_type, "transfer");
                        update_passbook(Sender.username, &TH1, &Sender.balance);
                        fwrite(&TH1, sizeof(TH1), 1, fp2);

                        break;
                    }
                } while (amount_again == 1 || max_transfer_exeded_option == 1);
            }
        }

        if (succsesful_transfer)
        {
            fp = fopen("username.txt", "rb+");

            while (fread(&Reciever, sizeof(Reciever), 1, fp))
            {
                if (strcmp(reciever_username, Reciever.username) == 0)
                {
                    Reciever.balance += temp_transfer_amount;
                    fseek(fp, -sizeof(Reciever), SEEK_CUR);
                    fwrite(&Reciever, sizeof(Reciever), 1, fp);
                    fflush(stdin);
                    fclose(fp);
                    strcpy(TH1.org_reciever_username, reciever_username);
                    strcpy(TH1.org_sender_username, "NONE");
                    strcpy(TH1.sender_username, sender_username);

                    update_passbook(Reciever.username, &TH1, &Reciever.balance);
                    fwrite(&TH1, sizeof(TH1), 1, fp2);
                }
            }
        }
    }
    fclose(fp);
    fclose(fp2);
}

int main()
{
    time_t currentTime;
    time(&currentTime);
    int main_option = 0;

    struct tm *localTime = localtime(&currentTime);
    int login_flag = 0;
    struct User U1;
    printf("Do You Have an account ? \n 1. Login \n");
    printf("Don't Have an account ? \n 2. Create an Account \n");
    printf("Entre Option\n");
    scanf("%d", &main_option);
    if (main_option == 2)
    {
        Create_Account();
        main_option = 1;
    }
    printf("\n");
    if (main_option == 1)
    {
        printf("Account Login !\n");
        printf("Entre Username ");
        scanf("%s", U1.username);
        printf("\nEntre Password ");
        scanf("%s", U1.password);
    }
    if (check_username_exists(U1.username) && check_pass_exists(U1.password))
    {
        printf("Login succesful !\n");
        login_flag = 1;

    }
    if (login_flag)
    {
        int option = 0;
        do
        {
            printf("\n 0 . Exit \n 1 . Deposite \n 2 . Withdraw \n 3 . Acoount Details \n 4 . KYC Update \n 5 . Transfer Money \n ");
            scanf("%d", &option);
            switch (option)
            {
            case 0:
                return 0;
                break;
            case 1:
                deposite(U1.username, U1.password);
                break;
            case 2:
                withdraw(U1.username, U1.password);
                break;
            case 3:
                display(U1.username);
                break;
            case 4:
                kyc(U1.username);
                do
                {
                    printf("\nEntre The New details again \n");
                    printf("Entre username ");
                    scanf("%s", U1.username);
                    printf("\nEntre Password ");
                    scanf("%s", U1.password);
                } while (check_pass_exists(U1.password) == 0 && check_username_exists(U1.username) == 0);
                break;
            case 5:
                transfer(U1.username, U1.password);
                break;
            }
        } while (option >= 1 && option <= 8);
    }
    else
    {
        printf("Invalid Username or Password !\n");
    }
}
