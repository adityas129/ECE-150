#include <iostream>
using namespace std;

//new data type called Node
//has two parts, an integer and a pointer
struct Node
{
  int value;
  Node * next;
};
void print_nodes(Node * head){
  Node * traverse = head; //head gets the value of linkedin list head

  while (traverse !=NULL){
    cout << traverse-> value << "->";
    traverse = traverse -> next;
  }
}
void add_nodes (int value, Node * head){
  Node * traverse = head;
  while (traverse -> next != NULL){
    traverse = traverse->next;
  }
  Node * new_node = new Node;
  new_node -> value = value;
  new_node -> next = NULL;

  traverse -> next = new_node;
  new_node = NULL;
}

int main (const int argc, const char* argv[]){
  /*
  int a;
  Node node_1;
  node_1.value = 27;

  node_1.next = 27;
  */

  Node * linked_list_head = NULL;
  Node * new_node = new Node;
  new_node -> value = 283;
  new_node -> next = NULL;
  linked_list_head = new_node;
  new_node = NULL;

  new_node = new Node;
  new_node->value = 150;
  new_node -> next = NULL;

  linked_list_head -> next = new_node;
  new_node = NULL;

  print_nodes(linked_list_head);

  new_node = new Node;
  new_node -> value = 115;
  new_node -> next = NULL;

  linked_list_head -> next -> next;

return 0;
}
