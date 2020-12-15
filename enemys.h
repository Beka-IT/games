#include <SFML/Graphics.hpp>
using namespace sf;

class Enemy{
public:
    Sprite spr;
    Sprite hum_spr;
    Texture tex;
    Texture tex_hum;
    RectangleShape proccess;
    float x,y,transformation;
    int dir;
    bool vaccinating;
    Enemy(String F,float x,float y){
        tex.loadFromFile("img/"+F);
        spr.setTexture(tex);
        this->x = x;this->y = y;
        dir = 0;
        spr.setPosition(x,y);
        tex_hum.loadFromFile("img/boy.png");
        hum_spr.setTexture(tex_hum);
        hum_spr.setPosition(this->x,this->y);
        hum_spr.setTextureRect(IntRect(0,0,0,0));
        transformation = 100;
        Vector2f size(0,0);
        proccess.setSize(size);
        proccess.setFillColor(Color::Yellow);
        proccess.setPosition(this->x,this->y-20);
        vaccinating = false;
    }
    void becomeToPerson(){
        if(transformation>0){
            transformation-=0.2;
            Vector2f size(transformation,10);
            proccess.setSize(size);

        }else{
            spr.setTextureRect(IntRect(0,0,0,0));
            hum_spr.setTextureRect(IntRect(0,0,25,44));
        }
    }
    void startVaccination(){
        vaccinating = true;
    }
    virtual void attack() = 0;
};


class Thor:public Enemy{
public:
    Thor():Enemy("thor.png",630,380){
        spr.setTextureRect(IntRect(0,0,45,50));
    }
    void attack(){

    }
};
