#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#define total 100000.0
#define RESET      "\x1b[0m"
#define RED        "\x1b[31m"
#define GREEN      "\x1b[32m"
#define YELLOW     "\x1b[33m"
#define BLUE       "\x1b[34m"
#define MAGENTA    "\x1b[35m" //colour code for ascii
#define CYAN       "\x1b[36m"
#define WHITE      "\x1b[37m"
#define BOLDWHITE  "\x1b[1;37m"
#define BOLDGREEN  "\x1b[1;32m"
#define BOLDRED    "\x1b[1;31m"#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#define total 100000.0
#define RESET      "\x1b[0m"
#define RED        "\x1b[31m"
#define GREEN      "\x1b[32m"
#define YELLOW     "\x1b[33m"
#define BLUE       "\x1b[34m"
#define MAGENTA    "\x1b[35m" //colour code for ascii
#define CYAN       "\x1b[36m"
#define WHITE      "\x1b[37m"
#define BOLDWHITE  "\x1b[1;37m"
#define BOLDGREEN  "\x1b[1;32m"
#define BOLDRED    "\x1b[1;31m"

typedef  struct core{
    char uni_name[50];
    char country_name[50];
    char major[50];
    double cgpa;
    int fee;
}core;

typedef struct list_tree_node{
    core data;
    struct list_tree_node * left_prev;
    struct list_tree_node * right_next;
}list_tree_node;

list_tree_node * root = NULL; // root of tree for the explore page
list_tree_node * head = NULL; // head of linked list for admin page

void mainpage(){//fixed spacing
    printf(BOLDWHITE"----------------------------------\n"RESET);
    printf(BOLDWHITE"|   "BOLDGREEN"Smart University Advisor"BOLDWHITE"     |\n"RESET);
    printf(BOLDWHITE"----------------------------------\n"RESET);
    printf(BOLDWHITE"|                                |\n"RESET);
    printf(BOLDWHITE"|  1. ADMIN      2. EXPLORE      |\n"RESET);
    printf(BOLDWHITE"|  3. ADVISOR    "RED"0. EXIT"RESET"         |\n"RESET); 
    printf(BOLDWHITE"|                                |\n"RESET);
    printf(BOLDWHITE"----------------------------------\n"RESET);
}

void last_page(){
    printf(BOLDWHITE"\n--------------------------------\n"RESET);
    printf("|          "BOLDGREEN"THANK YOU"RESET"           |\n");    
    printf("|              "GREEN"XD"RESET"              |\n");
    printf(BOLDWHITE"--------------------------------\n"RESET);
}

void exit_page(){
    printf("\n--------------------------------\n");
    printf("| 1. RETURN TO MAIN PAGE       |\n"); 
    printf("| "RED"0. EXIT""                      "RESET"|\n");
    printf("--------------------------------\n");
}

void leftover_eater(){ // eating the leftovers after the scanfs
    int ch; 
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void dis_admin_ui_main() {//spacing done
    printf(BOLDWHITE"----------------------------------\n"RESET);
    printf(BOLDWHITE"|          "BOLDGREEN"ADMIN MODE"BOLDWHITE"             |\n"RESET);
    printf(BOLDWHITE"----------------------------------\n"RESET);
    printf(BOLDWHITE"|                                |\n"RESET);
    printf(BOLDWHITE"| "BOLDWHITE"1. ADD UNIVERSITY"RESET"              |\n"RESET);
    printf(BOLDWHITE"| "BOLDWHITE"2. UPDATE UNIVERSITY"RESET"           |\n"RESET);
    printf(BOLDWHITE"| "BOLDWHITE"3. DELETE UNIVERSITY"RESET"           |\n"RESET);
    printf(BOLDWHITE"|                                |\n"RESET);
    printf(BOLDWHITE"----------------------------------\n"RESET);
}

void explore_ui_main() {//spacing done
    printf(BOLDWHITE"----------------------------------\n"RESET);
    printf(BOLDWHITE"|        "BOLDGREEN"EXPLORE MODE"BOLDWHITE"            |\n"RESET);
    printf(BOLDWHITE"----------------------------------\n"RESET);
    printf(BOLDWHITE"|                                |\n"RESET);
    printf(BOLDWHITE"| "BOLDWHITE"1. DASHBOARD"RESET"                   |\n"RESET);
    printf(BOLDWHITE"| "BOLDWHITE"2. FILTER by"RESET" "CYAN"COUNTRY"RESET"           |\n"RESET);
    printf(BOLDWHITE"| "BOLDWHITE"3. FILTER by"RESET" "CYAN"BUDGET"RESET"            |\n"RESET);
    printf(BOLDWHITE"| "BOLDWHITE"4. SEARCH UNIVERSITY"RESET"           |\n"RESET);
    printf(BOLDWHITE"|                                |\n"RESET);
    printf(BOLDWHITE"----------------------------------\n"RESET);
}

void advisor_ui_main(){//spacing done
    printf(BOLDWHITE"------------------------------------------\n"RESET);
    printf(BOLDWHITE"|              "BOLDGREEN"ADVISOR MODE"RESET BOLDWHITE"              |\n"RESET);
    printf(BOLDWHITE"------------------------------------------\n"RESET);
}

void dis_cancel_del() {//spacing done
    printf(BOLDWHITE"\n--------------------------------\n"RESET);
    printf("|        "RED"TASK CANCELLED"RESET"        |\n");  
    printf(BOLDWHITE"--------------------------------\n"RESET);
}

void no_match(){//spacing done
    printf(RED"\n--------------------------------\n"RESET);
    printf(RED"|"RESET"          "BOLDRED"NO  MATCH"RESET"           "RED"|\n"RESET);   
    printf(RED"|"RESET"            "BOLDRED"FOUND"RESET"             "RED"|\n"RESET);
    printf(RED"|"RESET"             "BOLDRED":(               "RED"|\n"RESET);
    printf(RED"--------------------------------\n"RESET);
}

void nomatch(){//spacing done
    printf(RED"\n--------------------------------\n"RESET);
    printf(RED"|"RESET"          "BOLDRED"NO  MATCH"RESET"           "RED"|\n"RESET);   
    printf(RED"|"RESET"            "BOLDRED"FOUND"RESET"             "RED"|\n"RESET);
    printf(RED"|"RESET"             "BOLDRED":(               "RED"|\n"RESET);
    printf(RED"--------------------------------\n"RESET);
}

void dis_update_done() { //spacing done
    printf(BOLDWHITE"\n------------------------------------\n"RESET);
    printf("|        "BOLDGREEN"UPDATE SUCCESSFUL"RESET"        |\n");
    printf("------------------------------------\n");
}

void dis_delete_done() {//spacing done
    printf(BOLDWHITE"\n------------------------------------\n"RESET);
    printf("|        "BOLDGREEN"DELETE SUCCESSFUL"RESET"        |\n");
    printf("------------------------------------\n");
}

void dis_for_new_add(){
    printf(BOLDWHITE"----------------------------------------------\n"RESET);
    printf(BOLDWHITE"|      "BOLDGREEN"Enter University New Details"RESET BOLDWHITE"      |\n"RESET);
    printf(BOLDWHITE"----------------------------------------------\n"RESET);
}

void dis_delete_confirm(){
    
    printf("\n"BLUE" # write "RESET"\""BOLDRED"confirm"RESET"\""BLUE" to delete:"RESET" ");
}

core dis_add_new(){ // takes the data from the user for new add
    core temp;
    dis_for_new_add();

    printf(BOLDWHITE"=>"RESET"" CYAN"Enter University Name: "RESET);
    fgets(temp.uni_name,50,stdin);
    temp.uni_name[strcspn(temp.uni_name,"\n")] = '\0';

    printf(BOLDWHITE"=>"RESET""CYAN"Enter Country Name: "RESET);
    fgets(temp.country_name,50,stdin);
    temp.country_name[strcspn(temp.country_name,"\n")] = '\0';

    printf(BOLDWHITE"=>"RESET""CYAN"Enter Major: "RESET);
    fgets(temp.major,50,stdin);
    temp.major[strcspn(temp.major,"\n")] = '\0';

    printf(BOLDWHITE"=>"RESET""CYAN"Enter CGPA: "RESET);
    scanf("%lf", &temp.cgpa);
    leftover_eater();

    printf(BOLDWHITE"=>"RESET""CYAN"Enter Fee: "RESET);
    scanf("%d", &temp.fee);
    leftover_eater();

    return temp;
}

void new_uni_added(core temp) { // new node adding success display
    printf(BOLDWHITE"\n--------------------------------\n"RESET);
    printf("|     "BOLDGREEN"NEW UNIVERSITY ADDED"RESET"    |\n");  
    printf(BOLDWHITE"--------------------------------\n"RESET);
    printf("| "CYAN"UNIVERSITY NAME: %-14s"RESET" |\n", temp.uni_name);
    printf("| "CYAN"COUNTRY        : %-14s"RESET" |\n", temp.country_name);
    printf("| "CYAN"MAJOR          : %-14s"RESET" |\n", temp.major);
    printf("| "CYAN"CGPA           : %-14.2lf"RESET" |\n",temp.cgpa);
    printf("| "CYAN"FEE            : %-14d"RESET" |\n", temp.fee);
    printf(BOLDWHITE"--------------------------------\n"RESET);
}

void target_uni_found(list_tree_node * temp) { // new node adding success display
    printf(BOLDWHITE"\n--------------------------------\n"RESET);
    printf("|     "BOLDGREEN"UNIVERSITY FOUND"RESET"    |\n");  
    printf(BOLDWHITE"--------------------------------\n"RESET);
    printf("| "CYAN"UNIVERSITY NAME: %-14s"RESET" |\n", temp->data.uni_name);
    printf("| "CYAN"COUNTRY        : %-14s"RESET" |\n", temp->data.country_name);
    printf("| "CYAN"MAJOR          : %-14s"RESET" |\n", temp->data.major);
    printf("| "CYAN"CGPA           : %-14.2lf"RESET" |\n", temp->data.cgpa);
    printf("| "CYAN"FEE            : %-14d"RESET" |\n", temp->data.fee);
    printf(BOLDWHITE"--------------------------------\n"RESET);
}

void dis_return_page(){//spacing done
    printf("\n--------------------------------\n");
    printf("| 1. RETURN TO MAIN PAGE       |\n"); 
    printf("| "RED"0. EXIT""                      "RESET"|\n");
    printf("--------------------------------\n");
}

void dis_disboard_heading(){//spacing done
    printf("-----------------------------------------------------------------------\n");
    printf("|                       "BOLDGREEN"DASHBOARD VIEW"RESET"                         |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("| "BOLDWHITE"UNIVERSITY NAME"RESET"      | "BOLDWHITE"COUNTRY"RESET"    | "BOLDWHITE"MAJOR"RESET"       | "BOLDWHITE"CGPA"RESET" | "BOLDWHITE"FEE"RESET"    |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------\n");
}

void dis_fil_country_heading(){//spacing done
    printf("-----------------------------------------------------------------------\n");
    printf("|                       "BOLDGREEN"FILTER COUNTRY"RESET"                         |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("| "BOLDWHITE"UNIVERSITY NAME"RESET"      | "GREEN"COUNTRY"RESET"    | "BOLDWHITE"MAJOR"RESET"       | "BOLDWHITE"CGPA"RESET" | "BOLDWHITE"FEE"RESET"    |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------\n");
}

void dis_fil_budget_heading(){//spacing done
    printf("-----------------------------------------------------------------------\n");
    printf("|                        "BOLDGREEN"FILTER BUDGET"RESET"                         |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("| "BOLDWHITE"UNIVERSITY NAME"RESET"      | "BOLDWHITE"COUNTRY"RESET"    | "BOLDWHITE"MAJOR"RESET"       | "BOLDWHITE"CGPA"RESET" | "GREEN"FEE"RESET"    |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------\n");
}

void dis_dashboard_data(list_tree_node * temp){//spacing done
    printf("| %-20s | %-10s | %-12s | %.2lf | %-7d |\n",
           temp->data.uni_name,
           temp->data.country_name,
           temp->data.major,
           temp->data.cgpa,
           temp->data.fee);
    printf("-----------------------------------------------------------------------\n");
}

void dis_student_info(){ // advisor mode student header
    printf(BOLDWHITE"------------------------------------------\n"RESET);
    printf(BOLDWHITE"|           "BOLDWHITE"Enter Student Details"RESET BOLDWHITE"           |\n"RESET);
    printf(BOLDWHITE"------------------------------------------\n"RESET);
}

core student_info(){ // student information for the advisor mode
    core temp;
    dis_student_info();

    printf(BOLDWHITE"=>"RESET"" CYAN"Enter Your Name: "RESET);
    fgets(temp.uni_name,50,stdin);
    temp.uni_name[strcspn(temp.uni_name,"\n")] = '\0';

    printf(BOLDWHITE"=>"RESET""CYAN"Enter Prefered Country Name: "RESET);
    fgets(temp.country_name,50,stdin);
    temp.country_name[strcspn(temp.country_name,"\n")] = '\0';

    printf(BOLDWHITE"=>"RESET""CYAN"Enter Preferable Major: "RESET);
    fgets(temp.major,50,stdin);
    temp.major[strcspn(temp.major,"\n")] = '\0';

    printf(BOLDWHITE"=>"RESET""CYAN"Enter Your CGPA: "RESET);
    scanf("%lf", &temp.cgpa);
    leftover_eater();

    printf(BOLDWHITE"=>"RESET""CYAN"Enter Your budget: "RESET);
    scanf("%d", &temp.fee);
    leftover_eater();

    return temp;
}

void dis_recom_heading() { // spacing fixed
    printf("-----------------------------------------------------------------------\n");
    printf("|                           "BOLDGREEN"RECOMMENDATIONS"RESET"                            |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("| "BOLDWHITE"UNIVERSITY NAME"RESET"       | "BOLDWHITE"COUNTRY"RESET"      | "BOLDWHITE"MAJOR"RESET"         | "BOLDWHITE"CGPA"RESET" | "BOLDWHITE"FEE"RESET"   |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------\n");
}

void dis_after_recom(){//after showing top recommendations
    printf(BOLDWHITE"----------------------------------\n"RESET);
    printf(BOLDWHITE"|                                |\n"RESET);
    printf(BOLDWHITE"| "BOLDWHITE"1. COMPARE UNIVERSITY"RESET"         |\n"RESET);
    printf(BOLDWHITE"| "BOLDWHITE"2. SEARCH UNIVERSITY"RESET"          |\n"RESET);
    printf(BOLDWHITE"|                                |\n"RESET);
    printf(BOLDWHITE"----------------------------------\n"RESET);
}

void dis_compare_uni(list_tree_node * uni1, list_tree_node * uni2) { // for displaying the university comparison
    printf("-----------------------------------------------------------------------\n");
    printf("|                           "BOLDGREEN"COMPARISON"RESET"                                |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("|       "BOLDWHITE"UNIVERSITY no.1"RESET"       |       "BOLDWHITE"UNIVERSITY no.2"RESET"       |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("| %-26s | %-26s |\n",uni1->data.uni_name,uni2->data.uni_name);
    printf("| %-26s | %-26s |\n",uni1->data.country_name,uni2->data.country_name);
    printf("| %-26s | %-26s |\n",uni1->data.major,uni2->data.major);
    
    if(uni1->data.cgpa > uni2->data.cgpa){
        printf("| "GREEN"%-26.2lf"RESET" | %-26.2lf |\n",uni1->data.cgpa,uni2->data.cgpa);
    }
    else if(uni1->data.cgpa < uni2->data.cgpa){
        printf("| %-26.2lf | "GREEN"%-26.2lf"RESET" |\n",uni1->data.cgpa,uni2->data.cgpa);
    }
    else{
        printf("| %-26.2lf | %-26.2lf |\n",uni1->data.cgpa,uni2->data.cgpa);
    }
    
    if(uni1->data.fee < uni2->data.fee){  // Lower fee is better!
        printf("| "GREEN"%-26d"RESET" | %-26d |\n",uni1->data.fee,uni2->data.fee);
    }
    else if(uni1->data.fee > uni2->data.fee){
        printf("| %-26d | "GREEN"%-26d"RESET" |\n",uni1->data.fee,uni2->data.fee);
    }
    else{
        printf("| %-26d | %-26d |\n",uni1->data.fee,uni2->data.fee);
    }
    printf("-----------------------------------------------------------------------\n");
}


// explore mode logic starts from here 

void free_tree() { //for reseting the tree for next use
    if(root == NULL) return;
    free_tree(root->left_prev);
    free_tree(root->right_next);
    free(root);
}

list_tree_node * add_to_tree_helper(list_tree_node * parent, core temp){ // for making and adding nodes into the tree(recursion used)
    if(parent == NULL){
        list_tree_node * new = malloc(sizeof(list_tree_node));
        new->data = temp;
        new->left_prev = NULL;
        new->right_next = NULL;
        return new;
    }
    int cmp = strcasecmp(parent->data.uni_name,temp.uni_name);//making the value if smaller or bigger

    if(cmp < 0){//name is smaller than the root name, go left
        parent->left_prev = add_to_tree_helper(parent->left_prev,temp);
    }
    else if(cmp>0){//for right side of the tree bigger values
        parent->right_next = add_to_tree_helper(parent->right_next,temp);
    }

    return parent;
}

void add_to_tree(core temp){// send the data into tree making helper
    root = add_to_tree_helper(root,temp); 
}

void file_to_tree(){ // for reading the file data fro tree

    FILE * file = fopen("uni.txt", "r");
    free_tree(); // resetting the tree for new data load

    char line[300];
    while(fgets(line,300,file)){
        core temp;
        int c = sscanf(line, "%49[^,],%49[^,],%49[^,],%lf,%d", // for opening the file for tree
            temp.uni_name, 
            temp.country_name, 
            temp.major, 
            &temp.cgpa, 
            &temp.fee);
        if(c == 5) add_to_tree(temp);
    }
    fclose(file);    
}

void dashboard_explore_helper(list_tree_node * parent){ // for printing the dashboard data
    if(parent == NULL) return ;

    dashboard_explore_helper(parent->left_prev); //checking the left nodes

    dis_dashboard_data(parent); //printing the data one by one

    dashboard_explore_helper(parent->right_next);
}

void dashboard_explore(){ // dashboard printing starter

    dis_disboard_heading();
    dashboard_explore_helper(root);
}

void filter_country_helper(list_tree_node * parent , char * country){ //country filter printer helper
    if(parent == NULL) return ;

    filter_country_helper(parent->left_prev,country);

    int cmp = strcasecmp(parent->data.country_name,country); //checking if you can print it or not;
    if(cmp == 0) dis_dashboard_data(parent);

    filter_country_helper(parent->right_next,country);
}

void filter_country(){// country filter printer

    char country[50];
    printf(CYAN"Enter Country Name: "RESET);

    fgets(country,50,stdin);
    country[strcspn(country,"\n")] = '\0';

    dis_fil_country_heading();
    filter_country_helper(root, country);

}

void filter_budget_helper(list_tree_node * parent , int budget){//budget filter printer helper
    if(parent == NULL) return ;

    filter_budget_helper(parent->left_prev,budget);

    if(parent->data.fee<= budget) dis_dashboard_data(parent); //checking the budget condition

    filter_budget_helper(parent->right_next,budget);
}

void filter_budget(){ // budget filter printer

    int budget;
    printf(CYAN"Enter Budget Amount: "RESET);
    scanf("%d",&budget);
    leftover_eater();
    
    dis_fil_country_heading();
    filter_budget_helper(root, budget);

}

void search_university(){ // searching university printer, works as a binary search for the university  information tree

    char uni_name[50];
    printf(CYAN"Enter University Name: "RESET);

    fgets(uni_name,50,stdin);
    uni_name[strcspn(uni_name,"\n")] = '\0';

    list_tree_node * temp = root;
    while(temp != NULL && strcasecmp(temp->data.uni_name, uni_name) != 0){
        int cmp = strcasecmp(temp->data.uni_name, uni_name);
        if(cmp < 0){
            temp = temp->left_prev;
        }
        else if(cmp > 0){
            temp = temp->right_next;
        }
    }
    if(!(temp)){ // main work is to search the node and return its address
        no_match();
    }
    else{
        target_uni_found(temp);
    }
}

//explore mode ends here and admin mode starts from here 

void reset_the_list(){//freeing the head after every use to make sure no duplicates
    list_tree_node * temp ;

    while(head != NULL){
        temp = head;
        head = head->right_next;
        free(temp);
    }
}

void admin_list_add(core data){ //connecting file data to the linked list or new node from user
    list_tree_node * new = malloc(sizeof(list_tree_node));
    
    new->data = data;
    new->left_prev = NULL;
    new->right_next = NULL;

    if(head == NULL){
        head = new;
        
    }
    else{
        list_tree_node * temp = head;
        while(temp->right_next != NULL){
            temp = temp->right_next;
        }
        new->left_prev = temp;
        temp->right_next = new;
    }
}

void load_from_file(){ //reading data from file and sending to linked list

    FILE * file = fopen("uni.txt", "r");
    reset_the_list(); // resetting the linked list for new data load
    
    char line[300];
    while(fgets(line,300,file)){
        core temp;
        int c = sscanf(line, "%49[^,],%49[^,],%49[^,],%lf,%d", 
            temp.uni_name, 
            temp.country_name, 
            temp.major, 
            &temp.cgpa, 
            &temp.fee);
        if(c == 5) admin_list_add(temp);
    }
    fclose(file);    
}

void write_in_file(){ // for rewritiing everything into the file
    FILE * file = fopen("uni.txt","w");

    list_tree_node * temp = head;

    while(temp != NULL){
        fprintf(file, "%s,%s,%s,%.2lf,%d\n",
                temp->data.uni_name,
                temp->data.country_name,
                temp->data.major,
                temp->data.cgpa,
                temp->data.fee);
        
        temp = temp->right_next; //write till list is empty
    }
    fclose(file);
}

void add_new_node(){ //take the data then send it to the adder and print

    core temp;
    temp = dis_add_new();
    
    admin_list_add(temp);
    new_uni_added(temp);

    write_in_file(); // updating the file
}

list_tree_node * search_node(char * str){ // searching in the list for the node 
    list_tree_node *  temp = head;
    while(temp != NULL && strcasecmp(temp->data.uni_name, str) != 0){
        temp = temp->right_next;
    }
    if(!(temp)){ // main work is to search the node and return its address
        
        return NULL;
    }
    else{
        return temp;
    }
}

void update_list_info(){ //updating the data in the linked list 
    
    printf(BOLDWHITE"----------------------------------------------\n"RESET);
    printf(CYAN"Enter University Name to Update: "RESET);

    char str[50];
    fgets(str,50,stdin);
    str[strcspn(str,"\n")] = '\0';

    list_tree_node * target;
    target = search_node(str); // finding the target nde

    core new = dis_add_new();
    
    if(target != NULL){
        target->data = new; //updating the data
        dis_update_done();
        write_in_file(); // updating the file
    }
    else{
        nomatch();
    }
}

void delete_node(){ //deleting the node from the linked list
    char str[50];
    list_tree_node * target;

    printf(BOLDWHITE"----------------------------------------------\n"RESET);
    printf(CYAN"Enter University Name to Delete: "RESET);

    fgets(str,50,stdin);
    str[strcspn(str,"\n")] = '\0';

    target = search_node(str); // finding the target node
    list_tree_node * k=NULL;
    if(target == NULL){
        nomatch();
    }
    else{
        target_uni_found(target);
        dis_delete_confirm(); 

        char confirm[11];
        scanf("%s",confirm);

        if(strcasecmp(confirm,"confirm")!=0){  //making sure if the user really wants to delete or not
            dis_cancel_del();
            return;
        }

        if(target == head){ //if the node is in head
            head= head->right_next;
            if(head) head->left_prev = NULL;
            free(target);
            write_in_file(); // updating the file
            dis_delete_done();
        }

        else if(target->right_next == NULL){ //if it is in the last
            k = target->left_prev;
            k->right_next = NULL;
            free(target);
            write_in_file(); // updating the file
            dis_delete_done();
        }

        else{ // in middle
            k = target->left_prev;
            k->right_next=target->right_next;
            target->right_next->left_prev = k;
            free(target);
            write_in_file(); // updating the file
            dis_delete_done();
        }
    }
}

// admin mode ends here and advisor mode starts from here

list_tree_node * advisor_tree_helper(list_tree_node * parent, core data){ // making the advisor tree in fees root
    if(parent == NULL){
        list_tree_node * new = malloc(sizeof(list_tree_node));
        new->data = data;
        new->left_prev = NULL;
        new->right_next = NULL;
        return new;
    }
    if(parent->data.fee>data.fee){
        parent->left_prev = advisor_tree_helper(parent->left_prev,data);
    }
    else{
        parent->right_next = advisor_tree_helper(parent->right_next,data);
    }
    return parent;
}

void add_to_advisor_tree(core temp){ //advisor tree adder
    root = advisor_tree_helper(root,temp);
}

void file_to_advisor(){//checks who can go to advisor tree and also works as a filter here

    FILE * file = fopen("uni.txt", "r");
    core candidate = student_info();
    free_tree(); // resetting the tree for new data load

    char line[300];
    while(fgets(line,300,file)){
        core temp;
        int c = sscanf(line, "%49[^,],%49[^,],%49[^,],%lf,%d", // for opening the file for tree
            temp.uni_name, 
            temp.country_name, 
            temp.major, 
            &temp.cgpa, 
            &temp.fee);
        if((c==5) && (temp.cgpa <= candidate.cgpa) && (temp.fee <= candidate.fee) && (strcasecmp(temp.country_name,candidate.country_name)==0) && (strstr(temp.major,candidate.major) != NULL)){
            add_to_advisor_tree(temp);
        }
            
    }
    fclose(file);    
}

list_tree_node * advisor_search_helper(list_tree_node * parent, char * name){ //searching the tree for a node using name
    if(parent == NULL) return NULL;

    if(strcasecmp(parent->data.uni_name, name) == 0){// Check current node and if found
        return parent;  
    }

    list_tree_node * left_result = advisor_search_helper(parent->left_prev, name); // Search left subtree
    if(left_result != NULL){
        return left_result;  // Found in left
    }

    return advisor_search_helper(parent->right_next, name); // Search right subtree
}

void advisor_suggestion_helper(list_tree_node * parent){//this will print the recomanded unis, tree is already sorted, just printing 
    if(parent == NULL) return ;

    advisor_suggestion_helper(parent->left_prev);
    dis_dashboard_data(parent);
    advisor_suggestion_helper(parent->right_next);
}

void advisor_suggestion(){ //advisor er recommandation starter
    dis_recom_heading();
    advisor_suggestion_helper(root);
    dis_after_recom();
}

void search_uni_advisor(){ // to search a uni full information in the suggestions 
    char name[50];
    printf(CYAN"Enter University Name: "RESET);
    fgets(name,50,stdin);
    name[strcspn(name,"\n")] = '\0';

    list_tree_node * result = advisor_search_helper(root, name);
    if(result != NULL){
        target_uni_found(result);
    }
    else{
        no_match();
    }
}

void advisor_compare_uni(){
    char name1[50], name2[50];
    printf(CYAN"Enter First University Name: "RESET);
    fgets(name1,50,stdin);
    name1[strcspn(name1,"\n")] = '\0';

    printf(CYAN"Enter Second University Name: "RESET);
    fgets(name2,50,stdin);
    name2[strcspn(name2,"\n")] = '\0';

    list_tree_node * temp1 = advisor_search_helper(root, name1);
    list_tree_node * temp2 = advisor_search_helper(root, name2);

    if(temp1 != NULL && temp2 != NULL){
        dis_compare_uni(temp1, temp2);
    }
    else{
        no_match();
    }
}

// main function starts from here

int main() {
    int n, m, t;
    mainpage();

    while (1) {
        /* read main menu choice safely */
        if (scanf("%d", &n) != 1) {
            leftover_eater();
            mainpage();
            continue;
        }
        leftover_eater();

        if (n == 0) break; /* exit */

        /* ----- ADMIN ----- */
        if (n == 1) {
            load_from_file();          /* build linked list */
            dis_admin_ui_main();

            if (scanf("%d", &m) != 1) {
                leftover_eater();
                mainpage();
                continue;
            }
            leftover_eater();

            if (m == 1) { /* Add */
                add_new_node();
                exit_page();
                if (scanf("%d", &t) == 1) {
                    leftover_eater();
                    if (t == 1) { mainpage(); continue; }
                    else if (t == 0) return 0;
                }
                mainpage();
                continue;
            }
            else if (m == 2) { /* Update */
                update_list_info();
                exit_page();
                if (scanf("%d", &t) == 1) {
                    leftover_eater();
                    if (t == 1) { mainpage(); continue; }
                    else if (t == 0) return 0;
                }
                mainpage();
                continue;
            }
            else if (m == 3) { /* Delete */
                delete_node();
                exit_page();
                if (scanf("%d", &t) == 1) {
                    leftover_eater();
                    if (t == 1) { mainpage(); continue; }
                    else if (t == 0) return 0;
                }
                mainpage();
                continue;
            }
            else { /* invalid admin option */
                mainpage();
                continue;
            }
        }

        /* ----- EXPLORE ----- */
        else if (n == 2) {
            file_to_tree();           /* build tree for dashboard */
            explore_ui_main();

            if (scanf("%d", &m) != 1) {
                leftover_eater();
                mainpage();
                continue;
            }
            leftover_eater();

            if (m == 1) { /* Dashboard */
                dashboard_explore();
                exit_page();
                if (scanf("%d", &t) == 1) {
                    leftover_eater();
                    if (t == 1) { mainpage(); continue; }
                    else if (t == 0) return 0;
                }
                mainpage();
                continue;
            }
            else if (m == 2) { /* Filter by country */
                filter_country();
                exit_page();
                if (scanf("%d", &t) == 1) {
                    leftover_eater();
                    if (t == 1) { mainpage(); continue; }
                    else if (t == 0) return 0;
                }
                mainpage();
                continue;
            }
            else if (m == 3) { /* Filter by budget */
                filter_budget();
                exit_page();
                if (scanf("%d", &t) == 1) {
                    leftover_eater();
                    if (t == 1) { mainpage(); continue; }
                    else if (t == 0) return 0;
                }
                mainpage();
                continue;
            }
            else if (m == 4) { /* Search */
                search_university();
                exit_page();
                if (scanf("%d", &t) == 1) {
                    leftover_eater();
                    if (t == 1) { mainpage(); continue; }
                    else if (t == 0) return 0;
                }
                mainpage();
                continue;
            }
            else {
                mainpage();
                continue;
            }
        }

        /* ----- ADVISOR ----- */
        else if (n == 3) {
            advisor_ui_main();
            file_to_advisor();        /* build advisor tree (filtered) */
            advisor_suggestion();     /* prints suggestions and heading */

            if (scanf("%d", &m) != 1) {
                leftover_eater();
                mainpage();
                continue;
            }
            leftover_eater();

            if (m == 1) { /* Compare */
                advisor_compare_uni();
                exit_page();
                if (scanf("%d", &t) == 1) {
                    leftover_eater();
                    if (t == 1) { mainpage(); continue; }
                    else if (t == 0) return 0;
                }
                mainpage();
                continue;
            }
            else if (m == 2) { /* Search within suggestions */
                search_uni_advisor();
                exit_page();
                if (scanf("%d", &t) == 1) {
                    leftover_eater();
                    if (t == 1) { mainpage(); continue; }
                    else if (t == 0) return 0;
                }
                mainpage();
                continue;
            }
            else {
                mainpage();
                continue;
            }
        }

        
    } /* while */

    last_page();
    return 0;
}
