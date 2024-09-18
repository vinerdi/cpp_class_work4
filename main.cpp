#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
T** create2DArray(int col, int row) {
	T** matrix = new T * [col];
	for (int i = 0; i < col; i++)
	{
		matrix[i] = new T[row];
	}
	return matrix;
}

template<typename T>
T** create2DArray(int col, int* rows) {
	T** matrix = new T * [col];
	for (int i = 0; i < col; i++)
	{
		matrix[i] = new T[rows[i]];
	}
	return matrix;
}

template<typename T>
void fill2DArray(T** matrix, int col, int row) {
	for (size_t i = 0; i < col; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}
}

template<typename T>
void fill2DArray(T** matrix, int col, int * rows) {
	for (size_t i = 0; i < col; i++)
	{
		for (size_t j = 0; j < rows[i]; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}
}

template<typename T>
void delete2DArray(T** matrix, int col) {
	for (size_t i = 0; i < col; i++)
	{
		delete matrix[i];
	}
	delete matrix;
}

template<typename T>
void print2DArry(int** matrix, int col, int row) {
	for (size_t i = 0; i < col; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}

template<typename T>
void print2DArry(int** matrix, int col, int * rows) {
	for (size_t i = 0; i < col; i++)
	{
		for (size_t j = 0; j < rows[i]; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}

template<typename T>
void addRowTo2DArrayEnd(T**& matrix, int& col, int*& rows) {
	// Створюємо новий масив
	T** newMatrix = new T * [col + 1];

	// Копіюємо старі дані
	for (int i = 0; i < col; i++) {
		newMatrix[i] = matrix[i];
	}

	// Вводимо розмір нового рядка
	int newRowSize;
	cout << "Enter newRowSize: ";
	cin >> newRowSize;

	// Створюємо новий рядок і заповнюємо його випадковими числами
	newMatrix[col] = new T[newRowSize];
	for (int j = 0; j < newRowSize; j++) {
		newMatrix[col][j] = rand() % 10;
	}

	// Оновлюємо масив розмірів рядків
	int* newRows = new int[col + 1];
	for (int i = 0; i < col; i++) {
		newRows[i] = rows[i];
	}
	newRows[col] = newRowSize;

	// Збільшуємо кількість стовпців
	col++;

	// Звільняємо старі масиви
	delete[] rows;
	delete[] matrix;

	// Оновлюємо вказівники
	matrix = newMatrix;
	rows = newRows;
}


template<typename T>
void addRowTo2DArrayStart(T**& matrix, int& col, int*& rows) {
	// Створюємо новий масив більшого розміру
	T** newMatrix = new T * [col + 1];

	// Вводимо розмір нового рядка
	int newRowSize;
	cout << "Enter newRowSize: ";
	cin >> newRowSize;

	// Створюємо новий рядок і заповнюємо його випадковими числами
	newMatrix[0] = new T[newRowSize];
	for (int j = 0; j < newRowSize; j++) {
		newMatrix[0][j] = rand() % 10;
	}

	// Копіюємо старі дані після нового рядка
	for (int i = 0; i < col; i++) {
		newMatrix[i + 1] = matrix[i];
	}

	// Оновлюємо масив розмірів рядків
	int* newRows = new int[col + 1];
	newRows[0] = newRowSize;
	for (int i = 0; i < col; i++) {
		newRows[i + 1] = rows[i];
	}

	// Збільшуємо кількість стовпців
	col++;

	// Звільняємо старі масиви
	delete[] rows;
	delete[] matrix;

	// Оновлюємо вказівники
	matrix = newMatrix;
	rows = newRows;
}

template<typename T>
void addRowTo2DArrayAtPosition(T**& matrix, int& col, int*& rows, int position) {
	if (position < 0 || position > col) {
		cout << "Invalid position! The row cannot be added." << endl;
		return;
	}

	// Створюємо новий масив більшого розміру
	T** newMatrix = new T * [col + 1];

	// Вводимо розмір нового рядка
	int newRowSize;
	cout << "Enter newRowSize: ";
	cin >> newRowSize;

	// Створюємо новий рядок і заповнюємо його випадковими числами
	newMatrix[position] = new T[newRowSize];
	for (int j = 0; j < newRowSize; j++) {
		newMatrix[position][j] = rand() % 10;
	}

	// Копіюємо старі дані перед і після нової позиції
	for (int i = 0; i < position; i++) {
		newMatrix[i] = matrix[i];
	}
	for (int i = position; i < col; i++) {
		newMatrix[i + 1] = matrix[i];
	}

	// Оновлюємо масив розмірів рядків
	int* newRows = new int[col + 1];
	for (int i = 0; i < position; i++) {
		newRows[i] = rows[i];
	}
	for (int i = position; i < col; i++) {
		newRows[i + 1] = rows[i];
	}

	// Збільшуємо кількість стовпців
	col++;

	// Звільняємо старі масиви
	delete[] rows;
	delete[] matrix;

	// Оновлюємо вказівники
	matrix = newMatrix;
	rows = newRows;
}

template<typename T>
void deleteRowFrom2DArrayAtPosition(T**& matrix, int& col, int*& rows, int position) {
	if (position < 0 || position >= col) {
		cout << "Invalid position! The row cannot be added." << endl;
		return;
	}

	// Створюємо новий масив більшого розміру
	T** newMatrix = new T * [col - 1];


	// Копіюємо старі дані перед і після нової позиції
	for (int i = 0; i < position; i++) {
		newMatrix[i] = matrix[i];
	}
	for (int i = position + 1; i < col; i++) {
		newMatrix[i - 1] = matrix[i];
	}

	// Видаляємо рядок на вказаній позиції
	delete[] matrix[position];

	// Оновлюємо масив розмірів рядків
	int* newRows = new int[col - 1];
	for (int i = 0; i < position; i++) {
		newRows[i] = rows[i];
	}
	for (int i = position + 1; i < col; i++) {
		newRows[i - 1] = rows[i];
	}

	// Збільшуємо кількість стовпців
	col--;

	// Звільняємо старі масиви
	delete[] rows;
	delete[] matrix;

	// Оновлюємо вказівники
	matrix = newMatrix;
	rows = newRows;
}

int main() {
	srand(time(0));
	int col;

	cout << "enter col: ";
	cin >> col;
	int* rows = new int[col];
	for (size_t i = 0; i < col; i++)
	{
		cout << "Enter the number of rows for columm: ";
		cin >> rows[i];
	}
	int** matrix = create2DArray<int>(col, rows);
	
	fill2DArray<int>(matrix, col, rows);
	print2DArry<int>(matrix, col, rows);

	deleteRowFrom2DArrayAtPosition(matrix, col, rows, 2);

	print2DArry<int>(matrix, col, rows);
	delete2DArray<int>(matrix, col);

	

	system("pause");
	return 0;
}