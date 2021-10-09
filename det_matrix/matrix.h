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
					// prints matrix values
		);
		int get_size(
					// returns matrix size
		);
		int** get_matrix(
					// returns pointer to matrix
		);
	private:
		void set_size(
			int		// matrix size
		);
		void set_matrix(
			   		// matrix init
		);
		void malloc_matrix(
   					// allocate memory for matrix
		);
		void gen_matrix(
			   		// fill matrix with random values in range [0,99]
		);
};
