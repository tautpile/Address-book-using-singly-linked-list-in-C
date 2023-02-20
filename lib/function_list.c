#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "function_list.h"
//#include "helping_functions.h"

static void check_condition(char *input, struct address *temp)
{
        if( (strcmp(input, temp->name)) == 0 || strcmp(input, temp->surname) == 0 || strcmp(input, temp->email) == 0 || strcmp(input, temp->phonenumber) == 0) 
        {
                print_node(temp);
        }
}

struct address* create_address_node(char *address_line)
{
        struct address *newcontact = NULL;
        char *name;
        char *surname;
        char *email;
        char *phonenumber;

        name =  strtok(address_line, ",");      
        surname = strtok(NULL, ",");
        email = strtok(NULL, ",");
        phonenumber = strtok(NULL, ",");
        newcontact = create_node(name, surname, email, phonenumber);
        return newcontact;
}

struct address* create_node(char *name, char *surname, char *email, char *phonenumber)
{
        struct address *newcontact = NULL;
        newcontact = (struct address*)malloc(sizeof(struct address));
        if(newcontact == NULL) {
                return NULL;
        }

        strcpy(newcontact -> name, name);
        strcpy(newcontact -> surname, surname);
        strcpy(newcontact -> email, email);
        strcpy(newcontact -> phonenumber, phonenumber);

        newcontact -> link = NULL;
        return newcontact;
}

void add_to_list(struct address **info, struct address *newcontact)
{
        struct address *temp = *info;
        if(temp == NULL) {
                *info = newcontact;
                return;
        }

        while (temp -> link != NULL) {
                temp = temp -> link;
        }
        temp -> link = newcontact;
}

void print_list(struct address *info)
{
        struct address *temp = info;
        int i = 1;
        if(temp == NULL) {
                printf("List is empty\n");
                return;
        }
        while(temp != NULL) {
                printf("Entry %d -> ", i);
                print_node(temp);
                temp = temp->link;
                i++;
        }
        printf("\n\n");
}

void inserting_at_pos(int pos, struct address *newcontact, struct address **info)
{
        struct address *temp = *info;
        while(pos != 2) {
                temp = temp -> link;
                pos--;
        }
        newcontact -> link = temp -> link;
        temp -> link = newcontact;
}

void delete_at_position(int pos, struct address **info)
{
        struct address *current = *info;
        struct address *previous = *info;

        while (pos != 1) {
                previous = current;
                current = current -> link;
                pos--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;  
}


void deleting_at_one(struct address **info)
{
        struct address *current = *info;
        *info = current -> link;
        free(current);
        current = NULL;
}

void deleting_list(struct address **info) 
{
        struct address *current = *info;
        struct address *next = NULL;
        while(current != NULL) {
                next = current -> link;
                free(current);
                current = next;
        }
}

void find_by_parameter(char *key, struct address **info) 
{
        struct address *temp = *info;
        char *input = key;

        while((temp->link) != NULL) {
                check_condition(input, temp);
                temp = temp -> link;  
        }      
        if((temp->link) == NULL) {
                check_condition(input, temp);
        } else {
                printf("\nNo matches found");
        }
}

void print_node(struct address *newcontact)
{
        printf("Name - %s - ", newcontact->name);
        printf("Surname - %s - ", newcontact->surname);
        printf("Email - %s - ", newcontact->email);
        printf("Number - %s\n", newcontact->phonenumber);
}
