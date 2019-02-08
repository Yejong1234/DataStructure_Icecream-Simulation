#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#define MAX_QUEUE_SIZE	100

	typedef struct element {
		int id;
		int arrival_time;
		int service_time;
} element;	 	// Customer structure

	typedef struct QueueType {//고객들이 대기하는 장소 queue 구조로 선언
		element  queue[MAX_QUEUE_SIZE];
		int  front, rear;
	} QueueType;
	QueueType queue;

	// Real random number generation function between 0 and 1
	double random() {
		return rand() / (double)RAND_MAX;
}
	// Various state variables needed for simulation
	int duration = 10; // Simulation time
	double arrival_prob = 0.7; // Average number of customers arriving in one time unit
	int max_serv_time = 5; // maximum service time for one customer
	int clock;

	// Results of the simulation
	int customers; // Total number of customers
	int served_customers; // Number of customers served
	int waited_time; // Time the customers waited

	// Empty state detection function
	int is_empty(QueueType * q)
	{
		return (q->front == q->rear);//둘다 null인 경우이니까
	}
	// Full state detection function
	int is_full(QueueType * q)
	{
		return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
	}

	// Insert function
	void enqueue(QueueType * q, element item)
	{
		if (is_full(q))
			printf("Queue is full\n");
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->queue[q->rear] = item;
		}	// delete function
	element dequeue(QueueType * q)
	{
		if (is_empty(q))
			printf("Queue is empty\n");
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->queue[q->front];
		}
	// Generate a random number.
	// If it is smaller than ��arrival_prov��, assume that new customer comes in the bank.
	int is_customer_arrived()
	{
		if (random() < arrival_prob)//random()이 반환하는 숫자가 0.7보다 크다면
			return true;//고객이 도착한 것으로 간주
			else return false;
		}
	// Insert newly arrived customer into queue
	void insert_customer(int arrival_time)
	{
		element customer;

		customer.id = customers++;//customer 아이디를 하나씩 증가시킴(customers는 전역변수)
		customer.arrival_time = arrival_time;//arrive time을 패러미터로 받아서 element 구조체에 저장
		customer.service_time = (int)(max_serv_time * random()) + 1;//random 정수를 받는 방법!! int로 캐스팅 해준다. 그리고 1을 더해줌
		enqueue(&queue, customer);//대기실에 고객을 집어넣는다.
		printf("Customer %d comes in %d minutes. Service time is %d minutes.\n", customer.id, customer.arrival_time, customer.service_time);
		}

	// Retrieve the customer waiting in the queue and return the customer's service time.
	int remove_customer()//대기실에서 대기중인 고객을 꺼내서 서비스를 받게 해준다.
	{
		element customer;
		int service_time = 0;
	
		if (is_empty(&queue)) return 0;
		customer = dequeue(&queue);//queue에서 빼주기
		service_time = customer.service_time - 1;
		served_customers++;
		waited_time += clock - customer.arrival_time;
		printf("Customer %d starts service in %d minutes. Wait time was %d minutes.\n", customer.id, clock, clock - customer.arrival_time);
		return service_time;
		}
	// Print the statistics.
	void print_stat()
	{
		printf("Number of customers served = %d\n", served_customers);
		printf("Total wait time =% d minutes\n", waited_time);
		printf("Average wait time per person = %f minutes\n",
			(double)waited_time / served_customers);
		printf("Number of customers still waiting = %d\n", customers - served_customers);
		}

	// Simulation program
	void main()
	{
		int service_time1 = 0;//staff가 두명 있으니 서비스 타임 2개 선언
		int service_time2 = 0;
	
		clock = 0;
		while (clock < duration) {//duration안에서 수행
			clock++;
			printf("Current time=%d\n", clock);
			if (is_customer_arrived()) {//customer가 도착했다면
				insert_customer(clock);//insert 해준다. clock 시간과 함께
		}
			// Check if the customer who is receiving the service is finished.
			if (service_time1 > 0)	// the customer is receiving service
				service_time1--;
	
			else {
					service_time1 = remove_customer();
		}
		
			if (service_time2 > 0)//2번째 staff의 시간도 체크해준다.
					service_time2--;

			else {//2번째 staff가 비어있다면
				service_time2 = remove_customer();//대기실에서 꺼내서 서비스를 받게 해준다.
		}

	}
		print_stat();//출력
		}
