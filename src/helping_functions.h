
void get_user_input(char *name, char *surname, char *email, char *phonenumber);
void finding_specified(struct address **info);
void addresses_load(struct address **info);
void insert_at_pos(struct address **info);
void delete_at_pos(struct address **info);
void print_at_pos(struct address **info);
void delete_list(struct address **info);
void add_at_end(struct address **info);

void print_menu();

int get_user_position();
int get_user_option();

char *get_user_keyword();

