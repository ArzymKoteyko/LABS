struct queue_element {
	queue_element* ptr_next;
	queue_element* ptr_back;
	int value; 
};

class Queue {
	private:
		queue_element queue_head;
	public:
		Queue ();
		int get_size();
		void say_size();
		void say_queue();

		void append_start(int);
		void append_back(int);
		void pop_start();
		void pop_back();
	private:
		void set_size(int);
};
