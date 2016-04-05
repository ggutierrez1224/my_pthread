#include "my_pthread_t.h"

//static ucontext_t temp;
//static ucontext_t mainctx;

void func()
{
	int i = 0;
	//for(i=0; i<105; i++)
	for(i=0; i<5; i++)
	{
		printf("Val: %d\n", i);
		sleep(1);
	}
	//swapcontext(&temp, &mainctx);
	return;
}

void func2()
{
	int i = 0;
	//for(i=0; i<100; i++)
	for(i=0; i<5; i++)
	{
		printf("Func2: %d\n", i*1000);
		usleep(1000*100);
	}
	//swapcontext(&temp, &mainctx);
	return;
}

void func3()
{
	int i = 0;
	for(i=0; i<10; i++)
		printf("Mohan \n");
}

int main()
{
	my_pthread_init();
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	my_pthread_create(&t1, NULL, &func, NULL);
	my_pthread_create(&t2, NULL, &func2, NULL);
	my_pthread_create(&t3, NULL, &func3, NULL);
	my_timer_init();
	/*
	printf("GetCtx: %d @%s:%d\n",getcontext(&temp), __func__, __LINE__);
	temp.uc_link = 0;
	temp.uc_stack.ss_sp = malloc(STACKSIZE);
	temp.uc_stack.ss_size = STACKSIZE;
	temp.uc_stack.ss_flags = 0;

	makecontext(&temp, &func, 0);
	DEBUG_PRINT
	swapcontext(&mainctx, &temp);
	DEBUG_PRINT
	*/
	return 0;
}
