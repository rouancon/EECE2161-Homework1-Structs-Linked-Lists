#include <stdio.h>
#include <stdlib.h>

/**
 * Define the node struct
 */
typedef struct list_node ListNode;

struct list_node
	{
		char name[40]; //An array of chars of max length 40 characters since the name is a word
		ListNode *next; //Define the pointer to the next element
	};

/**
 * Alphabetically add the name passed in to the list
 *  - iterates through the list to find the proper alpha positon then inserts
 *
 *@param  head		first pointer in list
 *@param  new_name	new name to add
 */
void add_name(struct ListNode *head, char new_name[])
{
	int not_added = 1;
	while(head && not_added)
	{
		if (strcmp(new_name, head->name) > 0)
		{
			ListNode newNode->name = new_name; //declare new node with name value
			newNode->next = head; //the new node next takes over the old next
			head = *newNode; //the old head now points to new node
			not_added = 0;
		}
		head = head->next;
	}
}

/**
 * Alphabetically print out the list
 *  - iterates through the list and prints it out
 *
 *@param  head		first pointer in list
 */
void alphaPrint(struct ListNode *head)
{
	while(head)
	{
		printf("%s", head->name);
		head = head->next;
	}
}

/**
 * Reverse alphabetically print the list
 *  - recursively moves through the list and prints it reverse alphabetically
 *
 *@param  head		first pointer in list
 */
void rev_alphaPrint(struct ListNode *head)
{
		if (head->next == null)
		{
			printf("%s", head->name);
		} else
		{
			rev_alphaPrint(head->next);
			printf("%s", head->name);
		}
}

int main()
{
	int total_names;
	char new_name[40];
	printf("\nHow many names would you like to enter? ");
	scanf("%d\n", &total_names);
	
	head = (*struct ListNode)malloc(sizeof(struct ListNode));
	
	for(int i=0; i<total_names; i++)  //iterate through to collect, sort and add names
	{
		printf("\nEnter a name: ");
		scanf("%s", &new_name);
		
		add_name(&head, new_name);
	}
	
	alphaPrint(&head);
	rev_alphaPrint(&head);
	
	return 0;
}
