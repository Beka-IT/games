#include<SFML/Graphics.hpp>
using namespace sf;

class Util{
public:
    Sprite spr;
    Texture tex;
    String filename;
    float x,y;
    bool toMagnet;
    Util(String F){
        filename = F;
        tex.loadFromFile("img/"+filename);
        spr.setTexture(tex);
        spr.setPosition(0,0);
        toMagnet = false;

    }
   // virtual void usingUtil(int dir) = 0;
    void comeToMagnetto(){
        toMagnet = true;

    }
};
class Shield:public Util{
    public:
    Shield(float x,float y):Util("shield.png"){
        this->x = x;this->y = y;
        spr.setPosition(x+35.5,y-50);
        spr.setTextureRect(IntRect(0,0,0,0));
    }
    void usingUtil(int dir,float x,float y,bool isShield){
        if(dir == 0){
            spr.setPosition(x+34.5,y+10);
            if(isShield)spr.setTextureRect(IntRect(25,3,22,40));
            else spr.setTextureRect(IntRect(0,0,0,0));
        }else if(dir == 1){
            spr.setPosition(x-10,y+10);
            if(isShield)spr.setTextureRect(IntRect(0,0,22,40));
            else spr.setTextureRect(IntRect(0,0,0,0));
        }
    }
};

class FlameThrower:public Util{
public:
    Sprite fire;
    Texture fire_tex;
    float currentFrame;
    bool isShoot,toBack;
    FlameThrower(float x,float y):Util("a1.png"){
        fire_tex.loadFromFile("img/fire.png");
        fire.setTexture(fire_tex);
        fire.setTextureRect(IntRect(0,20,0,0));
        fire.setPosition(x-10,y-41);
        spr.setPosition(x+5,y-35);
        spr.setTextureRect(IntRect(0,0,0,0));
        currentFrame = 0;
        isShoot = false;
        toBack = false;
        this->x = x;this->y = y;
    }
    void usingUtil(int dir,float x,float y,bool isFlame){
        if(dir == 0){
            spr.setPosition(x+5,y+22);
            fire.setPosition(x+55,y+15);
            if(isFlame)spr.setTextureRect(IntRect(0,0,50,20));
            else spr.setTextureRect(IntRect(0,0,0,0));
        }else if(dir == 1){
            spr.setPosition(x-10,y+22);
            if(isFlame)spr.setTextureRect(IntRect(50,0,50,20));
            else spr.setTextureRect(IntRect(0,0,0,0));
        }
        this->x = x;this->y = y;
    }
    void toShoot(int dir){
        if(isShoot){
            if(!toBack)currentFrame += 0.05;
            else currentFrame -= 0.1;
            if(dir == 0){
                if(currentFrame<1)fire.setTextureRect(IntRect(0,0,20,20));
                else if(currentFrame<2)fire.setTextureRect(IntRect(20,0,30,20));
                else if(currentFrame<3)fire.setTextureRect(IntRect(50,0,45,20));
                else if(currentFrame<4)fire.setTextureRect(IntRect(95,0,75,20));
                else if(currentFrame<5)fire.setTextureRect(IntRect(170,0,75,20));
                else{
                    toBack = true;
                }

            }else if(dir == 1){
                if(currentFrame<1){
                    fire.setTextureRect(IntRect(0,20,20,20));
                    fire.setPosition(x-30,y+20);
                }
                else if(currentFrame<2){
                    fire.setTextureRect(IntRect(20,20,30,20));
                    fire.setPosition(x-40,y+20);
                }
                else if(currentFrame<3){
                    fire.setTextureRect(IntRect(55,20,45,20));
                    fire.setPosition(x-55,y+20);
                }
                else if(currentFrame<4){
                    fire.setTextureRect(IntRect(98,20,75,20));
                    fire.setPosition(x-85,y+20);
                }
                else if(currentFrame<5){
                    fire.setTextureRect(IntRect(173,20,75,20));
                    fire.setPosition(x-85,y+20);
                }
                else{
                    toBack = true;
                }
            }
            if(currentFrame<0){
                    fire.setTextureRect(IntRect(0,0,0,0));
                    toBack = false;
                    isShoot = false;
            }
        }else{fire.setTextureRect(IntRect(0,0,0,0));}
    }

};
class Shoker:public Util{
public:
    Sprite shock;
    Texture shock_tex;
    float currentFrame;
    bool isShoot,isDie;
    Shoker(float x,float y):Util("orb.png"){
        this->x = x;this->y = y;
        spr.setPosition(x+35.5,y-30);
        spr.setTextureRect(IntRect(0,0,20,20));
        isShoot = false;
        isDie = false;
        shock_tex.loadFromFile("img/lighting.png");
        shock.setTexture(shock_tex);
        shock.setTextureRect(IntRect(0,0,0,0));
    }
    void usingUtil(int dir,float x,float y,bool isShoker){
        if(dir == 0){
            spr.setPosition(x+35.5,y+30);
            if(isShoker)spr.setTextureRect(IntRect(0,0,20,20));
            else spr.setTextureRect(IntRect(0,0,0,0));
        }else if(dir == 1){
            spr.setPosition(x-10,y+30);
            if(isShoker)spr.setTextureRect(IntRect(0,0,20,20));
            else spr.setTextureRect(IntRect(0,0,0,0));
        }
        this->x = x;this->y = y;
    }
    void check_shoker(int x,int y){
        if(this->x>=x){
            toShock(x,y);
            isDie = true;
            spr.setTextureRect(IntRect(0,0,0,0));
        }
    }
    void toShock(int x,int y){
        currentFrame += 0.07;
        if(currentFrame < 3){
            shock.setTextureRect(IntRect(65.3*int(currentFrame),0,65.3,63));
        }else if(currentFrame < 6){
            shock.setTextureRect(IntRect(65.3*(int(currentFrame-3)),65.3,65.3,63));
        }else if(currentFrame < 9){
            shock.setTextureRect(IntRect(65.3*(int(currentFrame)-6),130.6,65.3,63));
        }else{
            shock.setTextureRect(IntRect(0,0,0,0));
        }
        shock.setPosition(x,y);
    }
};


