#include "../../thread.h"
#include "../../mutex.h"
#include "../../mailbox.h"
#include <stdio.h>
int test(void* test)
{
	Mailbox<int>* box = (Mailbox<int>*) test;
	//Mutex* mutex = (Mutex*) test;
	//mutex->Lock();
	//mutex->Unlock();
	while(box->IsEmpty());
	
	printf("test %d\r\n", box->GetMessage());
	Sleep (100);
	return 0;
}
int main()
{
	Mailbox<int> box;
	//Mutex mutex;
	Thread thread;
	thread.SetThreadFunction(&test);
	thread.SetParam(&box);
	//mutex.Lock();
	thread.Start();
	box.PutMessage(1000);

	Sleep(1000);
	//mutex.Unlock();
	Sleep(1000);
	thread.Stop();

	return 0;
}