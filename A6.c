/*
 ============================================================================
 Name        : ange7290_a6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/**
 * -------------------------
 * Student Name: Marissa angeles
 * Student ID:200377290
 * Student email:ange7290@mylaurier.ca
 * -------------------------
 */

//put your include statements here

# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include "A6.h"
# include <stdio.h>

//optional utility functions
unsigned long _get_UPID();
int _is_valid_resource(char* res);
int _has_resource(OSProcess *p, char* resource);
void _remove_osprocess_resource(OSProcess *p);

//-------------- Task 1: create_osprocess ----------------
OSProcess* create_osprocess(char* name){
	//your code here

	OSProcess *ptr = (OSProcess*)malloc(sizeof(OSProcess));

	//printf("%s", name);
	strcpy(ptr->name, name);
	ptr->name[10] = '\0';

	ptr->state = (char*)malloc(sizeof(char)*15);
	strcpy(ptr->state, "idle");
	ptr->priority = 'R';
	ptr->num_resources = 0;
	for (int i = 0; i<6;i++){
		strcpy(ptr->resources[i],""); //init all 6 to nothing
	}
	ptr->PID = _get_UPID(name);

	return ptr;
}

unsigned long _get_UPID(char *name){
	//your code here
	//after three calls then change 4th digit

	static int first = 1000; //first four
	static int second = 1000;
	static int counter = 0;
	unsigned long upid = 0;

	if (counter == 0){
		//first call no change just return
		counter++;
		upid = first*10000+second;
		return upid;
	}
	//second calls no change to first
	second++;
	if (second != 1000 && second%4 == 0){
		//fourth call increments first
		first++;
	}
	upid = first*10000+second;

	return upid;
}

//-------------- Task 2: Printing Functions ----------------
char* osprocess_to_str(OSProcess *p){
	//your code here
	//<name>:(<priority>[<PID>:state]{<resources>}

	char ptr[60];

	sprintf(ptr, "%s:(%c)[%lu:%s]", p->name, p->priority, p->PID, p->state);
	strcat(ptr,"{");

	int i =0;
	for (i = 0; i < 6 && strcmp(p->resources[i], "") != 0; i++){

		strcat(ptr, p->resources[i]);

		if (strcmp(p->resources[i+1],"") != 0 && i+1<6){
			strcat(ptr,",");
		}
	}
	strcat(ptr,"}");

	char *ptrr = (char*)malloc(sizeof(ptr));
	strcpy(ptrr,ptr);

	return ptrr;
}

void print_osprocess(OSProcess *p){


	char ptr[60];
	strcpy(ptr, osprocess_to_str(p));
		printf("%s", ptr);
		return;
}


//-------------- Task 3: Requesting resource service ----------------
int _is_valid_resource(char* res){
	//your code here
	char* resources[6] = {"CP","NK","IN","OU","HD","RM"};

	int isvalid = 0;
	int i = 0;
	for (i = 0; i < 6; i++){
		if(strcmp(resources[i], res) == 0) {
			//res is in the array which means  its there
			isvalid = 1;
		}
	}

	return isvalid;
}

int _has_resource(OSProcess *p, char* resource){
	//your code here
	//basically check structure to see if its already there
	int isvalid = 1;//1 means false no has resource
	int i = 0;

	for (i = 0; i<6;i++){
			if (strcmp(p->resources[i],resource) == 0){
				//compare all elements to resource and if true it has it

				isvalid = 0; //yes it has resource dont add
			}

		}

	return isvalid;
}

int add_resource_osprocess(OSProcess *p, char* resource){
	//your code here

	int istrue = 0;
	istrue = _is_valid_resource(resource); //in the array returns 1
	if (istrue == 0){
		return istrue;
	}
	istrue = _has_resource(p, resource); //not in resource already returns 1

	if (istrue == 1){
		//if true then can add it
		int i = 0;
		for (i = 0; i<6;i++){
			if (strcmp(p->resources[i],"") == 0){
						//compare all elements to see if empty space
				strcpy(p->resources[i],resource);
				return istrue;
			}
		}

	}
	return istrue;
}

//-------------- Task 4: starting and stopping a process ----------------
int start_osprocess(OSProcess *p){
	//your code here
	//conditions to run
	int valid = 0;
	if (strcmp(p->state, "idle") == 0 && strcmp(p->resources[0], "") != 0){
		p->state = "running";

		valid = 1;
	}
	else{

		valid = 0;
	}
	//otherwise false

	return valid;
}

int stop_osprocess(OSProcess *p){
	//your code here
	//condition to run if its run then stop
	if (strcmp(p->state, "running") == 0){
		p ->state ="idle";
		return 1;
	}
	//otherwise false
	return 0;
}

//-------------- Task 5: Serving a process ----------------
int serve_osprocess(OSProcess *p){
	//your code here
	if (strcmp(p->state, "running") == 0 && strcmp(p->resources[0], "") != 0){
		printf("serving osprocess [%lu] for %s\n", p->PID, p->resources[0]);
		_remove_osprocess_resource(p);
			return 1;
		}
	return 0;
}

void _remove_osprocess_resource(OSProcess *p){
	//your code here
	//The above function removes the first resource
	//in the array and shift the other resources to the left.
	int i;
	for (i = 0; i<6;i++){
		strcpy(p->resources[i],p->resources[i+1]);
	}
	return;
}

//-------------- Task 6: Destroy OSProcess ----------------
void destroy_osprocess(OSProcess ** p){
	//your code here
	strcpy((*p)->name, "");
	(*p)->state = "";
	(*p)->priority = '\0';
	(*p)->num_resources = 0;
	for (int i = 0; i<6;i++){
		strcpy((*p)->resources[i],""); //init all 6 to nothing
	}

	(*p)->PID = 0;
	//free(*p);
	*p = NULL;
	return;
}

