/**
* (The program takes an amount of encrypted chunks and then sorts them via
* by the first character of the chunk and then decrypts each chunk based
* on the decryption shift defined.)
*
* Completion time: (1 hour)
*
* @author (Jayme), (Acuna)
* @version (10/14/2018)
*/

////////////////////////////////////////////////////////////////////////////////
//INCLUDES
#include <stdio.h>
#include <string.h>

//macros: constants
#define CHUNK_LENGTH (20+1)  //each chunk has twenty characters, we add 1 so
                           //there is space for the null terminator.
#define NUMBER_OF_CHUNKS 4 //the message is spread across 4 chunks.
#define DECRYPTION_SHIFT 5 //this is the ASCII table shift used for decryption.

//forward declarations
void sort_chunks();
void decrypt_chunks();
void display_chunks();

char chunks[NUMBER_OF_CHUNKS][CHUNK_LENGTH];

int main() {
	//copy message into memory.
	strcpy(chunks[0], "2i1%fsi%fs%jstwrtzx%");
	strcpy(chunks[1], "1'H%nx%vznwp~1%kqf|j");
	strcpy(chunks[2], "4R3%Wnyhmnj%%%%%%%%%");
	strcpy(chunks[3], "3xzhhjxx3'%2%Ijssnx%");

	//the format of a chunk is a single number indicating its order in overall
	//message followed by twenty encrypted characters.


	//reorder chunks in message by sorting them based on the first digital
	//they contain. looking above, one can see they are currently in the order
	//2, 1, 4, 3 but should be ordered 1, 2, 3, 4.
	sort_chunks();

	//shift the characters in the message to produce the original characters.
	decrypt_chunks();

	//display the decrypted message.
	display_chunks();


	return 0; 
}

//given two strings, swaps their contents in memory.
void swap_strings(char* x, char* y) {
	//create a temporary holding place for the data so we don't lose it.
	char temp[CHUNK_LENGTH];

	strcpy(temp, x);
	strcpy(x, y);////////////////////////////////////////////////////////////////////////////////
//INCLUDES
	strcpy(y, temp);
}
////////////////////////////////////////////////////////////////////////////////
//INCLUDES
//sorts the strings the global chunks variable by the first character they contain.
void sort_chunks() {
	//TODO: Implement sort_chunks(). Using your favorite sorting algorithm (we
	//      suggest selection sort), sort the array containing the message chunks.
	//      Sort based on the first character in the chunk - it will always be a
	//      number. We provide a swap_strings function that you may use. Example
        //      usage: swap_strings(chunks[0], chunks[1]) will swap the contents of
	//      the first and second string.
    int i, j;
    char* message;
    char* message2;
    for(i = 0; i < NUMBER_OF_CHUNKS; i++){
        message = chunks[i];
        for(j = i + 1; j < NUMBER_OF_CHUNKS; j++){
            message2 = chunks[j];
            if(message[0] > message2[0]){
                swap_strings(chunks[j], chunks[i]);
            }
        }
    }
}

//for each string in the global chunks variable, shifts the characters in it by
//DECRYPTION_SHIFT.
void decrypt_chunks() {

    int i, j;
    char* pointer;
    for(i = 0; i < NUMBER_OF_CHUNKS; i++){
        pointer = chunks[i];
        for(j = 1; j < CHUNK_LENGTH - 1; j++){
            pointer[j] -= DECRYPTION_SHIFT;
        }
    }
}


//displays the strings in the global chunks variable
void display_chunks() {
	//TODO: Implement display_chunks(). Loop over each string in the array of
	//      message chunks (strings) and print it. Do not print the first
	//      character in each string since it is only used to store the order of
	//      the chunks. (Hint: use pointer arithmetic to skip a character.)
    int i, j, count = 0;
    char* message;
    while(count != NUMBER_OF_CHUNKS){
        message = chunks[count];
        for(i = 1; i < CHUNK_LENGTH - 1; i++){
            printf("%c", message[i]);
        }
        count++;
    }
}