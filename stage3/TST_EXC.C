#include "model.h"
#include "event.h"

int main()
{
	int platformCollisionOrNo;
	bool airborne;
	bool collisionCheck;
	bool topCheck;
	bool botCheck;
	bool rightCheck;
	bool leftCheck;
	struct Model test10SecondHero;
	initModel(&test10SecondHero);


	

	/* This tests the playerRun function. WORKS.
	printf("player x: %u \n", test10SecondHero.player.x);
	playerRun(&test10SecondHero.player);
	printf("new player x: %u \n", test10SecondHero.player.x);
	
	/* This tests the crystalMove function, WORKS
 	printf("crystal x: %u \n", test10SecondHero.crystal.x);
	moveCrystal(&test10SecondHero.crystal, 13, 27);
	printf("new crystal x: %u \n", test10SecondHero.crystal.x);
	
	/* This tests the decreaseTime function, WORKS
 	printf("timer time: %u \n", test10SecondHero.timeLeft.wholeSecs);
	decreaseTime(&test10SecondHero.timeLeft);
	printf("new timer time: %u \n", test10SecondHero.timeLeft.wholeSecs);
	
	/* This tests the increaseTime function, WORKS
 	printf("timer time: %u \n", test10SecondHero.timeLeft.wholeSecs);
	increaseTime(&test10SecondHero.timeLeft);
	printf("new timer time: %u \n", test10SecondHero.timeLeft.wholeSecs);
	
	/* This tests the increaseScore function, WORKS
 	printf("score amt: %u \n", test10SecondHero.score.scoreAmnt);
	increaseScore(&test10SecondHero.score);
	printf("new score amt: %u \n", test10SecondHero.score.scoreAmnt);
	
	yeah = isTimer0(test10SecondHero);
	printf("timer is 0? %i\n", yeah);
	
	 
	printf("crystal x before rand spawn:%u\n", test10SecondHero.crystal.x);
	printf("crystal y before rand spawn:%u\n", test10SecondHero.crystal.y);
	crystalRandomSpawn(&test10SecondHero.crystal);
	printf("crystal x before rand spawn:%u\n", test10SecondHero.crystal.x);
	printf("crystal y before rand spawn:%u\n", test10SecondHero.crystal.y);
	*/
	
	
	printf("platform top left y%u\n", test10SecondHero.platforms[0].hitbox.topLeftY);
	printf("platform bottom right y%u\n", test10SecondHero.platforms[0].hitbox.bottomRightY);
	printf("platform top left x%u\n", test10SecondHero.platforms[0].hitbox.topLeftX);
	printf("platform bottom right x%u\n", test10SecondHero.platforms[0].hitbox.bottomRightX);
		
	printf("player top left y %u\n",
		test10SecondHero.player.hitbox.topLeftY);	
	printf("player bottom right y %u\n",
		test10SecondHero.player.hitbox.bottomRightY);
	printf("player top left x %u\n",
		test10SecondHero.player.hitbox.topLeftX);	
	printf("player bottom right x %u\n",
		test10SecondHero.player.hitbox.bottomRightX);
	
	platformCollisionOrNo = platformCollisionsCheck(test10SecondHero);
	
	collisionCheck = collision(test10SecondHero.player.hitbox, 
		test10SecondHero.platforms[0].hitbox);
	
	topCheck = collideTopOfPlatform(test10SecondHero.player.hitbox, 
		test10SecondHero.platforms[0].hitbox);
		
	botCheck = collideBottomOfPlatform(test10SecondHero.player.hitbox, 
		test10SecondHero.platforms[0].hitbox);
	
	rightCheck = collideRightOfPlatform(test10SecondHero.player.hitbox, 
		test10SecondHero.platforms[0].hitbox);
		
	leftCheck = collideLeftOfPlatform(test10SecondHero.player.hitbox, 
		test10SecondHero.platforms[0].hitbox);
		
	airborne = airborneCheck(test10SecondHero);

	printf("collision happened?%i\n", collisionCheck);
	printf("player hit top of platform?%i\n", topCheck);
	printf("player hit bottom of platform?%i\n", botCheck);
	printf("player hit right of platform?%i\n", rightCheck);
	printf("player hit left of platform?%i\n", leftCheck);
	printf("the platform collided with:%i\n", platformCollisionOrNo);
	printf("is player airborne? :%i\n", airborne);
	
	printf("\n\n");
	
	playerFall(&test10SecondHero);
	printf("PLAYER FELL 1\n\n");
	playerJump(&test10SecondHero);
	playerFall(&test10SecondHero);
	printf("PLAYER FELL 2\n\n");
	playerFall(&test10SecondHero);
	printf("PLAYER FELL 3\n\n");
	playerFall(&test10SecondHero);
	printf("PLAYER FELL 4\n\n");
	playerFall(&test10SecondHero);
	printf("PLAYER FELL 5\n\n");	
	playerFall(&test10SecondHero);
	printf("PLAYER FELL 6\n\n");
	playerFall(&test10SecondHero);
	printf("PLAYER FELL 7\n\n");
	playerFall(&test10SecondHero);
	printf("PLAYER FELL 8\n\n");
	playerFall(&test10SecondHero);
	printf("PLAYER FELL 9\n\n");
	playerFall(&test10SecondHero);
	printf("PLAYER FELL 10\n\n");

	airborne = airborneCheck(test10SecondHero);
	platformCollisionOrNo = platformCollisionsCheck(test10SecondHero);
	collisionCheck = collision(test10SecondHero.player.hitbox, 
		test10SecondHero.platforms[0].hitbox);
	
	topCheck = collideTopOfPlatform(test10SecondHero.player.hitbox, 
		test10SecondHero.platforms[0].hitbox);
		
	botCheck = collideBottomOfPlatform(test10SecondHero.player.hitbox, 
		test10SecondHero.platforms[0].hitbox);
	
	rightCheck = collideRightOfPlatform(test10SecondHero.player.hitbox, 
		test10SecondHero.platforms[0].hitbox);
		
	leftCheck = collideLeftOfPlatform(test10SecondHero.player.hitbox, 
		test10SecondHero.platforms[0].hitbox);
		
	airborne = airborneCheck(test10SecondHero);

	printf("collision happened?%i\n", collisionCheck);
	printf("player hit top of platform?%i\n", topCheck);
	printf("player hit bottom of platform?%i\n", botCheck);
	printf("the platform collided with:%i\n", platformCollisionOrNo);
	printf("is player airborne? :%i\n", airborne);
    return 0; 
}

