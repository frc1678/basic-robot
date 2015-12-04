#include <functional>
#include <string>

class State {
public:
  State();
  State(std::string name);
  State(std::string name, std::function<std::string()> update_func);
  State(std::string name, std::function<void()> init_func, std::function<std::string()> update_func);
  virtual ~State();
  virtual void init();
  virtual std::string update();
  std::string name();

private:
  std::string _name;
  std::function<void()> _init_func;
  std::function<std::string()> _update_func;
};
