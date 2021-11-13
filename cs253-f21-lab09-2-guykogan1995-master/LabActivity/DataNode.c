/* 
 * File: DataNode.c
 * Author: Guy Kogan
 * Date: Friday 29 Oct 2021 06:50:11 PM MT
 * Description: This is all of the methods referance from DataNode.h
 *    implemented on how they will be run when called.
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "DataNode.h"

DataNode* CreateDataNode(const char data[]){

    if(data == NULL){
        return NULL;
    }
    DataNode *thisNode = (DataNode*)malloc(sizeof(DataNode));
    

    thisNode->nextNodePtr = NULL;
    thisNode->dataSize = strlen(data);

    thisNode->dataValue = (char*)malloc(thisNode->dataSize + 1 * sizeof(char));
    if(thisNode->dataValue == NULL){
        return NULL;
    }
    
    strncpy(thisNode->dataValue, data, thisNode->dataSize);
    thisNode->dataValue[thisNode->dataSize] = '\0';

    return thisNode;
}

int InsertDataNodeAfter(DataNode* nodeInList, DataNode* newNode){
    if(nodeInList == NULL || newNode == NULL){
        return -1;
    }
    newNode->nextNodePtr = nodeInList->nextNodePtr;
    nodeInList->nextNodePtr = newNode;
    return 0;  
}

int SetNextDataNode(DataNode* nodeInList, DataNode* newNode){
    if(nodeInList == NULL){
        printf("Error: Unable to set next PlaylistNode\n");
        return -1;
    }
    nodeInList->nextNodePtr = newNode;
    return 0;
}

DataNode* GetNextDataNode(DataNode* nodeInList){
  if (nodeInList == NULL) {
      return NULL;
   }
   return nodeInList->nextNodePtr;
}

void PrintDataNode(DataNode* thisNode){
if(thisNode == NULL){
        return;
    }
    printf("\n%s\n", thisNode->dataValue);
    return;   
}

DataNode* BuildDataList(char * data[], int numElements){
    if(numElements <= 0){
        return NULL;
    }
    DataNode* tmpNode[numElements];
    tmpNode[0] = CreateDataNode(data[0]);
    DataNode* newNode;
    
    for(int i = 1; i < numElements; i++){
        newNode = CreateDataNode(data[i]);
        tmpNode[i] = newNode;
        InsertDataNodeAfter(tmpNode[i-1], newNode);
    }
    if(tmpNode[0] == NULL){
        return NULL;
    }
    return tmpNode[0];
}

int GetDataListSize(DataNode* listHead){
    if(listHead == NULL){
        return -1;
    }
    int i = 1;
    while(listHead->nextNodePtr != NULL){
        i++;
        listHead = GetNextDataNode(listHead);
    }
    return i;
}

void PrintDataList(DataNode *listHead){
    if(listHead == NULL){
        return;
    }
    while(listHead->nextNodePtr != NULL){
        printf("%s, ", listHead->dataValue);
        listHead = GetNextDataNode(listHead);
        if(listHead->nextNodePtr == NULL){
            printf("%s", listHead->dataValue);
        }
    }
}

DataNode* GetRandomDataNode(DataNode *listHead){
    if(listHead == NULL){
        return NULL;
    }
    int randNode = 0;
    int i = 0;
    int listSize = GetDataListSize(listHead);
    randNode = rand()%listSize;
    if(randNode < 0 || randNode > listSize){
        return NULL;
    }
    if (randNode == 0){
        return listHead;
    }
    while(listHead != NULL){
        i++;
        listHead = GetNextDataNode(listHead);
        if(i == randNode){
            break;
        }
    }
    return listHead;
}

void DestroyDataNode(DataNode* thisNode){
    if(thisNode == NULL){
        return;
    }
    if(thisNode->dataValue != NULL){
    free(thisNode->dataValue);
    }
    free(thisNode);
}

void DestroyDataList(DataNode* listHead){
    DataNode* tmpNode = listHead;

    while (listHead != NULL) {
        listHead = listHead->nextNodePtr;
        DestroyDataNode(tmpNode);
        tmpNode = listHead;
    }     
    
}