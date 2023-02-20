
struct address {
        char name[30];
        char surname[30];
        char email[30];
        char phonenumber[30];
        struct address *link;
};

struct address* create_node(char *name, char *surname, char *email, char *phonenumber);
struct address* create_address_node(char *address_line);

void delete_at_position(int pos, struct address **info);
void inserting_at_pos(int pos, struct address *newcontact, struct address **info);
void deleting_at_one(struct address **info);
void add_to_list(struct address **info, struct address *newcontact);
void deleting_list(struct address **info);
void print_node(struct address *newcontact);
void delete_at_pos(struct address **info);
void find_by_parameter(char *input, struct address **info);
void print_list(struct address *info);
