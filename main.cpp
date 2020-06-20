#include <TGUI/TGUI.hpp>
#include <iostream>

void signalHandler(tgui::EditBox::Ptr edit_box)
{
    edit_box->setText("TESTING");
}

int main()
{
    sf::RenderWindow window{{800, 600}, "Window"};
    tgui::Gui gui{window};

    tgui::EditBox::Ptr editBox = tgui::EditBox::create();
    editBox->setPosition({"&.width / 4 - width / 2", "&.height - height"});
    
    tgui::Button::Ptr button = tgui::Button::create();
    button->setPosition(200, 0);
    button->setSize(60, 20);
    button->setText("Button");
    button->connect("pressed", signalHandler, editBox);
    
    gui.add(button);
    gui.add(editBox, "MyWidgetName");    
    
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            
            gui.handleEvent(event);
        }
        
        window.clear();
        gui.draw();
        window.display();   
    }
}
