class Matrix {
	
	private:
		const int *matrix_size; // size of square matrix
		int **matrix;
	public: 
		Matrix(
			int 	// matrix size
		);
		void say_size(
				// prints to console mstrix size
		);
		void say_matrix(
				// prints mtrix values
		);
		int get_size(
				//	
		);
		int** get_matrix(
				//
		);
	private:
		void set_size(
			int	//
		);
		void set_matrix(
				//
		);
		void malloc_matrix(
				//
		);
		void gen_matrix(
				//
		);
};
