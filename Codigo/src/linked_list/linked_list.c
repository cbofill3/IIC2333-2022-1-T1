#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <signal.h>
#include "linked_list.h"


int delete(pid_t pid) {
   struct node* current = head;
   struct node* previous = NULL;
   if(head == NULL) {
      return 1;
   }
   while(current->pid != pid) {
      if(current->next == NULL) {
         return 1;
      } else {
         previous = current;
         current = current->next;
      }
   }
   if(current == head) {
      head = head->next;
   } else {
      previous->next = current->next;
   }   
   return 0; 
}


void printList() {
   struct node *ptr = head;
   pid_t end_id;
   printf("\n PID, COMMAND, RUN TIME\n");
   while(ptr != NULL) {
      end_id = waitpid(ptr->pid, NULL, WNOHANG);
      if(end_id == 0){
         time_t end_time = time(NULL);
         printf(" %d, %s, %ld s\n", ptr->pid, ptr->command, end_time - ptr->start_time);  
      }else{
         delete(ptr->pid);
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

int thereIsAnActiveProcess(){
   struct node *ptr = head;
   pid_t end_id;
   while(ptr != NULL) {
      end_id = waitpid(ptr->pid, NULL, WNOHANG);
      if(end_id == 0){
         return 1;
      }
      ptr = ptr->next;
   }
   return 0;
}

void interruptAll(){
   struct node *ptr = head;
   while(ptr != NULL) {
      kill(ptr->pid, SIGINT);
      ptr = ptr->next;
   }
}

void terminateAll() {
   struct node *ptr = head;
   while(ptr != NULL) {
      kill(ptr->pid, SIGKILL);
      ptr = ptr->next;
   }
}