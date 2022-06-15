#include "button.h"
#include "normalshot.h"
#include "player.h"
#include "protonbomb.h"
#include "tiefighter.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>

void Shop(Player &player){
    sf::Font font;
    if(!font.loadFromFile("fonts/Starjedi.ttf")){
        std::cerr<<"blad ladowania Starjedi.ttf"<<std::endl;
    }

    sf::RenderWindow window(sf::VideoMode(420, 340), "Star Wars - The Space warfare", sf::Style::None);
    window.setFramerateLimit(60);

    sf::Texture texture_proton_bomb;
    if(!texture_proton_bomb.loadFromFile("textures/proton_bomb.png")){
        std::cerr<<"blad ladowania proton_bomb.png"<<std::endl;
    }

    const sf::Texture *pTexture_proton = &texture_proton_bomb;
    sf::RectangleShape proton_image;
    proton_image.setTexture(pTexture_proton);
    proton_image.setRotation(270);
    proton_image.setPosition(70, 195);
    proton_image.setSize(sf::Vector2f(30, 114));

    Button close;
    close.setFont(font);
    close.setFillColor(sf::Color::Red);
    close.setOutlineColor(sf::Color::White);
    close.setOutlineThickness(0.8);
    close.setString("x");
    close.setCharacterSize(50);
    close.setPosition(370, 0);

    Button points;
    points.setFont(font);
    points.setFillColor(sf::Color::Black);
    points.setOutlineColor(sf::Color::White);
    points.setOutlineThickness(0.8);
    points.setString(std::to_string(player.GetPoints()));
    points.setCharacterSize(50);
    points.setPosition(270, 45);

    Button points_text;
    points_text.setFont(font);
    points_text.setFillColor(sf::Color::Black);
    points_text.setOutlineColor(sf::Color::White);
    points_text.setOutlineThickness(0.8);
    points_text.setString("points:");
    points_text.setCharacterSize(50);
    points_text.setPosition(50, 45);

    Button buy_proton_bomb;
    buy_proton_bomb.setFont(font);
    buy_proton_bomb.setFillColor(sf::Color::Black);
    buy_proton_bomb.setOutlineColor(sf::Color::White);
    buy_proton_bomb.setOutlineThickness(0.8);
    buy_proton_bomb.setString("buy");
    buy_proton_bomb.setCharacterSize(50);
    buy_proton_bomb.setPosition(230, 145);

    Button how_much_bombs;
    how_much_bombs.setFont(font);
    how_much_bombs.setFillColor(sf::Color::Black);
    how_much_bombs.setOutlineColor(sf::Color::White);
    how_much_bombs.setOutlineThickness(0.8);
    how_much_bombs.setString(std::to_string(player.GetProtonBomb()));
    how_much_bombs.setCharacterSize(50);
    how_much_bombs.setPosition(270, 245);

    Button bombs_text;
    bombs_text.setFont(font);
    bombs_text.setFillColor(sf::Color::Black);
    bombs_text.setOutlineColor(sf::Color::White);
    bombs_text.setOutlineThickness(0.8);
    bombs_text.setString("bombs:");
    bombs_text.setCharacterSize(50);
    bombs_text.setPosition(50, 245);

    while(window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while(window.pollEvent(event)) {
            // "close requested" event: we close the window
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if((window.mapPixelToCoords(sf::Mouse::getPosition(window)).x < buy_proton_bomb.getPosition().x + buy_proton_bomb.getGlobalBounds().width)
                    && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).x > buy_proton_bomb.getPosition().x)
                    && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).y > buy_proton_bomb.getPosition().y)
                    && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).y < buy_proton_bomb.getPosition().y + buy_proton_bomb.getGlobalBounds().height)){
                buy_proton_bomb.setFillColor(sf::Color(241, 212, 0));
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    if(player.GetPoints() > 2){
                        player.AddPoints(-3);
                        player.AddProtonBomb(1);
                    }
                }
            }
            else{
                buy_proton_bomb.setFillColor(sf::Color::Black);
            }
            if((window.mapPixelToCoords(sf::Mouse::getPosition(window)).x < close.getPosition().x + close.getGlobalBounds().width)
                    && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).x > close.getPosition().x)
                    && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).y > close.getPosition().y)
                    && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).y < close.getPosition().y + close.getGlobalBounds().height)){
                close.setFillColor(sf::Color(241, 212, 0));
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    window.close();
                }
            }
            else{
                close.setFillColor(sf::Color::Red);
            }
        }

        // LOGIC
        window.clear(sf::Color::Black);

        points.setString(std::to_string(player.GetPoints()));
        how_much_bombs.setString(std::to_string(player.GetProtonBomb()));

        // DRAW
        window.draw(buy_proton_bomb);
        window.draw(points);
        window.draw(points_text);
        window.draw(how_much_bombs);
        window.draw(bombs_text);
        window.draw(close);
        window.draw(proton_image);

        window.display();
    }
}
void Options(sf::Sound &theme){
    // create the window
    sf::RenderWindow window(sf::VideoMode(400, 400), "Star Wars - The Space warfare", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Texture texture_vol_off;
    if(!texture_vol_off.loadFromFile("textures/speakersOff.png")){
        std::cerr<<"Blad ladowania volumeOff.png"<<std::endl;
    }

    sf::Sprite volumeOff;
    volumeOff.setTexture(texture_vol_off);
    volumeOff.setPosition(300, 300);
    volumeOff.setScale(0.25,0.25);


    while(window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while(window.pollEvent(event)) {
            // "close requested" event: we close the window
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        // LOGIC
        if((window.mapPixelToCoords(sf::Mouse::getPosition(window)).x < volumeOff.getPosition().x + volumeOff.getGlobalBounds().width)
                && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).x > volumeOff.getPosition().x)
                && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).y > volumeOff.getPosition().y)
                && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).y < volumeOff.getPosition().y + volumeOff.getGlobalBounds().height)){
            volumeOff.setColor(sf::Color::Red);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                window.close();
                theme.setVolume(0);
            }
        }
        else {
            volumeOff.setColor(sf::Color::Black);
        }

        // clear the window with black color / background image
        window.clear(sf::Color::White);

        // DRAW
        // draw everything here...
        window.draw(volumeOff);

        // end the current frame
        window.display();
    }
}
void Game(){
    // create the window
    // SOUND
    sf::SoundBuffer buffer_shot;
    if(!buffer_shot.loadFromFile("samples/x_wing_shot.wav")){
        std::cerr<<"blad ladowania x_wing_shot.wav"<<std::endl;
    }

    sf::Sound shot_right;
    shot_right.setBuffer(buffer_shot);
    shot_right.setVolume(10);

    sf::Sound shot_left;
    shot_left.setBuffer(buffer_shot);
    shot_left.setVolume(10);

    sf::Font font;
    if(!font.loadFromFile("fonts/Starjedi.ttf")){
        std::cerr<<"blad ladowania Starjedi.ttf"<<std::endl;
    }

    sf::RenderWindow window(sf::VideoMode(960, 540), "Star Wars - The Space warfare", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    // create some objects

    // PLAYER
    sf::Texture texture_x_wing;
    if(!texture_x_wing.loadFromFile("textures/x_wing.png")){
        std::cerr<<"Blad ladowania x_wing.png"<<std::endl;
    }
    sf::Texture texture_x_wing_power_up;
    if(!texture_x_wing_power_up.loadFromFile("textures/x_wing_power_up.png")){
        std::cerr<<"blad ladowania x_wing_power_up.png"<<std::endl;
    }
    sf::Texture texture_x_wing_destroyed;
    if(!texture_x_wing_destroyed.loadFromFile("textures/x_wing_destroyed.png")){
        std::cerr<<"blad ladowania x_wing.png"<<std::endl;
    }

    Player player(texture_x_wing);
    player.setOrigin(player.getGlobalBounds().width/2, player.getGlobalBounds().height/2);
    player.setPosition(window.getSize().x/2, window.getSize().y/2 + 200);
    player.setScale(0.1, 0.1);

    // OPPONENTS
    sf::Texture texture_tie_fighter;
    if(!texture_tie_fighter.loadFromFile("textures/tie_fighter.png")){
        std::cerr<<"blad ladowania texture_tie_fighter.png"<<std::endl;
    }

    std::vector<std::unique_ptr<Opponents>> opponents;

    for(int i=0; i<10; i++){
        auto temp = std::make_unique<TieFighter>(texture_tie_fighter);
        temp->setPosition(10 + rand()%(window.getSize().x-50), -50);
        temp->setScale(0.12, 0.12);
        opponents.emplace_back(std::move(temp));
    }

    Button pause_text;
    pause_text.setFont(font);
    pause_text.setFillColor(sf::Color::Black);
    pause_text.setOutlineColor(sf::Color::White);
    pause_text.setOutlineThickness(0.8);
    pause_text.setString("paused! press enter");
    pause_text.setCharacterSize(50);
    pause_text.setPosition(170, 245);

    Button points_text;
    points_text.setFont(font);
    points_text.setFillColor(sf::Color::Black);
    points_text.setOutlineColor(sf::Color::White);
    points_text.setOutlineThickness(0.8);
    points_text.setString(std::to_string(player.GetPoints()));
    points_text.setCharacterSize(25);
    points_text.setPosition(10, 10);

    // BACKGROUND
    sf::Texture texture_background;
    if(!texture_background.loadFromFile("textures/background1.png")){
        std::cerr<<"blad ladowania background.png"<<std::endl;
    }
    texture_background.setRepeated(true);

    sf::Sprite background(texture_background);
    background.setTextureRect(sf::IntRect(0, 0, window.getSize().x, 50*window.getSize().y));
    background.setPosition(window.getSize().x, window.getSize().y);
    background.setRotation(180);

    sf::Texture texture_normal_shot_green;
    if(!texture_normal_shot_green.loadFromFile("textures/shot_green.png")){
        std::cerr<<"blad ladowania shot_green.png"<<std::endl;
    }

    sf::Texture texture_normal_shot_red;
    if(!texture_normal_shot_red.loadFromFile("textures/shot_red.png")){
        std::cerr<<"blad ladowania shot_red.png"<<std::endl;
    }

    sf::Texture texture_proton_bomb;
    if(!texture_proton_bomb.loadFromFile("textures/proton_bomb.png")){
        std::cerr<<"blad ladowania proton_bomb.png"<<std::endl;
    }

    std::vector<std::unique_ptr<Bullet>> bullets;

    // CLOCKS
    sf::Clock clock;
    double elapsed = 0;
    double elapsedShot = 0;
    double elapsedShotProtonBomb = 0;

    enum{
        left_gun,
        right_gun
    };

    bool WhichGun = left_gun;
    bool pause = false;

    // run the program as long as the window is open
    while(window.isOpen()) {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        elapsed = clock.restart().asSeconds();
        elapsedShot += elapsed;
        elapsedShotProtonBomb += elapsed;

        while(window.pollEvent(event)) {
            // "close requested" event: we close the window
            if(event.type == sf::Event::Closed){
                window.close();
            }

            if(event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::P){
                    pause=true;
                    Shop(player);
                }
            }
            if(event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::Enter){
                    pause=!pause;
                }
            }
        }

        points_text.setString(std::to_string(player.GetPoints()));

        //
        if(!pause){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                player.move(-player.GetSpeedX()*elapsed, 0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                player.move(player.GetSpeedX()*elapsed, 0);
            }

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(elapsedShotProtonBomb > 1){
                    if(player.GetProtonBomb() > 0){
                        auto temp = std::make_unique<ProtonBomb>(texture_proton_bomb, player);
                        temp->ShootToTarget(player, window, elapsed);
                        temp->setScale(0.4, 0.4);

                        bullets.emplace_back(std::move(temp));
                        player.AddProtonBomb(-1);
                        elapsedShotProtonBomb = 0;
                    }
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                if(elapsedShot > 0.2){
                    auto temp = std::make_unique<NormalShot>(texture_normal_shot_red);
                    if(WhichGun == left_gun){
                        temp->ShootLeft(player);
                        shot_left.play();
                        WhichGun = right_gun;
                    }
                    else{
                        temp->ShootRight(player);
                        shot_right.play();
                        WhichGun = left_gun;
                    }
                    bullets.emplace_back(std::move(temp));
                    elapsedShot = 0;
                }
            }

            // LOGIC
            player.BorderLimit(window);

            if(player.getPosition().y < 500){
                player.move(0, 100*elapsed);
            }

            background.move(0, 15*elapsed);

            for(auto it=bullets.begin(); it!=bullets.end();){
                if((*it)->getGlobalBounds().top + (*it)->getGlobalBounds().height < -100){
                    NormalShot *normalShot = dynamic_cast<NormalShot*>(it->get());
                    ProtonBomb *protonBomb = dynamic_cast<ProtonBomb*>(it->get());
                    if(normalShot!=nullptr){
                        it = bullets.erase(it);
                    }
                    else if(protonBomb!=nullptr){
                        it = bullets.erase(it);
                    }
                    else{}
                }
                else{
                    it++;
                }
            }

            for(auto it=bullets.begin(); it!=bullets.end(); it++){
                (*it)->Shoot(elapsed);
            }

            for(auto it=opponents.begin(); it!=opponents.end();){
                TieFighter *tiefighter = dynamic_cast<TieFighter*>(it->get());
                tiefighter->Movement(window, elapsed);
                if(tiefighter!=nullptr){
                    for(auto itr=bullets.begin(); itr!=bullets.end();){
                        NormalShot *normalshot = dynamic_cast<NormalShot*>(itr->get());
                        ProtonBomb *protonbomb = dynamic_cast<ProtonBomb*>(itr->get());
                        if(normalshot!=nullptr){
                            if(normalshot->getGlobalBounds().intersects(tiefighter->getGlobalBounds())){
                                tiefighter->LostHP(20+rand()%10);
                                itr = bullets.erase(itr);
                            }
                            else{
                                itr++;
                            }
                        }
                        else if(protonbomb!=nullptr){
                            if(protonbomb->getGlobalBounds().intersects(tiefighter->getGlobalBounds())){
                                tiefighter->LostHP(50);
                                itr = bullets.erase(itr);
                            }
                            else{
                                itr++;
                            }
                        }
                        else{
                            itr++;
                        }
                    }
                    it++;
                }
                else{
                    it++;
                }
            }

            for(auto it=opponents.begin(); it!=opponents.end();){
                TieFighter *tiefighter = dynamic_cast<TieFighter*>(it->get());
                if(tiefighter!=nullptr){
                    tiefighter->Movement(window, elapsed);
                    if(tiefighter->GetHP() <= 0){
                        player.AddPoints(1);
                        it = opponents.erase(it);
                    }
                    else if(tiefighter->getPosition().y > window.getSize().y){
                        it = opponents.erase(it);
                    }
                    else{
                        it++;
                    }
                }
                else {
                    it++;
                }
            }
        }

        if(opponents.empty()){
            for(int i=0; i<10; i++){
                auto temp = std::make_unique<TieFighter>(texture_tie_fighter);
                temp->setPosition(10 + rand()%(window.getSize().x-50), -200);
                temp->setScale(0.12, 0.12);
                opponents.emplace_back(std::move(temp));
            }
        }

        // clear the window with black color / background image
        //window.clear(sf::Color::Black);
        window.draw(background);

        // DRAW
        // draw everything here...
        for(auto &el: bullets){
            window.draw(*el);
        }

        for(auto &el: opponents){
            window.draw(*el);
        }

        for(auto &el: opponents){
            el->HPdraw();
            window.draw(el->hp_bar);
        }

        window.draw(player);
        if(pause){
            window.draw(pause_text);
        }

        window.draw(points_text);

        // end the current frame
        window.display();
    }
}
void MainMenu(){
    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile("samples/mainmenutheme.wav")){
        std::cerr<<"blad ladowania mainmenutheme.wav"<<std::endl;
    }

    // create the window
    sf::RenderWindow window(sf::VideoMode(960, 540), "Star Wars - The Space warfare", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Texture texture_intro;
    texture_intro.loadFromFile("textures/intro.png");
    texture_intro.setRepeated(false);

    sf::Sprite intro(texture_intro);

    sf::Sound theme;
    theme.setBuffer(buffer);
    theme.play();
    theme.setVolume(5); // zmienic na 10

    sf::Font font;
    if(!font.loadFromFile("fonts/Starjedi.ttf")){
        std::cerr<<"blad ladowania Starjedi.ttf"<<std::endl;
    }

    //LOGO
    Button logo_star_wars;
    logo_star_wars.setFont(font);
    logo_star_wars.setFillColor(sf::Color::Black);
    logo_star_wars.setOutlineColor(sf::Color::White);
    logo_star_wars.setOutlineThickness(0.8);
    logo_star_wars.setString("star wars");
    logo_star_wars.setCharacterSize(70);
    logo_star_wars.setPosition(80, 300);

    Button logo_the_space;
    logo_the_space.setFont(font);
    logo_the_space.setFillColor(sf::Color(241, 212, 0));
    logo_the_space.setOutlineColor(sf::Color::Black);
    logo_the_space.setOutlineThickness(0.8);
    logo_the_space.setString("the space warfare");
    logo_the_space.setCharacterSize(37);
    logo_the_space.setPosition(80, 370);

    //Play button
    Button play;
    play.setFont(font);
    play.setFillColor(sf::Color::White);
    play.setOutlineColor(sf::Color::Black);
    play.setOutlineThickness(0.5);
    play.setString("play");
    play.setCharacterSize(50);
    play.setPosition(650, 300);

    //Options button
    Button options;
    options.setFont(font);
    options.setFillColor(sf::Color::White);
    options.setOutlineColor(sf::Color::Black);
    options.setOutlineThickness(0.5);
    options.setString("options");
    options.setCharacterSize(50);
    options.setPosition(650, 370);

    //About button
    Button about;
    about.setFont(font);
    about.setFillColor(sf::Color::White);
    about.setOutlineColor(sf::Color::Black);
    about.setOutlineThickness(0.5);
    about.setString("about");
    about.setCharacterSize(50);
    about.setPosition(650, 440);

    while(window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while(window.pollEvent(event)) {
            // "close requested" event: we close the window
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        // LOGIC
        if((window.mapPixelToCoords(sf::Mouse::getPosition(window)).x < play.getPosition().x + play.getGlobalBounds().width)
                && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).x > play.getPosition().x)
                && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).y > play.getPosition().y)
                && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).y < play.getPosition().y + play.getGlobalBounds().height)){
            play.setFillColor(sf::Color(241, 212, 0));
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                window.close();
                Game();
            }
        }
        else {
            play.setFillColor(sf::Color::White);
        }

        if((window.mapPixelToCoords(sf::Mouse::getPosition(window)).x < options.getPosition().x + options.getGlobalBounds().width)
                && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).x > options.getPosition().x)
                && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).y > options.getPosition().y)
                && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).y < options.getPosition().y + options.getGlobalBounds().height)){
            options.setFillColor(sf::Color(241, 212, 0));
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                window.close();
                Options(theme);
            }
        }
        else {
            options.setFillColor(sf::Color::White);
        }

        if((window.mapPixelToCoords(sf::Mouse::getPosition(window)).x < about.getPosition().x + about.getGlobalBounds().width)
                && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).x > about.getPosition().x)
                && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).y > about.getPosition().y)
                && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).y < about.getPosition().y + about.getGlobalBounds().height)){
            about.setFillColor(sf::Color(241, 212, 0));
        }
        else {
            about.setFillColor(sf::Color::White);
        }

        // clear the window with black color / background image
        //window.clear(sf::Color::Black);
        window.draw(intro);

        // DRAW
        // draw everything here...
        window.draw(logo_star_wars);
        window.draw(logo_the_space);
        window.draw(play);
        window.draw(options);
        window.draw(about);

        // end the current frame
        window.display();
    }
}

int main(){
    MainMenu();
    return 0;
}
