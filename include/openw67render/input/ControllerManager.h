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

#ifndef OPENW67RENDER_CONTROLLERS_H
#define OPENW67RENDER_CONTROLLERS_H

#include "Controller.h"
#include <vector>

namespace w67r
{
    class ControllerBaseListener
    {
    public:
        virtual void connect(Controller &controller) = 0;

        virtual void disconnect(Controller &controller) = 0;
    };

    class Controllers
    {
    private:
        std::vector<Controller> controllers;

        std::vector<ControllerBaseListener *> baseListeners;

        Controllers();

    public:
        Controller getController(uint8_t id);

        std::vector<ControllerBaseListener *> getBaseListeners() const;

        Controllers(Controllers const &) = delete;

        void operator=(Controllers const &)  = delete;

        static Controllers CONTROLLER_MANAGER;
    };
}

#endif //OPENW67RENDER_CONTROLLERS_H