#include <SFML/Graphics.hpp>
#include <iostream>
#include "view.h"
#include "hero.h"
#include "situation.h"
#include "utils.h"
#include "enemys.h"
using namespace sf;

int main(){
    RenderWindow window(VideoMode(800,500),"Vaccination 1");
    view.reset(FloatRect(0,100,800,500));
    Texture map_tex;
    Texture map2_tex;
    map_tex.loadFromFile("img/map.png");
    map2_tex.loadFromFile("img/map2.png");
    Sprite map;
    Sprite map2;
    map.setTexture(map_tex);
    map2.setTexture(map2_tex);
    map2.setPosition(4000,0);
    Elevator elev1("elevator.png",4040,1380,4040,4390,1380,1380);
    Elevator elev2("elevator.png",5590,1250,5590,5590,1250,940);
    Hero hero(20,488);
    Shield shield(20,488);
    FlameThrower flame(20,488);
    Shoker shoker(20,488);
    Font font;
    font.loadFromFile("f1.ttf");
    Text text("You won",font,40);
    text.setColor(Color::Green);
    text.setStyle(Text::Bold);
    text.setPosition(6150,740);

    Thor thor;

    Clock clock;
    Event e;
    bool isEnd= false,isShield = false,isFlame=false,isShoker=false;
    cycle:
    while(window.isOpen()){
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /=800;
        while(window.pollEvent(e)){
            if(e.type==Event::Closed){
                window.close();
            }
        }
        if(Keyboard::isKeyPressed(Keyboard::D)){
            hero.moveRight(time);
        }
        if(Keyboard::isKeyPressed(Keyboard::A)){
            hero.moveLeft(time);
        }
        if(Keyboard::isKeyPressed(Keyboard::Space)){
            hero.jump();
        }
        if(Keyboard::isKeyPressed(Keyboard::P)){
            hero.isPara = true;
            hero.para.setTextureRect(IntRect(0,0,50,80));
        }
        hero.update();
        if(hero.x>=6237){
            view.setCenter(6260,hero.y-100);
        }
        if(hero.x<376){
            view.setCenter(400,hero.y-100);
        }
        if(Keyboard::isKeyPressed(Keyboard::R)){
            isShield = true;
            isFlame = false;
            isShoker = false;
        }
        if(Keyboard::isKeyPressed(Keyboard::F)){
            isFlame = true;
            isShield = false;
            isShoker = false;
        }
        if(Keyboard::isKeyPressed(Keyboard::V)){
            isFlame = false;
            isShield = false;
            isShoker = true;
        }
        if(Keyboard::isKeyPressed(Keyboard::Q)&&isFlame){
            flame.isShoot = true;
        }
        if(Keyboard::isKeyPressed(Keyboard::E)){
            flame.comeToMagnetto();
            flame.spr.setTextureRect(IntRect(0,0,50,20));
            shield.comeToMagnetto();
            shield.spr.setTextureRect(IntRect(25,3,22,40));
            shoker.comeToMagnetto();
            shoker.spr.setTextureRect(IntRect(0,0,20,20));
        }
        if(flame.toMagnet){
            flame.spr.move(0.5,0);
            flame.spr.setTextureRect(IntRect(0,0,50,20));
            isFlame = false;
        }
        if(shield.toMagnet){
            shield.spr.move(1,0);
            shield.spr.setTextureRect(IntRect(25,3,22,40));
            isShield = false;
        }
        if(shoker.toMagnet&&!shoker.isDie){
            shoker.spr.move(2,0);
            shoker.spr.setTextureRect(IntRect(0,0,20,20));
            shoker.x += 2;
            isShoker = false;
            std::cout<<shoker.x<<std::endl;
        }
        if(Keyboard::isKeyPressed(Keyboard::T)){
            shoker.isShoot = true;
            thor.startVaccination();
        }
        if(shoker.isShoot){
                shoker.comeToMagnetto();
                isShoker = false;
        }
        if(thor.vaccinating)thor.becomeToPerson();
        shoker.check_shoker(250,420);
        flame.toShoot(hero.dir);
        if(!shield.toMagnet)shield.usingUtil(hero.dir,hero.x,hero.y,isShield);
        if(!flame.toMagnet)flame.usingUtil(hero.dir,hero.x,hero.y,isFlame);
        if(!shoker.toMagnet&&!shoker.isDie)shoker.usingUtil(hero.dir,hero.x,hero.y,isShoker);
        elev1.moveHorizont();
        isEnd = check_place(hero,elev1,elev2);
        moveCamera();
        window.setView(view);
        window.clear();
        window.draw(map);
        window.draw(map2);
        window.draw(elev1.spr);
        window.draw(elev2.spr);
        window.draw(flame.spr);
        window.draw(hero.spr);
        window.draw(hero.para);
        window.draw(shield.spr);
        window.draw(flame.fire);
        window.draw(shoker.spr);
        window.draw(shoker.shock);
        window.draw(thor.spr);
        window.draw(thor.proccess);
        window.draw(thor.hum_spr);
        if(isEnd)window.draw(text);
        window.display();
        if(hero.isDie){
            hero.isDie = false;
            goto cycle;
        }
    }
    return 0;
}
