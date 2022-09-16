/// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <ctsdlib>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
    // Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "ChaosGame", Style::Default);
	rectangleShape rectangle;
    vector<Vector2f> vertices;
    vector<Vector2f> points;

	while (window.isOpen())
	{
        /*
		****************************************
		Handle the players input
		****************************************
		*/
        Event event;
		while (window.pollEvent(event))
		{
            if (event.type == Event::Closed)
            {
				// Quit the game when the window is closed
				window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    if(vertices.size() < 3)
                    {
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                    else if(points.size() == 0)
                    {
                        ///fourth click
                        ///push back to points vector
			points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y))
                    }
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
        /*
		****************************************
		Update
		****************************************
		*/
	RectangleShape rect(Vector2f(10, 10));
        rect.setPosition(event.mouseButton.x, event.mouseButton.y);
        rect.setFillColor(Color::Blue);
		
	int midpoint_x, midpoint_y;
	int point = rand() %3;
	int scale=1/2;
        if(points.size() > 0)
        {
            ///generate more point(s)
            ///select random vertex
            ///calculate midpoint between random vertex and the last point in the vector
            ///push back the newly generated coord.
		midpoint_x= points[points.size()-1].x - (vertices[points].x - points[points.size() -1].x) *scale;
		midpoint_y= points[points.size()-1].y - (vertices[points].y - points[points.size() -1].y) *scale;
		//new coordinate is pushed back
		
	    cout << "points[point.size() - 1].x\t" << points[points.size() - 1].x << endl;
            cout << "vertices[point].x\t" << vertices[point].x << endl;
            cout << "scale\t" << scale << endl;
            cout << "midpoint_x\t" << midpoint_x << endl;
            cout << "midpoint_y\t" << midpoint_y << endl << endl;
		
		RectangleShape rect(Vector2f(10, 10));
            rect.setSize(Vector2f(10, 10));
      		rect.setPosition(midpoint_x, midpoint_y);
        }

        /*
		****************************************
		Draw
		****************************************
		*/
        window.clear();
        for(int i = 0; i < vertices.size(); i++)
        {
            RectangleShape rect(Vector2f(10,10));
            rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
            rect.setFillColor(Color::Blue);
            window.draw(rect);
        }
        window.display();
    }
}
