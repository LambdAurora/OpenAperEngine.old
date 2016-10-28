/*
 * Copyright © 2016 Clément "w67clement" Wagner
 *
 * This file is part of Openw67Render.
 *
 * Openw67Render is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Openw67Render is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Openw67Render.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../../include/openw67render/input/Controller.h"

namespace w67r
{
    Controller::Controller(SDL_Joystick *id) : joystick(id)
    {
    }

    Controller::~Controller()
    {
        close();
    }

    SDL_Joystick *Controller::getPointer() const
    {
        return joystick;
    }

    const char *Controller::getName()
    {
        const char *name = SDL_JoystickName(joystick);
        if (name == NULL)
            return "NULL";
        return name;
    }

    bool Controller::isConnected()
    {
        return SDL_JoystickGetAttached(joystick);
    }

    void Controller::close()
    {
        SDL_JoystickClose(joystick);
    }
}