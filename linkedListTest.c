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

void addFiveToGivenIntData(void * data){
	*(int*)data = *(int*)data + 5 ;
};

void test_Write_a_generic_traverse_function_that_can_go_through_a_list_and_process_each_element(){
	int number = 10, number1 = 20, number2 = 30;
	void* result;

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)number));
	
	add_to_list(&list,create_node((void*)number1));

	add_to_list(&list,create_node((void*)number2));

	traverse(list, addFiveToGivenIntData);
	result = get_first_element(list);

	assertEqual(*(int*)result, 15);
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

void changeStringToUpperCase(void * data){
	int i=0;
	char* string = malloc(sizeof(char*));
	strcpy(string,*(char**)data);
	while(string[i]!='\0'){
		string[i] = string[i] - 32;
		i++;
	}
	*(char**)data = string;
};

void test_traverse_to_list_add_the_element_into_list_and_give_string(){
	char* name = "hello", *name1 = "gello", *name2 = "ghello";
	void* result;

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)name));
	
	add_to_list(&list,create_node((void*)name1));

	add_to_list(&list,create_node((void*)name2));

	traverse(list, changeStringToUpperCase);
	result = get_last_element(list);

	assertEqual(strcmp("GHELLO",*(char**)result),0);
};

void test_traverse_to_list_add_the_element_into_list_and_give_capital_letter_string(){
	char* name = "hello", *name1 = "gello", *name2 = "ghello";
	void* result;

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)name));
	
	add_to_list(&list,create_node((void*)name1));

	add_to_list(&list,create_node((void*)name2));

	traverse(list, changeStringToUpperCase);
	result = get_first_element(list);

	assertEqual(strcmp("HELLO",*(char**)result),0);
};

void test_Given_an_index_as_an_integer_return_the_data_reference_contained_at_that_position_in_the_list(){
	void *result;
	int index = 1;
	LinkedList list = createList();
	list = initialize(list);

	result = getElementAt(list,index);

	assertEqual((int)result, 45);
};

void test_Given_an_element_find_the_first_index_at_which_this_element_occurs_in_a_list(){
	int result;
	int element = 45;
	LinkedList list = createList();
	list = initialize(list);

	result = indexOf(list,(void*)element);
	assertEqual((int)result,1);
};

void test_Given_an_element_find_the_first_index_at_which_this_23_element_occurs_in_a_list(){
	int result;
	int element = 23;
	LinkedList list = createList();
	list = initialize(list);

	result = indexOf(list,(void*)element);
	assertEqual((int)result,0);
};

void test_Given_an_element_find_the_first_index_at_which_this_19_element_occurs_in_a_list_this_should_return_minus_1(){
	int result;
	int element = 19;
	LinkedList list = createList();
	list = initialize(list);

	result = indexOf(list,(void*)element);
	assertEqual((int)result,-1);
};

void test_Given_an_index_delete_the_element_at_that_list_Return_the_data_referenced_by_the_node_at_that_position(){
	int number = 10, number1 = 20, number2 = 30,index=1;
	void* result;

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)number));
	
	add_to_list(&list,create_node((void*)number1));

	add_to_list(&list,create_node((void*)number2));

	result = deleteElementAt(&list,index);
	
	assertEqual((int)result, 20);
};

void test_Given_an_index_delete_the_element_at_that_list_Return_the_data_referenced_by_the_node_at_position_0(){
	int number = 10, number1 = 20, number2 = 30,index=0;
	void* result;

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)number));
	
	add_to_list(&list,create_node((void*)number1));

	add_to_list(&list,create_node((void*)number2));

	result = deleteElementAt(&list,index);
	
	assertEqual((int)result, 10);
};

void test_Given_an_index_delete_the_element_at_that_list_Return_the_data_referenced_by_the_node_at_position_2(){
	int number = 10, number1 = 20, number2 = 30, index=2;
	void* result;

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)number));
	
	add_to_list(&list,create_node((void*)number1));

	add_to_list(&list,create_node((void*)number2));

	result = deleteElementAt(&list,index);
	
	assertEqual((int)result, 30);
};

void test_after_delete_first_element_that_element_should_not_present_in_the_list(){
	int number = 10, number1 = 20, number2 = 30;
	int index=0;
	void* result, *element;

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)number));
	
	add_to_list(&list,create_node((void*)number1));

	add_to_list(&list,create_node((void*)number2));

	result = deleteElementAt(&list,index);
	element = get_first_element(list);

	assertEqual((int)result, 10);
	assertEqual(*(int*)element, 20);
};

void test_after_delete_last_element_that_element_should_not_present_in_the_list(){
	int number = 10, number1 = 20, number2 = 30;
	int index=2;
	void* result,* element;

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)number));
	
	add_to_list(&list,create_node((void*)number1));

	add_to_list(&list,create_node((void*)number2));

	result = deleteElementAt(&list,index);
	element = get_last_element(list);

	assertEqual((int)result, 30);
	assertEqual(*(int*)element, 20);
};

void test_delete_string_from_a_list_by_given_index(){
	char* name = "hello", *name1 = "gello", *name2 = "ghello";
	int index=2;
	void* result,* element;

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)name));
	
	add_to_list(&list,create_node((void*)name1));

	add_to_list(&list,create_node((void*)name2));

	result = deleteElementAt(&list,index);
	element = get_last_element(list);

	assertEqual(strcmp((char*)result,"ghello"),0);
	assertEqual(strcmp(*(char**)element,"gello"),0);
};

void test_delete_string_from_a_list_by_given_index_0(){
	char* name = "hello", *name1 = "gello", *name2 = "ghello";
	int index=0;
	void* result,* element;

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)name));
	
	add_to_list(&list,create_node((void*)name1));

	add_to_list(&list,create_node((void*)name2));

	result = deleteElementAt(&list,index);
	element = get_last_element(list);

	assertEqual(strcmp((char*)result,"hello"),0);
	assertEqual(strcmp(*(char**)element,"ghello"),0);
};

void test_delete_string_from_a_list_by_given_index_0_and_gello_will_be_first_term(){
	char* name = "hello",*name1 = "gello",*name2 = "ghello";
	int index=0;
	void* result,* element;

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)name));
	
	add_to_list(&list,create_node((void*)name1));

	add_to_list(&list,create_node((void*)name2));

	result = deleteElementAt(&list,index);
	element = get_first_element(list);

	assertEqual(strcmp((char*)result,"hello"),0);
	assertEqual(strcmp(*(char**)element,"gello"),0);
};

void test_delete_string_from_a_list_by_given_index_1_and_gello_will_be_nomore_there(){
	char* name = "hello",*name1 = "gello",*name2 = "ghello";
	int index=1,element;
	void* result;

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)name));
	
	add_to_list(&list,create_node((void*)name1));

	add_to_list(&list,create_node((void*)name2));

	result = deleteElementAt(&list,index);
	element = indexOf(list,(void*)name1);

	assertEqual(strcmp((char*)result,"gello"),0);
	assertEqual(element,-1);
};

void test_delete_string_from_a_list_by_given_index_1_replace_the_value_with_next_value(){
	char* name = "hello",*name1 = "gello",*name2 = "ghello";
	int index=1,element;
	void* result;

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)name));
	
	add_to_list(&list,create_node((void*)name1));

	add_to_list(&list,create_node((void*)name2));

	result = deleteElementAt(&list,index);
	element = indexOf(list,(void*)name);

	assertEqual(strcmp((char*)result,"gello"),0);
	assertEqual((int)element,0);
};

void test_this_function_will_populate_the_array_with_all_the_elements_of_a_list (){
	int number = 10,number1 = 20,number2 = 30,result;
	void *array[3];

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)number));
	
	add_to_list(&list,create_node((void*)number1));

	add_to_list(&list,create_node((void*)number2));

	result = asArray(list,array);
	assertEqual(result,3);

};

int isEven(void *data){
	return ((int)data%2==0)?1:0;
}

void test_filter_gives_list_of_evens(){
	int number = 10,number1 = 30,number2 = 21;
	LinkedList* result;

	LinkedList list = createList();

	add_to_list(&list,create_node((void*)number));
	
	add_to_list(&list,create_node((void*)number1));

	add_to_list(&list,create_node((void*)number2));

	result=filter(list,isEven);
	assertEqual((int)result->tail->data,30);
};
/////////////////

int isOdd(void* element){
	return ((int)element%2==0)?0:1;
};

void test_filter_returns_list_of_data_23_and_45(){
	LinkedList list = createList();
	LinkedList *result;
	list = initialize(list);
	result = filter(list,isOdd);

	assertEqual((int)result->count,2);
	free(result);
};

void test_filter_returns_list_of_data_23_and_45_and_head_will_be_23(){
	LinkedList list = createList();
	LinkedList *result;
	list = initialize(list);
	result = filter(list,isOdd);

	assertEqual((int)result->count,2);
	assertEqual((int)result->head->data,23);
	free(result);
};

void test_filter_returns_list_of_data_23_and_45_and_last_will_be_45(){
	LinkedList list = createList();
	LinkedList *result;
	list = initialize(list);
	result = filter(list,isOdd);

	assertEqual((int)result->count,2);
	assertEqual(*(int*)get_last_element(*result),45);
	free(result);
};
int lessThan(void* element){
	return (strlen((char*)element)>5)?1:0;
};

void test_filter_will_return_lenth_1_and_gellooo_atFirst(){
	char* name = "hello";
	char *name1 = "gellooo",*element;
	int length;
	LinkedList *result;
	node_ptr expected1,expected;
	LinkedList list = createList();

	expected = create_node((void*)name);
	add_to_list(&list,expected);
	
	expected1 = create_node((void*)name1);
	add_to_list(&list,expected1);
	result = filter(list,lessThan);
	strcpy(element,get_first_element(*result));

	assertEqual((int)result->count,1);
	assertEqual(strcmp(*(char**)element,"gellooo"),0);
	free(expected);
	free(expected1);
	free(result);
};

void test_filter_will_return_lenth_1_and_gellooo_atLast(){
	char* name = "hello";
	char *name1 = "gellooo",*element;
	int length;
	LinkedList *result;
	node_ptr expected1,expected;
	LinkedList list = createList();

	expected = create_node((void*)name);
	add_to_list(&list,expected);
	
	expected1 = create_node((void*)name1);
	add_to_list(&list,expected1);
	result = filter(list,lessThan);
	strcpy(element,get_last_element(*result));

	assertEqual((int)result->count,1);
	assertEqual(strcmp(*(char**)element,"gellooo"),0);
	free(expected);
	free(expected1);
	free(result);
};