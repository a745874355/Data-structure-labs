#include <iostream>

template <typename T>
class DList {
	struct Node {
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data = T{}, Node* next = nullptr, Node* prev = nullptr) {
			data_ = data;
			next_ = next;
			prev_ = prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	DList() {
		front_ = nullptr;
		back_ = nullptr;
	}
	void push_front(const T& data);
	~DList();

	class const_iterator {
	protected:
		friend class DList<T>;
		DList* list;
		Node* data;
	public:
		const_iterator() {}
		const_iterator(Node* node) {
			this->data = node;
		}
		const_iterator(Node* node, DList* list) {
			data = node;
			this->list = list;
		}
		const_iterator operator++() {
			if (data)
			{
				this->data = data->next_;
			}
			return *this;
		}

		const_iterator operator++(int) {
			operator++();
			return *this;
		}
		const_iterator operator--() {
			if (data)
			{
				this->data = data->prev_;
			}
			return *this;
		}
		const_iterator operator--(int) {
			return operator--();
		}
		bool operator==(const_iterator rhs) {
			return this->data == rhs.data;
		}
		bool operator!=(const_iterator rhs) {
			return !operator==(rhs);
		}
		const T& operator*()const {
			return data->data_;
		}
	};
	class iterator :public const_iterator {
	public:
		iterator() : const_iterator() {}
		iterator(Node* node) :const_iterator(node) {}
		iterator operator++() {
			const_iterator::operator++();
			return *this;
		}
		iterator operator++(int) {
			operator++();
			return *this;
		}
		iterator operator--() {
			const_iterator::operator--();
			return *this;
		}
		iterator operator--(int) {
			operator--();
			return *this;
		}
		T& operator*() {
			return const_iterator::data->data_;
		}
		const T& operator*()const {
			return const_iterator::operator*();
		}

	};
	const_iterator cbegin() const {
		return const_iterator(front_);
	}
	iterator begin() {
		return iterator(front_);
	}
	const_iterator cend() const {
		return const_iterator(back_);
	}
	iterator end() {
		return iterator(back_);
	}
};





template <typename T>
void DList<T>::push_front(const T& data) {
	Node* nn = new Node(data, front_);
	if (front_ != nullptr) {
		front_->prev_ = nn;
	}
	else {
		back_ = nn;
	}
	front_ = nn;
}


template <typename T>
DList<T>::~DList() {
	auto node = front_;
	while (node) {
		auto next = node->next_;
		delete node;
		node = next;
	}
}
template <typename T>
class Sentinel {
	struct Node {
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data = T{}, Node* next = nullptr, Node* prev = nullptr) {
			data_ = data;
			next_ = next;
			prev_ = prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	Sentinel() {
		front_ = new Node();
		back_ = new Node();
		front_->next_ = back_;
		back_->prev_ = front_;
	}
	void push_front(const T& data);
	~Sentinel();

	class const_iterator {
	protected:
		Node* data;
		Sentinel* list;
	public:
		const_iterator() {
			data = nullptr;
			list = nullptr;
		}
		const_iterator(Node* data) {
			this->data = data;
		}
		const_iterator(Node* data, Sentinel* list) {
			this->data = data;
			this->list = list;
		}
		const_iterator operator++() {
			if (this->data->next_)
			{
				this->data = data->next_;
			}
			return *this;
		}
		const_iterator operator++(int) {
			operator++();
			return *this;
		}
		const_iterator operator--() {
			if (this->data->prev_)
			{
				this->data = data->prev_;
			}
			return *this;
		}
		const_iterator operator--(int) {
			operator--();
			return *this;
		}
		bool operator==(const_iterator rhs) {
			if (!rhs.data->next_) //if rhs is last sentinel
			{
				if (!this->data->prev_) //if this is first sentinel
				{
					if (this->data->next_ == rhs.data) //if there is no data between 2 sentinels
					{
						return true;
					}
				}
			}


			return this->data == rhs.data;
		}
		bool operator!=(const_iterator rhs) {
			return !operator==(rhs);
		}
		const T& operator*()const {
			return data->data_;
		}
	};
	class iterator :public const_iterator {
	public:
		iterator() :const_iterator() {}
		iterator(Node* node) : const_iterator(node) {}
		iterator(Node* node, Sentinel* list) : const_iterator(node, list) {}
		iterator(const_iterator& it) {
			const_iterator::data = it.data;
			const_iterator::list = it.list;
		}
		iterator operator++() {
			const_iterator::operator++();
			return *this;
		}
		iterator operator++(int) {
			return operator++();

		}
		iterator operator--() {
			return const_iterator::operator--();
		}
		iterator operator--(int) {
			return operator--();
		}
		T& operator*() {
			return const_iterator::data->data_;
		}
		const T& operator*()const {
			return const_iterator::operator*();
		}
	};
	const_iterator cbegin() const {
		return const_iterator(front_);
	}
	iterator begin() {
		return iterator(front_);
	}
	const_iterator cend() const {
		return const_iterator(back_);
	}
	iterator end() {
		return iterator(back_);
	}
};


template <typename T>
void Sentinel<T>::push_front(const T& data) {
	Node* nn = new Node(data, front_->next_, front_);
	front_->next_ = nn;
	nn->next_->prev_ = nn;
}


template <typename T>
Sentinel<T>::~Sentinel() {
	auto node = front_;
	while (node) {
		auto next = node->next_;
		delete node;
		node = next;
	}
}
