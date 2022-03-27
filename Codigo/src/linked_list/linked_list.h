#pragma once

struct node {
   pid_t pid;
   char *command;
   time_t start_time;
   struct node *next;
};

static struct node *head = NULL;
int delete(pid_t pid);
void printList();
void insertFirst(pid_t pid, char *command, time_t start_time);
int thereIsAnActiveProcess();
void interruptAll();
void terminateAll(); 