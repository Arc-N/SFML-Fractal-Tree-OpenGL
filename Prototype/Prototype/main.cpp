#include <SFML/Graphics.hpp>
#include "FractalTree.h"
int main()
{
	//WINDOW SETUP
	sf::RenderWindow window;
	window.create(sf::VideoMode(1500,800), "Tree");
	sf::Event event;
	//WINDOW SETUP END

	//Variables
	int numberOfBranches = 13;
	float lengthReducer = 0.85f;
	float angle = 20;

	//Setup SFML Text for instructions
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("Press z and x to scale\nPress Up and Down to change angle\nPress left and Right to change the number of branches\n");
	text.setCharacterSize(14);
	text.setPosition(0, 0);

	sf::VertexArray branches(sf::LinesStrip, 2); //Array of 2 points
	branches[0].color = sf::Color::White;
	branches[1].color = sf::Color::Color(211, 72, 226,255); //end of initializing vertexes

	sf::Vector2f root((float)window.getSize().x / 2, (float)window.getSize().y); //get the buttom of the screen as a root

	sf::Transform transform; //Used to rotate vertexes in the Window.draw function

	FractalTree fTree(window); //Create a tree object 


	//GAME LOOP

	while (window.isOpen())
	{
		//clears window every frame (MUST BE INSIDE THE LOOP)
		window.clear(sf::Color::Color(68, 93, 132,255));
		//Process window events 
		while (window.pollEvent(event))
		{
			//Close event
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			//Angle Control
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				angle++;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				angle--;
			}
			//Number of Branches Control
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				if(numberOfBranches<15)
				numberOfBranches++;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if(numberOfBranches>0)
				numberOfBranches--;
			}
			//LengthReducer Control
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				if (lengthReducer>0)
					lengthReducer-=0.01f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			{
				if (lengthReducer<0.99f)
					lengthReducer+=0.01f;
			}
		}//End Of While(Events)

		/*
		Call the function that draws a fractal tree: 
		takes Two Branch points, 
		the root coordinate, 
		transform, 
		1stNumberOfBranches is used to store the value to access it later,
		number of branches must be the same as the previous, (Can be adjusted in controls during runtime)
		angle to rotate branches (Can be adjusted in controls during runtime)
		Length reducer is a number between 0 and 1 that the length is multilplied by to shorten it as the tree grows.
		Example for length reducer would be Length*LengthReducer = Length*0.85 next time the branch will be 85% shorter.
		*/
		fTree.tree(branches, root, transform, numberOfBranches, numberOfBranches, angle, lengthReducer);

		//Draw Instructions
		window.draw(text);

		//Everything is drawn on the frame proceed to rendering
		window.display();
	} //End of While(isOpen)
	return 0;
}


