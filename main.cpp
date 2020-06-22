#include <TGUI/TGUI.hpp>
#include <TGUI/Widgets/Label.hpp>
#include <iostream>

void signalHandler(tgui::EditBox::Ptr edit_box, tgui::TextBox::Ptr text_box)
{
    text_box->setText(text_box->getText() + "\n" + edit_box->getText());
}

int main()
{
    sf::RenderWindow window{{800, 600}, "Window"};
    tgui::Gui gui{window};

    tgui::EditBox::Ptr editBox = tgui::EditBox::create();
    tgui::TextBox::Ptr textBox = tgui::TextBox::create();
    tgui::Button::Ptr button = tgui::Button::create();
    
    tgui::VerticalLayout::Ptr stat_block_labels = tgui::VerticalLayout::create();
    stat_block_labels->setSize("5%", "20%");
    stat_block_labels->setPosition(10, 10);

    tgui::Label::Ptr strength_label = tgui::Label::create();
    strength_label->setText("STR:");
    strength_label->getSharedRenderer()->setTextColor(sf::Color::White);
    tgui::Label::Ptr dexterity_label = tgui::Label::create();
    dexterity_label->setText("DEX:");
    dexterity_label->getSharedRenderer()->setTextColor(sf::Color::White);
    tgui::Label::Ptr intelligence_label = tgui::Label::create();
    intelligence_label->setText("INT:");
    intelligence_label->getSharedRenderer()->setTextColor(sf::Color::White);
    tgui::Label::Ptr wisdom_label = tgui::Label::create();
    wisdom_label->setText("WIS:");
    wisdom_label->getSharedRenderer()->setTextColor(sf::Color::White);
    tgui::Label::Ptr constitution_label = tgui::Label::create();
    constitution_label->setText("CON:");
    constitution_label->getSharedRenderer()->setTextColor(sf::Color::White);
    tgui::Label::Ptr charisma_label = tgui::Label::create();
    charisma_label->setText("CHA:");
    charisma_label->getSharedRenderer()->setTextColor(sf::Color::White);

    stat_block_labels->add(strength_label);
    stat_block_labels->add(dexterity_label);
    stat_block_labels->add(intelligence_label);
    stat_block_labels->add(wisdom_label);
    stat_block_labels->add(constitution_label);
    stat_block_labels->add(charisma_label);

    tgui::VerticalLayout::Ptr stat_block_values = tgui::VerticalLayout::create();
    stat_block_values->setSize("5%", "20%");
    stat_block_values->setPosition(10, 10);

    tgui::TextBox::Ptr strength = tgui::TextBox::create();
    strength->setReadOnly(true);
    strength->setText("10");
    tgui::TextBox::Ptr dexterity = tgui::TextBox::create();
    dexterity->setReadOnly(true);
    dexterity->setText("11");
    tgui::TextBox::Ptr intelligence = tgui::TextBox::create();
    intelligence->setReadOnly(true);
    intelligence->setText("12");
    tgui::TextBox::Ptr wisdom = tgui::TextBox::create();
    wisdom->setReadOnly(true);
    wisdom->setText("13");
    tgui::TextBox::Ptr constitution = tgui::TextBox::create();
    constitution->setReadOnly(true);
    constitution->setText("14");
    tgui::TextBox::Ptr charisma = tgui::TextBox::create();
    charisma->setReadOnly(true);
    charisma->setText("15");

    stat_block_values->add(strength);
    stat_block_values->add(dexterity);
    stat_block_values->add(intelligence);
    stat_block_values->add(wisdom);
    stat_block_values->add(constitution);
    stat_block_values->add(charisma);

    tgui::HorizontalLayout::Ptr stat_block_hl = tgui::HorizontalLayout::create();
    stat_block_hl->setSize("10%", "20%");

    stat_block_hl->add(stat_block_labels);
    stat_block_hl->add(stat_block_values);

    gui.add(stat_block_hl);

    sf::Vector2u window_size = window.getSize();
    textBox->setPosition(window_size.x / 2, 5);
    textBox->setSize((window_size.x / 2) - 5, window_size.y - 10);
    textBox->setText("Testing\nthis\ntext box\nto see\nhow it\nworks.");

    button->setPosition(200, 0);
    button->setSize(60, 20);
    button->setText("Button");
    button->connect("pressed", signalHandler, editBox, textBox);
    
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
