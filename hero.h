#include <SFML/Graphics.hpp>
using namespace sf;

class Hero{
public:
    Sprite spr;
    Sprite para;
    Texture tex;
    Texture tex_para;
    int health,dir;
    float x,y,currentFrame,a,g;
    bool isJump,isDie,isPara;
    Hero(float x,float y){
        this->x = x;
        this->y = y;
        health = 5;
        tex.loadFromFile("img/hero.png");
        tex_para.loadFromFile("img/parachute.png");
        para.setTexture(tex_para);
        spr.setTexture(tex);
        spr.setTextureRect(IntRect(0,60,47.5,60));
        spr.setPosition(this->x,this->y);
        para.setPosition(this->x-1.25,this->y-100);
        para.setTextureRect(IntRect(0,0,0,0));
        currentFrame = 0;
        isJump = false;
        g = -0.005;
        a = 1;
        isDie = false;
        isPara = false;
        dir = 0;
    }
    void moveRight(float time){
        if(!(x>272&&x<272.5&&!isJump)&&!(x+47.5>=1869.5&&x+47.5<1870&&y+60>362)
           &&!(x+47.5>=2899.5&&x+47.5<2900&&y+60>1030)&&!(x+47.5>=4822.5&&x+47.5<4823&&y+60>1360)
           &&!(x+47.5>=4932&&x+47.5<4932.5&&y+60>1320)&&!(x+47.5>=5042.5&&x+47.5<5043&&y+60>1277)
           &&!(x+47.5>=5158&&x+47.5<5158.5&&y+60>1250)){
            x += 0.28;
            spr.setPosition(x,y);
            para.setPosition(this->x-1.25,this->y-40);
            currentFrame += 0.005*time;
            if(currentFrame>3)currentFrame-=3;
            spr.setTextureRect(IntRect(47.5*int(currentFrame),60,47.5,60));
            view.setCenter(x+23.75,y-100);
            dir = 0;
        }
    }
    void moveLeft(float time){
        if(!(x>1951.5&&x<=1952&&y+60>362)&&!(x>2520.5&&x<=2521&&y+60>426)
           &&!(x>0&&x<=0.5)&&!(x>3326&&x<=3326.5&&y+60>1030)&&!(x>3364&&x<=3364.5&&y+60>1050)
           &&!(x>3404&&x<=3404.5&&y+60>1090)&&!(x>3443&&x<=3443.5&&y+60>1130)
           &&!(x>3484&&x<=3484.5&&y+60>1170)&&!(x>3524&&x<=3524.5&&y+60>1210)
           &&!(x>3563&&x<=3563.5&&y+60>1250)&&!(x>3603&&x<=3603.5&&y+60>1290)
           &&!(x>3643&&x<=3643.5&&y+60>1330)&&!(x>3682&&x<=3682.5&&y+60>1370)){
            x -= 0.28;
            para.setPosition(this->x-1.25,this->y-40);
            spr.setPosition(x,y);
            currentFrame += 0.005*time;
            if(currentFrame>3)currentFrame-=3;
            spr.setTextureRect(IntRect(47.5*int(currentFrame),0,47.5,60));
            view.setCenter(x+23.75,y-100);
            dir = 1;
        }
    }
    void jump(){
        if(!(x>2520&&x+47.5<=2900&&y+60<1089))isJump = true;
    }
    void update(){
        if(isJump){
            if(a <= -0.99){
                isJump = false;
                a = 1;
            }
            else{y -= a+g;
            spr.setPosition(x,y);
            para.setPosition(this->x-1.25,this->y-40);
            a+=g;}

        }
        view.setCenter(x+23.75,y-100);
    }
    void die(){
        x = 10;
        y = 488;
        spr.setPosition(x,y);
        para.setPosition(this->x-1.25,this->y-40);
        isDie = true;
    }
};
