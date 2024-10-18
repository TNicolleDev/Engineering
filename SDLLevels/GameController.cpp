#include "GameController.h"
#include "Renderer.h"
#include "SpriteSheet.h"
#include "SpriteAnim.h"
#include "TTFont.h"
#include "Timing.h"
#include "Level.h"


GameController::GameController()
    : currentState(GameState::LEVEL1)
{

    m_sdlEvent = {};




}

GameController::~GameController()
{}

// Timing made by professor
Timing* t = &Timing::Instance();
// I made this maybe relocate it later..
int RandomNumber(int min, int max)
{
    int random = (min + rand() % (max - min + 1));

    return random;
}
void GameController::RunGame()
{
    // bytes of memory for your assets to use.
    AssetController::Instance().Initialize(10000000);
    // create a renderer.
    Renderer* r = &Renderer::Instance();
    // renderer makes window.
    r->Initialize(1440, 900);//DONT FORGET TO CHANGE THIS TO 1080x1920
    TTFont* font = new TTFont();
    font->Initialize(20);
    Point ws = r->GetWindowSize();


    // 2 objects pools 
    SpriteSheet::Pool = new ObjectPool<SpriteSheet>();
    SpriteAnim::Pool = new ObjectPool<SpriteAnim>();
    SpriteSheet* sheet = SpriteSheet::Pool->GetResource();

    sheet->Load("../Assets/Textures/Warrior.tga");
    // this maps to our warrior tga file.
    sheet->SetSize(17, 6, 69, 44);

    sheet->AddAnimation(EN_AN_IDLE, 0, 6, 6.0f);
    sheet->AddAnimation(EN_AN_RUN, 6, 7, 6.0f);
    Level* level = new Level(sheet, r, font);
    //const float scale = 1.8f; // Scale factor for width and height
    //const int spriteWidth = 69;  // Width of each sprite from SetSize
    //const int spriteHeight = 44;
    //int rectMin = 0;
    //int rectMax = 0;
    //int speed = 100;
    //int rectRand = RandomNumber(rectMin, rectMax);
    //int rectX = 0;
    //int rectDefault = 0;
    //int rectAsh = 0;

    while (m_sdlEvent.type != SDL_QUIT)
    {
        t->Tick();
        SDL_PollEvent(&m_sdlEvent);


        switch (currentState)
        {
        case GameState::LEVEL1:
        {
            level->RunLevel1Logic(t->GetDeltaTime());
            /*float speed = 0.1f;*/
           // rectX += 160* t->GetDeltaTime();
          /*  rectMin = 100;
            rectMax = 400;
            rectRand = RandomNumber(rectMin, rectMax);
            rectX += rectRand * t->GetDeltaTime();

            rectAsh += 200 * t->GetDeltaTime();

            r->SetDrawColor(Color(128, 128, 128, 255));
            r->ClearScreen();
            r->RenderTexture(sheet, sheet->Update(EN_AN_RUN, t->GetDeltaTime()), Rect(rectX, 10, (rectX + spriteWidth * scale), (10 + spriteHeight * scale)));
            r->RenderTexture(sheet, sheet->Update(EN_AN_RUN, t->GetDeltaTime()), Rect(rectAsh, 110, (rectAsh + spriteWidth * scale), (110 + spriteHeight * scale)));
            r->RenderTexture(sheet, sheet->Update(EN_AN_RUN, t->GetDeltaTime()), Rect(rectX, 210, (rectX + spriteWidth * scale), (210 + spriteHeight * scale)));



            std::string fps = "Frames Per Second: " + std::to_string(t->GetFPS());
            std::cout << "Delta Time: " << t->GetDeltaTime() << std::endl;

            font->Write(r->GetRenderer(), fps.c_str(), SDL_Color{ 0,0,255 }, SDL_Point{ 0,0 });*/
            break;
        }
        case GameState::LEVEL2:

            break;
        }

        SDL_RenderPresent(r->GetRenderer());
    }
    delete SpriteAnim::Pool;
    delete SpriteSheet::Pool;
    r->Shutdown();
}

void GameController::UpdateLvl1()
{



}