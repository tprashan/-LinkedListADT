typedef struct node Node;
typedef struct node * node_ptr;
typedef struct linked_list LinkedList;
typedef struct student Student;
typedef void traverseFunction (void *);

struct node{
	void* data;
	node_ptr next;
};


struct linked_list{
	node_ptr head;
	node_ptr tail;
	int count;
};

struct student{
	int id;
	int score;
	char* name;
};

LinkedList createList(void);
Node * create_node(void *data);
int add_to_list(LinkedList *,Node *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void traverse(LinkedList, void (*)(void *data));
void * getElementAt(LinkedList, int );