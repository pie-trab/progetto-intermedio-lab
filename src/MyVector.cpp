#include <iostream>

#include "../include/MyVector.h"

constexpr int INIT_CAPACITY = 1;

MyVector::MyVector(): size {0}, capacity{INIT_CAPACITY}, buffer {new double[INIT_CAPACITY]}{}

MyVector::MyVector(int n): size{0}, capacity{n}, buffer {new double[capacity]}{}

MyVector::~MyVector(){
	delete[] buffer;
}

double MyVector::operator[](int i) const{
	return buffer[i];
}

double& MyVector::operator[](int i){
	return buffer[i];
}

const double& MyVector::at(int i) const{
	if(i >= 0 && i < size){
		return buffer[i];
	}
	throw out_of_range();
}

double& MyVector::at(int i){
	if(i >= 0 && i < size){
		return buffer[i];
	}
	throw out_of_range();
}

void MyVector::reserve(int n){
	if(n > capacity){
		double* temp = new double[n];
		for(int i = 0; i < size; i++){
			temp[i] = buffer[i];
		}
		delete[] buffer;
		buffer = temp;
		capacity = n;
	}
}

void MyVector::push_back(double elem){
	if(size == capacity){
		reserve(2 * capacity);
	}
	buffer[size] = elem;
	size++;
}

double MyVector::pop_back(){
	if(size > 0){
		size--;
		return buffer[size];
	}
	throw empty_vector();
}

MyVector::MyVector(const MyVector& myVector): size{myVector.size}, capacity{myVector.capacity}, buffer{new double[myVector.size]}{
	std::copy(myVector.buffer, myVector.buffer + size, buffer);
	std::cout << "costruttore di copia invocato\n";
}

MyVector& MyVector::operator=(const MyVector& myVector){
	double* temp = new double[myVector.size];
	std::copy(myVector.buffer, myVector.buffer + myVector.size, temp);
	delete[] buffer;
	buffer = temp;
	size = myVector.size;
	capacity = myVector.capacity;
	std::cout << "operatore di copia invocato\n";
	return *this;
}

MyVector::MyVector(MyVector&& myVector): size {myVector.size}, capacity {myVector.capacity}, buffer{myVector.buffer}{
	myVector.size = 0;
	myVector.capacity = INIT_CAPACITY;
	myVector.buffer = nullptr;
	
	std::cout << "costruttore di spostamento invocato\n";
	
}

MyVector& MyVector::operator=(MyVector&& myVector){
	delete[] buffer;
	size = myVector.size;
	capacity = myVector.capacity;
	buffer = myVector.buffer;
	myVector.size = 0;
	myVector.capacity = INIT_CAPACITY;
	myVector.buffer = nullptr;
	std::cout << "operatore di spostamento invocato\n";
	return *this;
}

MyVector::MyVector(std::initializer_list<double> lst): size {(int) lst.size()}, capacity {(int) lst.size()}, buffer{new double[size]}{
	std::copy(lst.begin(), lst.end(), buffer);
}

