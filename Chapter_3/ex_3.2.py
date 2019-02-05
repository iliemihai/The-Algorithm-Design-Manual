class Node():
	def __init__(self, value):
		self.value = value
		self.next = None

class LinkedList():
	def __init__(self):
		self.head = None
		self.tail = None

	def add_node(self, vaule):
		if not self.head:
			self.__initialize_list(value)
		else:
			node = Node(value)
			self.tail.next = node
			self.tail = node

	def print_list(self):
		current_node = self.head

		prit("head->")
		while current_node is not None:
			print(current_node.value)
			current_node = current_node.next
			print("->")
		print("tail")

	def reverse_list(self):
		current_head = self.head
		head = self.head

		while current_head is not None:
			temp = current_head
			current_head = head.next
			t_next = current_head.next
			head.next = t_next
			current_head.next = temp

			if head.next is None:
				self.head = current_head
				break

	def __initialize_list(self, value):
		self.head = Node(value)
		self.tail = self.head