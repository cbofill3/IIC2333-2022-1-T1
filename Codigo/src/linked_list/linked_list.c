#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct node {
   pid_t pid;
   char *command;
   time_t run_time;
   struct node *next;
};

static struct node *head = NULL;

void printList() {
   struct node *ptr = head;
   printf("\n PID, COMMAND, RUN TIME\n");

   while(ptr != NULL) {
      printf(" %d, %s, %ld\n", ptr->pid, ptr->command, ptr->run_time);
      ptr = ptr->next;
   }
   printf("====\n");
}

void insertFirst(pid_t pid, char *command) {
   printf("Inserting node with pid %d and command %s\n", pid, command);
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->pid = pid;
   link->command = command;
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
