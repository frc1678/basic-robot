#include "event_manager.h"
#include <iostream>

EventManager* EventManager::instance = new EventManager();

EventManager::EventManager() {
  current_queue_ = 0;
  event_queues_.push_back(std::queue<Event>());
  event_queues_.push_back(std::queue<Event>());
}

void EventManager::RegisterListener(int event_type,
                                    std::function<void(EventData*)> handler) {
  if (event_handlers_.find(event_type) == event_handlers_.end())
    event_handlers_[event_type] =
        std::vector<std::function<void(EventData*)>>();
  event_handlers_[event_type].push_back(handler);
}

void EventManager::QueueEvent(Event evt) { write_queue().push(evt); }

std::queue<Event>& EventManager::read_queue() {
  return event_queues_[current_queue_];
}

std::queue<Event>& EventManager::write_queue() {
  return event_queues_[!current_queue_];
}

void EventManager::Update() {
  while (!read_queue().empty()) {
    Event proc = read_queue().front();
    read_queue().pop();
    if (event_handlers_.find(proc.GetEventType()) != event_handlers_.end()) {
      for (auto handler : event_handlers_[proc.GetEventType()]) {
        handler(proc.data);
      }
    }
  }
  current_queue_ = (current_queue_ + 1) % event_queues_.size();
}
