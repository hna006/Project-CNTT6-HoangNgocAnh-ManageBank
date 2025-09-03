#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_USERS 100
struct Date {
    int day;
    int month;
    int year;
};
struct User {
    char userId[10];
    char name[20];
    struct Date dateOfBirth;
    bool gender;
    char phone[20];
    char email[40];
    char status[10];
};
struct User users[MAX_USERS];
int userCount = 0;
void addUser() {
    if (userCount >= MAX_USERS) {
        printf("Danh sach da day!\n");
        return;
    }
    struct User user;
    getchar();
    printf("Nhap ma nguoi dung: ");
    fgets(user.userId, sizeof(user.userId), stdin);
    user.userId[strcspn(user.userId, "\n")] = '\0';
    printf("Nhap ten nguoi dung: ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = '\0';
    printf("Nhap ngay sinh (dd mm yyyy): ");
    scanf("%d %d %d", &user.dateOfBirth.day, &user.dateOfBirth.month, &user.dateOfBirth.year);
    int genderInput;
    printf("Nhap gioi tinh (1 = Nam, 0 = Nu): ");
    scanf("%d", &genderInput);
    user.gender = (genderInput == 1);
    getchar();
    printf("Nhap so dien thoai: ");
    fgets(user.phone, sizeof(user.phone), stdin);
    user.phone[strcspn(user.phone, "\n")] = '\0';
    printf("Nhap email: ");
    fgets(user.email, sizeof(user.email), stdin);
    user.email[strcspn(user.email, "\n")] = '\0';
    strcpy(user.status, "Open");
    users[userCount++] = user;
    printf("Da them nguoi dung thanh cong!\n");
}
void showAllUsers() {
    if (userCount == 0) {
        printf("Chua co nguoi dung nao!\n");
        return;
    }
    printf("+------------+--------------------+--------------------+------------+--------+\n");
    printf("| ID         | Name               | Email              | Phone      | Status |\n");
    printf("+------------+--------------------+--------------------+------------+--------+\n");
    for (int i = 0; i < userCount; i++) {
        printf("| %-10s | %-18s | %-18s | %-10s | %-6s |\n",
               users[i].userId,
               users[i].name,
               users[i].email,
               users[i].phone,
               users[i].status);
    }
    printf("+------------+--------------------+--------------------+------------+--------+\n");
}
int main() {
    int choice;
    while (1) {
        printf("\n==============================\n");
        printf(" ***BANK MANAGEMENT SYSTEM USING C***\n");
        printf("       CHOOSE YOUR ROLE\n");
        printf("==============================\n");
        printf("[1] Admin\n");
        printf("[2] User\n");
        printf("[0] Exit the Program\n");
        printf("------------------------------\n");
        printf("Enter The Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int selectUser;
                printf("        MENU \n");
                printf("[1] Add A New user.\n");
                printf("[2] Show All user.\n");
                printf("[3] Show detail an user\n");
                printf("[4] Lock (Unlock) an user.\n");
                printf("[5] User Guideline.\n");
                printf("[6] About Us.\n");
                printf("[0] Exit the Program.\n");
                printf("Enter your choice: ");
                scanf("%d", &selectUser);
                switch (selectUser) {
                    case 1:
                        addUser();
                        break;
                    case 2:
                        showAllUsers();
                        break;
                    case 3:
                        printf("Chuc nang chua ho tro.\n");
                        break;
                    case 4:
                        printf("Chuc nang chua ho tro.\n");
                        break;
                    case 5:
                        printf("Huong dan su dung se duoc cap nhat.\n");
                        break;
                    case 6:
                        printf("Duoc phat trien boi Anh Anh.\n");
                        break;
                    case 0:
                        printf("======= Thank You=======\n");
                        printf("======= See You Soon =====\n");
                        printf("----------------------------\n");
                        break;
                    default:
                        printf("Lua chon khong hop le.\n");
                }
                break;
            }
            case 2:
                printf("Chuc nang User chua ho tro.\n");
                break;
            case 0:
                printf("======= Thank You=======\n");
                printf("======= See You Soon =====\n");
                printf("----------------------------\n");
                exit(0);
            default:
                printf("Lua chon khong hop le.\n");
        }
    }

    return 0;
}
