#include "SpriteAnim.h"

ObjectPool<SpriteAnim>* SpriteAnim::Pool;

SpriteAnim::SpriteAnim()
{
    ClearMemory();
}

SpriteAnim::~SpriteAnim()
{
}

void SpriteAnim::Create(short _clipStart, short _clipCount, float _clipSpeed)
{//initializes animation params(frames in the animation)
    m_clipStart = _clipStart;
    m_clipCount = _clipCount;
    m_clipSpeed = _clipSpeed;
    m_clipCurrent = _clipStart;
    m_clipEnd = m_clipStart + m_clipCount;
}

void SpriteAnim::ClearMemory()
{
    m_clipStart = 0;
    m_clipCount = 0;
    m_clipCurrent = 0;
}

void SpriteAnim::Update(float _deltaTime)
{
   // std::cout << "Current Clip: " << m_clipCurrent << std::endl;

    // Increment the current clip based on time passed and the speed of animation
    float timePerClip = 1.0f / m_clipSpeed;  // The time for one frame
    m_clipCurrent += _deltaTime / timePerClip; // Advance the clip

    // Ensure the clip loops if it goes beyond the last one
    if (m_clipCurrent >= m_clipStart + m_clipCount) {
        m_clipCurrent = m_clipStart;  // Loop back to the first clip
    }
}

//void SpriteAnim::Update(float _deltaTime)
//{
//
//    m_clipCurrent += m_clipSpeed * _deltaTime;
//    short currentFrame = static_cast<short>(m_clipCurrent);
//
//    if (currentFrame > m_clipEnd)
//    {
//        m_clipCurrent = static_cast<float>(m_clipStart);
//    }
//}



void SpriteAnim::Serialize(std::ostream& _stream)
{//writes the state of SpriteAnim to the byte stream
    _stream.write(reinterpret_cast<char*>(&m_clipStart), sizeof(m_clipStart));
    _stream.write(reinterpret_cast<char*>(&m_clipCount), sizeof(m_clipCount));
    _stream.write(reinterpret_cast<char*>(&m_clipSpeed), sizeof(m_clipSpeed));
    Resource::Serialize(_stream);
}

void SpriteAnim::Deserialize(std::istream& _stream)
{//reads the SpriteAnim object state from the stream
    _stream.read(reinterpret_cast<char*>(&m_clipStart), sizeof(m_clipStart));
    _stream.read(reinterpret_cast<char*>(&m_clipCount), sizeof(m_clipCount));
    _stream.read(reinterpret_cast<char*>(&m_clipSpeed), sizeof(m_clipSpeed));
    m_clipEnd = m_clipStart + m_clipCount;
    Resource::Deserialize(_stream);
}

void SpriteAnim::ToString()
{
    cout << "SPRITE ANIMATION: ";
    cout << "Clip Start: " << m_clipStart;
    cout << "Clip Count: " << m_clipCount << endl;
    Resource::ToString();
}
