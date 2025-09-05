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
    char name[40];
    struct Date dateOfBirth;
    bool gender;
    char phone[20];
    char email[40];
    char status[10];
};
struct User users[MAX_USERS];
int userCount = 0;
bool isEmpty(char str[]) {
    return strlen(str) == 0;
}
bool isDuplicate(struct User newUser) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].userId, newUser.userId) == 0 ||
            strcmp(users[i].name, newUser.name) == 0 ||
            strcmp(users[i].phone, newUser.phone) == 0 ||
            strcmp(users[i].email, newUser.email) == 0) {
            return true;
        }
    }
    return false;
}
void addUser() {
    if (userCount >= MAX_USERS) {
        printf("Danh sach da day!\n");
        return;
    }
    struct User user;
    while (true) {
        getchar();
        printf("Nhap ma nguoi dung (toi da 9 ky tu): ");
        fgets(user.userId, sizeof(user.userId), stdin);
        user.userId[strcspn(user.userId, "\n")] = '\0';
        if (strlen(user.userId) == 0 || strlen(user.userId) > 9) {
            printf("ID khong hop le. Vui long nhap lai.\n");
            continue;
        }
        getchar();
        printf("Nhap ten nguoi dung (toi da 19 ky tu): ");
        fgets(user.name, sizeof(user.name), stdin);
        user.name[strcspn(user.name, "\n")] = '\0';
        if (strlen(user.name) == 0 || strlen(user.name) > 19) {
            printf("Ten khong hop le. Vui long nhap lai.\n");
            continue;
        }
        printf("Nhap ngay sinh (dd mm yyyy): ");
        if (scanf("%d %d %d", &user.dateOfBirth.day, &user.dateOfBirth.month, &user.dateOfBirth.year) != 3) {
            printf("Ngay sinh khong hop le. Vui long nhap lai.\n");
            continue;
        }
        int genderInput;
        printf("Nhap gioi tinh (1 = Nam, 0 = Nu): ");
        if (scanf("%d", &genderInput) != 1 || (genderInput != 0 && genderInput != 1)) {
            printf("Gioi tinh khong hop le. Vui long nhap lai.\n");
            continue;
        }
        user.gender = (genderInput == 1);
        getchar();
        printf("Nhap so dien thoai (toi da 19 ky tu): ");
        fgets(user.phone, sizeof(user.phone), stdin);
        user.phone[strcspn(user.phone, "\n")] = '\0';
        if (strlen(user.phone) == 0 || strlen(user.phone) > 19) {
            printf("So dien thoai khong hop le. Vui long nhap lai.\n");
            continue;
        }
        printf("Nhap email (toi da 39 ky tu): ");
        fgets(user.email, sizeof(user.email), stdin);
        user.email[strcspn(user.email, "\n")] = '\0';
        if (strlen(user.email) == 0 || strlen(user.email) > 39) {
            printf("Email khong hop le. Vui long nhap lai.\n");
            continue;
        }
        bool trung = false;
        for (int i = 0; i < userCount; i++) {
            if (strcmp(users[i].userId, user.userId) == 0 ||
                strcmp(users[i].name, user.name) == 0 ||
                strcmp(users[i].phone, user.phone) == 0 ||
                strcmp(users[i].email, user.email) == 0) {
                trung = true;
                break;
            }
        }
        if (trung) {
            printf("Thong tin da ton tai. Vui long nhap lai.\n");
            continue;
        }
        strcpy(user.status, "Open");
        users[userCount++] = user;
        printf("Them nguoi dung thanh cong!\n");
        break;
    }
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
        printf("| %-10s | %-18s | %-18s | %-10s | %-6s |\n",users[i].userId,users[i].name,users[i].email,users[i].phone,users[i].status);
    }
    printf("+------------+--------------------+--------------------+------------+--------+\n");
}
void searchUser() {
    if (userCount == 0) {
        printf("Chua co nguoi dung nao!\n");
        return;
    }
    char searchName[20];
    getchar();
    printf("Nhap ten nguoi dung can tim: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    bool timThay = false;
    printf("+------------+--------------------+--------------------+------------+--------+\n");
    printf("| ID         | Name               | Email              | Phone      | Status |\n");
    printf("+------------+--------------------+--------------------+------------+--------+\n");
    for (int i = 0; i < userCount; i++) {
        if (strstr(users[i].name, searchName) != NULL) {
            printf("| %-10s | %-18s | %-18s | %-10s | %-6s |\n",
                   users[i].userId,
                   users[i].name,
                   users[i].email,
                   users[i].phone,
                   users[i].status);
            timThay = true;
        }
    }
    if (!timThay) {
        printf("| Khong tim thay nguoi dung co ten \"%s\" |\n", searchName);
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
                        searchUser();
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
