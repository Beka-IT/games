#include <SFML/Graphics.hpp>
using namespace sf;

View view;

void moveCamera(){
    if(Keyboard::isKeyPressed(Keyboard::Right)){
        view.move(3,0);
    }
    if(Keyboard::isKeyPressed(Keyboard::Left)){
        view.move(-3,0);
    }
    if(Keyboard::isKeyPressed(Keyboard::Up)){
        view.move(0,-0.5);
    }
    if(Keyboard::isKeyPressed(Keyboard::Down)){
        view.move(0,0.5);
    }
}

class Elevator{
public:
    Sprite spr;
    Texture tex;
    float x,y,x1,x2,y1,y2;bool toLeft;bool toUp;
    Elevator(String F,float X,float Y,float X1,float X2,float Y1,float Y2){
        x = X;y = Y;x1 = X1;x2 = X2;y1 = Y1;y2 = Y2;
        tex.loadFromFile("img/"+F);
        spr.setTexture(tex);
        spr.setPosition(x,y);
        toLeft = false;toUp = false;
    }
    void moveHorizont(){
        if(x<=x1)toLeft = false;
        if(x+120<=x2&&!toLeft){
            x+=0.3;
        }else if(x>=x1){
           x-=0.3;
           toLeft = true;
        }
        spr.setPosition(x,y);
    }
    void moveVertikal(){
        toUp = true;
        if(y>y2){
            y-=0.2;
        }else toUp = false;
        spr.setPosition(x,y);
    }
};
