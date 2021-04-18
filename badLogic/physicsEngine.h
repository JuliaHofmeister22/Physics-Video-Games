#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <unistd.h>
#include <unordered_map>


using namespace sf;

template <typename T>
bool collision(T obj1,T obj2, float changeT);

inline float gravity = -9.8;


