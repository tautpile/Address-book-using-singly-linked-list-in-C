#include "main.h"

static int run_loop = 1;

void sig_handler(int signum) 
{
        printf("CTRL + C was pressed. Stopping program");
        run_loop = 0;
}

int main()
{
        struct sigaction sa;
        memset(&sa, 0, sizeof(struct sigaction));
        sa.sa_handler = sig_handler;
        sa.sa_flags = 0;
        sigaction(SIGINT, &sa, NULL);
        struct address *info = NULL;

        addresses_load(&info);

        while(run_loop) {
                switch(get_user_option()) {
                case 1:
                        printf("\nDisplaying all contacts (SKYPE TM 2003)\n\n");
                        print_list(info);
                        printf("\n\n");
                        break;
                case 2:
                        add_at_end(&info);
                        printf("Contact added at the end\n\n");
                        print_list(info);
                        printf("\n\n");
                        break;
                case 3: 
                        insert_at_pos(&info);
                        printf("\nNew contact inserted\n\n");
                        print_list(info);
                        break;
                case 4:
                        delete_at_pos(&info);
                        printf("\nDeleted at your specifief position\n\n");
                        print_list(info);
                        break;
                case 5:
                        printf("\nDeleting all list\n");
                        delete_list(&info);
                        break;
                case 6:
                        print_at_pos(&info);
                        printf("Address displayed\n\n");
                        break;
                case 7:
                        printf("\nWill find address by name, surname, email, number\n");
                        finding_specified(&info);
                        break;
                case 8:
                        printf("\nSKYPE SYSTEM SHUTTING DOWN\n");
                        run_loop = 0;
                        break;
   
                default:
                        printf("\nError CODE : 404 contact support for more help\n");
                        break;  
                }
        }
        delete_list(&info);
        return 0;
}