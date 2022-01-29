/***************************************
* Author: Muhammad, Adil *
* Email: adil133@my.yorku.ca *
* York Student #: 218059956
************************************** **/

// Declare library functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Set size and max length of string
#define BUFFERS_SIZE 50
#define MAX_LEN 35

// Declare structures and their components
struct twoInts
{
  int int1;
  int int2;
};

// Structure which holds data, next and previous
struct node {  // list 'node' struct
   char data;
   struct node *next;
   struct node *prev;
};

// Declare methods
void init( );
void display();
int len();
char get(int);
int search (char);
void insert(char);
void insertAfter(char, int) ;
void delete(char);

// global variable, the head of the linkedlist
struct node * head;

int main() {
    // Declare variables
    int i, index; char key;

    struct twoInts * arr[MAX_LEN]; // an array of (unitilized) pionters to structs

    // Set the buffer with the given constant size
    char buffer[BUFFERS_SIZE];
    // Set values and count
    int value1, value2;
    int count= 0;

    // Access the data file for input
    FILE * file;
    file = fopen("data.txt", "r");

    // or  while (fscanf(file, "%d %d", &value1, &value2) == 2)
    while (fgets(buffer, BUFFERS_SIZE, file) != NULL) {
        // tokenize buffer and store into value1 and value2
        sscanf(buffer, "%d %d", &value1, &value2);   
        
        // call function malloc() to allocate memory for arr[count]
        arr[count] = (struct twoInts*) malloc(sizeof(struct twoInts));

        // set the two fields pointed by arr[count] with value1 and value2
	    arr[count] -> int1 = value1; // First field set to value1
        arr[count] -> int2 = value2; // Second field set to value2
	   
        // Increment counter variable
        count++;
    }

    // Close the file
    fclose(file);

    /* print the fields of stuctures pointed by the pointer array */
    for(i = 0; i < count; i++) {
        // Print the current number, along with the data in data.txt, side by side
        printf("arr[%d]: %d %d\n", i, arr[i] -> int1, arr[i] -> int2);
    }

    // now build up the list by reading from the array of structures
    printf("\n");
    // Access function init to initalize
    init();

    // Set i to 0
    i = 0;

    // Loop through the counter
    for(; i < count; i++){
        // read two ints from each structure pointed in the array, sum up and add into the list
        int value = arr[i] -> int1 + arr[i] -> int2;
        insert((char)value); // no more coding in main

    // Print formatted string for insert
	printf("insert %c: (%d)", value, len());
        // Call display to display current contents
        display();
    }

    // Remove given characters from the list
    char removeList [] = {'S','E','-','O','R','K','Y','U','C','\0'}; // \0 is the terminator token
    // Set i to 0
    i = 0;
    // Remove given keys from the list
    while ((key = removeList[i]) != '\0') {
        // Delete the given key
        delete(key);
        // Display a statement indicating the letter to be removed
        printf("remove %c: (%d)", key, len()); display();
        // Increment i
        i++;
    }

    // insert again
    char addList [] = "YORKU-CSE"; 
    // Set i to 0
    i = 0;
    // Ensure that the null character is not reached and add the given word indicated
    // by addList
    while ((key=addList[i]) != '\0'){ 
        // Call insert to insert the key
        insert(key);
        // Display a statement indicating the letter to be inserted
        printf("insert %c: (%d)", key, len());
        // Display the current contents
        display();
        // Increment i
        i++;
    }

    // Get the following values
    int v = get(0);  printf("\nget(0): %c\n", v);
    v = get(2);  printf("get(2): %c\n", v);
    v = get(3);  printf("get(3): %c\n", v);
    v = get(6);  printf("get(6): %c\n", v);
    v = get(7);  printf("get(7): %c\n", v);
    v = get(8);  printf("get(8): %c\n", v);

    // Call insert after
    key ='x'; index =2; insertAfter(key,index);
    printf("\ninsert %c after index %d: (%d)\n", key,index,len()); display();
    key ='y'; index = 0; insertAfter(key,index);
    printf("insert %c after index %d: (%d)\n", key,index,len()); display();
    key ='z'; index = 6;insertAfter(key,index);
    printf("insert %c after index %d: (%d)\n", key,index,len()); display();

    v = get(0);  printf("\nget(0): %c\n", v);
    v = get(2);  printf("get(2): %c\n", v);
    v = get(3);  printf("get(3): %c\n", v);
    v = get(6);  printf("get(6): %c\n", v);
    v = get(7);  printf("get(7): %c\n", v);
    v = get(8);  printf("get(8): %c\n", v);

    // search the list
    printf("\n");
    // Search for the following letters in searchList
    char searchList [] = "-orkUxyZAy";
    // Store the length of the list
    int len = strlen(searchList);
    // Declare i to be 0
    i = 0;
    // Loop through the length of the searchList
    while ( i < len ){
    // Set the key to the current element    
	char key = *(searchList + i);
        // State that the key is being searched for
        printf("search %c ....  ", key);
        
        // Call search to locate the key
        if (search(key))
            printf("found\n");

        // If not found    
        else
            printf("not found\n");

        // Increment counter
        i++;
    }
}

/* Initialize the list. */
void init() {
    // Initially, set the head to null
    head = NULL;
}

// Display the information in the list
void display() {
    // Check if starting point is null
    if (head == NULL) {
        printf("\n");
        return;
    }

    // Copy the structure head to current
    struct node *current = head;

    // If next is not null
    while (current -> next != NULL) {
       printf( "%3c", current -> data);  
       // Set current to (current*).next
       current = current -> next;    
    } 

    // Ensure formatting
	printf( "%3c", current -> data ); 
	printf( "    <-->  " );

    // Ensure current is not null
	while (current != NULL){
       printf( "%3c", current -> data );  
       // Similar to the previous loop, set current to (*current).prev
       current = current -> prev;   
    } 

    //printf( "\n" );
    printf("\n");
}

// Method: Length of the list
int len() {
    // initialize counter to 0
    int counter = 0; 
    // Set head to the current structure
    struct node *current = head; 
    
    // Terminate loop when current is null
    while(current != NULL) {
        // Increment counter
        counter = counter + 1;
        // Set current to (*current).next
        current = current -> next;
    }

    // Return the counter
    return counter;  
}

// Get node's data at the given index
char get(int index){
    struct node *current = head; // set current to head

    // loop over the list until we get the node at index
    while(index > 0) {
        // Continue to decrement index until we reach the node at index
        index = index - 1;
        // Set current to (*current).next
        current = current -> next;
    }

    // Return the date component of structure current
    return current -> data;
}

/* search the list for key, return whether or not it is found */
int search (char key) {
    // Set the contents of head to the current structure
    struct node * current = head;
    
    // Loop until current is Null
    while(current != NULL) {
        // If current data equates to the key (key is found)
        if(current -> data == key) 
            // Return 1 if the key is found
            return 1;
    // Set the current to the next key        
    current = current -> next;
    }

    return 0; // key not found
}

/* Insert a new data element with key c into the end of the list. */
/* Hint: You may want to consider the special case that the list is empty,
   and the general case that the list is not empty */

void insert(char c ) { //  at the end
    /* the special case: the list is empty, need to change head  */
    if (head == NULL){
        // Reserve space for the head using malloc
        head = (struct node*)malloc(sizeof(struct node));
        
        head -> prev = NULL; // Set previous node to null
        head -> next = NULL; // Set next to null
        head -> data = c;    // Set data to the given character
    }

    else {
        // Assign the contents of head to current
        struct node * current = head;

        // Attain the last node
        while(current -> next != NULL)
        // Assign the next node to the current node
        current = current -> next;

        // Store the current character in a node
        struct node * newNode = malloc(sizeof(struct node));  // Make space in memory for the node

        newNode -> data = c;        // Set data to the given character
        newNode -> next = NULL;     // Set the next node to null
        newNode -> prev = current;  // Set the previous node to current
        current -> next = newNode;  // Set the next node to the new node
    }
 }

/* insert in the middle.
  insert new node with data c, after the node of index 'index'
  assume the list is not empty, and index is in [0, len()-1]
 */
void insertAfter(char c, int index) {
    // Create memory space for a newNode
    struct node *newNode = malloc(sizeof(struct node));
    newNode -> data = c;          // Set the data of the new node the current character
    newNode -> next = NULL;       // Set the next new node to null
    newNode -> prev = NULL;       // Set the previous new node to null as well 

    struct node *current = head;  // Set the current contents of head to current  

    // Ensure that the index is greater than 0
    while(index > 0) {
        // Set the current node to the next node
        current = current -> next;
        // Go through each index by decrementing for every iteration
        index = index - 1;
    }

    newNode -> next = current -> next; // Set the next newNode to the next currentNode 
    newNode -> prev = current;         // Set the previous newNode to the current node
    current -> next -> prev = newNode; // Set the previous node to the newNode
    current -> next = newNode;         // Set the next current node to the newNode 
}

/* lab version */
/* Remove the node with value c from the list */
/* assume the list is not empty */
/* assume no duplicated keys in the list */
/* assume the node to be deleted is in the list */
/* You do not have to free the space (welcome to do so)  */
void delete(char c) {
    // Check if the data of head is equivalent to the given character
    if (head -> data == c){
        // Set the contents of head to temporary
        struct node *temporary = head;
        // Assign the next head node to head
        head = head -> next;

        // If the head is empty
        if(head != NULL) 
            // Assign the previous head node to null
            head -> prev = NULL;
        
        // Delete the temporary structure and its components
        free(temporary);
    }       

    else {
        // Set the contents of head to current
        struct node * current = head;

        // Ensure that the current structure is not null and 
        // that the current node's data is not equivalent to the given character
        while(current != NULL && current -> data != c) {
            // Set the current node to the next node
            current = current -> next;
        }

        // Given that the current node is not null
        if(current != NULL) {
            // Set the contents of head to temporary
            struct node * temporary = current; 
            // Set the next node to the next current node
            current -> prev -> next = current -> next;
            
            // Finally, check if the next current node is not null
            if(current -> next != NULL)
                // Assign the previous node to the previous current node
                current -> next -> prev = current -> prev;

            // Delete the temporary structure and its components
            free(temporary);
        }
    }
}

 
