/**
* (The program has a method called termination and count how many iterations
* the function does and displays it to the user.)
*
* Completion time: (20 minutes)
*
* @author (Jayme Rutkoski), (Acuna)
* @version (10/12/2018)
*/

#include <stdio.h>
int termination(int n){
    int count = 0;
    while(n != 1){
        if(n % 2){
            n = 3 * n + 1;
            count++;
        }
        else{
            n = n/2;
            count++;
        }
    }
    return count;
}

/*int main(void) {
    int num;
    printf("Enter any positive whole number: ");
    scanf("%d", &num);
    printf("Number of iterations: %d", termination(num));
    return (0);
}
 * */

