#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    if (!nd) os << "nullptr";
    else {
        os << "data: " << nd->data << " next: ";
    }
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
    if (!head) {
        head = new Node(d, nullptr);
    }
    else {
        add_at_end(head->next, d);
    }
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* head) {
    os << head;
    if (head) print_list(os, head->next);
    else os << endl;
}


/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
    head = new Node(d, head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    if (!head) return nullptr;
    else if (!head->next) return head;
    else return last(head->next);
}


/*
 * Delete the first node and set head to firstnode->next.
 * De-allocate the memory for the node deleted.
 * */
bool del_head(Node*& head) {
    if (!head) return false;
    else {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
}


/*
 * Delete the last node and set prev->next to nullptr.
 * De-allocate the memory for the node deleted.
 * */
bool del_tail(Node*& curr) {
    if (!curr) return false;
    else {
        if (curr->next == nullptr) {
            delete curr;
            curr = nullptr;
            return true;
        }
        else {
            return del_tail(curr->next);
        }
    }
}


/*
 * Duplicate the entire list -- you must not share memory!
 * */
Node* duplicate(Node* head) {
    if (!(head->next)) return new Node(head->data,nullptr);
    else {
        Node* new_head = new Node(head->data,nullptr);
        Node* cursor = head->next;
        while (cursor) {
            add_at_end(new_head, cursor->data);
            cursor = cursor->next;
        }
        return new_head;
    }
}

/*
 * Reverse the list: return a brand new list with everything reversed.
 * Once again, you must not share memory.
 * */
Node* reverse(Node* curr, Node* new_next) {
    if (!curr) return new_next;
    else {
        return reverse(curr->next, new Node(curr->data, new_next));
    }
}

Node* join(Node*& list1, Node* list2) {
    Node* joined_lst = new Node(list1->data,nullptr);
    Node* cursor = list1->next;
    while (cursor) {
        add_at_end(joined_lst, cursor->data);
        cursor = cursor->next;
    }
    Node* cursor2 = list2;
    while (cursor2) {
        add_at_end(joined_lst, cursor2->data);
        cursor2 = cursor2->next;
    }
    return joined_lst;
    
}


