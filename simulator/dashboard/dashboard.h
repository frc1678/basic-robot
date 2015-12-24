#include <SFML/Graphics.hpp>

class Dashboard {
 public:
  Dashboard();
  ~Dashboard();
  bool Render();

 private:
  sf::Vector2f enable_position_ { 0., 0. }, enable_size_ { 400., 200. };
  sf::Vector2f auto_position_{ 0., 280. }, teleop_position_ { 0., 320. };
  bool enabled_ = false, auto_ = false;

  sf::RenderWindow window_;
  sf::Font font;
};
