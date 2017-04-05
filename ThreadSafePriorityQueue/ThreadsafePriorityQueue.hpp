#ifndef THREADSAFE_PRIORITY_QUEUE_H
#define THREADSAFE_PRIORITY_QUEUE_H

#include <mutex>
#include <queue>
#include <condition_variable>
#include <memory>

template <
			class T,
			class Container = std::deque<T>,
			class Compare = std::greater<typename Container::value_type >
		>
class ThreadsafePriorityQueue
{
private:
	mutable std::mutex mut;
	std::priority_queue<T, Container, Compare> pq;
	std::condition_variable data_cond;

public:
	ThreadsafePriorityQueue() {}
	ThreadsafePriorityQueue(const ThreadsafePriorityQueue&) = delete;
	ThreadsafePriorityQueue& operator = (const ThreadsafePriorityQueue&) = delete;

	void push(T new_value)
	{
		std::lock_guard<std::mutex> lk(mut);
		pq.push(new_value);
		data_cond.notify_one();
	}

	void wait_and_pop(T& value)
	{
		std::unique_lock<std::mutex> lk(mut);
		data_cond.wait(lk, [this]{return !pq.empty(); });
		value = pq.top();
		pq.pop();
	}

	std::shared_ptr<T> wait_and_pop()
	{
		std::unique_lock<std::mutex> lk(mut);
		data_cond.wait(lk, [this]{return !pq.empty(); });
		std::shared_ptr<T> res(std::make_shared<T>(pq.top()));
		pq.pop();
		return res;
	}

	bool try_pop(T& value)
	{
		std::lock_guard<std::mutex> lk(mut);
		if (pq.empty())
			return false;
		value = pq.top();
		pq.pop();
		return true;
	}

	std::shared_ptr<T> try_pop()
	{
		std::lock_guard<std::mutex> lk(mut);
		if (pq.empty())
			return std::shared_ptr<T>();
		std::shared_ptr<T> res(std::make_shared<T>(pq.top()));
		pq.pop();
		return res;
	}

	bool empty() const
	{
		std::lock_guard<std::mutex> lk(mut);
		return pq.empty();
	}
};

#endif	// THREADSAFE_PRIORITY_QUEUE_H