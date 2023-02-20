#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function_list.h"
#include "helping_functions.h"

void finding_specified(struct address **info)
{
        char *key;
        key = get_user_keyword();
        find_by_parameter(key, info);
        free(key); 
}

void delete_at_pos(struct address **info)
{
        int pos;
        pos = get_user_position();
        if(*info == NULL) {
                printf("\nList is empty\n");
                return;
        } else if(pos == 1) {
                deleting_at_one(info);
                return;
        } 
        delete_at_position(pos, info);
}

void delete_list(struct address **info)
{
        struct address *current = *info;
        if(*info == NULL) {
                printf("\nList is empty\n");
                return;
        } 
        deleting_list(info);
        if(current == NULL)
                printf("\nLinked List deleted succesfully\n\n");
        
        *info = NULL;
}

void insert_at_pos(struct address **info)
{
        struct address *newcontact = NULL;
        char name[30], surname[30], email[30], phonenumber[30];
        int pos;
  
        pos = get_user_position();
        if(pos <= 0) {
                printf("Invalid position\n\n");
                return;
        }
        get_user_input(name, surname, email, phonenumber);
        newcontact = create_node(name, surname, email, phonenumber);
        inserting_at_pos(pos, newcontact, info);
}

void add_at_end(struct address **info) 
{
        struct address *newcontact = NULL;
        char name[30], surname[30], email[30], phonenumber[30];
        get_user_input(name, surname, email, phonenumber);
        newcontact = create_node(name, surname, email, phonenumber);
        if(newcontact != NULL) {
                add_to_list(info, newcontact);
        }  
}

void addresses_load(struct address **info) 
{
        char address[15] = "/addresses.csv";
        char *home = getenv("HOME");
        strcat(home, address);

        FILE *fptr = NULL;
        fptr = fopen(home, "a+");
        if(fptr == NULL){
                printf("\nERROR opening file, code : 404\n");
                printf("Contact SKYPE support for more help\n\n");
                return;
        }
        char line[100];
        while(fgets(line, sizeof(line), fptr)) {
                
                int len = strlen(line);
                if(len > 0 && line[len - 1] == '\n'){
                line[len - 1] = '\0';
                }

                struct address *newcontact = NULL;
                if(strcmp(line,"\n") == 0) {
                        printf("\nNew Line empty\n");
                        exit(1);
                }
                newcontact = create_address_node(line);
                if(newcontact != NULL) {
                        add_to_list(info, newcontact);
                }
        }
        fclose(fptr);
}

void print_at_pos(struct address **info)
{
        struct address *temp = *info;
        int pos;
        int i = 1;

        if(temp == NULL) {
                printf("No members\n");
        }

        pos = get_user_position();
        while (i < pos) {
                temp = temp->link;
                i++;
        }

        print_node(temp);
}

void get_user_input(char *name, char *surname, char *email, char *phonenumber)
{
        printf("\nEnter name : ");
        fscanf(stdin, "%29s", name);
        printf("\nEnter surname : ");
        fscanf(stdin, "%29s", surname);
        printf("\nEnter email : ");
        fscanf(stdin, "%29s", email);
        printf("\nEnter phonenumber : ");
        fscanf(stdin, "%29s", phonenumber);
}

void print_menu() {
        printf("\n-----------SKYPE technologies 2003 TM-----------\n");
        printf("\n********** Select the operation: **********\n\n");
        printf("1. Display all records in the address book\n");
        printf("2. Add new address to the book (to the end)\n");
        printf("3. Add new address indicating the position where to put it)\n");
        printf("4. Delete address indicating its position in the book\n");
        printf("5. Delete whole address book\n");
        printf("6. Find address by position\n");
        printf("7. Find address by name, surname, email or phone number\n");
        printf("8. Exit program\n\n");
        printf("This is John from SKYPE how can I help you?\n");
        printf("Select your prefered operation.\n");
}

int get_user_option() {
        int c;
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &c);
        while (getchar() != '\n' && c != EOF);
        printf("\n%d", c);
        return c;
}

int get_user_position()
{
        int position;
        printf("\nEnter position: ");
        scanf("%d", &position);
        while(getchar() != '\n' && position != EOF);
        return position;
}

char *get_user_keyword()
{
        char *keyword = (char *) malloc(sizeof(char) * 30);
        printf("Enter search keyword: ");
        scanf("%29s", keyword);
        return keyword;
}