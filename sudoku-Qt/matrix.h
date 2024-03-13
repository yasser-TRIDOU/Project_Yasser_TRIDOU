
#define N 9
#define N1 3
namespace sudoku{
	class matrix{
		public:
		bool you_win();
        void write(int i, int j, int val);
		void new_puzzle();
		void solvebacktracking();
        void reset();
		int read(int i, int j);
        matrix();
        matrix(const matrix&);

		private:
		int obj[N][N];
		int ne[N][N];
        void empty();
		void init();

	};
}
