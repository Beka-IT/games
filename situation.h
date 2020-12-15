#include <SFML/Graphics.hpp>
using namespace sf;
void last_place(Hero&hero,int x1,int x2,int y){
    if(hero.x+47.5>x1&&hero.x<x2&&hero.y+60>y&&hero.isJump){
        hero.y = y-60;
        hero.isJump = false;
        hero.a = 1;
    }else if(hero.x+47.5>x1&&hero.x<=x2&&hero.y+60<=y&&!hero.isJump){
        hero.y +=0.5;
        hero.spr.setPosition(hero.x,hero.y);
    }
}

void box_place(Hero&hero,int x1,int x2,int y){
     if(hero.x>x1&&hero.x+20<=x2&&hero.y+60>=y&&hero.isJump){
        hero.y = y-60;
        hero.isJump = false;
        hero.a = 1;

    }
    else if(hero.x>x1&&hero.x+20<=x2&&hero.y+60<=y&&!hero.isJump){
        hero.y +=0.5;
        hero.spr.setPosition(hero.x,hero.y);
    }

}
void way_place(Hero&hero,int x1,int x2,int y){
     if(hero.x+20.5>x1&&hero.x<=x2&&hero.y+60>=y&&hero.isJump){
        hero.y = y-60;
        hero.isJump = false;
        hero.a = 1;

    }
    else if(hero.x+20.5>x1&&hero.x<=x2&&hero.y+60<=y&&!hero.isJump){
        hero.y +=0.5;
        hero.spr.setPosition(hero.x,hero.y);
    }
}

int check_place(Hero &hero,Elevator &elev1,Elevator &elev2){
    if(hero.x>=0 && hero.x+47.5<=320&&hero.y+60<=488&&!hero.isJump){
        hero.y += 0.5;
        hero.spr.setPosition(hero.x,hero.y);
    }
    else if(hero.x>=0 && hero.x+47.5<=320&&hero.y+60>=488){
        hero.y = 428;
        hero.isJump = false;
        hero.a = 1;
    }
    else if(hero.x+47.5>320&&hero.x<=740&&hero.y+60>=430&&hero.isJump){
        hero.y = 370;
        hero.isJump = false;
        hero.a = 1;

    }
    else if(hero.x+47.5>320&&hero.x<=740&&hero.y+60<=430&&!hero.isJump){
        hero.y +=0.5;
        hero.spr.setPosition(hero.x,hero.y);
    }

    else if(hero.x>=742&&hero.x+47.5<820&&hero.y+60>370){
        hero.die();
    }
    else if(hero.x+47.5>=820&&hero.x+47.5<1100&&hero.y+60<=380&&!hero.isJump){
        hero.y += 0.5;
        hero.spr.setPosition(hero.x,hero.y);
    }
    else if(hero.x+47.5>=820&&hero.x+47.5<1100&&hero.y+60>=380&&hero.isJump){
        hero.y = 320;
        hero.isJump = false;
        hero.a = 1;
    }
    else if(hero.x>=1100&&hero.x+47.5<1180&&hero.y+60>370){
        hero.die();
    }

    else if(hero.x+47.5>1180&&hero.x<=1690&&hero.y+60>=430&&hero.isJump){
        hero.y = 370;
        hero.isJump = false;
        hero.a = 1;

    }
    else if(hero.x+47.5>1180&&hero.x<=1690&&hero.y+60<=430&&!hero.isJump){
        hero.y +=0.5;
        hero.spr.setPosition(hero.x,hero.y);
    }
    else if(hero.x>=1690&&hero.x+47.5<1750&&hero.y+60>370){
        hero.die();
    }

    else if(hero.x+47.5>1750&&hero.x<=1830&&hero.y+60>=390&&hero.isJump){
        hero.y = 330;
        hero.isJump = false;
        hero.a = 1;

    }
    else if(hero.x+47.5>1750&&hero.x<=1830&&hero.y+60<=390&&!hero.isJump){
        hero.y +=0.5;
        hero.spr.setPosition(hero.x,hero.y);
    }
    else if(hero.x+47.5>1870&&hero.x<=1950&&hero.y+60>=362&&hero.isJump){
        hero.y = 302;
        hero.isJump = false;
        hero.a = 1;

    }
    else if(hero.x+47.5>1870&&hero.x<=1950&&hero.y+60<=362&&!hero.isJump){
        hero.y +=0.5;
        hero.spr.setPosition(hero.x,hero.y);
    }
    else if(hero.x+47.5>1990&&hero.x<=2070&&hero.y+60>=390&&hero.isJump){
        hero.y = 330;
        hero.isJump = false;
        hero.a = 1;

    }
    else if(hero.x+47.5>1990&&hero.x<=2070&&hero.y+60<=390&&!hero.isJump){
        hero.y +=0.5;
        hero.spr.setPosition(hero.x,hero.y);
    }
    else if(hero.x>=2070&&hero.x+47.5<2130&&hero.y+60>=390){
        hero.die();
    }

    else if(hero.x+47.5>2180&&hero.x<=2520&&hero.y+60>=430&&hero.isJump){
        hero.y = 370;
        hero.isJump = false;
        hero.a = 1;

    }
    else if(hero.x+47.5>2180&&hero.x<=2520&&hero.y+60<=430&&!hero.isJump&&hero.x+47.5<2900){
        hero.y +=0.5;
        hero.spr.setPosition(hero.x,hero.y);
    }

    else if(hero.x>2520&&!hero.isJump&&hero.y+60<1090&&hero.x+47.5<2900){
        if(hero.isPara){
            hero.y+=0.2;
            hero.para.setPosition(hero.x-1.25,hero.y-40);
            if(hero.y+60>=1080)hero.para.setTextureRect(IntRect(0,0,0,0));
        }
        else {
            hero.y+=2;
            if(hero.y+60 >= 1070)hero.die();
        }
        hero.spr.setPosition(hero.x,hero.y);
    }


    else if(hero.x+47.5>2900&&hero.x<=3327&&hero.y+60>=1030&&hero.isJump){
        hero.y = 970;
        hero.isJump = false;
        //hero.a = 1;

    }
    else if(hero.x+47.5>2900&&hero.x<=3327&&hero.y+60<=1030&&!hero.isJump){
        hero.y += 0.5;
        hero.spr.setPosition(hero.x,hero.y);
        hero.a = 1;
    }
    box_place(hero,3327,3364,1050);
    box_place(hero,3364,3404,1090);
    box_place(hero,3404,3444,1130);
    box_place(hero,3444,3484,1170);
    box_place(hero,3484,3524,1210);
    box_place(hero,3524,3563,1250);
    box_place(hero,3563,3604,1290);
    box_place(hero,3604,3644,1330);
    box_place(hero,3644,3683,1370);
    way_place(hero,3683,4015,1410);
    if(hero.x>4015&&hero.x+47.5<=4420){
        if(hero.y+60<=1410){
            if(hero.x+47.5>elev1.x&&hero.x<elev1.x+120){
                if(hero.y+60>=elev1.y){
                    if(hero.isJump){
                        hero.y = elev1.y-60;
                        hero.isJump = false;
                        hero.a = 1;
                    }
                }else{
                    if(!hero.isJump)hero.y = elev1.y-60;
                }
                if(hero.y==elev1.y-60){
                    if(elev1.x+120<=elev1.x2&&!elev1.toLeft){
                        hero.x+=0.3;
                    }else if(elev1.x>=elev1.x1){
                        hero.x-=0.3;
                    }
                    hero.spr.setPosition(hero.x,hero.y);
                }
            }else{
                if(!hero.isJump){
                    hero.y += 0.5;
                }
            }
        }else{
            hero.die();
        }

    }
    last_place(hero,4420,4778,1410);
    last_place(hero,4822,4907,1360);
    last_place(hero,4932,5018,1320);
    last_place(hero,5042,5126,1277);
    last_place(hero,5158,5579,1250);
    last_place(hero,5723,6662,940);
    if(hero.x>5578&&hero.x+47.5<=5723){
        elev2.moveVertikal();
        if(elev2.toUp){
            hero.y-=0.2;
        }
        hero.spr.setPosition(hero.x,hero.y);
    }
    if(hero.x+47.5>6590){
        return true;
    }
    return false;

}
