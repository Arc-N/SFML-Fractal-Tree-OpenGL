#include <SFML/Graphics.hpp>
#include "FractalTree.h"
FractalTree::FractalTree(sf::RenderWindow &windowP)
	: window(windowP)
{
}
//Implementation of tree function
void FractalTree::tree(sf::VertexArray branches, sf::Vector2f root, sf::Transform transform,int storedNumberOfBranches, int numberOfBranches, float angle, float lengthReducer)
{
	//This if statement adds an extra length to the root if needed: Simply change the if statement to always be false to avoid running it.
	if (numberOfBranches == storedNumberOfBranches )
	{
		branches[0].position = sf::Vector2f(root);
		branches[1].position = sf::Vector2f(root.x, root.y*0.9);
		window.draw(branches, transform);
		root = sf::Vector2f(root.x, root.y*0.9);
	}
	//Assign 1st Branch point to root position
	branches[0].position = sf::Vector2f(root);
	//Assign 2nd Branch point to a point above the root
	branches[1].position = sf::Vector2f(root.x, root.y*lengthReducer);
	//Draw a line between the two points and rotate according to the transform angnle
	window.draw(branches, transform);
	//Translate the root point to the end of the previous branch in order to continue drawing
	root = sf::Vector2f(root.x, root.y*lengthReducer);
	//Number of times the recursive function should happen;
	if (numberOfBranches > 0)
	{
		//Decrease the branch count
		numberOfBranches--;
		//Assign a rotation angle to the transform
		transform.rotate(angle, root);
		//Call the function recursively to draw the branch again
		tree(branches, root, transform, storedNumberOfBranches, numberOfBranches, angle, lengthReducer);
		//Assign a rotation angle on reverse
		transform.rotate(-angle * 2, root);
		//Call the function recursively to draw the branch again
		tree(branches, root, transform, storedNumberOfBranches, numberOfBranches, angle, lengthReducer);
	}

}