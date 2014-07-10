/**************************************************************************************\
									Thread.h

Author		:	R.J.H.M.	Stevens
Begin		:	10-07-2014
				
Version		:	1.0.0

Description	:	This is a basic threading class that supports multiple platforms

Changes		:
				10-07-2014	-	Setting up the basic structor of the class		

\**************************************************************************************/
#ifndef THREAD_H_
#define THREAD_H_

/*
 *	Windows specific includes
 */
#ifdef _WIN32
#include <windows.h>
#endif

/*
 *	General includes
 */
#include "thread_errors.h"

class Thread
{
public:
	Thread();
	/**
	 *	Set the function that hass to run and tell if it has to run in a while (true) loop
	 *
	 *	@param loop true for a endless loop else false
	 *	@param p_function the pointer to the function that has to run as a thread
	 *
	 *	@return 0 on success else >0
	 */
	int SetThreadFunction(int (*p_function)(void*));
	int SetParam(void* p_param);
	int Start();
	int Stop();
	//int Pause();

	int GetThreadId();

	~Thread();

protected:
	/*
	 *	Windows specific threading functions
	 */
	#ifdef _WIN32
	static DWORD WINAPI ThreadRunner(LPVOID lpParam);
	#endif

	void* mp_param;				/**< A pointer to the param that has to be send to the thread */
	int (*mp_function)(void*);	/**< A pointer to the function that has to run as a thread */

	HANDLE m_thread;	
	DWORD m_threadId;	
};

#endif

//#if __cplusplus > 199711L