#pragma once

#include <vector>
#include <map>
#include <functional>
#include <queue>
#include "event.h"

class EventManager {
 public:
  EventManager();
  void RegisterListener(int event_type,
                        std::function<void(EventData*)> handler);
  void QueueEvent(Event evt);
  void Update();

  static EventManager* GetInstance() { return instance; };

 private:
  std::map<int, std::vector<std::function<void(EventData*)>>> event_handlers_;
  std::vector<std::queue<Event>> event_queues_;
  int current_queue_;
  std::queue<Event>& read_queue();
  std::queue<Event>& write_queue();

  static EventManager* instance;
};
