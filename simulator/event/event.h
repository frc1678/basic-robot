#pragma once

class EventData {
 public:
  virtual ~EventData() {}
  int GetEventType() { return event_type_; }

 protected:
  EventData(int event_type) : event_type_(event_type) {}

 private:
  int event_type_;
};

class Event {
 public:
  Event(EventData* data) : data(data) {}
  ~Event() {}
  int GetEventType() { return data->GetEventType(); }
  EventData* data;

 protected:
 private:
  int event_type_;
};
