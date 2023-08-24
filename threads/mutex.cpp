#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int myaccount = 0;
mutex m;

void run()
{
	m.lock();
	myaccount++;
	cout << myaccount << endl;
	m.unlock();
}

int main()
{
	thread t1(run);
	thread t2(run);
	t1.join();
	t2.join();

	cout << myaccount << endl;
	return 0;
}
