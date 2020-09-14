#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

void print1(struct Contact *c)
{
  printf("Contact id: %s\n",c->phone);
}

void print2(struct Contact *c)
{
  printf("Contact id: %d\n",c->contact_id);
}

void something(void (*f)(struct Contact *),struct Contact *c)
{
  f(c);
}

int main()
{
  struct Contact *c = (struct Contact*)malloc(sizeof(struct Contact));
  c->contact_id = 1234;
  strcpy(c->phone,"8073148425");
  something(&print1,c);
  something(&print2,c);
}