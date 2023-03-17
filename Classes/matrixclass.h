#ifndef _matrixclass
#define _matrixclass

class Matrix1D {
	private: 
		int rows, cols;
		int * data;
    public:
		Matrix1D(int r, int c);
		int GetIndex(int i, int j);
		void SetIndex(int i, int j, int val);
};


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
class Matrix2D {
	private: 
		int rows, cols;
		int ** data;
    public:
		Matrix2D(int r, int c);
		int GetIndex(int i, int j);
		void SetIndex(int i, int j, int val);
};

#endif
