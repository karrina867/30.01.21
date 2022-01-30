#include"SFML/Graphics.hpp"
#include"const.h"
#include"boll.h"
#include"bat.h"
#include"left bat.h"
#include"right bat.h"
#include"text_obgect.h"
using namespace sf;
int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Works!");
	window.setFramerateLimit(60);
	//�������� ������� ��������
	Ball ball;
	LeftBat left_bat(20, SCREEN_HEIGHT / 2 - 50);
	RightBat right_bat(SCREEN_WIDTH -40, SCREEN_HEIGHT / 2 - 50);
	TextObj left_score(SCREEN_WIDTH * 1 / 5, 20);
	TextObj right_score(SCREEN_WIDTH * 4/ 5, 20);


	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// 1 ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
		// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		//2 update (��������� ������� ��������
		ball.update();
		left_bat.update();
		right_bat.update();
		left_score.update(std::to_string(ball.getLeftScore()));
		right_score.update(std::to_string(ball.getRightScore()));
		//��������� ������������
		if (ball.getHitBox().intersects(left_bat.getHitBox())) {
			//������ ����
			ball.reboundHorizontal();
			if (left_bat.getHitBox().contains(ball.getMidBottom())) {
				ball.setPosition(sf::Vector2f(ball.getPosition().x, left_bat.getPosition().y- 2*ball.getRadius()));
				ball.reboundVertical();
			}
			else if (left_bat.getHitBox().contains(ball.getMidLeft())) {
				ball.reboundHorizontal();
			}
			else if (left_bat.getHitBox().contains(ball.getMidTop())) {
				ball.setPosition(sf::Vector2f(ball.getPosition().x, left_bat.getPosition().y + 2 * left_bat.getHaight()));
				ball.reboundVertical();
			}
		}
		if (ball.getHitBox().intersects(right_bat.getHitBox())) {
			ball.reboundHorizontal();
		}
		// 3  ��������� ����
		//3.1 ������� ����
		window.clear(Color(60, 60, 60, 0));
		// 3.2 ������ ������� ������� (� ������)
		window.draw(ball.getShape());
		window.draw(left_bat.getShape());
		window.draw(right_bat.getShape());
		window.draw(left_score.getText());
		window.draw(right_score.getText());
		// 3.3 ����������� �� ������
		window.display();
	}
	return 0;
} 