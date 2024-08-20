
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


typedef struct Person {
	int  ID;
	char name[50];
} Person;

int main(int argc, char const *argv[]) {
	
	DLList *new_list = create_new_list();

	Person p1 = {1, "John"}, p2 = {2, "Amy"}, p3 = {3, "Jack"};

	Node *sentinel = get_sentinel_node(new_list);
	printf("Address of the sentinel node: %p\n", get_sentinel_node(new_list));

	append_node(new_list, &p1);
	prepend_node(new_list, &p2);
	printf("List size = %ld\n", get_list_size(new_list));

	Node *individual = get_first_node(new_list);
	insert_node_before(new_list, individual, &p3);
	printf("List size = %ld\n", get_list_size(new_list));

	destroy_list(new_list);

	return 0;
}