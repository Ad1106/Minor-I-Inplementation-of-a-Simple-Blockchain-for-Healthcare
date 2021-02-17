#include<stdlib.h>
#include<openssl/crypto.h>
#include<string.h>
#include<stdio.h>
#define SHA256_DIGEST_LENGTH 32
struct block
{
    unsigned char prevHash[SHA256_DIGEST_LENGTH];
    unsigned char Hash[SHA256_DIGEST_LENGTH];
    char blockData[1000];
    struct block *link;
};
struct block* head=NULL;

void addBlock(char[]);
void alterNthBlock(int,int);
int hashCompare(unsigned char*, unsigned char*);
void hashPrinter();
unsigned char* toString(struct block);
void printBlock();
void printAllBlocks();
//SHA256(src,size,dest)
//src and dest are of type of unsigned char *
void addBlock(char data[])
{   
	//Allocate new node
	struct block* newBlock = (struct block*)malloc (sizeof(struct block));
	
	struct block* last = head;
	
	strcpy(newBlock->blockData,data);
	newBlock->link = NULL;
	
    if(head==NULL)
    {
	
        head = newBlock;
        SHA256("",sizeof(""),head->prevHash);
        return;
    }
    
    
    while(last -> link != NULL)
        last = last->link;
        
    last->link = newBlock;

    SHA256(last->Hash,sizeof(last->Hash),newBlock->prevHash);
}

void verifyChain()
{
    if(head==NULL)
    {
        printf("Hey, Blockchain is empty! Please try after adding some block !\n");
        return;
    }
    else 
    printf("\nAdarsh's Blockchain is valid !!\n\n");
}

unsigned char* toString(struct block b)
{
    unsigned char *str=malloc(sizeof(unsigned char)*sizeof(b));
    memcpy(str,&b,sizeof(b));
    return str;
}
void hashPrinter(unsigned char hash[], int length)
{
    for(int i=0; i<length; i++)
        printf("%02x",hash[i]);
}
int hashCompare(unsigned char *str1, unsigned char *str2)
{
    for(int i=0;i<SHA256_DIGEST_LENGTH;i++)
        if(str1[i]!=str2[i])
            return 0;
    return 1;
}
void printBlock(struct block *b)
{
    char z;
    //printf("%p\t",b);                                     //address of this particular block
    hashPrinter(b->prevHash, sizeof(b->prevHash));        //hash value of previous block hash
    printf("\t");
    printf("%p%p%p%p%p%p\t",b,b,b,b,b,b);    
	/*printf("Basically, Blockchain does not allow to show the data stored in Blockchain but here we demonstrate the backend process of a blockchain network so if you see the data for varification purpose than press 'Y' otherwise press 'N'\n");
	scanf("%c",&z);
	switch(z)
	{
		case 'Y':
			printf("\t[%s]\t",b->blockData);
			break;
		case 'N':
			break;
	}*/
	printf("%p\n",b->link);
}
void printAllBlocks()
{
    struct block *curr=head;
    int count=0;
    while(curr)
    {
        printBlock(curr);
        curr = curr->link;
    }
}
void main()
{
    printf("\n\n\n        *******************************************************************************\n");
    printf("        ***                                                                         ***\n");
    printf("        ***  Minor Project : Implementation of Blockchain Network in C programming  ***\n");
    printf("        ***                                                                         ***\n");
    printf("        *******************************************************************************\n\n");
    int c,n,r,id;
    char name[100],test[100],status[100],cc[1000];
    FILE *fptr,*fptr1;
    while(1)
    {   printf("\n\nPRESS\n1: Add a new block Block\n2: Add n numbers of blocks in chain\n3: Print all block connection in blockchain\n4: Check Validity of Blockchain\n5: EXIT\n\n");
        printf("\n\nChoice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("We have list of specialist doctors list in various department\nChoose any 1 department to create block");
		printf("\n1. Pediatricians\n2. General Surgeon\n3. Cardiologist\n4. Dentist\n5. Dermatologists\n6. Gynecologist\n7. ENT Specialist\n\n");
	        scanf("%d",&n);
		switch(n)
		{
			case 1:
				fptr = fopen("Pediatricians.txt", "a");
    				if ((fptr = fopen("Pediatricians.txt", "a")) == NULL) 
				{
        				printf("Error! opening file");
        					exit(1);
    				}
				printf("Enter the Patient ID, Name, Test name and status of patient");
				scanf("%d%s%s%s",&id,name,test,status);
				fprintf(fptr, "%d\t%s\t%s\t%s\n", id,name,test,status);
    				fclose(fptr);
				fptr1 = fopen("Pediatricians.txt", "r");
				fseek( fptr1, -19, SEEK_END );
				fscanf(fptr1,"%[^\n]", cc);
				printf("=> %s",cc);
				addBlock(cc);	
    				fclose(fptr1);
			break;
			case 2:
    				fptr = fopen("Surgeon.txt", "a");
    				if ((fptr = fopen("Surgeon.txt", "a")) == NULL) 
				{
        				printf("Error! opening file");
        					exit(1);
    				}
				printf("Enter the Patient ID, Name, Test name and status of patient");
				scanf("%d%s%s%s",&id,name,test,status);
				fprintf(fptr, "%d\t%s\t%s\t%s\n", id,name,test,status);
    				fclose(fptr);
				fptr1 = fopen("Surgeon.txt", "r");
				fseek( fptr1, -19, SEEK_END );
				fscanf(fptr1,"%[^\n]", cc);
				printf("=> %s",cc);
				addBlock(cc);	
    				fclose(fptr1);
			break;
			case 3:
    				fptr = fopen("Cardiologist.txt", "a");
    				if ((fptr = fopen("Cardiologist.txt", "a")) == NULL) 
				{
        				printf("Error! opening file");
        					exit(1);
    				}
				printf("Enter the Patient ID, Name, Test name and status of patient");
				scanf("%d%s%s%s",&id,name,test,status);
				fprintf(fptr, "%d\t%s\t%s\t%s\n", id,name,test,status);
    				fclose(fptr);
				fptr1 = fopen("Cardiologist.txt", "r");
				fseek( fptr1, -19, SEEK_END );
				fscanf(fptr1,"%[^\n]", cc);
				printf("=> %s",cc);
				addBlock(cc);	
    				fclose(fptr1);
			break;
			case 4:
    				fptr = fopen("Dentist.txt", "a");
    				if ((fptr = fopen("Dentist.txt", "a")) == NULL) 
				{
        				printf("Error! opening file");
        					exit(1);
    				}
				printf("Enter the Patient ID, Name, Test name and status of patient");
				scanf("%d%s%s%s",&id,name,test,status);
				fprintf(fptr, "%d\t%s\t%s\t%s\n", id,name,test,status);
    				fclose(fptr);
				fptr1 = fopen("Dentist.txt", "r");
				fseek( fptr1, -19, SEEK_END );
				fscanf(fptr1,"%[^\n]", cc);
				printf("=> %s",cc);
				addBlock(cc);	
    				fclose(fptr1);
			break;
			case 5:
    				fptr = fopen("Dermatologists.txt", "a");
    				if ((fptr = fopen("Dermatologists.txt", "a")) == NULL) 
				{
        				printf("Error! opening file");
        					exit(1);
    				}
				printf("Enter the Patient ID, Name, Test name and status of patient");
				scanf("%d%s%s%s",&id,name,test,status);
				fprintf(fptr, "%d\t%s\t%s\t%s\n", id,name,test,status);
    				fclose(fptr);
				fptr1 = fopen("Dermatologists.txt", "r");
				fseek( fptr1, -19, SEEK_END );
				fscanf(fptr1,"%[^\n]", cc);
				printf("=> %s",cc);
				addBlock(cc);	
    				fclose(fptr1);
			break;
			case 6:
				fptr = fopen("Gynecologist.txt", "a");
    				if ((fptr = fopen("Gynecologist.txt", "a")) == NULL) 
				{
        				printf("Error! opening file");
        					exit(1);
    				}
				printf("Enter the Patient ID, Name, Test name and status of patient");
				scanf("%d%s%s%s",&id,name,test,status);
				fprintf(fptr, "%d\t%s\t%s\t%s\n", id,name,test,status);
    				fclose(fptr);
				fptr1 = fopen("Gynecologist.txt", "r");
				fseek( fptr1, -19, SEEK_END );
				fscanf(fptr1,"%[^\n]", cc);
				printf("=> %s",cc);
				addBlock(cc);	
    				fclose(fptr1);
			break;
			case 7:
    				fptr = fopen("ENT.txt", "a");
    				if ((fptr = fopen("ENT.txt", "a")) == NULL) 
				{
        				printf("Error! opening file");
        					exit(1);
    				}
				printf("Enter the Patient ID, Name, Test name and status of patient");
				scanf("%d%s%s%s",&id,name,test,status);
				fprintf(fptr, "%d\t%s\t%s\t%s\n", id,name,test,status);
    				fclose(fptr);
				fptr1 = fopen("ENT.txt", "r");
				fseek( fptr1, -19, SEEK_END );
				fscanf(fptr1,"%[^\n]", cc);
				printf("=> %s",cc);
				addBlock(cc);	
    				fclose(fptr1);
			break;
		}
                
		printf("\n1 Block added in Blockchain successfully"); 
                break;
            case 2:
                printf("How many blocks , you want to add in chain? : ");
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                {
		    printf("\n\nWe have list of specialist doctors list in various department\nChoose any 1 department to create block");
		printf("\n1. Pediatricians\n2. General Surgeon\n3. Cardiologist\n4. Dentist\n5. Dermatologists\n6. Gynecologist\n7. ENT Specialist\n\n");
	        scanf("%d",&n);
		switch(n)
		{
			case 1:
				fptr = fopen("Pediatricians.txt", "a");
    				if ((fptr = fopen("Pediatricians.txt", "a")) == NULL) 
				{
        				printf("Error! opening file");
        					exit(1);
    				}
				printf("Enter the Patient ID, Name, Test name and status of patient");
				scanf("%d%s%s%s",&id,name,test,status);
				fprintf(fptr, "%d\t%s\t%s\t%s\n", id,name,test,status);
    				fclose(fptr);
				fptr1 = fopen("Pediatricians.txt", "r");
				fseek( fptr1, -19, SEEK_END );
				fscanf(fptr1,"%[^\n]", cc);
				printf("=> %s",cc);
				addBlock(cc);	
    				fclose(fptr1);
			break;
			case 2:
    				fptr = fopen("Surgeon.txt", "a");
    				if ((fptr = fopen("Surgeon.txt", "a")) == NULL) 
				{
        				printf("Error! opening file");
        					exit(1);
    				}
				printf("Enter the Patient ID, Name, Test name and status of patient");
				scanf("%d%s%s%s",&id,name,test,status);
				fprintf(fptr, "%d\t%s\t%s\t%s\n", id,name,test,status);
    				fclose(fptr);
				fptr1 = fopen("Surgeon.txt", "r");
				fseek( fptr1, -19, SEEK_END );
				fscanf(fptr1,"%[^\n]", cc);
				printf("=> %s",cc);
				addBlock(cc);	
    				fclose(fptr1);
			break;
			case 3:
    				fptr = fopen("Cardiologist.txt", "a");
    				if ((fptr = fopen("Cardiologist.txt", "a")) == NULL) 
				{
        				printf("Error! opening file");
        					exit(1);
    				}
				printf("Enter the Patient ID, Name, Test name and status of patient");
				scanf("%d%s%s%s",&id,name,test,status);
				fprintf(fptr, "%d\t%s\t%s\t%s\n", id,name,test,status);
    				fclose(fptr);
				fptr1 = fopen("Cardiologist.txt", "r");
				fseek( fptr1, -19, SEEK_END );
				fscanf(fptr1,"%[^\n]", cc);
				printf("=> %s",cc);
				addBlock(cc);	
    				fclose(fptr1);
			break;
			case 4:
    				fptr = fopen("Dentist.txt", "a");
    				if ((fptr = fopen("Dentist.txt", "a")) == NULL) 
				{
        				printf("Error! opening file");
        					exit(1);
    				}
				printf("Enter the Patient ID, Name, Test name and status of patient");
				scanf("%d%s%s%s",&id,name,test,status);
				fprintf(fptr, "%d\t%s\t%s\t%s\n", id,name,test,status);
    				fclose(fptr);
				fptr1 = fopen("Dentist.txt", "r");
				fseek( fptr1, -19, SEEK_END );
				fscanf(fptr1,"%[^\n]", cc);
				printf("=> %s",cc);
				addBlock(cc);	
    				fclose(fptr1);
			break;
			case 5:
    				fptr = fopen("Dermatologists.txt", "a");
    				if ((fptr = fopen("Dermatologists.txt", "a")) == NULL) 
				{
        				printf("Error! opening file");
        					exit(1);
    				}
				printf("Enter the Patient ID, Name, Test name and status of patient");
				scanf("%d%s%s%s",&id,name,test,status);
				fprintf(fptr, "%d\t%s\t%s\t%s\n", id,name,test,status);
    				fclose(fptr);
				fptr1 = fopen("Dermatologists.txt", "r");
				fseek( fptr1, -19, SEEK_END );
				fscanf(fptr1,"%[^\n]", cc);
				printf("=> %s",cc);
				addBlock(cc);	
    				fclose(fptr1);
			break;
			case 6:
				fptr = fopen("Gynecologist.txt", "a");
    				if ((fptr = fopen("Gynecologist.txt", "a")) == NULL) 
				{
        				printf("Error! opening file");
        					exit(1);
    				}
				printf("Enter the Patient ID, Name, Test name and status of patient");
				scanf("%d%s%s%s",&id,name,test,status);
				fprintf(fptr, "%d\t%s\t%s\t%s\n", id,name,test,status);
    				fclose(fptr);
				fptr1 = fopen("Gynecologist.txt", "r");
				fseek( fptr1, -19, SEEK_END );
				fscanf(fptr1,"%[^\n]", cc);
				printf("=> %s",cc);
				addBlock(cc);	
    				fclose(fptr1);
			break;
			case 7:
    				fptr = fopen("ENT.txt", "a");
    				if ((fptr = fopen("ENT.txt", "a")) == NULL) 
				{
        				printf("Error! opening file");
        					exit(1);
    				}
				printf("Enter the Patient ID, Name, Test name and status of patient");
				scanf("%d%s%s%s",&id,name,test,status);
				fprintf(fptr, "%d\t%s\t%s\t%s\n", id,name,test,status);
    				fclose(fptr);
				fptr1 = fopen("ENT.txt", "r");
				fseek( fptr1, -19, SEEK_END );
				fscanf(fptr1,"%[^\n]", cc);
				printf("=> %s",cc);
				addBlock(cc);	
    				fclose(fptr1);
			break;
                }}
	        printf("\n\n%d blocks added in Blockchain Successfully",n);
                break;
            case 3:
		printf("\nParameters of Blocks : \n");
                printAllBlocks();
                break;
            case 4:
                verifyChain();
                break;
	    case 5:
		printf("Yoo !  \nSo this the time to terminate the program. BYE\n\n");
		exit(1);   
            default:
                printf("Wrong choice !\nPlease try again\n");
                break;
        }
    }
}



