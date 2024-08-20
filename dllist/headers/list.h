
/*
 * CIRCULAR DOUBLY LINKED LIST
 * Implementation of a circular doubly linked list with a sentinel node.
 *
 * Copyright (C) 2024, Rico Morasata.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * DISCLAIMER OF LIABILITY
 *
 * THIS SOFTWARE IS PROVIDED BY RICO MORASATA "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL RICO MORASATA BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>


/**
 * API for a circular doubly linked list with a sentinel node, 
 * adapted from the CS140 lecture of the Min H. Kao Department of Electrical Engineering and
 * Computer Science at the University of Kentucky:
 * web.eecs.utk.edu/~bvanderz/teaching/cs140Fa10/notes/Dllists
 * 
 * This approach precludes the need for head and tail pointers, as is usually the case in 
 * linked list implementations. As a result, the implementation is not only simpler but also
 * cheaper since only the sentinel is required.*/

/**
 * Checks whether the resource has been properly allocated. 
 * If not, the program will terminate.*/
#define IS_POINTER_VALID(ptr) 													\
	if (ptr == NULL) {															\
		fprintf(stderr, "%s", "Memory allocation failed, aborting...\n");		\
		exit(EXIT_FAILURE);														\
	}	

/**
 * Node definition*/
typedef struct Node {
	struct Node 	*prev, *next;
	void 			*data;
}Node;


/**
 * Circular doubly linked list definition.
 * The list also keeps track of its size.*/
typedef struct DLList {
	Node 	*sentinel;
	size_t 	list_size;
}DLList;


/**
 * Below are the operations supported by this data structure:*/

/**
 * Creates a new node*/
Node 	*create_new_node(void *data);

/**
 * Allocates and returns a new list*/
DLList	*create_new_list();


/**
 * Inserts a new node before the specified one.*/
void 	insert_node_before(DLList *list, Node *curr_node, void *val);


/**
 * Inserts a new node before the specified one.*/
void 	insert_node_after(DLList *list, Node *curr_node, void *val);


/**
 * Adds a new node at the beginning of the list.*/
void 	prepend_node(DLList *list, void *data);

/**
 * Adds a new node at the end of the list.*/
void 	append_node(DLList *list, void *data);


size_t 	get_list_size(DLList *list);

/**
 * @return 1 if the list is empty, 0 otherwise.*/
int 	is_list_empty(DLList *list);


void 	delete_node(DLList *list, Node *curr_node);

/**
 * @return 	pointer to the sentinel node.*/
Node 	*get_sentinel_node(DLList *list);

/**
 * @return pointer to the first node in the list.
 * If the list is empty, returns a pointer to the sentinel.*/
Node 	*get_first_node(DLList *list);


/**
 * @return pointer to the last node in the list.
 * If the list is empty, returns a pointer to the sentinel.*/
Node 	*get_last_node(DLList *list);

/**
 * @return pointer to the previous node in the list before curr_node.
 * If curr_node is the first node in the list, returns a pointer to the sentinel.*/
Node 	*get_prev_node(Node *curr_node);

/**
 * @return pointer to the next node in the list after curr_node.
 * If curr_node is the last node in the list, returns a pointer to the sentinel.*/
Node 	*get_next_node(Node *curr_node);

/**
 * @return 	pointer to the data held by curr_node.
 * If the list is empty, returns a null pointer.*/
void	*get_node_data(Node *curr_node);


void 	destroy_list(DLList *list);


#endif
