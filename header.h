#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>
extern char name[100];
extern int size;
extern int size2;
typedef struct user_node
{
	char usr_name[100];
	char password[100];
	struct user_node *link;
}user;

typedef struct passenger_node
{
	char username[100];
	int seat_no;
	int train_no;
	char date[20];
	char name[20];
	int age;
	char Gender[10];
	struct passenger_node *link;
}passenger;

typedef struct train_node
{
	int train_no;
	char train_name[30];
	char source[30];
	char destination[30];
	int no_of_seats;
	struct train_node *link;
}train;

typedef struct seat_node
{
	int train_no;
	int total_seats;
	int waiting_list;
	int current_booking_seat;
	struct seat_node *link;
}seat;

typedef struct book_data
{
	passenger *p_head;
	train *t_head;
	seat *s_head;
}book;

void sign_up();           //sign_up.c
user *usr_logins();      //sync_usr_logins.c
void save_logs(user *node);   //save_usr_logins.c
void sign_in();
void booking_menu();
passenger *sync_passengers_info();
void save_passengers_info(passenger *ptr);

void reserve_ticket(book *ptr);
void cancel_ticket(book *ptr);
void booking_info(book *ptr);

train *sync_train_info();
seat *sync_seat_info();
void save_seat_info(seat *ptr);

