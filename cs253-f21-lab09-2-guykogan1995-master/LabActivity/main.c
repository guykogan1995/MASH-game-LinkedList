/* 
 * Author: Guy Kogan
 * Date: Friday 29 Oct 2021 06:51:11 PM MT
 * Description: This program runs using linked lists in order
 *    to execute the game MASH and randomize outputs from this linked list
 *    for the user to play the game and have fun.
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#include "DataNode.h"

int main(void) {
   // Here the time value is changed so it is not a constant 1 and values differ
   srand(time(NULL));   
   int toss = rand() % 2;

   // Variables are declared to be used in MASH game.
   char personName[50] = "";
   char marryName[50] = "";
   char livePlace[50] = ""; 
   char occupationVal[50] = "";
   char livePlaceTwo[50] = "";
   char cityPlace[50] = "";
   char activityRand[50] = "";

   // Data values created to be store in Linked lists.
   char *mydata[] = {"mansion", "apartment", "shack", "house"};
   DataNode *listHead = BuildDataList(mydata, 4);
   char *mydataOne[] = {"Robin", "Lily", "Nora", "Patrice", "Zoey", "Quinn"};
   DataNode *listHeadOne = BuildDataList(mydataOne, 6);
   char *mydataTwo[] = {"Ted", "Marshall", "Barney", "Ranjit", "Carl", "Linus"};
   DataNode *listHeadTwo = BuildDataList(mydataTwo, 6);
   char *mydataThree[] = {"teacher", "architect", "lawyer", "newscaster", "undercover agent"};
   DataNode *listHeadThree = BuildDataList(mydataThree, 5);
   char *mydataFour[] = {"walk", "ride the train", "ride a bus", "fly an airplane", "carpool"};
   DataNode *listHeadFour = BuildDataList(mydataFour, 5);
   char *mydataFive[] = {"Cleveland", "Queens", "The Bronx", "Brooklyn", "Manhattan", "Staten Island"};
   DataNode *listHeadFive = BuildDataList(mydataFive, 6);
   
   // Coin toss to generate weather male or femal names will be chosen.
   if(toss == 0){
      strcpy(marryName,GetRandomDataNode(listHeadOne)->dataValue);
   } else {
      strcpy(marryName,GetRandomDataNode(listHeadTwo)->dataValue);
   }
   strcpy(livePlace,GetRandomDataNode(listHead)->dataValue);
   strcpy(occupationVal, GetRandomDataNode(listHeadThree)->dataValue);
   strcpy(livePlaceTwo, GetRandomDataNode(listHead)->dataValue);
   strcpy(cityPlace,GetRandomDataNode(listHeadFive)->dataValue);
   strcpy(activityRand,GetRandomDataNode(listHeadFour)->dataValue);

   // Menu of all possible choices shown to the user before the game begins.
   printf("\n--------------------- Future Possibilities Database ------------------------\n");
   printf("Home List: "); 
   PrintDataList(listHead);
   printf("\nFemale Spouse List: ");
   PrintDataList(listHeadOne);
   printf("\nMale Spouse List: ");
   PrintDataList(listHeadTwo);
   printf("\nOccupation List: ");
   PrintDataList(listHeadThree);
   printf("\nTransportation List: ");
   PrintDataList(listHeadFour);
   printf("\nHometown List: ");
   PrintDataList(listHeadFive);
   printf("\n----------------------------------------------------------------------------\n\n\n");

   // Asks user for name for MASH game and trims last char which is 
   // newline character to be a null character.
   printf("Please enter your name: ");
   fgets(personName, 50, stdin);
   personName[strlen(personName) - 1] = '\0';

   // Prints the game output randomized for fun.
   printf("\n\nWelcome %s, this is your future...\n", personName);
   printf("You will marry %s and live in a %s.\n", marryName, livePlace);
   printf("After 7 years of marriage, you will finally get your dream job of being a %s.\n", occupationVal);
   printf("Your family will move to a %s in the %s where you will %s to work each day.\n\n", livePlaceTwo, cityPlace, activityRand);

   // Cleans up Linked data lists created.
   DestroyDataList(listHead);
   DestroyDataList(listHeadOne);
   DestroyDataList(listHeadTwo);
   DestroyDataList(listHeadThree);
   DestroyDataList(listHeadFour);
   DestroyDataList(listHeadFive);
   return 0;
}
