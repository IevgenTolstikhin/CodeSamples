#ifndef MODEL_H
#define MODEL_H

#include <thread>
#include <vector>
#include <atomic>
#include <random>
#include "ThreadsafePriorityQueue.hpp"
#include "TagData.h"

class Model
{
private:
	static const BYTE min_priority;
	static const BYTE max_priority;
	static const int32_t min_client_sleep_in_milliseconds;
	static const int32_t max_client_sleep_in_milliseconds;
	static const int32_t server_sleep_time_in_seconds;
	const int32_t clients_number;
	const std::string log_file_name;
	ThreadsafePriorityQueue <TDATA, std::deque<TDATA>, std::greater<TDATA>> queue;
	std::vector <std::thread> client_threads;
	std::thread server_thread;
	std::atomic<bool> work_finished;
	std::default_random_engine engine;
	std::uniform_int_distribution<> priority_distribution;
	std::uniform_int_distribution<> delay_distribution;

	void run_client(const int32_t client_id);
	void run_server();
	TDATA generate_random_data(const int32_t client_id);

public:
	Model(const int32_t number, const std::string& log_path);
	~Model();

	Model(const Model& other) = delete;
	Model& operator = (const Model& other) = delete;
	
	void start();
	void stop();
};

#endif	// MODEL_H