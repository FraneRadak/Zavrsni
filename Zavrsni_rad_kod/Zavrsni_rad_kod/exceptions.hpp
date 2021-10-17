#include <iostream>
#include <cstdlib>
using namespace std;

class Exception {
private:
public:
	virtual void ThrowException()=0;
};
class NurseException :public Exception {
private:
public:
	void ThrowException() {
		cout << "Invalid nurse move!" << endl;
	};
};
class BishopException :public Exception {
private:
public:
	void ThrowException() {
		cout << "Invalid bishop move!" << endl;
	};
};
class RookException :public Exception {
private:
public:
	void ThrowException() {
		cout << "Invalid Rook move!" << endl;
	};
};
class QueenException :public Exception {
private:
public:
	void ThrowException() {
		cout << "Invalid Queen move!" << endl;
	};
};
class KingException :public Exception {
private:
public:
	void ThrowException() {
		cout << "Invalid King move!" << endl;
	};
};
class PawnException :public Exception {
private:
public:
	void ThrowException() {
		cout << "Invalid King move!" << endl;
	};
};