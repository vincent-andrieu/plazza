/*
** EPITECH PROJECT, 2021
** B-OOP-400-REN-4-1-arcade-vincent.andrieu
** File description:
** SdlModule
*/

#include <iostream>
#include "SdlModule/SdlModule.hpp"

static const SDL_Color BACKGROUND_COLOR = {0, 0, 0, 255};

extern "C"
{
    std::shared_ptr<IDisplayModule> entryPoint()
    {
        return std::make_shared<SdlModule>();
    }
}

void SdlModule::open(Vector screenSize, Vector screenScale)
{
    this->_isOpen = true;
    this->_screenSize = screenSize;
    this->_screenScale = screenScale;
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    _police = TTF_OpenFont(ASSET_FILE("font.ttf").c_str(), TEXT_SIZE);
    _window = SDL_CreateWindow(
        WIN_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenSize.x, screenSize.y, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(_renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
    SDL_RenderClear(_renderer);
}

void SdlModule::close()
{
    this->_isOpen = false;
    if (_renderer)
        SDL_DestroyRenderer(_renderer);
    if (_police)
        TTF_CloseFont(_police);
    SDL_DestroyWindow(_window);
    TTF_Quit();
    SDL_Quit();
    _renderer = nullptr;
}

bool SdlModule::isOpen() const
{
    return this->_isOpen;
}

void SdlModule::putRectFill(IDisplayModule::Color color, Coord size, Coord pos)
{
    SDL_FRect rect;
    SDL_Color sdl_color;

    if (_colorList.find(color) == _colorList.end())
        return;
    if (pos.x > this->_screenSize.x || pos.y > this->_screenSize.y)
        return;
    sdl_color = _colorList.at(color);
    rect.x = pos.x * this->_screenScale.x;
    rect.y = pos.y * this->_screenScale.y;
    rect.w = size.x * this->_screenScale.x;
    rect.h = size.y * this->_screenScale.y;
    SDL_SetRenderDrawColor(_renderer, sdl_color.r, sdl_color.g, sdl_color.b, sdl_color.a);
    SDL_RenderFillRectF(_renderer, &rect);
}

void SdlModule::putRectOutline(IDisplayModule::Color color, Coord size, Coord pos)
{
    SDL_Color sdl_color;

    if (_colorList.find(color) == _colorList.end())
        return;
    if (pos.x > this->_screenSize.x || pos.y > this->_screenSize.y)
        return;
    sdl_color = _colorList.at(color);
    putRectFill(color, Coord(size.x, 1), Coord(pos.x, pos.y));
    putRectFill(color, Coord(1, size.y), Coord(pos.x, pos.y));
    putRectFill(color, Coord(size.x, 1), Coord(pos.x, pos.y + size.y - OUTLINE_WIDTH));
    putRectFill(color, Coord(1, size.y), Coord(pos.x + size.x - OUTLINE_WIDTH, pos.y));
    putRectFill(color, Coord(size.x, 1), Coord(pos.x, pos.y + 0.1));
    putRectFill(color, Coord(size.x, 1), Coord(pos.x, pos.y + size.y - 1));
}

void SdlModule::putCircle(IDisplayModule::Color color, Coord pos, size_t radius)
{
    SDL_Color sdl_color;
    const size_t newX = pos.x * this->_screenScale.x;
    const size_t newY = pos.y * this->_screenScale.y;
    const size_t r2 = radius * RADIUS_COEF * radius * RADIUS_COEF;

    if (_colorList.find(color) == _colorList.end())
        return;
    if (pos.x > this->_screenSize.x || pos.y > this->_screenSize.y)
        return;
    sdl_color = _colorList.at(color);
    SDL_SetRenderDrawColor(_renderer, sdl_color.r, sdl_color.g, sdl_color.b, sdl_color.a);
    for (size_t i = newY - r2; i <= newY + r2; i++) {
        for (size_t j = newX - r2; j <= newX + r2; j++) {
            if ((j - newX) * (j - newX) + (i - newY) * (i - newY) <= r2) {
                SDL_RenderDrawPoint(_renderer, j - 3 + this->_screenScale.x, i - 8 + this->_screenScale.y);
            }
        }
    }
    SDL_SetRenderDrawColor(_renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
}

void SdlModule::putText(IDisplayModule::Color color, Coord pos, std::string const &value)
{
    SDL_Surface *textSurface{nullptr};
    SDL_Texture *texture{nullptr};
    SDL_Rect posRect;
    SDL_Color sdl_color;

    if (_colorList.find(color) == _colorList.end())
        return;
    sdl_color = _colorList.at(color);
    if (_police == nullptr)
        return;
    if (pos.x > this->_screenSize.x || pos.y > this->_screenSize.y)
        return;
    textSurface = TTF_RenderText_Solid(_police, value.c_str(), sdl_color);
    texture = SDL_CreateTextureFromSurface(_renderer, textSurface);
    posRect.w = textSurface->w;
    posRect.h = textSurface->h;
    posRect.x = pos.x * this->_screenScale.x;
    posRect.y = pos.y * this->_screenScale.y;
    SDL_RenderCopy(_renderer, texture, nullptr, &posRect);
    if (texture)
        SDL_DestroyTexture(texture);
    if (textSurface)
        SDL_FreeSurface(textSurface);
}

void SdlModule::displayScreen()
{
    SDL_RenderPresent(_renderer);
}

void SdlModule::refreshScreen()
{
    _refreshKeys();
}

void SdlModule::clearScreen()
{
    SDL_SetRenderDrawColor(_renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
    SDL_RenderClear(_renderer);
}

void SdlModule::_refreshKeys()
{
    SDL_Event event;

    _keysBuffer.clear();
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN || event.type == SDL_QUIT || event.type == SDL_MOUSEBUTTONDOWN) {
            _keysBuffer.push_back(event);
        }
    }

    if (std::find_if(_keysBuffer.begin(), _keysBuffer.end(),
            [](const SDL_Event &event) {
                return event.type == SDL_QUIT;
            })
        != _keysBuffer.end())
        close();
}

bool SdlModule::isEqualKey(const SDL_Event event, const IDisplayModule::KeyList key) const
{
    if (_keyList.find(key) == _keyList.end())
        return false;
    return event.key.keysym.sym == _keyList.at(key);
}

bool SdlModule::isKeyPress(const IDisplayModule::KeyList key) const
{
    return std::find_if(_keysBuffer.begin(), _keysBuffer.end(), [this, key](const SDL_Event event) {
        return isEqualKey(event, key) & (event.type == SDL_KEYDOWN);
    }) != _keysBuffer.end();
}

bool SdlModule::isMouseClicked() const
{
    return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(SDL_BUTTON_LEFT);
}

Coord SdlModule::getMousePos() const
{
    int x = 0;
    int y = 0;

    SDL_GetMouseState(&x, &y);
    return Coord(x / this->_screenScale.x, y / this->_screenScale.y);
}