// Rails.cpp: главный файл проекта.

#include "stdafx.h"
#include "FormMain.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<System::String ^> ^args)
{
	Application::Run(gcnew Rails::FormMain());
    return 0;
}
