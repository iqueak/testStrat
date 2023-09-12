//
// Created by bohdan.yurov on 11.09.2023.
//
#pragma once
#include <utility>

#include "raylib.h"
#include "raygui.h"
#include "vector"
#include "string"
#include "functional"
#include "iostream"
using namespace std;

namespace GuiController{

    struct Button {

        const char *label;
        Rectangle rect;
        function<void()> func;

        /// добавить статус кнопки, паддинг, ориентация в глобальном пространстве или в пространстве контейнера ( посмотреть как работают оригинальные контейнеры)
        /// поддержка уникальных стилей для каждого элемента

        void Draw() {
            if ( GuiButton( rect, label) ){
                func();
            }
        }

        void Update(){

        };
    };




    void Draw();
    void Update();
    void AddButton(char* label,function<void()> func, float padding = 0);
}


