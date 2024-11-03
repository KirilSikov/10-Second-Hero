#include <stdio.h>
#include <osbind.h>
#include <stdlib.h>
 
#define MAX 7
#define MIN 0
#define RAND_KEY 69
 
 /*note that the function assumes that
 srand() has been seeded*/
int calcRand(int oldNum);

int calcRand(int oldNum){
	int randNum = rand() % (MAX + 1 - MIN) + MIN;
	/*Make sure new number is different to old number*/
	while(randNum == oldNum){
		randNum = rand() % (MAX + 1 - MIN) + MIN;
	}
	return randNum;
}