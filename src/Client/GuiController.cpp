//
// Created by bohdan.yurov on 11.09.2023.
//

#include "GuiController.h"

#include <utility>
using namespace std;

namespace GuiController {

    vector<Button> btns;

    void Draw() {
        for(auto & btn : btns) {
            btn.Draw();
        }
    }

    void Update() {

    }

    void AddButton(char * label, function<void()> func,float padding){
        auto b = Button{label,Rectangle{300 + padding,300 + padding,100,50},std::move(func)}; /// Использование тут анонимной функции и передача через мув, не знаю насколько это хорошо для производительности
        btns.emplace_back(b);
    }
}
