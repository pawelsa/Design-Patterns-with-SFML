#pragma once
#include <SFML/Graphics.hpp>

typedef sf::Vector2f Size;
typedef sf::Vector2f Position;
typedef int TextSize;
typedef std::string String;
typedef sf::RectangleShape Rectangle;
typedef sf::Text TextView;

namespace DIM {

	sf::Font font;

	std::vector<std::string> MonthNames = { "January", "February", "March", "April", "May", "June", "July", "August" , "September" , "October" , "November" , "December" };

	std::vector<std::string> DayNames = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"  };

		/*	
		*	
		*	*	Item is basically the square which is printed in every view
		*	
		*	*	ItemOffset is offset from the upper left corner of window to first square (Item)
		*	
		*	*	TextOffset is offset of a text from the upper left corner of square (Item)
		*	
		*	*	OffsetBetweenItems distance between two squares (Items) 
		*			it consists of SizeOfItem and OutlineThickness
		*	
		*/


	/*			RenderWindow											*/

	const sf::Vector2u WindowSize = sf::Vector2u(1280, 720);

	/*			Calendar class											*/

	const Size SizeOfItem_Calendar = Size(160, 160);
	const Position ItemOffset_Calendar = Position(380, 220);
	const Position OffsetBetweenItems_Calendar = Position(200,0);
	const Position TextOffset_Calendar = Position(50, 60);
	const int ThicknessOfBlackOutliner = 100;
	const int TextSize_Calendar = 25;

	/*			Year class												*/

	const Size SizeOfItem_Year = Size(150, 150);
	const Position ItemOffset_Year = Position(340, 135);
	const int OutlineThickness_Year = 5;
	const Position OffsetBetweenItems_Year = SizeOfItem_Year + Position(OutlineThickness_Year, OutlineThickness_Year);
	const Position TextOffset_Year = Position(18, 18);
	const int TextSize_Year = 22;

	/*			Month class												*/

		const Size SizeOfItem_Month = Size(100, 100);
		const Position ItemOffset_Month = Position(300, 100);
		const int OutlineThickness_Month = 3;
		const Position OffestBetweenItems_Month = SizeOfItem_Month + Position(OutlineThickness_Month, OutlineThickness_Month);
		const Position TextOffset_Month = Position(15, 15);
		const Position DayNamesOffset = Position(300, 60);
		const int TextSize_Month = 17;

		/*			Week view											*/

		const Size SizeOfItem_Week = Size(100, 500);
		const Position ItemOffset_Week = Position(300, 100);
		const int OutlineThickness_Week = 3;
		const Position OffestBetweenItems_Week = SizeOfItem_Week + Position(OutlineThickness_Week, OutlineThickness_Week);
		const Position TextOffset_Week = Position(15, 15);
		const Position DayNamesOffset_Week = Position(300, 60);
		const int TextSize_Week = 17;

		
		const Size SizeOfEventTextBox_Week = Size(90, 80);
		const Position EventTextOffset_Week = Position(5, 5);
		const Position TextNameEventOffset_Week = Position(0, 40);
		const int EventTextSize_Week = 14;
		

	/*			Day class												*/

	const Size SizeOfItem_Day = Size(800, 40);
	const Position NoEventsTextPosition_Day = Position(500, 200);
	const Position ItemOffset_Day = Position(240, 150);
	const Position OffsetBetweenItems_Day = Position(0, 45);
	const Position TextOffset_Day = Position(5, 5);
	const Position TextNameEventOffset_Day = Position(200, 0);
	const int NoEventTextSize_Day = 40;
	const int EventTextSize_Day = 25;

	/*			Add Event button										*/
	
	const Size SizeOfButton = Size(150, 40);
	const Position ButtonOffset = Position(1080, 70);
	const int OutlineThickness_Button = 3;
	const Position TextOffset_Button = Position(10,3);
	const int TextSize_Button = 15;

	/*			Event Helper											*/

		/*			CheckBoxes										*/
		const Size SizeOfCheckBox_Helper = Size(20, 20);
		const Position CheckBoxOffset_Helper = Position(200, 100);
		const Position OffsetBetweekCheckBoxes_Helper = Position(200, 0);
		const int OutlineThickness_Helper = 5;
		const Position CheckBoxTextOffset_Helper = Position(30, 0);
		const int CheckBoxTextSize_Helper = 17;

		/*			Description Text Box							*/
		const Size SizeOfDescriptionBox_Helper = Size(600, 30);
		const Position DescriptionBoxOffset_Helper = Position(200, 200);
		const int OutlineThicknessDescriptionBox_Helper = 5;
		
		const int TextSizeDescriptionBox_Helper = 26;
		const Position TextDescriptionBoxOffset_Helper = Position(2, -2);

		/*			DD/MM/YYYY										*/

		const Size SizeOfDDMMYYYYBox_Helper = Size(50, 30);
		const Position DDMMYYYYBoxOffset_Helper = Position(200, 300);
		const Position OffsetBetweenDDMMYYYYBoxes_Helper = Position(SizeOfDDMMYYYYBox_Helper.x + 20, 0);
		const int OutlineThicknessDDMMYYYYBox_Helper = 5;

		const int TextSizeDDMMYYYY_Helper = 26;
		const Position TextDDMMYYYYBoxOffset_Helper = Position(2, -2);

		/*			HH MM											*/

		const Size SizeOfHHMMBox_Helper = Size(50, 30);
		const Position HHMMBoxOffset_Helper = Position(500, 300);
		const Position OffsetBetweenHHMMBoxes_Helper = Position(SizeOfDDMMYYYYBox_Helper.x + 20, 0);
		const int OutlineThicknessHHMMBox_Helper = 5;

		const int TextSizeHHMM_Helper = 26;
		const Position TextHHMMBoxOffset_Helper = Position(2, -2);


		const Position EndingHHMMBoxOffset_Helper = Position(700, 300);


		/*			Periodic & LongTerm								*/

		const Position InfoTextOffset_Helper = Position(200, 350);
		const Size SizeOfPeriodicBox_Helper = Size(50, 30);
		const Position PeriodicBoxOffset_Helper = Position(200, 400);
		const Position OffsetBetweenPeriodicBoxes_Helper = Position(SizeOfDDMMYYYYBox_Helper.x + 20, 0);
		const int OutlineThicknessPeriodicBox_Helper = 5;

		const int TextSizePeriodic_Helper = 26;
		const Position TextPeriodicBoxOffset_Helper = Position(2, -2);

		/*			Person											*/

		const Position InfoPersonTextOffset_Helper = Position(200, 450);
		const Size SizeOfPersonBox_Helper = Size(200, 30);
		const Position PersonBoxOffset_Helper = Position(200, 500);
		const Position OffsetBetweenPersonBoxes_Helper = Position(SizeOfPersonBox_Helper.x + 20, 0);
		const int OutlineThicknessPersonBox_Helper = 5;

		const int TextSizePerson_Helper = 26;
		const Position TextPersonBoxOffset_Helper = Position(2, -2);


}