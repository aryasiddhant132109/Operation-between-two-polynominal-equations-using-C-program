// creating polynominal equations operations using linked lists //
#include<stdio.h>
#include<stdlib.h>
struct Node{// creating a structure for linklist node (having coefficient as data, variable degree, and pointer to next node)
	int data;
	int degree;
	struct Node* next;
};
// To create a new node:
struct Node* create(int item,int deg){
	struct Node* newnode=(struct Node*)malloc(sizeof(struct Node)); // creating space for newnode
	//inserting item and degree
	newnode->data=item; 
	newnode->degree=deg;
	newnode->next=NULL;
	return newnode;  // returning newnode                                               
};
void display(struct Node* term){ // for display the equations after add/mul operations
	if(term==NULL) printf("0");
	else{
		int execution=0; // to check the first execution
		while(term!=NULL){
			if(execution==0){ // for 1st non-zero term in equation
				if(term->degree==0) printf("%d",term->data);// for zero degree
				else if(term->degree==1){  // for 1 degree
					if(term->data==1) printf("x");
					else printf("%dx",term->data); 
				} 
				else{
					if(term->data==1) printf("x^%d",term->degree);
					else printf("%dx^%d",term->data,term->degree); 
				}
			}
			else{
				if(term->degree==0){ // for zero degree
					if(term->data<0)  printf("%d",term->data); //-ve coefficient
					else  printf("+%d",term->data);
				} 
				else if(term->degree==1){ // for 1 degree
				    if(term->data==1) printf("+x"); //for coefficient=1
				    else if(term->data==-1) printf("-x"); //for coefficient=-1
				    else{ // for coefficients rather than 1 or -1
				    	if(term->data<0) printf("%dx",term->data); 
					else printf("+%dx",term->data);
					}
				}
				else{
					if(term->data==1) printf("+x^%d",term->degree); //for coefficient=1
				    else if(term->data==-1) printf("-x^%d",term->degree); //for coefficient=-1
				    else{ // for coefficients rather than 1 or -1
				    	if(term->data<0) printf("%dx^%d",term->data,term->degree); 
					else printf("+%dx^%d",term->data,term->degree);
					}
				}
			}
			term=term->next;
			execution++;
		}
    }
    printf("=0\n");
}
void add(struct Node* a1,struct Node* a2){ // for addition of both equations
	struct Node* tail=NULL; // create node as tail of linked list of added equations
	struct Node* head=NULL; // create node as head of linked list of added equations
	printf("---Addition of quadratic equation---\n");              
	struct Node* temp1=a1; // creating a duplicate of a1
	//int count=0; // to count no. of non zero terms in added equation
	// loop goes until the duplicate node is not NULL via which the node becomes it's next after each execution
	while(temp1!=NULL){ 
		struct Node* temp2=a2; // creating a duplicate of a2
		// loop goes until the duplicate node is not NULL via which the node becomes it's next after each execution
		while(temp2!=NULL){
			int add=temp1->data+temp2->data; // declaring variable as add of coefficients
			if(temp1->degree==temp2->degree && add!=0){
				//so that nodes are created with only addition of degree non zero terms
				struct Node* newnode=create(add,temp1->degree);
				if(head==NULL){ // when linked list is null
			    	head=newnode; 
			    	tail=newnode;
			    }
				else{
				    tail->next=newnode;
				    tail=tail->next;
				}
			//	count++;
				
			}
			temp2=temp2->next;
		}
		 
		temp1=temp1->next;
	}
	display(head); // calling display function
	
}           
void mul(struct Node* a1,struct Node* a2,int deg){ // for multiplication of both equations
    int size=deg+deg;
    int mult[size+1];
    for(int i=0;i<=size;i++) mult[i]=0;
	printf("---Multiplication of quadratic equation---\n");
	struct Node* tail=NULL; // create node as tail of linked list  
	struct Node* head=NULL; // create node as head of linked list of added equations           
	struct Node* temp1=a1; // creating a duplicate of a1
	//int count=0; // to count no. of non zero terms in multiplied equation
	// loop goes until the duplicate node is not NULL via which the node becomes it's next after each execution
	while(temp1!=NULL){ 
		struct Node* temp2=a2; // creating a duplicate of a2
		// loop goes until the duplicate node is not NULL via which the node becomes it's next after each execution
		while(temp2!=NULL){
			int power=temp1->degree+temp2->degree;
			mult[power]=mult[power]+(temp1->data*temp2->data); // declaring variable as add of coefficients
			temp2=temp2->next;
		}
		temp1=temp1->next;	
	}
	
	for(int j=size;j>=0;j--){
		if(mult[j]!=0){
	    	struct Node* newnode=create(mult[j],j);
	    	if(head==NULL){ // when linked list is null
		        head=newnode; 
	    	    tail=newnode;
	    	}
	    	else{
	    	    tail->next=newnode;
	    	    tail=tail->next;
	    	}
    	}
    }
	display(head); // calling display function
}           
// for creating equations
struct Node* eqn(int deg){ 
	struct Node* head=NULL;
	struct Node* tail=NULL;
	int power=deg; // to save min value of degree
	while(power>=0){ // loop goes until power goes to max(degree)
		int item;
		printf("Enter element of degree %d:",power);
		scanf("%d",&item);
		struct Node* newnode=create(item,power);
		if(head==NULL){
	    	head=newnode;  
			tail=head; 
	    }
		else{
			tail->next=newnode;
			tail=tail->next;
		}
		power--;
	}
	return head;
}; 
int main(){
	struct Node* a1=NULL; // consist of highest degree term in eq 1
	struct Node* a2=NULL; //  consist of highest degree term in eq 2
	int deg;   // highest degree in eqns
	printf("Enter highest degree of polynomial equations:");
	scanf("%d",&deg);
	printf("For 1st equations:\n");
	a1=eqn(deg); // value equal to returned value of eqn structure by passing pointer to degree
	printf("For 2nd equations:\n");
	a2=eqn(deg); // same thing here
    //calling adding and multyplying functions for both equations
	//by passing highest degree terms from both equations and there highest degree as well
	add(a1,a2);
	mul(a1,a2,deg);
	printf("\n--------created by Arya Siddhant----------");
	return 0;
}