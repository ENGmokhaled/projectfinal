#include <stdio.h>
#include <stdlib.h>

//create a structure representing student information
    struct student_data
{
   char student_name[70];
   int student_ID;
   int student_birth_day;
   int student_birth_month;
   int student_birth_year;
   int student_lastyear_score;
};

int p;

struct student_data* arr_student_data;
void insert(int j)
{
    p++;
    for (int i = p-1; i >= j; i--)
      arr_student_data[i] = arr_student_data[i - 1];
    printf("\nEnter details of student %d\n\n", j);

        printf("Enter name: ");
        scanf("%s", arr_student_data[j].student_name);

        printf("Enter ID: ");
        scanf("%d", &arr_student_data[j].student_ID);

        printf("Enter birthday: ");
        scanf("%d", &arr_student_data[j].student_birth_day);
        printf("Enter birth month: ");
        scanf("%d", &arr_student_data[j].student_birth_month);
        printf("Enter birth year: ");
        scanf("%d", &arr_student_data[j].student_birth_year);
        printf("Enter last year score: ");
        scanf("%d", &arr_student_data[j].student_lastyear_score);
        for(int i = 0; i < p; i++ )
    {
        printf("%s\t%d\t%.2d\t%s\t%.2d\t%s\t%.4d\t%s\t%.d\n",
        arr_student_data[i].student_name, arr_student_data[i].student_ID, arr_student_data[i].student_birth_day,"     ", arr_student_data[i].student_birth_month,"     ", arr_student_data[i].student_birth_year, "     ",arr_student_data[i].student_lastyear_score);
    }

}

struct nodeType //create a structure representing the linked list node
{
	struct student_data s;
	struct nodeType *next;
};

struct nodeType *Head,*Tail; //pointers to the first and last nodes in the list
int length=0; //the length of the list initially equals zero

void insertAtFirst(struct student_data ss) //function to insert at first
{
	struct nodeType *newNode = (struct nodeType*) malloc(sizeof(struct nodeType)); //dynamic allocation of a single block of memory with the size of our node
	//inserting the data in the node
	newNode->s.student_ID=ss.student_ID;
    strcpy(newNode->s.student_name,ss.student_name);
    newNode->s.student_birth_day=ss.student_birth_day;
    newNode->s.student_birth_month=ss.student_birth_month;
    newNode->s.student_birth_year=ss.student_birth_year;
    newNode->s.student_lastyear_score=ss.student_lastyear_score;



	if (length == 0) //if it is the first node to be added in the list
	{
		Head = Tail = newNode;
		newNode->next = NULL;
	}
	else //insert at first
	{
		newNode->next = Head;
		Head = newNode;
	}
	length++;
}
void printLinkedlist() //function to print the list
{
    struct nodeType *temp = Head; // temp pointer that will traverse the list printing the data in each node
	while (temp != NULL)
	{
		printf(" Id is: %d \n", temp->s.student_ID);
        printf(" Name is: %s \n", temp->s.student_name);
        printf(" Birth day is: %d \n", temp->s.student_birth_day);
        printf(" Birth month is: %d \n", temp->s.student_birth_month);
        printf(" Birth year is: %d \n", temp->s.student_birth_year);
        printf(" Score is: %d \n", temp->s.student_lastyear_score);

		temp = temp->next;
	}
}

void insertAtEnd(struct student_data ss) //function to insert at end
{
	struct nodeType *newNode = (struct nodeType*) malloc(sizeof(struct nodeType)); //dynamic allocation of a single block of memory with the size of our node
	//inserting the data in the node
	newNode->s.student_ID=ss.student_ID;
    strcpy(newNode->s.student_name,ss.student_name);
    newNode->s.student_birth_day=ss.student_birth_day;
    newNode->s.student_birth_month=ss.student_birth_month;
    newNode->s.student_birth_year=ss.student_birth_year;
    newNode->s.student_lastyear_score=ss.student_lastyear_score;

	if (length == 0) //if it is the first node to be added in the list
	{
		Head = Tail = newNode;
		newNode->next = NULL;
	}
	else //insert at end
	{
		Tail->next = newNode;
		newNode->next = NULL;
		Tail = newNode;
	}
	length++;
}

void insertAtPosition(int pos, struct student_data ss) //function to insert at any position
{
	if (pos < 0 || pos > length) //pos is the position you want to insert at
		printf(" ERORR \n");
	else
	{
		struct nodeType *newNode = (struct nodeType*) malloc(sizeof(struct nodeType)); //dynamic allocation of a single block of memory with the size of our node
	    //inserting the data in the node
	    newNode->s.student_ID=ss.student_ID;
        strcpy(newNode->s.student_name,ss.student_name);
        newNode->s.student_birth_day=ss.student_birth_day;
        newNode->s.student_birth_month=ss.student_birth_month;
        newNode->s.student_birth_year=ss.student_birth_year;
        newNode->s.student_lastyear_score=ss.student_lastyear_score;

		if (pos == 0) //insert at first
			insertAtFirst(ss);
		else if (pos == length) //insert at end;
			insertAtEnd(ss);
		else
		{
			struct nodeType *temp = Head;
			for (int k = 1; k < pos; k++)
				temp = temp->next;

			newNode->next = temp->next;
		    temp->next = newNode;
			length++;
		}

	}
}

int main()
{
    int n,type;

     //welcome text
    printf("welcome to our project with DR.omar nasr\n");

    // what is the type of data structure to be used
    first:
    printf("what is the type of data structure that will be used\n");
    printf("press 1 to create dynamic array\n");
    printf("press 2 to use linked list\n");
    scanf("%d", &type);

    //use dynamic array
    if(type==1)
        {
        printf("dynamic array\n");
         printf("%s","Enter the number of students at the beginning \n");
    scanf("%d",&p);
int i=0;
    arr_student_data = (struct student_data*)malloc(p*sizeof(struct student_data));
    for ( i = 0; i <= p-1 ; i++)
    {printf("\nEnter details of student %d\n\n", i);
        printf("Enter name: ");
        scanf("%s", arr_student_data[i].student_name);
        printf("Enter ID: ");
        scanf("%d", &arr_student_data[i].student_ID);
        printf("Enter birthday: ");
        scanf("%d", &arr_student_data[i].student_birth_day);
        printf("Enter birth month: ");
        scanf("%d", &arr_student_data[i].student_birth_month);
        printf("Enter birth year: ");
        scanf("%d", &arr_student_data[i].student_birth_year);
        printf("Enter last year score: ");
        scanf("%d", &arr_student_data[i].student_lastyear_score);}
        printf("%s\t%s\t%s\t%s\t%s\t%s\n","Name","ID","Birthday","Birth month","Birth year","Last year score");
        for(int i = 0; i < p; i++ )
    {
        printf("%s\t%d\t%.2d\t%s\t%.2d\t%s\t%.4d\t%s\t%.d\n",
        arr_student_data[i].student_name, arr_student_data[i].student_ID, arr_student_data[i].student_birth_day,"     ", arr_student_data[i].student_birth_month,"     ", arr_student_data[i].student_birth_year, "     ",arr_student_data[i].student_lastyear_score);
    }
end:
printf("%s","if you want to insert more student at any position enter 1\n if you want to insert more student at first enter 2\n if you want to insert more student at last enter 3 ");
    int k;
scanf("%d",&k);
if(k==1)
   {int q;
    printf("%s","enter the position to be insert in");
    scanf("%d",&q);
    insert(q);
   }

else if (k==2)
    insert(0);
else if(k==3)
   insert(p);

   printf("%s","if you want to insert more student enter 1 if not enter 0");
   int u;
scanf("%d",&u);
if(u==1)
   {goto end;}
}

    //use linked list
    else if (type==2)
    {
     struct student_data s1;
            begin:
            printf("Entering the student data \n");

            printf("Enter ID: ");
            scanf("%d", &s1.student_ID);

            printf("Enter name: ");
            scanf("%s", s1.student_name);

            printf("Enter Birth day: ");
            scanf("%d", &s1.student_birth_day);

            printf("Enter Birth month: ");
            scanf("%d", &s1.student_birth_month);

            printf("Enter Birth year: ");
            scanf("%d", &s1.student_birth_year);

            printf("Enter score: ");
            scanf("%d", &s1.student_lastyear_score);

            int choice;
            printf("To insert at First press 1 \n");
            printf("To insert at End press 2 \n");
            printf("To insert at at any position press 3 \n");

            scanf("%d", &choice);

            if (choice==1)
            insertAtFirst(s1);

            else if (choice==2)
            insertAtEnd(s1);

            else if (choice==3)
            { int pos;
            printf("Enter position");
            scanf("%d", &pos);
            insertAtPosition(pos,s1);}

            else
            printf(" ERORR \n");

            int flag;
            printf("To enter another student data press 1 \n");
            printf("To print your linked list press 2 \n");
            printf("To exit press 3 \n");
            scanf("%d", &flag);

            if (flag==1)
            goto begin;

            else if (flag==2)
            printLinkedlist();

            else if (flag==3)
            return 0;


            else
            printf(" ERORR \n");

    return 0;

    }

     // invalid input
    else{
        printf("invalid input!\n");
        goto first;
        }
    return 0;
}

