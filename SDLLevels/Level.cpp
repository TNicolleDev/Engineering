#include "Level.h"
float rectX1;
float rectX2;
float rectX3;
float rectX4;
float rectX5;
float rectX6;
float rectX7;
float rectX8;
float rectX9;
// Constructor
Level::Level(SpriteSheet* sheet, Renderer* renderer, TTFont* font)
    : rectX(0.0f), rectAsh(0.0f), scale(1.8f), spriteWidth(69), spriteHeight(44), currentFrame(0),
    sheet(sheet), renderer(renderer), font(font)
{
}

// Destructor
Level::~Level() {}

// Serialize the state of the level (positions, animation state, etc.)
void Level::Serialize(std::ostream& stream)
{
    stream.write(reinterpret_cast<char*>(&rectX), sizeof(rectX));
    stream.write(reinterpret_cast<char*>(&rectAsh), sizeof(rectAsh));
    stream.write(reinterpret_cast<char*>(&currentFrame), sizeof(currentFrame));
    stream.write(reinterpret_cast<char*>(&scale), sizeof(scale));
    stream.write(reinterpret_cast<char*>(&spriteWidth), sizeof(spriteWidth));
    stream.write(reinterpret_cast<char*>(&spriteHeight), sizeof(spriteHeight));
}

// Deserialize the state of the level
void Level::Deserialize(std::istream& stream)
{
    stream.read(reinterpret_cast<char*>(&rectX), sizeof(rectX));
    stream.read(reinterpret_cast<char*>(&rectAsh), sizeof(rectAsh));
    stream.read(reinterpret_cast<char*>(&currentFrame), sizeof(currentFrame));
    stream.read(reinterpret_cast<char*>(&scale), sizeof(scale));
    stream.read(reinterpret_cast<char*>(&spriteWidth), sizeof(spriteWidth));
    stream.read(reinterpret_cast<char*>(&spriteHeight), sizeof(spriteHeight));
}

// Level1 logic - updating and rendering
void Level::RunLevel1Logic(float deltaTime)
{
    

    // Set render color
    renderer->SetDrawColor(Color(128, 128, 128, 255));
    renderer->ClearScreen();

    // Get the specific SpriteAnim instance for the EN_AN_RUN animation
    SpriteAnim* runAnimation =  sheet->GetAnimation(EN_AN_RUN);
    SpriteAnim* runAnimation1 = sheet->GetAnimation(EN_AN_RUN1);
    SpriteAnim* runAnimation2 = sheet->GetAnimation(EN_AN_RUN2);
    SpriteAnim* runAnimation3 = sheet->GetAnimation(EN_AN_RUN3);
    SpriteAnim* runAnimation4 = sheet->GetAnimation(EN_AN_RUN4);
    SpriteAnim* runAnimation5 = sheet->GetAnimation(EN_AN_RUN5);
    SpriteAnim* runAnimation6 = sheet->GetAnimation(EN_AN_RUN6);
    SpriteAnim* runAnimation7 = sheet->GetAnimation(EN_AN_RUN7);
    SpriteAnim* runAnimation8 = sheet->GetAnimation(EN_AN_RUN8);
    SpriteAnim* runAnimation9 = sheet->GetAnimation(EN_AN_RUN9);

    float run = runAnimation->GetClipSpeed();
    std::cout << "run:" << run;
    float run1 = runAnimation1->GetClipSpeed();
    std::cout << "run1:" << run1;
    float run2 = runAnimation2->GetClipSpeed();
    std::cout << "run2:" << run2;
    float run3 = runAnimation3->GetClipSpeed();
    std::cout << "run3:" << run3;
    float run4 = runAnimation4->GetClipSpeed();
    std::cout << "run4:" << run4;
    float run5 = runAnimation5->GetClipSpeed();
    std::cout << "run5:" << run5;
    float run6 = runAnimation6->GetClipSpeed();
    std::cout << "run6" << run6;
    float run7 = runAnimation7->GetClipSpeed();
    std::cout << "run6" << run7;
    float run8 = runAnimation8->GetClipSpeed();
    std::cout << "run6" << run8;
    float run9 = runAnimation9->GetClipSpeed();
    std::cout << "run6" << run9;


    rectX  += run  + 100 * deltaTime;  // Example movement logic
    rectX1 += run1 + 100 * deltaTime;
    rectX2 += run2 + 100 * deltaTime;
    rectX3 += run3 + 100 * deltaTime;
    rectX4 += run4 + 100 * deltaTime;
    rectX5 += run5 + 100 * deltaTime;
    rectX6 += run6 + 100 * deltaTime;
    rectX7 += run7 + 100 * deltaTime;
    rectX8 += run8 + 100 * deltaTime;
    rectX9 += run9 + 100 * deltaTime;

    // Render textures based on updated positions
    renderer->RenderTexture(sheet, sheet->Update(EN_AN_RUN, deltaTime),
        Rect(rectX  , 10, (rectX + spriteWidth * scale), (10 + spriteHeight * scale)));
   
    renderer->RenderTexture(sheet, sheet->Update(EN_AN_RUN1, deltaTime),
        Rect(rectX1 , 110, (rectX1 + spriteWidth * scale), (110 + spriteHeight * scale)));
   
    renderer->RenderTexture(sheet, sheet->Update(EN_AN_RUN2, deltaTime),
        Rect(rectX2 , 210, (rectX2 + spriteWidth * scale), (210 + spriteHeight * scale)));

    renderer->RenderTexture(sheet, sheet->Update(EN_AN_RUN3, deltaTime),
        Rect(rectX3, 310, (rectX3 + spriteWidth * scale), (310 + spriteHeight * scale)));

   renderer->RenderTexture(sheet, sheet->Update(EN_AN_RUN4, deltaTime),
       Rect(rectX4, 410, (rectX4 + spriteWidth * scale), (410 + spriteHeight * scale)));

    renderer->RenderTexture(sheet, sheet->Update(EN_AN_RUN5, deltaTime),
        Rect(rectX5, 510, (rectX5 + spriteWidth * scale), (510 + spriteHeight * scale)));

    renderer->RenderTexture(sheet, sheet->Update(EN_AN_RUN6, deltaTime),
        Rect(rectX6, 610, (rectX6 + spriteWidth * scale), (610 + spriteHeight * scale)));

    renderer->RenderTexture(sheet, sheet->Update(EN_AN_RUN7, deltaTime),
        Rect(rectX7, 710, (rectX7 + spriteWidth * scale), (710 + spriteHeight * scale)));

    renderer->RenderTexture(sheet, sheet->Update(EN_AN_RUN8, deltaTime),
        Rect(rectX8, 810, (rectX8 + spriteWidth * scale), (810 + spriteHeight * scale)));

    renderer->RenderTexture(sheet, sheet->Update(EN_AN_RUN9, deltaTime),
        Rect(rectX9, 910, (rectX9 + spriteWidth * scale), (910 + spriteHeight * scale)));

    


    // Display FPS
    std::string fps = "Frames Per Second: " + std::to_string(Timing::Instance().GetFPS());
    font->Write(renderer->GetRenderer(), fps.c_str(), SDL_Color{ 0, 0, 255 }, SDL_Point{ 0, 0 });

    // Example output for deltaTime
    std::cout << "Delta Time: " << deltaTime << std::endl;
}