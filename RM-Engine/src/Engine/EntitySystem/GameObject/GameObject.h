/**
 * @file GameObject.h
 * @author sumin.park
 * @brief  GameObject
 * @version 0.1
 * @date 1/8/2026 7:30:10 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once

namespace rm
{
    class Component;
	class GameObject
	{
	public:
        GameObject();
        virtual ~GameObject();
	public:
        void Init();
        void Update(float dt);
        void LateUpdate(float dt);
        void Render();

        template <typename T>
       T* AddComponent() {
            //todo: check if component already exists
            //todo: also check if T is actually a type of component
            T* newComponent = new T(this);
           components.push_back(newComponent);
            return newComponent;
        }
	private:
        std::vector<Component*> components;
	};

} // rm namespace