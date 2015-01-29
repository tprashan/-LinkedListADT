# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "linkedList.h"
# include "expr_assert.h"

LinkedList initialize(LinkedList list){
	int score1=23,score2=45;
	node_ptr nodeToInsert,nodeToInsert1;

	nodeToInsert = create_node((void*)score1);
	add_to_list(&list,nodeToInsert);

	nodeToInsert1 = create_node((void*)score2);
	add_to_list(&list,nodeToInsert1);

	return list;
};


void test_create_an_empty_LinkedList_structure(){
	LinkedList result ;
	result = createList();
	assertEqual(0,result.count);
	assertEqual((int)NULL,(int)result.head);
};

void test_create_an_empty_LinkedList_structure_gives_NULL_in_tail(){
	LinkedList result ;
	result = createList();
	assertEqual(0,result.count);
	assertEqual((int)NULL,(int)result.tail);
};

void  test_create_an_appropriate_Node_structure_out_of_it_Note_the_data_can_be_of_any_type(){
	Node *result;
	int data = 10;
	result = create_node((void*)data);
	assertEqual(0,(int)result->next);
	assertEqual(10,(int)result->data);
	free(result);
};

void  test_create_an_appropriate_Node_structure_out_of_it_Note_the_data_can_be_of_char_type(){
	Node *result;
	char data = 'a';
	result = create_node((void*)data);
	assertEqual(0,(int)result->next);
	assertEqual('a',(char)result->data);
	free(result);
};

void  test_create_an_appropriate_Node_structure_out_of_it_Note_the_data_can_be_of_string_type(){
	Node *result;
	char* data = "hiiii";
	result = create_node((void*)data);
	assertEqual(0,(int)result->next);
	assertEqual(*(char*)"hiiii",*(char*)result->data);
	free(result);
};

void test_Given_some_node_add_it_to_list(){
	LinkedList list ;
	Node *node,*node1;
	int result,result1;
	int data = 10;
	int data1 = 20;
	list = createList();
	node = create_node((void*)data);
	node1 = create_node((void*)data1);
	result = add_to_list(&list,node);
	result1 = add_to_list(&list,node1);
	assertEqual(result,1);
	assertEqual(result1,2);
	free(node);
	free(node1);
};

void test_function_returns_the_first_element_in_the_list(){
	LinkedList list ;
	Node *node,*node1;
	void* result;
	int data = 10;
	int data1 = 20;
	list = createList();
	node = create_node((void*)data);
	node1 = create_node((void*)data1);
	add_to_list(&list,node);
	add_to_list(&list,node1);
	result = get_first_element(list);
	assertEqual(10,*(int *)result);
	free(node);
	free(node1);
};

void test_function_returns_the_last_element_in_the_list(){
	LinkedList list ;
	Node *node,*node1;
	void* result;
	int data = 10;
	int data1 = 20;
	list = createList();
	node = create_node((void*)data);
	node1 = create_node((void*)data1);
	add_to_list(&list,node);
	add_to_list(&list,node1);
	result = get_last_element(list);
	assertEqual(20,*(int *)result);
	free(node);
	free(node1);
};

// parmatma

void test_create_a_linkedList_it_return_head_NULL(){
	int count = 0;
	LinkedList expected = createList();
	assertEqual(0,(int)expected.head);
	assertEqual(0,(int)expected.tail);
};

void test_create_a_linkedList_it_return_with_0_element(){
	LinkedList expected = createList();
	assertEqual(0,((int)expected.count));
};

void test_create_a_node_it_contain_id_45_and_NULL(){
	int data = 45;
	Node *expected = create_node((void*)data);

	assertEqual(data,(int)expected->data);
	assertEqual(0,(int)expected->next);
	free(expected);
};

void test_create_a_node_it_contain_data_Parmatma_and_NULL(){
	char* data = "Parmatma";
	Node *expected = create_node((void*)data);
	char* expData = expected->data;

	assertEqual(strcmp(expData,data),0);
	assertEqual(0,(int)expected->next);
	free(expected);
};

void test_add_to_list_add_the_element_into_list_and_return_1(){
	int id = 23,count;
	LinkedList list = createList();
	node_ptr expected = create_node((void*)id);
	count = add_to_list(&list,expected);

	assertEqual(count,1);
	free(expected);
};

void test_add_to_list_add_the_element_into_list_and_give_count_2(){
	char* name = "hello";
	char *name1 = "gello";
	int count;
	node_ptr expected1,expected;

	LinkedList list = createList();

	expected = create_node((void*)name);
	count = add_to_list(&list,expected);
	
	expected1 = create_node((void*)name1);
	count = add_to_list(&list,expected1);

	assertEqual(count,2);
	free(expected);
};

void test_add_to_list_add_the_element_into_list_and_give_count_3(){
	char* name = "hello";
	char *name1 = "gello";
	char *name2 = "ghello";
	int count;
	node_ptr expected2,expected1,expected;

	LinkedList list = createList();

	expected = create_node((void*)name);
	count = add_to_list(&list,expected);
	
	expected1 = create_node((void*)name1);
	count = add_to_list(&list,expected1);

	expected2 = create_node((void*)name2);
	count = add_to_list(&list,expected2);

	assertEqual(count,3);
	free(expected);
};

void test_get_first_element_will_return_23(){
	int *result,id=23;
	LinkedList list = createList();
	node_ptr nodeToInsert = create_node((void*)id);
	add_to_list(&list,nodeToInsert);
	result = get_first_element(list);

	assertEqual(*result,23);
	free(nodeToInsert);
};

void test_get_last_will_return_45(){
	int *result,score1=23,score2=45;
	LinkedList list = createList();
	node_ptr nodeToInsert,nodeToInsert1;
	nodeToInsert = create_node((void*)score1);
	add_to_list(&list,nodeToInsert);

	nodeToInsert1 = create_node((void*)score2);
	add_to_list(&list,nodeToInsert1);

	result = get_last_element(list);

	assertEqual(*result,45);
	free(nodeToInsert);
};

void replaceNameWithKhello(void * data){
	*(int*)data = *(int*)data + 5 ;
};

void test_Write_a_generic_traverse_function_that_can_go_through_a_list_and_process_each_element(){
	int number = 10;
	int number1 = 20;
	int number2 = 30;
	int count;
	node_ptr expected2,expected1,expected;

	LinkedList list = createList();

	expected = create_node((void*)number);
	count = add_to_list(&list,expected);
	
	expected1 = create_node((void*)number1);
	count = add_to_list(&list,expected1);

	expected2 = create_node((void*)number2);
	count = add_to_list(&list,expected2);
	traverse(list, replaceNameWithKhello);
};

void increament(void* data){
	*(int*)data = *(int*)data + 1;
};

void test_traverse_gives_all_elements_by_increament_followed_by_one(){
	void *result;
	LinkedList list = createList();
	list = initialize(list);

	traverse(list,increament);
	result = get_first_element(list);

	assertEqual(*(int*)result, 24);
};

void test_traverse_gives_all_elements_by_increament_followed_by_one_get_last_46(){
	void *result;
	LinkedList list = createList();
	list = initialize(list);

	traverse(list,increament);
	result = get_last_element(list);

	assertEqual(*(int*)result, 46);
};