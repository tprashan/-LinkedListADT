# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "linkedList.h"

LinkedList createList(){
	LinkedList *new_list = malloc(sizeof(LinkedList));
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->count = 0;
	return *new_list;
};

Node * create_node(void *data){
	Node * new_node = malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
};

int add_to_list(LinkedList *list ,Node * node){
	if(list->head==NULL)
		list->head=node;
	else
		list->tail->next = node;
	list->tail=node;
	list->count++;
	return list->count;
};

void *get_first_element(LinkedList list){
	return list.head;
};

void *get_last_element(LinkedList list){
	return list.tail;
};

void traverse(LinkedList list, traverseFunction add){
	while(list.head!=NULL){
		add(&(list.head->data));
		list.head = list.head->next;
	}
};