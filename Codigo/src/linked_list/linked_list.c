#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include "linked_list.h"



void printList() {
   struct node *ptr = head;
   pid_t end_id;
   printf("\n PID, COMMAND, RUN TIME\n");
   while(ptr != NULL) {
      end_id = waitpid(ptr->pid, NULL, WNOHANG);
      if(end_id == 0){
         time_t end_time = time(NULL);
         printf(" %d, %s, %ld s\n", ptr->pid, ptr->command, end_time - ptr->start_time);  
      }
      ptr = ptr->next;
   }
   printf("====\n");
}

void insertFirst(pid_t pid, char *command, time_t start_time) {
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->pid = pid;
   link->command = command;
   link->start_time = start_time;
   link->next = head;
   head = link;
}

struct node* find( pid_t pid) {

   struct node* current = head;
   if(head == NULL) {
      return NULL;
   }
   while(current->pid != pid) {
      if(current->next == NULL) {
         return NULL;
      } else {
         current = current->next;
      }
   }      
   return current;
}
