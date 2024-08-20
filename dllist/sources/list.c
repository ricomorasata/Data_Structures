
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


#include "list.h"


Node *create_new_node(void *data) {

	Node *new_node = malloc(sizeof(Node));
	IS_POINTER_VALID(new_node);

	new_node->data = data;
	return new_node;
}


DLList *create_new_list() {

	Node 	*new_node = create_new_node(NULL);
	DLList 	*new_list = malloc(sizeof(DLList));
	IS_POINTER_VALID(new_list);
	
	new_list->sentinel 		= new_node;
	new_node->prev 			= new_node->next = new_node;
	new_list->list_size 	= 0;

	return new_list;
}


void insert_node_before(DLList *list, Node *curr_node, void *val) {

	Node *new_node = create_new_node(val);
	Node *prev_node = curr_node->prev;

	//Set the links
	new_node->prev = prev_node;
	new_node->next = curr_node;
	prev_node->next = curr_node->prev = new_node;

	list->list_size += 1;
}

/**
 * Equivalent to inserting a node before curr_node->next*/
void insert_node_after(DLList *list, Node *curr_node, void *val) {
	insert_node_before(list, curr_node->next, val);
}

/**
 * Equivalent to inserting before the first node in the list.*/
void prepend_node(DLList *list, void *data) {
	
	Node *first_node = get_first_node(list);
	insert_node_before(list, first_node, data);
}

/**
 * Equivalent to inserting before the sentinel.*/
void append_node(DLList *list, void *data) {
	
	Node *sentinel = get_sentinel_node(list);
	insert_node_before(list, sentinel, data);
}


size_t 	get_list_size(DLList *list) {
	return list->list_size;
}

int is_list_empty(DLList *list) {

	if (list->list_size == 0) {
		return 1;
	}
	return 0;
}

void delete_node(DLList *list, Node *curr_node) {

	Node *before_node = curr_node->prev;
	Node *after_node = curr_node->next;

	before_node->next = after_node;
	after_node->prev = before_node;
	free(curr_node);

	list->list_size -= 1;
}


Node *get_sentinel_node(DLList *list) {
	return list->sentinel;
}


Node *get_first_node(DLList *list) {
	return list->sentinel->next;
}


Node *get_last_node(DLList *list) {
	return list->sentinel->prev;
}


Node *get_prev_node(Node *curr_node) {
	return curr_node->prev;
}


Node *get_next_node(Node *curr_node) {
	return curr_node->next;
}

void *get_node_data(Node *curr_node) {
	return curr_node->data;
}

void destroy_list(DLList *list) {

	while (!is_list_empty(list)) {
		delete_node(list, get_first_node(list));
	}
	free(list->sentinel);
	free(list);
}
