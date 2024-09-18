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
	// ��������� ����� �����
	T** newMatrix = new T * [col + 1];

	// ������� ���� ���
	for (int i = 0; i < col; i++) {
		newMatrix[i] = matrix[i];
	}

	// ������� ����� ������ �����
	int newRowSize;
	cout << "Enter newRowSize: ";
	cin >> newRowSize;

	// ��������� ����� ����� � ���������� ���� ����������� �������
	newMatrix[col] = new T[newRowSize];
	for (int j = 0; j < newRowSize; j++) {
		newMatrix[col][j] = rand() % 10;
	}

	// ��������� ����� ������ �����
	int* newRows = new int[col + 1];
	for (int i = 0; i < col; i++) {
		newRows[i] = rows[i];
	}
	newRows[col] = newRowSize;

	// �������� ������� ��������
	col++;

	// ��������� ���� ������
	delete[] rows;
	delete[] matrix;

	// ��������� ���������
	matrix = newMatrix;
	rows = newRows;
}


template<typename T>
void addRowTo2DArrayStart(T**& matrix, int& col, int*& rows) {
	// ��������� ����� ����� ������� ������
	T** newMatrix = new T * [col + 1];

	// ������� ����� ������ �����
	int newRowSize;
	cout << "Enter newRowSize: ";
	cin >> newRowSize;

	// ��������� ����� ����� � ���������� ���� ����������� �������
	newMatrix[0] = new T[newRowSize];
	for (int j = 0; j < newRowSize; j++) {
		newMatrix[0][j] = rand() % 10;
	}

	// ������� ���� ��� ���� ������ �����
	for (int i = 0; i < col; i++) {
		newMatrix[i + 1] = matrix[i];
	}

	// ��������� ����� ������ �����
	int* newRows = new int[col + 1];
	newRows[0] = newRowSize;
	for (int i = 0; i < col; i++) {
		newRows[i + 1] = rows[i];
	}

	// �������� ������� ��������
	col++;

	// ��������� ���� ������
	delete[] rows;
	delete[] matrix;

	// ��������� ���������
	matrix = newMatrix;
	rows = newRows;
}

template<typename T>
void addRowTo2DArrayAtPosition(T**& matrix, int& col, int*& rows, int position) {
	if (position < 0 || position > col) {
		cout << "Invalid position! The row cannot be added." << endl;
		return;
	}

	// ��������� ����� ����� ������� ������
	T** newMatrix = new T * [col + 1];

	// ������� ����� ������ �����
	int newRowSize;
	cout << "Enter newRowSize: ";
	cin >> newRowSize;

	// ��������� ����� ����� � ���������� ���� ����������� �������
	newMatrix[position] = new T[newRowSize];
	for (int j = 0; j < newRowSize; j++) {
		newMatrix[position][j] = rand() % 10;
	}

	// ������� ���� ��� ����� � ���� ���� �������
	for (int i = 0; i < position; i++) {
		newMatrix[i] = matrix[i];
	}
	for (int i = position; i < col; i++) {
		newMatrix[i + 1] = matrix[i];
	}

	// ��������� ����� ������ �����
	int* newRows = new int[col + 1];
	for (int i = 0; i < position; i++) {
		newRows[i] = rows[i];
	}
	for (int i = position; i < col; i++) {
		newRows[i + 1] = rows[i];
	}

	// �������� ������� ��������
	col++;

	// ��������� ���� ������
	delete[] rows;
	delete[] matrix;

	// ��������� ���������
	matrix = newMatrix;
	rows = newRows;
}

template<typename T>
void deleteRowFrom2DArrayAtPosition(T**& matrix, int& col, int*& rows, int position) {
	if (position < 0 || position >= col) {
		cout << "Invalid position! The row cannot be added." << endl;
		return;
	}

	// ��������� ����� ����� ������� ������
	T** newMatrix = new T * [col - 1];


	// ������� ���� ��� ����� � ���� ���� �������
	for (int i = 0; i < position; i++) {
		newMatrix[i] = matrix[i];
	}
	for (int i = position + 1; i < col; i++) {
		newMatrix[i - 1] = matrix[i];
	}

	// ��������� ����� �� ������� �������
	delete[] matrix[position];

	// ��������� ����� ������ �����
	int* newRows = new int[col - 1];
	for (int i = 0; i < position; i++) {
		newRows[i] = rows[i];
	}
	for (int i = position + 1; i < col; i++) {
		newRows[i - 1] = rows[i];
	}

	// �������� ������� ��������
	col--;

	// ��������� ���� ������
	delete[] rows;
	delete[] matrix;

	// ��������� ���������
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