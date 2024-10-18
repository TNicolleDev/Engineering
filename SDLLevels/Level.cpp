#include "Level.h"

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
    rectX += 100 * deltaTime;  // Example movement logic
    rectAsh += 200 * deltaTime;

    // Set render color
    renderer->SetDrawColor(Color(128, 128, 128, 255));
    renderer->ClearScreen();

    // Render textures based on updated positions
    renderer->RenderTexture(sheet, sheet->Update(EN_AN_RUN, deltaTime),
        Rect(rectX, 10, (rectX + spriteWidth * scale), (10 + spriteHeight * scale)));
    renderer->RenderTexture(sheet, sheet->Update(EN_AN_RUN, deltaTime),
        Rect(rectAsh, 110, (rectAsh + spriteWidth * scale), (110 + spriteHeight * scale)));
    renderer->RenderTexture(sheet, sheet->Update(EN_AN_RUN, deltaTime),
        Rect(rectX, 210, (rectX + spriteWidth * scale), (210 + spriteHeight * scale)));

    // Display FPS
    std::string fps = "Frames Per Second: " + std::to_string(Timing::Instance().GetFPS());
    font->Write(renderer->GetRenderer(), fps.c_str(), SDL_Color{ 0, 0, 255 }, SDL_Point{ 0, 0 });

    // Example output for deltaTime
    std::cout << "Delta Time: " << deltaTime << std::endl;
}