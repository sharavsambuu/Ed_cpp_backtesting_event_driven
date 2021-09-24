#include "executionHandler.hpp"

InstantExecutionHandler::InstantExecutionHandler(std::queue<Event>* eventQueue, DataHandler* dataHandler) {
	this->eventQueue = eventQueue;
	this->dataHandler = dataHandler;
}

void InstantExecutionHandler::executeOrder(OrderEvent order) {
	auto timestamp = dataHandler->getLatestBars(order.symbol).rbegin()->first;

	eventQueue->push(FillEvent(order.symbol, timestamp, order.quantity, order.direction, 0));
}