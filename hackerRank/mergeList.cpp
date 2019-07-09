
/*
 * Author: Rambabu Yerajana
 * Text:   HackerRank 
 * Topic:  Puzzle 
 * Statement: Merge linked List 
 * Description: Merge linked List 
 * */

#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
  public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data) {
      this->data = node_data;
      this->next = nullptr;
    }
};

class SinglyLinkedList {
  public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList() {
      this->head = nullptr;
      this->tail = nullptr;
    }

    void insert_node(int node_data) {
      SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

      if (!this->head) {
        this->head = node;
      } else {
        this->tail->next = node;
      }

      this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
  while (node) {
    fout << node->data;

    node = node->next;

    if (node) {
      fout << sep;
    }
  }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
  while (node) {
    SinglyLinkedListNode* temp = node;
    node = node->next;

    free(temp);
  }
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

  if(!head1) return head2;
  if(!head2) return head1;

  SinglyLinkedListNode *dummy = nullptr;
  SinglyLinkedListNode *result = nullptr;

  while( head1 && head2 ){
    if(head1->data <= head2->data){
      if(!dummy){dummy=head1;result=head1;} 
      else {dummy->next = head1;}
      dummy = head1;
      head1=head1->next;
    }
    else{
      if(!dummy){dummy=head2;result=head2;}
      else dummy->next = head2;
      dummy = head2;
      head2=head2->next;
    }
  }
  dummy->next= head1 ? head1 : head2;
  return result;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int tests;
  cin >> tests;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
    SinglyLinkedList* llist1 = new SinglyLinkedList();

    int llist1_count;
    cin >> llist1_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist1_count; i++) {
      int llist1_item;
      cin >> llist1_item;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      llist1->insert_node(llist1_item);
    }

    SinglyLinkedList* llist2 = new SinglyLinkedList();

    int llist2_count;
    cin >> llist2_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist2_count; i++) {
      int llist2_item;
      cin >> llist2_item;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      llist2->insert_node(llist2_item);
    }

    SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

    print_singly_linked_list(llist3, " ", fout);
    fout << "\n";

    free_singly_linked_list(llist3);
  }

  fout.close();

  return 0;
}
