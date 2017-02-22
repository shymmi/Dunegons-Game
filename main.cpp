#include<iostream>
#include<allegro.h>

bool collision(int x, int y, int w, int h, int x2, int y2, int w2, int h2)
{
	if(x+w < x2 || y+h < y2 || x > x2+w2 || y > y2+h2)
		return false;
	else
		return true;
}
inline void init()
{
    /*allegro_init();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);*/
    install_timer();
}

int main()
{
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth( 16 );
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
    BITMAP * menu = NULL;
    BITMAP * buffer = NULL;
    BITMAP * option = NULL;
    BITMAP * music = NULL;
    buffer = create_bitmap(640,480);
    menu = load_bmp( "menu.bmp", default_palette);
    option = load_bmp( "options.bmp", default_palette );
    music = load_bmp( "music.bmp", default_palette );
    install_sound( DIGI_AUTODETECT, MIDI_AUTODETECT, "" );
    set_volume( 255, 255 );
    SAMPLE * dzwiek = NULL;
    SAMPLE * klik = NULL;
    dzwiek = load_sample( "muzyczka.wav" );
    klik = load_sample( "klik.wav" );
    play_sample( dzwiek, 255, 127, 1000, 1 );
    show_mouse(screen);
    blit( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
    masked_blit( menu, buffer, 0, 0, 0, 0, menu->w, menu->h );
    int score = 0, ex = 100, why = 100;
	bool quit = false, options = false, bMenu = true, gameop = false,play=false,muzyka=true,krew=true;
    BITMAP * floor = NULL;
    BITMAP * wall = NULL;
    BITMAP * door = NULL;
    BITMAP * klucz = NULL;
    BITMAP * enemy1 = NULL;
    BITMAP * enemy1_2 = NULL;
    BITMAP * enemy2 = NULL;
    BITMAP * enemy2_2 = NULL;
    BITMAP * enemy3 = NULL;
    BITMAP * enemy3_2 = NULL;
    BITMAP * pot = NULL;
    BITMAP * attack_one = NULL;
    BITMAP * attack_two = NULL;
    BITMAP * attack_three = NULL;
    BITMAP * attack_pot = NULL;
    BITMAP * sword = NULL;
    BITMAP * exit = NULL;
    BITMAP * hero = NULL;
    BITMAP * hero_2 = NULL;
    BITMAP * hp = NULL;
    BITMAP * hp_full = NULL;
    BITMAP * background = NULL;
    BITMAP * enemy = NULL;
    BITMAP * key_2 = NULL;
    BITMAP * pot_2 = NULL;
    BITMAP * blood = NULL;
    BITMAP * tablica = NULL;
    BITMAP * tablica2 = NULL;
    tablica2 = load_bmp ( "wygrana.bmp", default_palette);
    tablica = load_bmp ( "koniec.bmp", default_palette);
    floor = load_bmp( "floor.bmp", default_palette );
    wall = load_bmp( "wall.bmp", default_palette );
    door = load_bmp( "door.bmp", default_palette );
    klucz = load_bmp( "key.bmp", default_palette );
    sword = load_bmp( "sword.bmp", default_palette );
    exit = load_bmp( "exit.bmp", default_palette );
    hero = load_bmp( "hero.bmp", default_palette );
    hero_2 = load_bmp( "hero_2.bmp", default_palette );
    enemy1 = load_bmp( "waz.bmp", default_palette );
    enemy1_2 = load_bmp( "waz_2.bmp", default_palette );
    enemy2 = load_bmp( "oko.bmp", default_palette );
    enemy2_2 = load_bmp( "oko_2.bmp", default_palette );
    enemy3 = load_bmp( "gorgon.bmp", default_palette );
    enemy3_2 = load_bmp( "gorgon_2.bmp", default_palette );
    pot = load_bmp( "pot.bmp", default_palette );
    attack_one = load_bmp( "attack_one.bmp", default_palette );
    attack_two = load_bmp( "attack_two.bmp", default_palette );
    attack_three = load_bmp( "attack_three.bmp", default_palette );
    attack_pot = load_bmp( "attack_pot.bmp", default_palette );
    hp = load_bmp( "hp.bmp", default_palette );
    hp_full = load_bmp( "hp_full.bmp", default_palette );
    key_2 = load_bmp( "key_2.bmp", default_palette );
    pot_2 = load_bmp( "pot_2.bmp", default_palette );
    blood = load_bmp ( "blood.bmp",default_palette );
    background = load_bmp( "background.bmp", default_palette );
    while(!key[ KEY_ESC ])
	{
	    ex = mouse_x;
	    why = mouse_y;
        if(bMenu == true)
        {
            blit(menu, buffer, 0, 0, 0, 0, menu->w, menu->h);
            if(collision(ex, why, 0, 0, 250, 167, 140, 36) == true)
            {
                rect(buffer, 390, 176, 250, 207, makecol(255, 255, 255));
                if(mouse_b & 1)
                {
                    play_sample( klik, 255, 127, 1000, 0 );
                    play = true;
                    bMenu = false;
                }
            }
            if(collision(ex, why, 0, 0, 225, 207, 160, 36) == true)
            {
                rect(buffer, 400, 216, 234, 250, makecol(255, 255, 255));
                if(mouse_b & 1)
                {
                    play_sample( klik, 255, 127, 1000, 0 );
                    gameop = true;
                    bMenu = false;
                }

            }
            if(collision(ex, why, 0, 0, 255, 250, 100, 32) == true)
             {
                 rect(buffer, 267, 283, 355, 255, makecol(255,255,255));
                if(mouse_b & 1)
                {
                    play_sample( klik, 255, 127, 1000, 0 );
                    options = true;
                    bMenu = false;
                }
             }
            if(collision(ex, why, 0, 0, 275, 296, 60, 25) == true)
            {
                rect(buffer, 283, 322, 336, 290, makecol(255, 255, 255));
                if(mouse_b & 1)
                {
                    play_sample( klik, 255, 127, 1000, 0 );
                    break;
                }
            }
        }
         if(gameop == true)
        {
            blit(option, buffer, 0, 0, 0, 0, option->w, option->h);
            if(collision(ex, why, 0, 0, 273, 380, 70, 35) == true)
            {
                rect(buffer, 273, 410, 346, 380, makecol(255, 255, 255));
                if(mouse_b & 1)
                {
                    play_sample( klik, 255, 127, 1000, 0 );
                    bMenu = true;
                    gameop = false;
                }
            }
            if(collision(ex, why, 0, 0, 306, 337, 36, 33) == true)
            {
                rect(buffer, 309, 370, 345, 337, makecol(255, 255, 255));
                if(mouse_b & 1)
                {
                    krew = true;
                }
            }
            if(collision(ex, why, 0, 0, 355, 337, 37, 33) == true)
            {
                rect(buffer, 355, 370, 392, 337, makecol(255, 255, 255));
                if(mouse_b & 1)
                {
                    krew = false;
                }
            }
            if(key[KEY_ENTER])
            {
                bMenu = true;
                gameop = false;
            }
        }
        if(options == true)
        {
            blit(music, buffer, 0, 0, 0, 0, music->w, music->h);
            if(collision(ex, why, 0, 0, 273, 380, 70, 35) == true)
            {
                rect(buffer, 273, 410, 346, 380, makecol(255, 255, 255));
                if(mouse_b & 1)
                {
                    play_sample( klik, 255, 127, 1000, 0 );
                    bMenu = true;
                    options = false;
                }
            }
            if(collision(ex, why, 0, 0, 306, 337, 36, 33) == true)
            {
                rect(buffer, 312, 370, 348, 337, makecol(255, 255, 255));
                if(mouse_b & 1)
                {
                    muzyka = true;
                    play_sample( dzwiek, 255, 127, 1000, 1 );
                }
            }
            if(collision(ex, why, 0, 0, 360, 337, 37, 33) == true)
            {
                rect(buffer, 358, 370, 395, 337, makecol(255, 255, 255));
                if(mouse_b & 1)
                {
                    muzyka = false;
                    stop_sample( dzwiek );
                }
            }
            if(key[KEY_ENTER])
            {
                bMenu = true;
                options = false;
            }
        }

        if(play == true)
        {   //17165
            int board[21][32]=
            {
               { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
               { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
               { 1,1,5,5,0,1,5,1,1,1,1,0,0,0,41,1,5,3,5,1,1,1,0,0,0,0,1,5,5,6,1,1},
               { 1,1,1,1,41,1,3,1,1,5,1,0,1,1,5,1,1,41,1,1,1,1,0,1,1,1,1,1,5,5,1,1},
               { 1,1,1,1,0,1,42,1,1,43,0,0,1,1,1,1,0,0,0,0,0,2,0,1,0,0,0,1,1,2,1,1},
               { 1,1,0,0,0,1,0,1,1,1,0,0,1,3,5,1,0,0,0,0,1,1,1,1,0,1,0,1,1,0,1,1},
               { 1,1,0,0,0,1,0,1,1,1,1,2,1,41,1,1,0,0,0,0,1,1,1,1,0,1,0,0,2,0,1,1},
               { 1,1,1,1,2,0,0,0,2,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,1,1,1,1,1},
               { 1,1,3,1,1,1,0,0,1,1,1,2,1,1,0,0,1,1,1,0,1,1,1,1,0,1,43,1,1,1,1,1},
               { 1,1,43,0,0,0,0,1,1,1,1,0,1,1,0,0,0,1,1,0,0,0,0,0,0,1,3,5,3,5,1,1},
               { 1,1,1,1,0,1,1,1,1,1,0,0,1,1,0,0,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1},
               { 1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,1,1,1,1,0,1,1,1,1,5,1,1},
               { 1,1,1,1,0,1,1,1,0,1,1,1,3,42,0,0,0,1,1,0,1,1,1,0,0,0,0,0,41,3,1,1},
               { 1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,1,1,1,0,1,5,1,1},
               { 1,1,3,1,1,0,1,1,0,0,42,3,1,3,41,1,0,1,1,0,1,1,1,1,1,5,1,0,1,1,1,1},
               { 1,1,41,0,0,0,1,1,0,1,1,1,1,1,0,1,2,1,1,0,1,1,1,1,1,43,0,0,1,1,1,1},
               { 1,1,1,2,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,0,0,0,0,0,1,1,1,0,1,5,1,1},
               { 1,1,1,0,1,0,0,0,0,1,0,2,0,0,0,1,0,1,1,0,1,0,1,0,0,0,2,0,0,41,1,1},
               { 1,1,1,0,0,0,0,0,1,5,41,1,1,1,0,0,0,0,0,0,1,41,3,1,1,1,1,1,1,5,1,1},
               { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
               { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            };
            int i, j, los, k=0, heroi, heroj, klawisz=0, klawisz_walka=0, herodmg=3, hitchance=0, haskey=0,
            haspot=1, heromaxhp=18, herohp=18, enemy_1_hp=3, enemy_1_dmg=1, enemy_2_hp=5,
            enemy_2_dmg=3, enemy_3_hp=10, enemy_3_dmg=5, enemyhp, enemymaxhp, enemydmg;
            bool see[21][32];
            for(int j=0;j<21;j++)
                for(int i=0;i<32;i++)
                    see[j][i]=false;
            see[11][2]=true;
            see[11][3]=true;
            see[11][1]=true;
            see[12][1]=true;
            see[12][2]=true;
            see[12][3]=true;
            see[10][1]=true;
            see[10][2]=true;
            see[10][3]=true;
            see[11][4]=true;
            see[11][0]=true;
            see[ 9][2]=true;
            see[13][2]=true;
            heroi=2;
            heroj=11;
            board[heroj][heroi]=7;
            clear_to_color( buffer, makecol( 0, 0, 0 ) );
            for(int j=0;j<21;j++)
                for(int i=0;i<32;i++)
                {
                    if(see[j][i]==true)
                    {
                        if(board[j][i]==0)
                            masked_blit( floor , buffer, 0, 0, 20*i, 20*j, floor->w, floor->h );
                        if(board[j][i]==1)
                            masked_blit( wall  , buffer, 0, 0, 20*i, 20*j, wall->w , wall->h  );
                        if(board[j][i]==2)
                            masked_blit( door  , buffer, 0, 0, 20*i, 20*j, door->w , door->h  );
                        if(board[j][i]==3)
                            masked_blit( klucz   , buffer, 0, 0, 20*i, 20*j, klucz->w  , klucz->h   );
                        if(board[j][i]==41)
                            masked_blit( enemy1, buffer, 0, 0, 20*i, 20*j, enemy1->w, enemy1->h );
                        if(board[j][i]==42)
                            masked_blit( enemy2, buffer, 0, 0, 20*i, 20*j, enemy2->w, enemy2->h );
                        if(board[j][i]==43)
                            masked_blit( enemy3, buffer, 0, 0, 20*i, 20*j, enemy3->w, enemy3->h );
                        if(board[j][i]==5)
                            masked_blit( sword , buffer, 0, 0, 20*i, 20*j, sword->w, sword->h );
                        if(board[j][i]==6)
                            masked_blit( exit  , buffer, 0, 0, 20*i, 20*j, exit->w , exit->h  );
                        if(board[j][i]==7)
                            masked_blit( hero  , buffer, 0, 0, 20*i, 20*j, hero->w , hero->h  );
                        if(board[j][i]==8)
                            masked_blit( pot   , buffer, 0, 0, 20*i, 20*j, pot->w, pot->h );
                        if(board[j][i]==9)
                            masked_blit( blood , buffer, 0, 0, 20*i, 20*j, blood->w, blood->h );
                    }
                }
            masked_blit( hero_2   , buffer, 0, 0, 10, 430, hero_2->w, hero_2->h );
            for(i=0;i<heromaxhp;i++)
                masked_blit( hp_full   , buffer, 0, 0, 60 + 10*i,430, hp_full->w, hp_full->h );
            for(i=0;i<herohp;i++)
                masked_blit( hp   , buffer, 0, 0, 60 + 10*i,430 , hp->w, hp->h );
            masked_blit( hero_2   , buffer, 0, 0, 10, 430, hero_2->w, hero_2->h );

            if(haskey>0)
            {
                masked_blit( key_2   , buffer, 0, 0, 70 , 440, key_2->w, key_2->h );
            }
            if(haspot>0)
            {
                masked_blit( pot_2   , buffer, 0, 0, 110, 440, pot_2->w, pot_2->h );
            }
            blit( buffer, screen, 0, 0, 0, 0, 640, 480 );
            while( klawisz != 17165 )//15131 to esc
            {
                klawisz = readkey();
                if(klawisz == 20992)        //lewo
                {
                    if(board[heroj][heroi-1] != 1)
                    {
                        if(board[heroj][heroi-1] == 2)
                        {
                            if(haskey>0)
                            {
                                board[heroj][heroi-1]=0;
                                haskey--;
                                board[heroj][heroi]=0;
                                heroi--;
                            }
                        }
                        else
                        {
                            board[heroj][heroi]=0;
                            heroi--;
                        }

                    }
                }
                if(klawisz == 21248)    //prawo
                {
                    if(board[heroj][heroi+1] != 1)     //patrze czy to nei sciana
                    {
                        if(board[heroj][heroi+1] == 2)      // patrzce czy to nie drzwi
                        {
                            if(haskey>0)                    // jak ma klucz to wchodzi jak nie to nie
                            {
                                board[heroj][heroi+1]=0;
                                haskey--;
                                board[heroj][heroi]=0;
                                heroi++;
                            }
                        }
                        else                                // jak nie drzwi i nie sciana to po prostu idzie
                        {
                            board[heroj][heroi]=0;
                            heroi++;
                        }

                    }
                }
                if(klawisz == 21504)        //up
                {
                    if(board[heroj-1][heroi] != 1)
                    {
                        if(board[heroj-1][heroi] == 2)
                        {
                            if(haskey>0)
                            {
                                board[heroj-1][heroi]=0;
                                haskey--;
                                board[heroj][heroi]=0;
                                heroj--;
                            }
                        }
                        else
                        {
                            board[heroj][heroi]=0;
                            heroj--;
                        }

                    }
                }
                if(klawisz == 21760)         //down
                {
                    if(board[heroj+1][heroi] != 1)
                    {
                        if(board[heroj+1][heroi] == 2)
                        {
                            if(haskey>0)
                            {
                                board[heroj+1][heroi]=0;
                                haskey--;
                                board[heroj][heroi]=0;
                                heroj++;
                            }
                        }
                        else
                        {
                            board[heroj][heroi]=0;
                            heroj++;
                        }

                    }
                }
                if(klawisz == 7988)
                {
                    if(haspot>0)
                           {
                               haspot--;
                               herohp=heromaxhp;
                           }
                }
                if(board[heroj][heroi] == 3)        // sprawdzam czy znalazl klucz, jak tak to wrzucam go do inv
                    haskey++;
                if(board[heroj][heroi] == 5) // jak znajdzie miecz to dajemy dmg
                    herodmg+=2;
                if(board[heroj][heroi] == 6) // jak znajdzie exit to wywalic highscore/credits/menu w/e
                    {
                        while(!key[KEY_ENTER])
                        {
                            masked_blit(tablica2, screen, 0, 0, 170, 90, tablica2->w, tablica2->h);
                        }
                    }
                if(board[heroj][heroi] == 8)        // jak znajdzie potka do dodaje do inv
                    haspot++;
                board[heroj][heroi]=7; //stawiam hero w nowum miesjcu na planszy

                see[heroj-2][heroi  ]=true;
                see[heroj+2][heroi  ]=true;
                see[heroj-1][heroi-1]=true;
                see[heroj-1][heroi  ]=true;
                see[heroj-1][heroi+1]=true;
                see[heroj  ][heroi-2]=true;
                see[heroj  ][heroi-1]=true;
                see[heroj  ][heroi  ]=true;
                see[heroj  ][heroi+1]=true;
                see[heroj  ][heroi+2]=true;
                see[heroj+1][heroi-1]=true;
                see[heroj+1][heroi  ]=true;
                see[heroj+1][heroi+1]=true;

              clear_to_color( buffer, makecol( 0, 0, 0 ) );
                for(int j=0;j<21;j++)
                    for(int i=0;i<32;i++)
                    {
                        if(see[j][i]==true)
                        {
                            if(board[j][i]==0)
                                masked_blit( floor , buffer, 0, 0, 20*i, 20*j, floor->w, floor->h );
                            if(board[j][i]==1)
                                masked_blit( wall  , buffer, 0, 0, 20*i, 20*j, wall->w , wall->h  );
                            if(board[j][i]==2)
                                masked_blit( door  , buffer, 0, 0, 20*i, 20*j, door->w , door->h  );
                            if(board[j][i]==3)
                                masked_blit( klucz   , buffer, 0, 0, 20*i, 20*j, klucz->w  , klucz->h   );
                            if(board[j][i]==41)
                                masked_blit( enemy1, buffer, 0, 0, 20*i, 20*j, enemy1->w, enemy1->h );
                            if(board[j][i]==42)
                                masked_blit( enemy2, buffer, 0, 0, 20*i, 20*j, enemy2->w, enemy2->h );
                            if(board[j][i]==43)
                                masked_blit( enemy3, buffer, 0, 0, 20*i, 20*j, enemy3->w, enemy3->h );
                            if(board[j][i]==5)
                                masked_blit( sword , buffer, 0, 0, 20*i, 20*j, sword->w, sword->h );
                            if(board[j][i]==6)
                                masked_blit( exit  , buffer, 0, 0, 20*i, 20*j, exit->w , exit->h  );
                            if(board[j][i]==7)
                                masked_blit( hero  , buffer, 0, 0, 20*i, 20*j, hero->w , hero->h  );
                            if(board[j][i]==8)
                                masked_blit( pot   , buffer, 0, 0, 20*i, 20*j, pot->w, pot->h );
                            if(board[j][i]==9)
                                masked_blit( blood , buffer, 0, 0, 20*i, 20*j, blood->w, blood->h );
                        }
                    }
                masked_blit( hero_2   , buffer, 0, 0, 10, 430, hero_2->w, hero_2->h );
                for(i=0;i<heromaxhp;i++)
                    masked_blit( hp_full   , buffer, 0, 0, 60 + 10*i,430, hp_full->w, hp_full->h );
                for(i=0;i<herohp;i++)
                    masked_blit( hp   , buffer, 0, 0, 60 + 10*i,430, hp->w, hp->h );

                if(haskey>0)
                {
                    masked_blit( key_2   , buffer, 0, 0, 70 , 440, key_2->w, key_2->h );
                }
                if(haspot>0)
                {
                    masked_blit( pot_2   , buffer, 0, 0, 110, 440, pot_2->w, pot_2->h );
                }

                blit( buffer, screen, 0, 0, 0, 0, 640, 480 );
                if(board[heroj-1][heroi-1] > 40 || board[heroj-1][heroi] > 40 || board[heroj-1][heroi+1] > 40 || board[heroj][heroi-1] > 40 ||          //sprawdzam czy znalazl przeciwnika jak tak to walcze
                    board[heroj][heroi+1] > 40 || board[heroj+1][heroi-1] > 40 || board[heroj+1][heroi] > 40 || board[heroj+1][heroi+1] > 40)
                {
                    if(board[heroj-1][heroi-1] == 41 || board[heroj-1][heroi] == 41 || board[heroj-1][heroi+1] == 41 || board[heroj][heroi-1] == 41 ||          //sprawdzam z kim walcze
                    board[heroj][heroi+1] == 41 || board[heroj+1][heroi-1] == 41 || board[heroj+1][heroi] == 41 || board[heroj+1][heroi+1] == 41)
                    {
                        enemyhp =  enemy_1_hp;
                        enemydmg = enemy_1_dmg;
                        enemy = enemy1_2;
                    }
                    if(board[heroj-1][heroi-1] == 42 || board[heroj-1][heroi] == 42 || board[heroj-1][heroi+1] == 42 || board[heroj][heroi-1] == 42 ||          //sprawdzam z kim walcze
                    board[heroj][heroi+1] == 42 || board[heroj+1][heroi-1] == 42 || board[heroj+1][heroi] == 42 || board[heroj+1][heroi+1] == 42)
                    {
                        enemyhp =  enemy_2_hp;
                        enemydmg = enemy_2_dmg;
                        enemy = enemy2_2;
                    }
                    if(board[heroj-1][heroi-1] == 43 || board[heroj-1][heroi] == 43 || board[heroj-1][heroi+1] == 43 || board[heroj][heroi-1] == 43 ||          //sprawdzam z kim walcze
                    board[heroj][heroi+1] == 43 || board[heroj+1][heroi-1] == 43 || board[heroj+1][heroi] == 43 || board[heroj+1][heroi+1] == 43)
                    {
                        enemyhp =  enemy_3_hp;
                        enemydmg = enemy_3_dmg;
                        enemy = enemy3_2;
                    }
                    enemymaxhp=enemyhp;
                    //tu walka z przeciwnikiem, losowanie przeciwnika itp. walczy gdy ma przeciwnika w przylegajacej kratce
                    while(herohp > 0 && enemyhp > 0)         //poki zyje hero albo przeciwnik
                    {
                        //wyswietlanie 1 , 2 3, 4 jako opcji walki
                        clear_to_color( buffer, makecol( 0, 0, 0 ) );
                        for(int j=0;j<21;j++)
                            for(int i=0;i<32;i++)
                            {
                                if(see[j][i]==true)
                                {
                                    if(board[j][i]==0)
                                        masked_blit( floor , buffer, 0, 0, 20*i, 20*j, floor->w, floor->h );
                                    if(board[j][i]==1)
                                        masked_blit( wall  , buffer, 0, 0, 20*i, 20*j, wall->w , wall->h  );
                                    if(board[j][i]==2)
                                        masked_blit( door  , buffer, 0, 0, 20*i, 20*j, door->w , door->h  );
                                    if(board[j][i]==3)
                                        masked_blit( klucz   , buffer, 0, 0, 20*i, 20*j, klucz->w  , klucz->h   );
                                    if(board[j][i]==41)
                                        masked_blit( enemy1, buffer, 0, 0, 20*i, 20*j, enemy1->w, enemy1->h );
                                    if(board[j][i]==42)
                                        masked_blit( enemy2, buffer, 0, 0, 20*i, 20*j, enemy2->w, enemy2->h );
                                    if(board[j][i]==43)
                                        masked_blit( enemy3, buffer, 0, 0, 20*i, 20*j, enemy3->w, enemy3->h );
                                    if(board[j][i]==5)
                                        masked_blit( sword , buffer, 0, 0, 20*i, 20*j, sword->w, sword->h );
                                    if(board[j][i]==6)
                                        masked_blit( exit  , buffer, 0, 0, 20*i, 20*j, exit->w , exit->h  );
                                    if(board[j][i]==7)
                                        masked_blit( hero  , buffer, 0, 0, 20*i, 20*j, hero->w , hero->h  );
                                    if(board[j][i]==8)
                                        masked_blit( pot   , buffer, 0, 0, 20*i, 20*j, pot->w, pot->h );
                                    if(board[j][i]==9)
                                        masked_blit( blood , buffer, 0, 0, 20*i, 20*j, blood->w, blood->h );
                                }
                            }
                    masked_blit( hero_2   , buffer, 0, 0, 10, 430, hero_2->w, hero_2->h );
                    for(i=0;i<heromaxhp;i++)
                        masked_blit( hp_full   , buffer, 0, 0, 60 + 10*i,430, hp_full->w, hp_full->h );
                    for(i=0;i<herohp;i++)
                        masked_blit( hp   , buffer, 0, 0, 60 + 10*i,430, hp->w, hp->h );

                    masked_blit( enemy   , buffer, 0, 0, 590, 430, enemy->w, enemy->h );
                    for(i=0;i<enemymaxhp;i++)
                        masked_blit( hp_full   , buffer, 0, 0, 580 - 10*i,430, hp_full->w, hp_full->h );
                    for(i=0;i<enemyhp;i++)
                        masked_blit( hp   , buffer, 0, 0, 580 - 10*i,430, hp->w, hp->h );

                    if(haskey>0)
                    {
                        masked_blit( key_2   , buffer, 0, 0, 70 , 440, key_2->w, key_2->h );
                    }
                    if(haspot>0)
                    {
                        masked_blit( pot_2   , buffer, 0, 0, 110, 440, pot_2->w, pot_2->h );
                    }

                        masked_blit( attack_one     , buffer, 0, 0, 240 ,440, attack_one->w  , attack_one->h   );
                        masked_blit( attack_two     , buffer, 0, 0, 290 ,440, attack_two->w  , attack_two->h   );
                        masked_blit( attack_three   , buffer, 0, 0, 340 ,440, attack_three->w, attack_three->h );
                        masked_blit( attack_pot     , buffer, 0, 0, 390 ,440, attack_pot->w  , attack_pot->h   );
                        blit( buffer, screen, 0, 0, 0, 0, 640, 480 );
                        klawisz_walka=readkey();
                        if(klawisz_walka==10548 || klawisz_walka == 7988)        // w gore to potek , zmienic na 4
                        {
                           if(haspot>0)
                           {
                               haspot--;
                               herohp=heromaxhp;
                           }
                           else
                           {
                               textprintf( buffer, font, 300, 150, makecol( 150, 150, 150 ), "Nie masz potkow, wybierz cios" );
                               blit( buffer, screen, 0, 0, 0, 0, 640, 480 );
                               rest(200);
                               klawisz_walka=readkey();
                           }
                        }
                        if(klawisz_walka == 9777 || klawisz_walka == 7217 || klawisz_walka == 21504 || klawisz_walka == 21248
                           || klawisz_walka == 21760 || klawisz_walka == 20992)        //lewo to slaby atak zmienic na 1
                        {
                            los=rand()%100;
                            if(los<(85+hitchance))
                                enemyhp=enemyhp - 0.5 * herodmg;
                        }
                        if(klawisz_walka== 10034 || klawisz_walka == 7474)      //down to sredni atak, zmienic na 2
                        {
                            los=rand()%100;
                            if(los<(60+hitchance))
                                enemyhp=enemyhp - 0.8 * herodmg;
                        }
                        if(klawisz_walka== 10291 || klawisz_walka == 7731)  // prawo to silny atak, zmienic na 3
                        {
                            los=rand()%100;
                            if(los<(40+hitchance))
                                enemyhp=enemyhp - herodmg;
                        }
                        herohp=herohp - enemydmg;


                    }
                    if(herohp <= 0){
                            while(!key[KEY_ENTER])
                            {
                                masked_blit(tablica, screen, 0, 0, 170, 90, tablica->w, tablica->h);
                            }
                        klawisz = 17165;
                        bMenu = true;
                        play = false;
                        }
                    else
                    {
                        los=rand()%100;         // 20 procent na to ze potwor dropnie potka
                        if(los<=20)
                            los=8;
                        else
                            if(krew==true){los=9;}
                            else{los=0;}
                        clear_to_color( screen, makecol( 0, 0, 0 ) );
                        if(board[heroj-1][heroi-1] > 40) board[heroj-1][heroi-1] = los;
                        if(board[heroj-1][heroi] > 40) board[heroj-1][heroi] = los;
                        if(board[heroj-1][heroi+1] > 40) board[heroj-1][heroi+1] = los;
                        if(board[heroj][heroi-1] > 40) board[heroj][heroi-1] = los;
                        if(board[heroj][heroi+1] > 40) board[heroj][heroi+1] = los;
                        if(board[heroj+1][heroi-1] > 40) board[heroj+1][heroi-1] = los;
                        if(board[heroj+1][heroi] > 40) board[heroj+1][heroi] = los;
                        if(board[heroj+1][heroi+1] > 40) board[heroj+1][heroi+1] = los;
                        clear_to_color( buffer, makecol( 0, 0, 0 ) );
                        for(int j=0;j<21;j++)
                            for(int i=0;i<32;i++)
                            {
                                if(see[j][i]==true)
                                {
                                    if(board[j][i]==0)
                                        masked_blit( floor , buffer, 0, 0, 20*i, 20*j, floor->w, floor->h );
                                    if(board[j][i]==1)
                                        masked_blit( wall  , buffer, 0, 0, 20*i, 20*j, wall->w , wall->h  );
                                    if(board[j][i]==2)
                                        masked_blit( door  , buffer, 0, 0, 20*i, 20*j, door->w , door->h  );
                                    if(board[j][i]==3)
                                        masked_blit( klucz   , buffer, 0, 0, 20*i, 20*j, klucz->w  , klucz->h   );
                                    if(board[j][i]==41)
                                        masked_blit( enemy1, buffer, 0, 0, 20*i, 20*j, enemy1->w, enemy1->h );
                                    if(board[j][i]==42)
                                        masked_blit( enemy2, buffer, 0, 0, 20*i, 20*j, enemy2->w, enemy2->h );
                                    if(board[j][i]==43)
                                        masked_blit( enemy3, buffer, 0, 0, 20*i, 20*j, enemy3->w, enemy3->h );
                                    if(board[j][i]==5)
                                        masked_blit( sword , buffer, 0, 0, 20*i, 20*j, sword->w, sword->h );
                                    if(board[j][i]==6)
                                        masked_blit( exit  , buffer, 0, 0, 20*i, 20*j, exit->w , exit->h  );
                                    if(board[j][i]==7)
                                        masked_blit( hero  , buffer, 0, 0, 20*i, 20*j, hero->w , hero->h  );
                                    if(board[j][i]==8)
                                        masked_blit( pot   , buffer, 0, 0, 20*i, 20*j, pot->w, pot->h );
                                    if(board[j][i]==9)
                                        masked_blit( blood , buffer, 0, 0, 20*i, 20*j, blood->w, blood->h );
                                }
                            }
                    masked_blit( hero_2   , buffer, 0, 0, 10, 430, hero_2->w, hero_2->h );
                    for(i=0;i<heromaxhp;i++)
                        masked_blit( hp_full   , buffer, 0, 0, 60 + 10*i,430, hp_full->w, hp_full->h );
                    for(i=0;i<herohp;i++)
                        masked_blit( hp   , buffer, 0, 0, 60 + 10*i,430, hp->w, hp->h );
                    if(haskey>0)
                    {
                        masked_blit( key_2   , buffer, 0, 0, 70 , 440, key_2->w, key_2->h );
                    }
                    if(haspot>0)
                    {
                        masked_blit( pot_2   , buffer, 0, 0, 110, 440, pot_2->w, pot_2->h );
                    }

                    blit( buffer, screen, 0, 0, 0, 0, 640, 480 );
                    }
                }
            }
            if(key[KEY_ENTER])
            {
                bMenu = true;
                play = false;
            }
        }


    blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
    }
   destroy_bitmap( menu );
   destroy_bitmap( buffer );
   allegro_exit();
   return 0;
}
END_OF_MAIN()
