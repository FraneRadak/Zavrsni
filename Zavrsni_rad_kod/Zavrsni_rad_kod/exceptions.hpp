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