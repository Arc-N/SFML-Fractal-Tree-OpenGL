#include <SFML/Graphics.hpp>
#ifndef FRACTALTREE_H
#define FRACTALTREE_H
//Fractral Tree Class
class FractalTree
{
private:
	sf::RenderWindow &window;
public:
	//Constructor
	FractalTree(sf::RenderWindow&);
	//Tree Function Decleration
	void tree(sf::VertexArray, sf::Vector2f, sf::Transform, int, int, float, float);

protected:

};


#endif //FRACTALTREE_H
