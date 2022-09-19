#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace sf;

int main() {
	// open a window
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "CHAOS GAME", Style::Fullscreen);
	RectangleShape rectangle;

	vector<Vector2f> vertices;
	vector<Vector2f> points;

	window.clear();

	while (window.isOpen()) {

		Event event;

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		Font font;
		Text text;
		Text text1;
		text.setFont(font);
		text.setString("Welcome to the Chaos Game! Press 3 points for the veritices! Click again after to start the loop!");
		text.setPosition(20,20);
		text.setCharacterSize(20);
		//text.setFillColor(Color::Blue);
		window.draw(text);
		window.display();

		while (window.pollEvent(event)) // first loop that gets inputs
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					cout << "the right button was pressed" << endl;
					cout << "mouse x: " << event.mouseButton.x << endl;
					cout << "mouse y: " << event.mouseButton.y << endl;

					if (vertices.size() < 3)
					{
						vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
					}
					else if (points.size() == 0)
					{
						//fourth click
						points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
					}
				}
			}
		}

		RectangleShape rect(Vector2f(10, 10));
		rect.setPosition(event.mouseButton.x, event.mouseButton.y);
		rect.setFillColor(Color::Magenta);

		int midpoint_x, midpoint_y;
		int vert_select = rand() % 3;
		//double scale_factor = 0.5;



		if (points.size() > 0)
		{
			//generate more points
			//select random vertex
			//calculate midpoints between random vertex and the last point in the vector
			//push back to the newly generated coord.


			midpoint_x = (points[points.size() - 1].x + vertices[vert_select].x) /2;
			midpoint_y = (points[points.size() - 1].y + vertices[vert_select].y) /2;

			cout << "points size: " << points.size() << endl;
			cout << "points x: " << points[points.size() - 1].x << endl;
			cout << "points y: " << points[points.size() - 1].y << endl;
			cout << "vertices x: " << vertices[vert_select].x << endl;
			cout << "vertices y: " << vertices[vert_select].y << endl;
			//cout << "scale factor" << scale_factor << endl;
			cout << "midpoint x: " << midpoint_x << endl;
			cout << "midpoint y: " << midpoint_y << endl << endl;
			
			points.push_back(Vector2f(midpoint_x, midpoint_y));

		}


		switch (event.type) {

			// this case makes a 10 by 10 pixel dot where mouse clicks
		case Event::MouseButtonPressed:
			rect.setSize(Vector2f(10, 10));
			rect.setPosition(event.mouseButton.x, event.mouseButton.y);
			break;
		}


		/// its for the first 4 dot inputs
		/// second vector goes here for the points that get put in for the
		/// triangle now we have a while loop that goes through with the
		/// algorithm and draw a triangle

		
		for (int i = 0; i < vertices.size(); i++)
		{
			RectangleShape rect(Vector2f(5, 5));
			rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
			rect.setFillColor(Color::Blue);
			window.draw(rect);
		}

		for (int i = 0; i < points.size(); i++)
		{
			RectangleShape rect(Vector2f(2, 2));
			rect.setPosition(Vector2f(points[i].x, points[i].y));
			rect.setFillColor(Color::Red);
			window.draw(rect);
		}

		// Show everything that we drew
		window.display();
	}

	return 0;
}