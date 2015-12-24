#include <SFML/Graphics.hpp>
#include "simulator/wpilib/smart_dashboard.h"

class Dashboard {
 public:
  Dashboard();
  ~Dashboard();
  bool Render();

 private:
  sf::Vector2f enable_position_ { 0., 0. }, enable_size_ { 400., 200. };
  sf::Vector2f auto_position_{ 10., 280. };
  bool enabled_ = false, auto_ = false;
  std::map<std::string, sf::Vector2f> smart_dashboard_positions_;
  sf::Vector2f next_smartdash_pos_ {410, 10};

  sf::RenderWindow window_;
  sf::Font font;
};
