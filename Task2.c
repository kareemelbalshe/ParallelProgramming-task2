#include <stdio.h>
#include <string.h>
// KAMEL AHMED KAMEL G2 
union UserStatus {
    int isActive;
    int isInactive;
};

struct User {
    char username[20];
    char password[8];
    union UserStatus status;
};

void signUp(struct User* user)
{
    printf("Enter user name: ");
    scanf("%s", user->username);
    printf("Enter Password: ");
    scanf("%s", user->password);

    int statusValue;
    printf("Enter account status (0 - Inactive, 1 - Active): ");
    scanf("%d", &statusValue);

    if (statusValue == 1) {
        user->status.isActive = 1;
    } else {
        user->status.isInactive = 0;
    }
}

int login(const struct User* user)
{
    char username2[20];
    char password2[8];

    printf("Enter user name: ");
    scanf("%s", username2);
    printf("Enter Password: ");
    scanf("%s", password2);

    if (strcmp(user->username, username2) == 0 && strcmp(user->password, password2) == 0)
    {
        if (user->status.isActive)
        {
            return 1;
        }
        else
        {
            printf("Account is not active anymore.\n");
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct User user;
    int loggedIn = 0;

    printf("*********************SIGN UP***************************\n");
    signUp(&user);
    printf("Signed up successfully\n");

    printf("\n*********************LOGIN***************************\n");
    loggedIn = login(&user);

    if (loggedIn)
    {
        printf("Logged in Successfully\n");
    }
    else
    {
        printf("Failed to log in\n");
    }

    return 0;
}
